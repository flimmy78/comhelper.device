#ifndef BASE_H
#define BASE_H

#include "user.h"

//#define DEBUG
#define	FILE_LINE   __FILE__,__FUNCTION__,__LINE__
#define	PRINT_LINE()	Lib_printf("[%s][%s][%d]\n", FILE_LINE);
#define NO_ERR	0x00//�޴�
#define ERROR	0xEE//�д�
#define WM_USER_EXIT	-1//�����쳣����ֵ
#define EDIT_MAX_LEN	128
#define	FRAME_MAX_LEN	256

#define UART_WAIT_SHORT	2000//���ڵȴ�ʱ��-��-
#define UART_WAIT_MID	7000//���ڵȴ�ʱ��-��-
#define UART_WAIT_LONG	40000//���ڵȴ�ʱ��-��-

#pragma pack(push)
#pragma pack(1)
typedef struct {//ϵͳʱ��ṹ, ����洢�Է���ʹ��
	U8 u8second;	//��
	U8 u8minute;	//��
	U8 u8hour;		//ʱ
	U8 u8day;		//��
	U8 u8month;		//��
	U8 u8year;		//��
}sys_time_str;
typedef sys_time_str* sys_time_ptr;

#pragma pack(pop)

//�ֳֻ����õ�������, �����ݿ��е��к�Ҳ��˶�Ӧ
typedef enum {
	config_com_para = 0,//�˿���ز���
	config_meter_type,	//�Ǳ�����
	config_valve_type	//��������
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
