#ifndef BASE_H
#define BASE_H

#include "user.h"

//#define DEBUG
#define	FILE_LINE   __FILE__,__FUNCTION__,__LINE__
#define	PRINT_LINE()	Lib_printf("[%s][%s][%d]\n", FILE_LINE);
#define NO_ERR	0x00//无错
#define ERROR	0xEE//有错
#define WM_USER_EXIT	-1//界面异常返回值
#define EDIT_MAX_LEN	128
#define	FRAME_MAX_LEN	256

#define UART_WAIT_SHORT	2000//串口等待时间-短-
#define UART_WAIT_MID	7000//串口等待时间-中-
#define UART_WAIT_LONG	40000//串口等待时间-长-

#pragma pack(push)
#pragma pack(1)
typedef struct {//系统时间结构, 倒序存储以方便使用
	U8 u8second;	//秒
	U8 u8minute;	//分
	U8 u8hour;		//时
	U8 u8day;		//日
	U8 u8month;		//月
	U8 u8year;		//年
}sys_time_str;
typedef sys_time_str* sys_time_ptr;

#pragma pack(pop)

//手持机设置的索引号, 在数据库中的行号也与此对应
typedef enum {
	config_com_para = 0,//端口相关参数
	config_meter_type,	//仪表类型
	config_valve_type	//阀控类型
}config_rowidx;

typedef enum {
	em_device_rs485 = 0,
	em_device_mbus
}em_device_idx;

typedef enum {
	em_baud_1200 = 0,
	em_baud_2400,
	em_baud_4800,
	em_baud_9600,
	em_baud_19200,
	em_baud_38400,
	em_baud_57600,
	em_baud_115200
} em_baud_idx;

#endif // ifndef BASE_H
