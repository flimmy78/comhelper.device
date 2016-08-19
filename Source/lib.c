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

//读取系统时间
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

//校验, 累加和
U8 countCheck(U8 *buf, U16 bufSize)
{
	U8 cs = 0;
	U16 i;
	for (i = 0; i < bufSize; i++, buf++)
		cs += *buf;

	return cs;
}

/*
**	检查字符串是否都是16进制字符.
**	@s:		字符串
**	@len:	字符串长度
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
**	将数字字符串转为长整数.
**	参考: http://opensource.apple.com//source/xnu/xnu-1456.1.26/bsd/libkern/strtol.c
**	@nptr:		数字字符串
**	@endptr:	字符串长度
**	@base:		基数
**	return:		返回转换的整数
*/
U32 stringToL(const char* nptr, char **endptr, U8 base)
{
	const char *s = nptr;
	unsigned long acc;
	int c;
	unsigned long cutoff;//限度的绝对值
	int cutlim;
	int neg = 0, any;

	do {//略过空白
		c = *s++;
	} while (isspace(c));

	if (c == '-') {//符号位
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
	**	为了不超过长整数的范围, 
	**	设置cutoff为比不带符号的最大整数少1位.
	**	如果下一个字符的数字值比cutlim还大时,
	**	就不能继续计算了.
	**	比如输入的字符串为"-2147483649"
	**	base为10
	**	当计算到cutoff=214748364时, 
	**	字串的下一个字符为9, 大于cutlim
	**	(此时为8), 就不能再往下计算了
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

		if (any < 0 || acc > cutoff || acc == cutoff && c > cutlim)//超限, 不计算
			any = -1;
		else {//没超限
			any = 1;
			acc *= base;
			acc += c;
		}
	}

	if (any < 0) {//超限, 返回极限值
		acc = neg ? LONG_MIN : LONG_MAX;
	} else if (neg)//未超限, 但为负数
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
**	判断一个字符串是否是字节字符序列
**	@buf		字符串缓存
**	@bufSize	字符串缓存长度
*/
U8 isByteString(U8* buf, U16 bufSize)
{
	em_byte_state state = byte_state_init;
	U8* p = buf;
	while (*p == ' ') p++;//忽略最前面的空格
	for (; *p != '\0'; p++) {
		switch (state) {
		case byte_state_init://byte_state_init的接收字符是空格或16进制字符
			if (ishex(*p)) {
				state = byte_state_h1;
			} else if (*p!=' ') {
				state = byte_state_err;
				goto errRes;
			}
			break;
		case byte_state_h1://byte_state_h2的接收字符是空格或16进制字符
			if (*p == ' ') {
				state = byte_state_init;
			} else if (ishex(*p)) {
				state = byte_state_h2;
			} else {
				state = byte_state_err;
				goto errRes;
			}
			break;
		case byte_state_h2://byte_state_h2的唯一接收字符就是空格
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
**	将一个ASCII码表示的字节序列,
**	以从左至右的顺序, 转化为字节数组
**	@byteStr	字符串
**	@byteStrLen	字符串长度
**	@byteArray	用于存储字节的数组
**	@byteCnt	得到的字节数
**	注意: 本程序须与isByteString()
**	配合使用, 以排除非法输入
*/
U8 byteStrToByteArray(U8* byteStr, U16 byteStrLen, U8* byteArray, U16* byteCnt)
{
	U8* p = byteStr;
	U8* q = NULL;
	U8 firstSpace = 0;//标记, 是否遇到第一个空格(广义空格, 包括' '和'\0')
	U8 data = 0;

	*byteCnt = 0;
	while (*p == ' ') p++;//忽略最前面的空格, 将p指向第1个16进制字符
	q = p;//此时firstSpace==0, 即表明已经遇到16进制字符
	while (*p != '\0') {
		p++;
		if (ishex(*p) && firstSpace == 1) {
			firstSpace = 0;
			q = p;
		} else if ((*p == ' ' || *p == '\0') && firstSpace == 0) {
			data = *p;//保留原值
			*p = '\0';//修改为结束符, 以供stringToL使用
			byteArray[(*byteCnt)] = ASCSTR_TO_HEX(q);
			(*byteCnt) += 1;
			firstSpace = 1;
			*p = data;//恢复原值, 以供while判断是否到达字符串结尾
		}
	}

	return NO_ERR;
}

/* 
 * 计算ModBus-RTU传输协议的CRC校验值
 * @nData		指向消息头的指针;
 * @wLength		消息体的长度
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
