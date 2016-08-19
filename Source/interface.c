/***************************************************
**	ģ�鹦��:	�����û����潻��
**	ģ������:	interface.c
**	���ߣ�		�α���
****************************************************
*/

#include "db.h"
#include "protocol.h"
#include "logic.h"
#include "lib.h"
#include "interface.h"

sUART *gpu = NULL;//ָ�򴮿ڵ�ָ��global_pointer_uart
/************************************************************************/
/* widget����Ⱥ                                                         */
/************************************************************************/

static const GUI_WIDGET_CREATE_INFO widgetComHelper[] = {
	{ FRAMEWIN_CreateIndirect, "���ڵ�������", ID_FRAMEWIN_0, 0, 0, 240, 320, 0, 0 },
	{ TEXT_CreateIndirect, "�˿�", ID_TEXT_0, 5, 5, 60, 20, 0, 0 },
	{ TEXT_CreateIndirect, "������", ID_TEXT_1, 5, 30, 59, 20, 0, 0 },
	{ TEXT_CreateIndirect, "����ģʽ", ID_TEXT_2, 5, 55, 56, 20, 0, 0 },
	{ BUTTON_CreateIndirect, "��\n����", ID_BUTTON_0, 170, 5, 45, 65, 0, 0 },
	{ MULTIEDIT_CreateIndirect, "", ID_MULTILINE_0, 5, 90, 210, 80, 0, 0 },
	{ BUTTON_CreateIndirect, "CRC", ID_BUTTON_1, 5, 185, 45, 20, 0, 0 },
	{ BUTTON_CreateIndirect, "�ۼ�", ID_BUTTON_2, 60, 185, 51, 20, 0, 0 },
	{ MULTIEDIT_CreateIndirect, "", ID_MULTILINE_1, 5, 215, 210, 80, 0, 0 },
	{ BUTTON_CreateIndirect, "����", ID_BUTTON_3, 130, 185, 80, 20, 0, 0 },
	{ DROPDOWN_CreateIndirect, "", ID_DROPDOWN_0, 75, 5, 80, 19, 0, 0 },
	{ DROPDOWN_CreateIndirect, "", ID_DROPDOWN_1, 75, 30, 80, 19, 0, 0 },
	{ DROPDOWN_CreateIndirect, "", ID_DROPDOWN_2, 75, 55, 80, 19, 0, 0 }
};

S8* gs8deviceStrArray[] = { "RS485","MBUS" };

U8	gu8deviceIntArray[] = { UART_DEVICE_RS485, UART_DEVICE_MBUS };

S8* gs8baudStrArray[] = { "1200","2400","4800","9600","19200","38400","57600","115200" };

U32 gu32baudIntArray[] = { 1200,2400,4800,9600,19200,38400,57600,115200 };

S8* gs8dataModeStrArray[] = { "7,��,1", "7,ż,1", "8,��,1", "8,��,1", "8,ż,1", "9,��,1" };

U8	gu8dataModeIntArray[] = { UART_MODE_7B_ODD_1S, UART_MODE_7B_EVEN_1S, \
							UART_MODE_8B_NONE_1S, UART_MODE_8B_ODD_1S, \
							UART_MODE_8B_EVEN_1S, UART_MODE_9B_NONE_1S };
