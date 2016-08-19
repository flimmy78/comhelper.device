#ifndef PROTOCOL_H
#define PROTOCOL_H

#include "user.h"
#include "base.h"


#define METER_ADDR_LEN	7//仪表地址长度, 7位BCD码
#define ELSONIC_OPEN_HOUR_LEN	3//亿林家阀控的开阀时间中小时数的长度

#define PROTOCOL_STANDARD_CJ188	0//CJ188协议
#define PROTOCOL_STANDARD_26831	1//26831协议

#define OPEN_VALVE				0//打开阀门
#define CLOSE_VALVE				1//关闭阀门

#pragma pack(push)
#pragma pack(1)

typedef struct {
	U16 bigErr;//大流量误差
	U16 mid2Err;//中二流量误差
	U16 mid1Err;//中一流量误差
	U16 smallErr;//小流量误差
} flow_coe_str;
typedef flow_coe_str* flow_coe_ptr;

typedef struct {
	float bigErr;//大流量误差float
	float mid2Err;//中二流量误差float
	float mid1Err;//中一流量误差float
	float smallErr;//小流量误差float
} flow_error_str;
typedef flow_error_str* flow_error_ptr;

typedef struct {
	U8 inTemp[2];//供水温度 24.35C
	U8 pulseCnt[4];//脉冲个数
	U8 chkAccFlow[4];//检定时累积流量, 
	U8 chkAccFlowUnit;//检定时累积流量单位
	U8 chkAccHeat[4];//检定时累积热量
	U8 chkAccHeatUnit;//检定时累积热量单位
	U8 accWarnTime[3];//累积报警时间
	U8 meterDiam[2];//管径
	U8 diffAt0[4];//零点差值
	U8 pulseWidth[3];//脉冲宽度
	U8 meterAddr[4];//表号
	flow_coe_str flowErr;//流量误差
	U8 tempParam1[2]; //温度参数1
	U8 tempParam2[2];//温度参数2
	U8 meterParam[2];//仪表参数
	U8 outTemp[2];//回水温度, 24.29℃
	U8 misc;
	U8 date[4];//日期2016年 07月 31日
	U8 st[2];//ST
} meter_ret_data_str;
typedef meter_ret_data_str* meter_ret_data_ptr;

typedef struct {//仪表组帧时用到的信息, 为了方便的解析应答帧, 不能改变成员变量的次序
	U8	protoType;			//协议类型, 0 - CJ188; 1 - 26831
	U8	prefix;				//前导符
	U16	prefixCnt;			//前导符数量
	U8	startChar;			//开始符
	U8	meterType;			//仪表类型, 20-热表;B0-阀控;
	U8	meterAddr[METER_ADDR_LEN];//仪表地址, 最大支持7位, 即14位BCD码
	U8	ctlCode;			//控制符
	U8	dataLen;			//数据域长度
	U16	dataIdentify;		//数据标识
	U8	seq;				//序列号
	U8	endChar;			//结束符
	U8	busType;			//总线类型, 0 - RS485; 1 - MBUS
	U8	addrLen;			//仪表地址长度
	U8	radioAddr;			//广播读表时的字符
	U8*	pMsg;				//数据域指针, 指向数据标识后
} meter_frame_info_str;
typedef meter_frame_info_str* meter_frame_info_ptr;

typedef struct {
	U8	startChar;			//开始符
	U8	meterType;			//仪表类型, 20-热表;B0-阀控;
	U8	meterAddr[METER_ADDR_LEN];//仪表地址
	U8	ctlCode;			//控制符
	U8	dataLen;		//数据域长度
	U16	dataIdentify;	//数据标识
	U8*	pMsg;			//数据域指针, 指向数据标识后
	U8	cs;				//累加和
	U8	endChar;		//结束符
}cj188_send_frame_str;
typedef cj188_send_frame_str* cj188_send_frame_ptr;


#define ELSONIC_READ_VALUE	0xA0//亿林家阀控协议读取数据
#define ELSONIC_READ_VOPEN	0xA3//读取温控器的阀开时间
#define ELSONIC_OPER_VALVE	0xA9//操作亿林阀门命令
#define ELSONIC_CLOSE_VALVE	0x80//强制关闭亿林阀门
#define ELSONIC_OPEN_VALVE	0x40//强制开启亿林阀门

