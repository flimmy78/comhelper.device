#include <math.h>
#include "limits.h"
#include "lib.h"

void printBuf(U8* buf, U16 bufSize, const char* file, const char* func, U32 line)
{
	U8	strBuf[2048] = { 0 };
#ifdef DEBUG
	U16 i = 0;
	Lib_printf("[%s][%s][%d]buf: ", file, func, line);
	for (i = 0; i < bufSize; i++)
		Lib_printf("%02X ", buf[i]);
	Lib_printf("\n");
#endif // DEBUG
	bytesToLog(buf, bufSize, strBuf, file, func, line);
	writeByteToFile(strBuf, strlen((const char*)strBuf), "log.txt");
}

//��ȡϵͳʱ��
U8 readSysTime(sys_time_ptr pTime)
{
	RtcGetDate(&(pTime->u8year), &(pTime->u8month), &(pTime->u8day));
	RtcGetTime(&(pTime->u8hour), &(pTime->u8minute), &(pTime->u8second));

	pTime->u8year = HEX_TO_BCD(pTime->u8year);
	pTime->u8month = HEX_TO_BCD(pTime->u8month);
	pTime->u8day = HEX_TO_BCD(pTime->u8day);
	pTime->u8hour = HEX_TO_BCD(pTime->u8hour);
	pTime->u8minute = HEX_TO_BCD(pTime->u8minute);
	pTime->u8second = HEX_TO_BCD(pTime->u8second);

	return 0;
}

//У��, �ۼӺ�
U8 countCheck(U8 *buf, U16 bufSize)
{
	U8 cs = 0;
	U16 i;
	for (i = 0; i < bufSize; i++, buf++)
		cs += *buf;

	return cs;
}

/*
**	����ַ����Ƿ���16�����ַ�.
**	@s:		�ַ���
**	@len:	�ַ�������
*/
U8 isHex(U8* s, U16 len)
{
	U16 i = 0;
	if (len == 0) {
		return ERROR;
	}
	for (i = 0; i < len; s++, i++) {
		if (!ishex(*s)) {
			return ERROR;
		}
	}

	return NO_ERR;
}

/*
**	�������ַ���תΪ������.
**	�ο�: http://opensource.apple.com//source/xnu/xnu-1456.1.26/bsd/libkern/strtol.c
**	@nptr:		�����ַ���
**	@endptr:	�ַ�������
**	@base:		����
**	return:		����ת��������
*/
U32 stringToL(const char* nptr, char **endptr, U8 base)
{
	const char *s = nptr;
	unsigned long acc;
	int c;
	unsigned long cutoff;//�޶ȵľ���ֵ
	int cutlim;
	int neg = 0, any;

	do {//�Թ��հ�
		c = *s++;
	} while (isspace(c));

	if (c == '-') {//����λ
		neg = 1;
		c = *s++;
	} else if (c == '+')
		c = *s++;

	if ((base == 0 || base == 16) && \
		c == '0' && (*s == 'x' || *s == 'X')) {
		c = s[1];
		s += 2;
		base = 16;
	} else if ((base == 0 || base == 2) && \
		c == '0' && (*s == 'b' || *s == 'B')) {
		c = s[1];
		s += 2;
		base = 2;
	}

	if (base == 0)
		base = c == '0' ? 8 : 10;

	/*
	**	Ϊ�˲������������ķ�Χ, 
	**	����cutoffΪ�Ȳ������ŵ����������1λ.
	**	�����һ���ַ�������ֵ��cutlim����ʱ,
	**	�Ͳ��ܼ���������.
	**	����������ַ���Ϊ"-2147483649"
	**	baseΪ10
	**	�����㵽cutoff=214748364ʱ, 
	**	�ִ�����һ���ַ�Ϊ9, ����cutlim
	**	(��ʱΪ8), �Ͳ��������¼�����
	*/
	cutoff = neg ? -(unsigned long)LONG_MIN : LONG_MAX;
	cutlim = cutoff % (unsigned long)base;
	cutoff /= (unsigned long)base;

	for (acc = 0, any = 0;; c = *s++) {
		if (isdigit(c))
			c -= '0';
		else if (isalpha(c))
			c -= (isupper(c) ? ('A' - 10) : ('a' - 10));
		else
			break;

		if (c >= base)
			break;

		if (any < 0 || acc > cutoff || acc == cutoff && c > cutlim)//����, ������
			any = -1;
		else {//û����
			any = 1;
			acc *= base;
			acc += c;
		}
	}

	if (any < 0) {//����, ���ؼ���ֵ
		acc = neg ? LONG_MIN : LONG_MAX;
	} else if (neg)//δ����, ��Ϊ����
		acc = -acc;

	if (endptr != NULL)
		*endptr = (char *)(any ? s - 1 : nptr);

	return (acc);
}

