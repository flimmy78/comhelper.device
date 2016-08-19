#ifndef LIB_H
#define LIB_H

#include "user.h"
#include "base.h"
#include "protocol.h"
#include "db.h"


#define HEX_TO_BCD(x) (((x)/0x0A)*0x10+((x)%0x0A))
#define BCD_TO_HEX(x) (((x)/0x10)*0x0A+((x)%0x10))

#define ASCII_TO_HEX(c) ((c >='0' && c <='9')?(c-'0'):((c>='A'&&c<='F')?(c-'A'+10):((c>='a'&&c<='f')?(c-'a'+10):0)))
#define ASCSTR_TO_HEX(str)	stringToL((const char*)(str), NULL, 16)//以16进制表示的字符串转化为16进制数

#define isspace(c)	(c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\12' || c == '\0')
#define isdigit(c)	((unsigned) ((c)-'0') < 10)
#define ishex(c)	((unsigned) ((c)-'0') < 10 || (unsigned) ((c)-'a') < 6 || (unsigned) ((c)-'A') < 6 )
#define isalpha(c)	((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
#define isupper(c)	(c >= 'A' && c <= 'Z')
#define STRLEN(c)	strlen((const char*)(c))
#define IS_SPACE	0x01
#define NOT_SPACE	0x00

typedef enum {
	float_state_init = 0,
	float_state_sign,
	float_state_digit,
	float_state_dec_point,
	float_state_err
} em_float_state;

typedef enum {
	byte_state_init = 0,	//初始状态
	byte_state_h1,			//第1个16进制字符状态
	byte_state_h2,			//第2个16进制字符状态
	byte_state_err			//错误状态
} em_byte_state;

extern void printBuf(U8* buf, U16 bufSize, const char* file, const char* func, U32 line);
extern U8 readSysTime(sys_time_ptr pTime);
extern U8 countCheck(U8 *data, U16 len);
extern U16 crc16ModRtu(const U8 *nData, U16 wLength);
extern U8 isHex(U8* s, U16 len);
extern U8 isByteString(U8* buf, U16 bufSize);
extern U8 bytesToString(U8* buf, U16 bufSize, U8* strBuf);
extern U8 bytesToLog(U8* buf, U16 bufSize, U8* strBuf, const char* file, const char* func, U32 line);
extern U8 writeByteToFile(U8* buf, U16 bufSize, S8* fileName);
extern U8 byteStrToByteArray(U8* byteStr, U16 byteStrLen, U8* byteArray, U16* byteCnt);
extern U16 crc16ModRtu(const U8 *nData, U16 wLength);
#endif