#define	ELSONIC_FLAG_OPEN	0x01//面板开机
#define	ELSONIC_FLAG_LOAD_OPEN	0x02//负载(阀门)强制开启
#define	ELSONIC_FLAG_PANEL_LOCK	0x04//面板锁定
#define ELSONIC_CHK_CODE		0xA5//亿林家校验和的异或码
typedef struct {//读写亿林家阀控协议
	U8	cmd;	//读写命令
	U16	addr;	//阀控地址
	U8	func;	//功能码, 开关机, 锁定面板等操作
	U8	supTemp;//补偿温度
	U8	setTemp;//手动设定温度
	U8	rsv;	//保留
	U8	cs;		//校验
} vElsonic_send_frame_str;
typedef vElsonic_send_frame_str* vElsonic_send_frame_ptr;

typedef struct {//亿林家阀控返回帧结构
	U8	aswcode;//应答码, 固定0x50
	U16	addr;	//阀控地址
	U8	func;	//功能码, 开关机, 锁定面板等状态
	U8	supTemp;//补偿温度
	U8	setTemp;//手动设定温度
	U8	rsv;	//保留
	U8	loadSt;	//负载状态
	U8	roomTemp;//房间温度
	U8	inTemp;	//进水温度
	U8	outTemp;//回水温度
	U8	cs;		//校验
}vElsonic_asw_frame_str;
typedef vElsonic_asw_frame_str* vElsonic_asw_frame_ptr;

typedef struct {//亿林家阀控, 返回阀门状态的帧结构
	U8	aswcode;	//应答码, 固定0x50
	U16	addr;		//阀控地址
	U8	openMin;	//阀开时间, 分钟位(HEX)
	U8	openHour[3];//阀开时间小时, 小端(BCD)
	U8	energy[4];	//用热, 小端(BCD)
	U8	cs;			//校验
}vElsonic_vopen_frame_str;
typedef vElsonic_vopen_frame_str* vElsonic_vopen_frame_ptr;

typedef struct {
	U8	dOpen	: 1;//开关机, 0 -> 关机, 1->开机
	U8	fOpen	: 1;//强制开启负载标志, 1->负载强制开启, 0->负载正常工作
	U8	cLock	: 1;//锁定面板, 0->解锁, 1->锁定
	U8	eDisp	: 1;//用热显示, 1：启用, 0：禁止
	U8	tDiff1	: 1;//启动温差(1℃~5℃)
	U8	tDiff2 : 1;//启动温差(1℃~5℃)
	U8	tDiff3 : 1;//启动温差(1℃~5℃)
	U8	fClose	: 1;//强制关闭负载标志, 1->负载强制关闭, 0->负载正常工作
}vElsonic_state;

#pragma pack(pop)



typedef enum
{
	em_bus_rs485 = 0,
	em_bus_mbus
} em_busType_idx;




extern U8 protoR_radioMAddr(U8* buf, U16* bufSize, meter_frame_info_ptr pSendFrame);
extern U8 protoA_meterAddr(U8* buf, U16 bufSize, meter_frame_info_ptr pFrameInfo, flow_coe_ptr pFlowErr);
extern U8 protoW_ModifyCoe(U8* buf, U16* bufSize, U8* meterAddr, meter_frame_info_ptr pSendFrame, flow_coe_ptr pFlowCoe);
extern U8 vprotoR_readValue(U8* buf, U16* bufSize, U8* valveAddr);
extern U8 vprotoA_readValue(U8* buf, U16 bufSize, vElsonic_asw_frame_ptr pElRetFrame);
extern U8 vprotoR_readOpenTime(U8* buf, U16* bufSize, U8* valveAddr);
extern U8 vprotoA_readOpenTime(U8* buf, U16 bufSize, vElsonic_vopen_frame_ptr pElRetFrame);
extern U8 vprotoX_operValue(U8* buf, U16* bufSize, U8* valveAddr, U8 openClose);
extern U8 vprotoA_operValue(U8* buf, U16 bufSize, U8 openClose);
#endif