/************************************************************************/
/* Init����Ⱥ                                                           */
/************************************************************************/
static void comhelperInit(WM_HWIN hDlg)
{
	WM_HWIN hItem;
	U16 i = 0;
	sUART lComConfig;//com config
	U16 itemCnt = 0;

	db_getCongfig(config_com_para, (U8*)&lComConfig);

	for (i = ID_TEXT_0; i <= ID_TEXT_6; i++) {
		hItem = WM_GetDialogItem(hDlg, i);
		TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
	}

	hItem = WM_GetDialogItem(hDlg, ID_DROPDOWN_0);
	itemCnt = sizeof(gs8deviceStrArray) / sizeof(S8*);
	for (i = 0; i < itemCnt; i++) {
		DROPDOWN_AddString(hItem, gs8deviceStrArray[i]);
		if (gu8deviceIntArray[i] == lComConfig.device) {
			DROPDOWN_SetSel(hItem, i);
		}
	}

	hItem = WM_GetDialogItem(hDlg, ID_DROPDOWN_1);
	itemCnt = sizeof(gs8baudStrArray) / sizeof(S8*);
	for (i = 0; i < itemCnt; i++) {
		DROPDOWN_AddString(hItem, gs8baudStrArray[i]);
		if (gu32baudIntArray[i] == lComConfig.baud) {
			DROPDOWN_SetSel(hItem, i);
		}
	}

	hItem = WM_GetDialogItem(hDlg, ID_DROPDOWN_2);
	itemCnt = sizeof(gs8dataModeStrArray) / sizeof(S8*);
	for (i = 0; i < itemCnt; i++) {
		DROPDOWN_AddString(hItem, gs8dataModeStrArray[i]);
		if (gu8dataModeIntArray[i] == lComConfig.mode) {
			DROPDOWN_SetSel(hItem, i);
		}
	}
	hItem = WM_GetDialogItem(hDlg, ID_MULTILINE_0);
	MULTIEDIT_SetWrapWord(hItem);
	hItem = WM_GetDialogItem(hDlg, ID_MULTILINE_1);
	MULTIEDIT_SetWrapWord(hItem);
}

/************************************************************************/
/* CallBack����Ⱥ                                                       */
/************************************************************************/

void openCom(WM_HWIN hDlg)
{
	WM_HWIN hItem;
	U8  device;
	U32 baud;
	U8  mode;

	//�豸
	hItem = WM_GetDialogItem(hDlg, ID_DROPDOWN_0);
	device = gu8deviceIntArray[DROPDOWN_GetSel(hItem)];
	//������
	hItem = WM_GetDialogItem(hDlg, ID_DROPDOWN_1);
	baud = gu32baudIntArray[DROPDOWN_GetSel(hItem)];
	//����ģʽ
	hItem = WM_GetDialogItem(hDlg, ID_DROPDOWN_2);
	mode = gu8dataModeIntArray[DROPDOWN_GetSel(hItem)];

	gpu = UartOpen(baud, mode, device);//�򿪴���
	if (!gpu) {
		GUI_MessageBox("\n�򿪴���ʧ��\n", "ʧ��", GUI_MESSAGEBOX_CF_MODAL);
	} else {
		if (logic_saveConfig(device, baud, mode) == ERROR)
			GUI_MessageBox("\n��������ʧ��\n", "ʧ��", GUI_MESSAGEBOX_CF_MODAL);
		GUI_MessageBox("\n�򿪴��ڳɹ�\n", "�ɹ�", GUI_MESSAGEBOX_CF_MODAL);
	}
	WM_SetFocus(hDlg);
}

void crcChk(WM_HWIN hDlg)
{
	WM_HWIN hItem;
	U8 sendbuf[3 * FRAME_MAX_LEN + 1] = { 0 };

	hItem = WM_GetDialogItem(hDlg, ID_MULTILINE_0);
	MULTIEDIT_GetText(hItem, (S8*)sendbuf, 2 * FRAME_MAX_LEN);

	if (isByteString(sendbuf, STRLEN(sendbuf)) == ERROR) {
		GUI_MessageBox("\n�������ֽ�\n", "����", GUI_MESSAGEBOX_CF_MODAL);
	}
	if (logic_crcChk(sendbuf) == ERROR) {
		GUI_MessageBox("\nCRCУ��ʧ��\n", "ʧ��", GUI_MESSAGEBOX_CF_MODAL);
	} else {
		hItem = WM_GetDialogItem(hDlg, ID_MULTILINE_0);
		MULTIEDIT_SetText(hItem, (const S8*)sendbuf);
	}
	WM_SetFocus(hDlg);
}

void chkSum(WM_HWIN hDlg)
{
	WM_HWIN hItem;
	U8 sendbuf[3 * FRAME_MAX_LEN + 1] = { 0 };

	hItem = WM_GetDialogItem(hDlg, ID_MULTILINE_0);
	MULTIEDIT_GetText(hItem, (S8*)sendbuf, 2 * FRAME_MAX_LEN);

	if (isByteString(sendbuf, STRLEN(sendbuf)) == ERROR) {
		GUI_MessageBox("\n�������ֽ�\n", "����", GUI_MESSAGEBOX_CF_MODAL);
	}
	if (logic_chkSum(sendbuf) == ERROR) {
		GUI_MessageBox("\nCRCУ��ʧ��\n", "ʧ��", GUI_MESSAGEBOX_CF_MODAL);
	}
	else {
		hItem = WM_GetDialogItem(hDlg, ID_MULTILINE_0);
		MULTIEDIT_SetText(hItem, (const S8*)sendbuf);
	}
	WM_SetFocus(hDlg);
}

