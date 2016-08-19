#ifndef DB_H
#define DB_H

#include "user.h"
#include "base.h"

#define CONFIG_FIELD_CNT	2	//配置数据库的字段数量
#define DB_CONFIG_ID_LEN	1	//配置数据库中ID字段的长度
#define DB_CONFIG_VALUE_LEN	20	//配置数据库中VALUE字段的长度

#define CONFIG_INITTED		0x01//手持机参数已经被初始化
#define CONFIG_NOT_INITTED	0x00//手持机参数还没被初始化

#define DB_CONFIG_NAME			"串口调试配置.DBF"

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
