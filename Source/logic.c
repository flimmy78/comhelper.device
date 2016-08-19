/***************************************************
**	ģ�鹦��:	����ҵ���߼�
**	ģ������:	logic.c
**	���ߣ�		�α���
****************************************************
*/

#include "db.h"
#include "lib.h"
#include "protocol.h"
#include "logic.h"

extern sUART* gpu;

/*
**	�򴮿ڶ�д����.
**	@buf:		������������ݻ�����
**	@bufSize:	����������
*/
U8 logic_sendAndRead(U8* buf, U16* bufSize, U32 timeout)
{
	UartWrite(buf, *bufSize, timeout, gpu);
	*bufSize = UartRead(buf, 100, timeout, gpu);
	if (*bufSize == 0) {//�����ʱ��û�ж�������, ���ش���
		return ERROR;
	}
	return NO_ERR;
}

U8 logic_saveConfig(U8 device, U32 baud, U8  mode)
{
	if (db_setComConfig(device, baud, mode) == ERROR) {
		return ERROR;
	}
	return db_writeConfig();
}

U8 logic_crcChk(U8* sendbuf)
{
	U8 byteArray[FRAME_MAX_LEN] = { 0 };
	U16 byteCnt = 0;
	U16 crcChk = 0;

	byteStrToByteArray(sendbuf, STRLEN(sendbuf), byteArray, &byteCnt);
	crcChk = crc16ModRtu(byteArray, byteCnt);
	memcpy(byteArray, (U8*)&crcChk, sizeof(U16));
	Lib_sprintf((S8*)sendbuf, "%s %02X %02X", sendbuf, byteArray[0], byteArray[1]);//С��
	return NO_ERR;
}

U8 logic_chkSum(U8* sendbuf)
{
	U8 byteArray[FRAME_MAX_LEN] = { 0 };
	U16 byteCnt = 0;

	byteStrToByteArray(sendbuf, STRLEN(sendbuf), byteArray, &byteCnt);
	Lib_sprintf((S8*)sendbuf, "%s %02X", sendbuf, countCheck(byteArray, byteCnt));
	return NO_ERR;
}

U8 logic_sendBuf(U8* sendbuf)
{
	U8 byteArray[FRAME_MAX_LEN] = { 0 };
	U16 byteCnt = 0;

	byteStrToByteArray(sendbuf, STRLEN(sendbuf), byteArray, &byteCnt);
	if (logic_sendAndRead(byteArray, &byteCnt, UART_WAIT_SHORT) == NO_ERR) {
		memset(sendbuf, 0, STRLEN(sendbuf));
		bytesToString(byteArray, byteCnt, sendbuf);
	}
	return NO_ERR;
}