void sendData(WM_HWIN hDlg)
{
	WM_HWIN hItem;
	U8 sendbuf[3 * FRAME_MAX_LEN + 1] = { 0 };

	hItem = WM_GetDialogItem(hDlg, ID_MULTILINE_0);
	MULTIEDIT_GetText(hItem, (S8*)sendbuf, 2 * FRAME_MAX_LEN);

	if (isByteString(sendbuf, STRLEN(sendbuf)) == ERROR) {
		GUI_MessageBox("\n�������ֽ�\n", "����", GUI_MESSAGEBOX_CF_MODAL);
	}
	if (gpu != NULL) {
		if (logic_sendBuf(sendbuf) == ERROR) {
			GUI_MessageBox("\nCRCУ��ʧ��\n", "ʧ��", GUI_MESSAGEBOX_CF_MODAL);
		}
		else {
			hItem = WM_GetDialogItem(hDlg, ID_MULTILINE_1);
			MULTIEDIT_SetText(hItem, (const S8*)sendbuf);
		}
	} else {
		GUI_MessageBox("\n���ȴ򿪴���\n", "ʧ��", GUI_MESSAGEBOX_CF_MODAL);
	}
	WM_SetFocus(hDlg);
}

void comHelperCb(WM_MESSAGE* pMsg)
{
	int NCode, Id;
	WM_HWIN hDlg;
	hDlg = pMsg->hWin;

	switch (pMsg->MsgId)
	{
	case WM_INIT_DIALOG:
		comhelperInit(hDlg);
		break;
	case WM_PAINT:
		break;
	case WM_NOTIFY_PARENT:
		Id = WM_GetId(pMsg->hWinSrc);
		NCode = pMsg->Data.v;
		switch (NCode)
		{
		case WM_NOTIFICATION_RELEASED: //��������Ϣ
			switch (Id) {
			case ID_BUTTON_0://�򿪴���
				openCom(hDlg);
				break;
			case ID_BUTTON_1://CRC16
				crcChk(hDlg);
				break;
			case ID_BUTTON_2://У���
				chkSum(hDlg);
				break;
			case ID_BUTTON_3://����
				sendData(hDlg);
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
		break;
	case WM_KEY: //������Ϣ
		switch (((WM_KEY_INFO *)(pMsg->Data.p))->Key) {
		case GUI_KEY_ESCAPE://Exit
			GUI_EndDialog(hDlg, WM_USER_EXIT);
			break;
		case GUI_KEY_NUM1://�򿪴���
			openCom(hDlg);
			break;
		case GUI_KEY_NUM2://CRC16
			crcChk(hDlg);
			break;
		case GUI_KEY_NUM3://У���
			chkSum(hDlg);
			break; 
		case GUI_KEY_NUM4://����
			sendData(hDlg);
			break;
		case GUI_KEY_ENTER:
			break;
		case GUI_KEY_UP:
			WM_SetFocusOnPrevChild(WM_GetParent(WM_GetDialogItem(hDlg, ID_BUTTON_0)));
			break;
		case GUI_KEY_DOWN:
			WM_SetFocusOnNextChild(WM_GetParent(WM_GetDialogItem(hDlg, ID_BUTTON_0)));
			break;
		default:
			break;
		}
		break;
	default:
		WM_DefaultProc(pMsg);
	}
}

void comHelper()
{
	int iRet;
	while (1) {
		iRet = GUI_ExecDialogBox(widgetComHelper, GUI_COUNTOF(widgetComHelper), &comHelperCb, WM_HBKWIN, 0, 0);
		if (iRet == WM_USER_EXIT) {
			if (gpu)
				UartClose(gpu);//�ȹرմ���, ���˳�
			return;
		}
	}
}
