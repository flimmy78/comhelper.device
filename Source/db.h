#ifndef DB_H
#define DB_H

#include "user.h"
#include "base.h"

#define CONFIG_FIELD_CNT	2	//�������ݿ���ֶ�����
#define DB_CONFIG_ID_LEN	1	//�������ݿ���ID�ֶεĳ���
#define DB_CONFIG_VALUE_LEN	20	//�������ݿ���VALUE�ֶεĳ���

#define CONFIG_INITTED		0x01//�ֳֻ������Ѿ�����ʼ��
#define CONFIG_NOT_INITTED	0x00//�ֳֻ�������û����ʼ��

#define DB_CONFIG_NAME			"���ڵ�������.DBF"

#define CONFIG_DELIMITER	','

typedef enum
{
	config_field_id = 0,
	config_field_vale,
}config_field_idx;


extern U8 openDBF(U8* dbfName);
extern U8 closeDBF(void);
extern U8 db_setComConfig(U8 device, U32 baud, U8  mode);
extern U8 db_writeConfig(void);
extern U8 db_readAllConfig(void);
extern U8 db_getCongfig(u16 configIdx, U8* config);

#endif // DB_H