U8 bytesToString(U8* buf, U16 bufSize, U8* strBuf)
{
	U16	i = 0;
	S8	tmpStr[4] = { 0 };

	if (bufSize == 0) {
		return ERROR;
	}
	for (i = 0; i < bufSize - 1; i++) {
		Lib_sprintf(tmpStr, "%02X ", buf[i]);
		strcat((S8*)strBuf, (const char*)tmpStr);
	}

	Lib_sprintf(tmpStr, "%02X\n", buf[i]);
	strcat((S8*)strBuf, (const char*)tmpStr);
	return NO_ERR;
}

U8 bytesToLog(U8* buf, U16 bufSize, U8* strBuf, const char* file, const char* func, U32 line)
{
	sys_time_str timeStr;
	U8 s[3 * FRAME_MAX_LEN + 1] = { 0 };

	readSysTime(&timeStr);

	Lib_sprintf((S8*)strBuf, "[20%02X-%02X-%02X %02X:%02X:%02X][%s, %s, %d]", \
		timeStr.u8year, timeStr.u8month, timeStr.u8day, \
		timeStr.u8hour, timeStr.u8minute, timeStr.u8second, file, func, line);
	if (bytesToString(buf, bufSize, s) == ERROR) {
		return ERROR;
	}
	strcat((S8*)strBuf, (const S8*)s);
	return NO_ERR;
}

U8 writeByteToFile(U8* buf, U16 bufSize, S8* fileName)
{
	sFILE *fp = FileOpen(fileName, "war");

	if (fp == NULL) {
		return ERROR;
	}
	FileWrite(buf, bufSize, fp);
	FileClose(fp);
	return NO_ERR;
}

/*
**	�ж�һ���ַ����Ƿ����ֽ��ַ�����
**	@buf		�ַ�������
**	@bufSize	�ַ������泤��
*/
U8 isByteString(U8* buf, U16 bufSize)
{
	em_byte_state state = byte_state_init;
	U8* p = buf;
	while (*p == ' ') p++;//������ǰ��Ŀո�
	for (; *p != '\0'; p++) {
		switch (state) {
		case byte_state_init://byte_state_init�Ľ����ַ��ǿո��16�����ַ�
			if (ishex(*p)) {
				state = byte_state_h1;
			} else if (*p!=' ') {
				state = byte_state_err;
				goto errRes;
			}
			break;
		case byte_state_h1://byte_state_h2�Ľ����ַ��ǿո��16�����ַ�
			if (*p == ' ') {
				state = byte_state_init;
			} else if (ishex(*p)) {
				state = byte_state_h2;
			} else {
				state = byte_state_err;
				goto errRes;
			}
			break;
		case byte_state_h2://byte_state_h2��Ψһ�����ַ����ǿո�
			if (*p == ' ') {
				state = byte_state_init;
			} else {
				state = byte_state_err;
				goto errRes;
			}
			break;
		default:
			break;
		}
	}
	return NO_ERR;
errRes:
	return ERROR;
}

/*
**	��һ��ASCII���ʾ���ֽ�����,
**	�Դ������ҵ�˳��, ת��Ϊ�ֽ�����
**	@byteStr	�ַ���
**	@byteStrLen	�ַ�������
**	@byteArray	���ڴ洢�ֽڵ�����
**	@byteCnt	�õ����ֽ���
**	ע��: ����������isByteString()
**	���ʹ��, ���ų��Ƿ�����
*/
U8 byteStrToByteArray(U8* byteStr, U16 byteStrLen, U8* byteArray, U16* byteCnt)
{
	U8* p = byteStr;
	U8* q = NULL;
	U8 firstSpace = 0;//���, �Ƿ�������һ���ո�(����ո�, ����' '��'\0')
	U8 data = 0;

	*byteCnt = 0;
	while (*p == ' ') p++;//������ǰ��Ŀո�, ��pָ���1��16�����ַ�
	q = p;//��ʱfirstSpace==0, �������Ѿ�����16�����ַ�
	while (*p != '\0') {
		p++;
		if (ishex(*p) && firstSpace == 1) {
			firstSpace = 0;
			q = p;
		} else if ((*p == ' ' || *p == '\0') && firstSpace == 0) {
			data = *p;//����ԭֵ
			*p = '\0';//�޸�Ϊ������, �Թ�stringToLʹ��
			byteArray[(*byteCnt)] = ASCSTR_TO_HEX(q);
			(*byteCnt) += 1;
			firstSpace = 1;
			*p = data;//�ָ�ԭֵ, �Թ�while�ж��Ƿ񵽴��ַ�����β
		}
	}

	return NO_ERR;
}

/* 
 * ����ModBus-RTU����Э���CRCУ��ֵ
 * @nData		ָ����Ϣͷ��ָ��;
 * @wLength		��Ϣ��ĳ���
 */
U16 crc16ModRtu(const U8 *nData, U16 wLength)
{
	static const U16 wCRCTable[] = {
		0x0000, 0xC0C1, 0xC181, 0x0140, 0xC301, 0x03C0, 0x0280, 0xC241,
		0xC601, 0x06C0, 0x0780, 0xC741, 0x0500, 0xC5C1, 0xC481, 0x0440,
		0xCC01, 0x0CC0, 0x0D80, 0xCD41, 0x0F00, 0xCFC1, 0xCE81, 0x0E40,
		0x0A00, 0xCAC1, 0xCB81, 0x0B40, 0xC901, 0x09C0, 0x0880, 0xC841,
		0xD801, 0x18C0, 0x1980, 0xD941, 0x1B00, 0xDBC1, 0xDA81, 0x1A40,
		0x1E00, 0xDEC1, 0xDF81, 0x1F40, 0xDD01, 0x1DC0, 0x1C80, 0xDC41,
		0x1400, 0xD4C1, 0xD581, 0x1540, 0xD701, 0x17C0, 0x1680, 0xD641,
		0xD201, 0x12C0, 0x1380, 0xD341, 0x1100, 0xD1C1, 0xD081, 0x1040,
		0xF001, 0x30C0, 0x3180, 0xF141, 0x3300, 0xF3C1, 0xF281, 0x3240,
		0x3600, 0xF6C1, 0xF781, 0x3740, 0xF501, 0x35C0, 0x3480, 0xF441,
		0x3C00, 0xFCC1, 0xFD81, 0x3D40, 0xFF01, 0x3FC0, 0x3E80, 0xFE41,
		0xFA01, 0x3AC0, 0x3B80, 0xFB41, 0x3900, 0xF9C1, 0xF881, 0x3840,
		0x2800, 0xE8C1, 0xE981, 0x2940, 0xEB01, 0x2BC0, 0x2A80, 0xEA41,
		0xEE01, 0x2EC0, 0x2F80, 0xEF41, 0x2D00, 0xEDC1, 0xEC81, 0x2C40,
		0xE401, 0x24C0, 0x2580, 0xE541, 0x2700, 0xE7C1, 0xE681, 0x2640,
		0x2200, 0xE2C1, 0xE381, 0x2340, 0xE101, 0x21C0, 0x2080, 0xE041,
		0xA001, 0x60C0, 0x6180, 0xA141, 0x6300, 0xA3C1, 0xA281, 0x6240,
		0x6600, 0xA6C1, 0xA781, 0x6740, 0xA501, 0x65C0, 0x6480, 0xA441,
		0x6C00, 0xACC1, 0xAD81, 0x6D40, 0xAF01, 0x6FC0, 0x6E80, 0xAE41,
		0xAA01, 0x6AC0, 0x6B80, 0xAB41, 0x6900, 0xA9C1, 0xA881, 0x6840,
		0x7800, 0xB8C1, 0xB981, 0x7940, 0xBB01, 0x7BC0, 0x7A80, 0xBA41,
		0xBE01, 0x7EC0, 0x7F80, 0xBF41, 0x7D00, 0xBDC1, 0xBC81, 0x7C40,
		0xB401, 0x74C0, 0x7580, 0xB541, 0x7700, 0xB7C1, 0xB681, 0x7640,
		0x7200, 0xB2C1, 0xB381, 0x7340, 0xB101, 0x71C0, 0x7080, 0xB041,
		0x5000, 0x90C1, 0x9181, 0x5140, 0x9301, 0x53C0, 0x5280, 0x9241,
		0x9601, 0x56C0, 0x5780, 0x9741, 0x5500, 0x95C1, 0x9481, 0x5440,
		0x9C01, 0x5CC0, 0x5D80, 0x9D41, 0x5F00, 0x9FC1, 0x9E81, 0x5E40,
		0x5A00, 0x9AC1, 0x9B81, 0x5B40, 0x9901, 0x59C0, 0x5880, 0x9841,
		0x8801, 0x48C0, 0x4980, 0x8941, 0x4B00, 0x8BC1, 0x8A81, 0x4A40,
		0x4E00, 0x8EC1, 0x8F81, 0x4F40, 0x8D01, 0x4DC0, 0x4C80, 0x8C41,
		0x4400, 0x84C1, 0x8581, 0x4540, 0x8701, 0x47C0, 0x4680, 0x8641,
		0x8201, 0x42C0, 0x4380, 0x8341, 0x4100, 0x81C1, 0x8081, 0x4040
	};

	U8 nTemp;
	U16 wCRCWord = 0xFFFF;

	while (wLength--) {
		nTemp = *nData++ ^ wCRCWord;
		wCRCWord >>= 8;
		wCRCWord ^= wCRCTable[nTemp];
	}
	return wCRCWord;
}
