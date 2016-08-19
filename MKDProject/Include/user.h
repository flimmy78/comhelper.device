#ifndef _USER_H
#define _USER_H
/*
*********************************************************************************************************
*                                               INT DEFINES
*********************************************************************************************************
*/

#define  BSP_INT_ID_WWDG                                   0    /* Window WatchDog Interrupt                            */
#define  BSP_INT_ID_PVD                                    1    /* PVD through EXTI Line detection Interrupt            */
#define  BSP_INT_ID_TAMPER                                 2    /* Tamper Interrupt                                     */
#define  BSP_INT_ID_RTC                                    3    /* RTC global Interrupt                                 */
#define  BSP_INT_ID_FLASH                                  4    /* FLASH global Interrupt                               */
#define  BSP_INT_ID_RCC                                    5    /* RCC global Interrupt                                 */
#define  BSP_INT_ID_EXTI0                                  6    /* EXTI Line0 Interrupt                                 */
#define  BSP_INT_ID_EXTI1                                  7    /* EXTI Line1 Interrupt                                 */
#define  BSP_INT_ID_EXTI2                                  8    /* EXTI Line2 Interrupt                                 */
#define  BSP_INT_ID_EXTI3                                  9    /* EXTI Line3 Interrupt                                 */
#define  BSP_INT_ID_EXTI4                                 10    /* EXTI Line4 Interrupt                                 */
#define  BSP_INT_ID_DMA1_CH1                              11    /* DMA1 Channel 1 global Interrupt                      */
#define  BSP_INT_ID_DMA1_CH2                              12    /* DMA1 Channel 2 global Interrupt                      */
#define  BSP_INT_ID_DMA1_CH3                              13    /* DMA1 Channel 3 global Interrupt                      */
#define  BSP_INT_ID_DMA1_CH4                              14    /* DMA1 Channel 4 global Interrupt                      */
#define  BSP_INT_ID_DMA1_CH5                              15    /* DMA1 Channel 5 global Interrupt                      */
#define  BSP_INT_ID_DMA1_CH6                              16    /* DMA1 Channel 6 global Interrupt                      */
#define  BSP_INT_ID_DMA1_CH7                              17    /* DMA1 Channel 7 global Interrupt                      */
#define  BSP_INT_ID_ADC1_2                                18    /* ADC1 et ADC2 global Interrupt                        */
#define  BSP_INT_ID_USB_HP_CAN_TX                         19    /* USB High Priority or CAN TX Interrupts               */
#define  BSP_INT_ID_USB_LP_CAN_RX0                        20    /* USB Low Priority or CAN RX0 Interrupts               */
#define  BSP_INT_ID_CAN_RX1                               21    /* CAN RX1 Interrupt                                    */
#define  BSP_INT_ID_CAN_SCE                               22    /* CAN SCE Interrupt                                    */
#define  BSP_INT_ID_EXTI9_5                               23    /* External Line[9:5] Interrupts                        */
#define  BSP_INT_ID_TIM1_BRK                              24    /* TIM1 Break Interrupt                                 */
#define  BSP_INT_ID_TIM1_UP                               25    /* TIM1 Update Interrupt                                */
#define  BSP_INT_ID_TIM1_TRG_COM                          26    /* TIM1 Trigger and Commutation Interrupt               */
#define  BSP_INT_ID_TIM1_CC                               27    /* TIM1 Capture Compare Interrupt                       */
#define  BSP_INT_ID_TIM2                                  28    /* TIM2 global Interrupt                                */
#define  BSP_INT_ID_TIM3                                  29    /* TIM3 global Interrupt                                */
#define  BSP_INT_ID_TIM4                                  30    /* TIM4 global Interrupt                                */
#define  BSP_INT_ID_I2C1_EV                               31    /* I2C1 Event Interrupt                                 */
#define  BSP_INT_ID_I2C1_ER                               32    /* I2C1 Error Interrupt                                 */
#define  BSP_INT_ID_I2C2_EV                               33    /* I2C2 Event Interrupt                                 */
#define  BSP_INT_ID_I2C2_ER                               34    /* I2C2 Error Interrupt                                 */
#define  BSP_INT_ID_SPI1                                  35    /* SPI1 global Interrupt                                */
#define  BSP_INT_ID_SPI2                                  36    /* SPI2 global Interrupt                                */
#define  BSP_INT_ID_USART1                                37    /* USART1 global Interrupt                              */
#define  BSP_INT_ID_USART2                                38    /* USART2 global Interrupt                              */
#define  BSP_INT_ID_USART3                                39    /* USART3 global Interrupt                              */
#define  BSP_INT_ID_EXTI15_10                             40    /* External Line[15:10] Interrupts                      */
#define  BSP_INT_ID_RTCAlarm                              41    /* RTC Alarm through EXTI Line Interrupt                */
#define  BSP_INT_ID_USBWakeUp                             42    /* USB WakeUp from suspend through EXTI Line Interrupt  */
#define  BSP_INT_ID_TIM8_BRK                              43    /* TIM8 Break Interrupt                                 */
#define  BSP_INT_ID_TIM8_UP                               44    /* TIM8 Update Interrupt                                */
#define  BSP_INT_ID_TIM8_TRG_COM                          45    /* TIM8 Trigger and Commutation Interrupt               */
#define  BSP_INT_ID_TIM8_CC                               46    /* TIM8 Capture Compare Interrupt                       */
#define  BSP_INT_ID_ADC3                                  47    /* ADC3 global Interrupt                                */
#define  BSP_INT_ID_FSMC                                  48    /* FSMC global Interrupt                                */
#define  BSP_INT_ID_SDIO                                  49    /* SDIO global Interrupt                                */
#define  BSP_INT_ID_TIM5                                  50    /* TIM5 global Interrupt                                */
#define  BSP_INT_ID_SPI3                                  51    /* SPI3 global Interrupt                                */
#define  BSP_INT_ID_UART4                                 52    /* UART4 global Interrupt                               */
#define  BSP_INT_ID_UART5                                 53    /* UART5 global Interrupt                               */
#define  BSP_INT_ID_TIM6                                  54    /* TIM6 global Interrupt                                */
#define  BSP_INT_ID_TIM7                                  55    /* TIM7 global Interrupt                                */
#define  BSP_INT_ID_DMA2_CH1                              56    /* DMA2 Channel 1 global Interrupt                      */
#define  BSP_INT_ID_DMA2_CH2                              57    /* DMA2 Channel 2 global Interrupt                      */
#define  BSP_INT_ID_DMA2_CH3                              58    /* DMA2 Channel 3 global Interrupt                      */
#define  BSP_INT_ID_DMA2_CH4_5                            59    /* DMA2 Channel 4 and DMA2 Channel 5 global Interrupt   */

//数据类型定义

#define I8    signed char
#define U8  unsigned char     	/* unsigned 8  bits. */
#define I16   signed short    	/*   signed 16 bits. */
#define U16 unsigned short    	/* unsigned 16 bits. */
#define I32   signed long   	/*   signed 32 bits. */
#define U32 unsigned long   	/* unsigned 32 bits. */
#define I16P I16              	/*   signed 16 bits OR MORE ! */
#define U16P U16              	/* unsigned 16 bits OR MORE ! */

#define S8    char
#define S16   signed short    	/*   signed 16 bits. */
#define S32   signed long   	/*   signed 32 bits. */

#define SWAP16(x) x=((x>>8)&0xff)+((x&0xff)<<8)

#define SWAP32(x) x=((x>>24)&0xff)+((x>>8)&0xff00)+((x&0xff)<<24)+((x&0xff00)<<8)

#define SWAP64(x) x=((x>>56)&0xff)+((x>>40)&0xff00)+((x>>24)&0xff0000)+((x>>8)&0xff000000)\
					+((x&0xff)<<56)+((x&0xff00)<<40)+((x&0xff0000)<<24)+((x&0xff000000)<<8)

#ifndef NULL
#define NULL		((void *)0)
#endif

#define KEY_NUM0  	0x30
#define KEY_NUM1  	0x31
#define KEY_NUM2  	0x32
#define KEY_NUM3  	0x33
#define KEY_NUM4  	0x34
#define KEY_NUM5  	0x35
#define KEY_NUM6  	0x36
#define KEY_NUM7  	0x37
#define KEY_NUM8 	0x38
#define KEY_NUM9  	0x39
#define KEY_DOT  	0x2E
#define KEY_SWITCH  	0x2D
#define KEY_LAMP  	0x15
#define KEY_SCAN  	0x16
#define KEY_ENTER  	0x0D
#define KEY_ESC  	0x1B
#define KEY_UP  	0x11
#define KEY_DOWN  	0x12
#define KEY_LEFT  	0x13
#define KEY_RIGHT  	0x14
#define KEY_DELETE  	0x08//0x10
#define KEY_FUN  	0x0A
#define KEY_SIDE_R 	0x1c
#define KEY_SIDE_L  	0x1d
#define KEY_FUN1	0x1E
#define KEY_FUN2    	0x1F

#define INPUT_UNLOCKED 			0
#define INPUT_LOCKED 			1

#define INPUT_TYPE_NUMBER		0
#define INPUT_TYPE_CHINESEPY		1
#define INPUT_TYPE_CHINESEBH		2
#define INPUT_TYPE_MIX 			3
#define INPUT_TYPE_CAPTITAL		4
#define INPUT_TYPE_LOWERCASE		5

#define ICON_RUN_SPECIFY 		0
#define ICON_RUN_SELETE  		1
#define ICON_SHOW_INFO			2
#define ICON_COM_MANAGE			3
#define ICON_FILE_MANAGE		4
#define ICON_SYS_SETTING		5
#define ICON_CALENDAR			6
#define ICON_CALCULATE			7
#define ICON_HELP			8
#define ICON_USB			9
#define ICON_USART			10
#define ICON_BULETOOTH			11
#define ICON_HIGHT_IRDA			12
#define ICON_LOW_IRDA			13
#define ICON_WIRELESS			14
#define ICON_PASSWORD			15
#define ICON_ALARM			16
#define ICON_CONTRAST			17
#define ICON_TIME			18
#define ICON_USER_INFO			19
#define ICON_DISPLAY_MODE		20
#define ICON_SHUTDOWN			21
#define ICON_EXE_FILE			22
#define ICON_DBF_FILE			23
#define ICON_TXT_FILE			24
#define ICON_WAV_FILE			25
#define ICON_OTHER_FILE			26
#define ICON_ALL_FILE			27
#define ICON_CHECK_FILE			28
#define ICON_RECIRLCE_FILE		29
#define ICON_ENTERPRISE			30
#define ICON_USER_NAME			31
#define ICON_USER_INDEX			32
#define ICON_MACH_INDEX			33
#define ICON_REMARKS			34
#define ICON_LAMP			35
#define ICON_ASSISTTANT			36
#define ICON_READER			37
#define ICON_SIGH			38
#define ICON_RIGHT			39
#define ICON_ERROR			40
#define ICON_FIND			41
#define ICON_BELL			42
#define ICON_BARCODE			43


#define FILE_NAME_LENGTH  		32
#define SEEK_SET			0		/*文件定位标志:从文件头*/
#define SEEK_CUR			1		/*文件定位标志:从当前位置*/
#define SEEK_END			2		/*文件定位标志:从文件尾*/
typedef struct {
	S8 FileName[FILE_NAME_LENGTH];
	U8 FileFlagRw;						//文件打开时的读写状态	
	U16 FirstBlockNo;					//与文件列表的对应关系
	U16 BlockNo;						//当前操作的文件块
	U32 FileSize;						//原始文件大小
	U8 *pData;							//当前的文件指针
}sFILE;	

#define MAX_FIELD_NUM				100
#define DBF_OPER_OK				0
#define DBF_INVALID_FORMAT			-1
#define DBF_FILE_FAILED				-2
#define DBF_NO_RECORD				-3
#define DBF_NO_FIELD				-4
#define DBF_NOTOPEN				-5
#define DBF_FILE_EXIST				-6
#define DBF_RECORD_EXCEED			-7
#define DBF_FILE_READ				-8

#define DBF_LOCATE_UP				1
#define DBF_LOCATE_DOWN				2

#define DBF_LOCATE_MATCH_PART			1
#define DBF_LOCATE_MATCH_ALL			2

#define DBF_RECORD_NORMAL			1
#define DBF_RECORD_DELETED			2

#define DBF_BISEARCH_MODE_STRING		1
#define DBF_BISEARCH_MODE_NUMBER		2

typedef struct 
{
	U8 cDbfVer;
	U8 cYear;
	U8 cMonth;
	U8 cDay;
	U32 iRecordCount;
	U16 iFirstRecordOffset;
	U16 iRecordLength;
	U8  szReserved1[16];
	U8  cDbfFlag;
	U8  cCodePage;
	U8  szReserved2[2];
}sDbfHead;

typedef struct 
{
	S8	szFieldName[11];
	U8	cFieldType;
	U32	iFieldOffset;
	U8	cFieldLength;
	U8	cDecimalNum;
	U8	szReserved[14];
}sField;

typedef struct {
	sFILE stDbfFile;
	sDbfHead stDbfHead;
	U32 iCurrentRecord;
	U16 iFieldNum;
	sField stDbfField[MAX_FIELD_NUM];
	U8 cSum;
}sDBF;

typedef struct {
	U8 year;
	U8 month;
	U8 day;
	U8 hour;
	U8 min;
	U8 sec;
}sRTC;

typedef struct {
 		U16 startx;			//mode=0,2有效
		U16 starty;			//mode=0,2有效
		U16 endx;			//mode=0时有效
		U16 endy;			//mode=0时有效
		S8 *hotkey;			//hotkey string...like "12345"
		U16 amount;			//total count
		U8 count;			//count display in one page，mode=1或2时有效
		U8 border;			//boder 当boder=1时，边界向外扩四个象素
		U16 current;			//which in choice
		U8 mode;			//0: fixed mode    1: center mode    2: expand mode
		U8 character;			//一行显示字符的个数 偶数，当mode=0时有效
		U8 style;			//字体类型,12,16,24
		}sMENU;


#define UART_DEVICE_IRDA_CLOSE 		1		//光敏高速红外
#define UART_DEVICE_IRDA_FAR		2		//载波低速远红外
#define UART_DEVICE_IRDA_NEAR 		3		//IRDA方式高速红外
#define UART_DEVICE_BARCODE		4		//一维/二维条码
#define UART_DEVICE_GPRS_2G		5 		//2G GPRS通信
#define UART_DEVICE_WCDMA_3G		6		//3G WCDMA通信
#define UART_DEVICE_RS485 		7		//RS485半双工通信
#define UART_DEVICE_RS232 		8		//RS232全双工通信
#define UART_DEVICE_COMM_24G 		9		//2.4G通信模块
#define UART_DEVICE_BLUETOOTH		10		//蓝牙通信模块
#define UART_DEVICE_WIFI		11		//WIFI通信模块
#define UART_DEVICE_RFID_LOW		12		//125K/134.2K低频采集模块
#define UART_DEVICE_RFID_HIGH		13		//13.56M高频采集模块
#define UART_DEVICE_RFID_UHIGH		14		//920M超高频采集模块
#define UART_DEVICE_VOICE		15		//语音模块
#define UART_DEVICE_CAMERA		16		//串口相机
#define UART_DEVICE_COMM_433M		17		//433M通信模块
#define UART_DEVICE_RFID_24G		18		//2.4G微波有源标签
#define UART_DEVICE_ZIGBEE		19		//zigbee通信模块
#define UART_DEVICE_GPS			20		//GPS定位模块
#define UART_DEVICE_MBUS		21		//MBUS采集模块
#define UART_DEVICE_VIRTUAL 		22		//虚拟串口
#define UART_DEVICE_COM1		23		//串口1
#define UART_DEVICE_COM2		24		//串口2
#define UART_DEVICE_COM3		25		//串口3
#define UART_DEVICE_COM4		26		//串口4
#define UART_DEVICE_COM5		27		//串口5
#define UART_DEVICE_COM6		28		//串口6
#define UART_DEVICE_COUNT		28		//设备总数


#define DEVICE_MODE_COMMAND 		0		//命令模式
#define DEVICE_MODE_DATA 		1		//数据模式
#define DEVICE_MODE_STATE1		2		//状态模式
#define DEVICE_MODE_STATE2		3		//状态模式

#define UART_MODE_7B_ODD_1S		1
#define UART_MODE_7B_EVEN_1S		2
#define UART_MODE_8B_NONE_1S		3
#define UART_MODE_8B_ODD_1S		4
#define UART_MODE_8B_EVEN_1S		5
#define UART_MODE_9B_NONE_1S		6

typedef  struct {
	U8  device;
	U8  mode;
	U32 baud;
	U8  state;
	U8  port;
	void *pUsartx;
}sUART;
typedef  void (*pExFunction)(void);
void EmptyFuntion(void);
//数据库操作函数
S32 DbfRecordRead(U32 record, U8 *data, sDBF *dbf);
S32 DbfRecordWrite(U32 record, U8 *data, sDBF *dbf);
S32 DbfOpen(S8 *dbfname, sDBF *dbf);
S32 DbfClose(sDBF *dbf);
S32 DbfGotoRecord(U32 record, sDBF *dbf);
S32 DbfGetCurrentRecord(sDBF *dbf);
S32 DbfRecordSize(sDBF *dbf);
S32 DbfRecordAppend(sDBF *dbf);
S32 DbfRecordCount(sDBF *dbf);
S32 DbfRecordIsDeleted(sDBF *dbf);
S32 DbfRecordLocate(U16 field, S8 *pattern, U8 direction, U8 match, sDBF *dbf);
S32 DbfGetMatchCount(U16 field, S8 *pattern, U8 match, sDBF *dbf);
S32 DbfFieldSize(U16 field, sDBF *dbf);
S32 DbfFieldGet(U16 field, S8 *data, sDBF *dbf);
S32 DbfFieldSet(U16 field, S8 *data, sDBF *dbf);
S32 DbfFieldCount(sDBF *dbf);
S32 DbfFieldInfo(U16 field, sField *fieldinfo, sDBF *dbf);
S32 DbfRecordDelete(sDBF *dbf);
S32 DbfRecordRestore(sDBF *dbf);
S32 DbfRecordErase(sDBF *dbf);
S32 DbfCreate(S8 *dbfname,U32 fieldcount,S8* fieldname[],U8 *fieldsize);
S32 DbfCopy(S8 *DisDbfName,S8 *SrcDbfName);
S32 DbfFieldIndex( S8 *fieldname, sDBF *dbf);
S32 DbfRecordPack(sDBF *dbf);
S32 DbfRecordBiSearch(U16 field,char *pattern,U8 mode,sDBF*dbf);
//文件操作函数
U32 FileDelete(sFILE *fp);
U32 FileClose(sFILE *fp);
U32 FileRead(U8 * buf,U32 size,sFILE *fp);
U32 FileWrite(U8* pdata,U32 size,sFILE *fp);
U32 FileSeek(sFILE *fp, S32 offset, U32 origin);	
U32 FileLength(sFILE *fp);
U32 FileTell(sFILE *fp);
U32 FileGetType(S8 *type,S8 *filename[],U32 count,U32 index);
U32 FileChoiceRecycle(sFILE *fp,U32 choice);
U32 FileRemain(U32 filesize);
void 	FileGetCreateTime(sFILE *fp,sRTC* createtime);
sFILE * FileOpen(S8 *filename, S8 *mode);
sFILE * FileOpenExpand(S8 *filename, S8 *mode,sFILE *fp);


//输入法函数
U32 Input(U32 x,U32 y,S8 *buffer,U32 size);
U32 InputBh(U32 x,U32 y,S8 *buffer,U32 size);
U32 InputMix(U32 x,U32 y,S8 *buffer,U32 size);
U32 InputYw(U32 x,U32 y,S8 *buffer,U32 size);
U32 InputPy(U32 x,U32 y,S8 * buffer,U32 size);
U32 InputSz(U32 x,U32 y,S8 *buffer,U32 size);
U32 InputPassword(U32 x,U32 y,S8 *buffer,U32 size);
U32 InputSzn(U32 x,U32 y,S8 *buffer,U32 size);
U32 InputABC(U32 x,U32 y,S8 *buffer,U32 size);
U32 InputSetParam(U32 type,U32 locked,U32 font);



//键盘函数
U8 KeyScan(void);
U8 KeyValue(void);
U8 KeyWait(void);
U8 KeySleepWait(void);
U8 KeyTimeWait(U32 time);
void KeySendValue(int key);

//显示函数
void LcdClear(void);
void LcdSetDot(U32 startx,U32 starty,U32 colour);
void LcdSetArea(U32 startx,U32 starty,U32 endx,U32 endy,U32 colour);
void LcdSetColor(U32 color);
void LcdSaveArea(U32 startx,U32 starty,U32 endx,U32 endy,U8 *buffer,U32 zip);
void LcdRestoreArea(U32 startx,U32 starty,U32 endx,U32 endy,U8 *buffer,U32 zip);
void LcdDrawLine(U32 startx,U32 starty,U32 endx,U32 endy);
void LcdDrawRect(U32 startx,U32 starty,U32 endx,U32 endy);
void LcdDisplayIcon(U32 startx,U32 starty,U8* icon,U32 mode,U32 type);
void LcdPutChar(U32 data,U32 mode,U32 font);
void LcdPutNChar(S8 *pdata,U32 count,U32 mode,U32 font);
void LcdPutString(S8 *pdata,U32 mode,U32 font);
void LcdPrintf(U32 mode,U32 font,S8 *fmt,...);
void LcdMoveto(U32 startx,U32 starty);
void LcdSetCursor(U32 status,U32 width,U32 height,U32 blink);
void LcdDrawArcAngle(S32 startx, S32 starty, S32 stangle, S32 endangle,S32 radius,S32 mode);
void LcdDrawArcCenter(S32 centrex,S32 centrey,S32 startx,S32 starty,S32 endx,S32 endy,U32 mode);
void LcdSaveToBmp24Bit(S8* name);
void LcdShowBmp(U32 x,U32 y,U32 xsize,U32 ysize,const U8 *bmpdata);
void LcdSetBgColor(U32 color);
U8 *LcdGetIconAddr(U32 index,U32 type);
U32 LcdGetX(void);
U32 LcdGetY(void);
S32 RGB888ToRGB565(S32 dst);
U32 LcdGetColor(U32 startx,U32 starty);



//菜单函数
S32 MenuDisplay(sMENU *menuparam,S8 *menu[]);
S32 MenuTextMain(sMENU *menuparam,const S8 *menu[],sMENU *submenuparam,const S8 *submenu[],S8 * subamount);
S32 MenuDisplayCenter(S8* menu[],S8 *keys,U8 menu_count,U8 count,U8 border);
S32 MenuDisplayIcon(S8* menu[], U8* keys, S32 MenuCount);
S32 MenuGraphMain(const S8* menu[], const U8* iconindex, S32 MenuCount,const S8* subiconindex[],U8 * subcount);


//延时函数,该函数会阻塞进程，多任务时慎用
void DelayMicrosecond(U32 microsecond );
void DelayMillisecond(U32 millisecond);
void PowerManage(U32 powerbit,U8 state); 
 
 //串口函数
 
U32 UartDeviceInit(U32 mode,sUART * pdevice);
U32 UartClose(sUART * pdevice);
U32 UartRead(U8 *data,U32 size,U32 timeout,sUART * pdevice);
U32 UartWrite(U8 *data,U32 size,U32 timeout,sUART * pdevice);
U32 UartRxByte(U8 *data,U32 timeout,sUART *pdevice);
U32 UartTxByte(U8 data,U32 timeout,sUART *pdevice);
U32 UartRxString(S8 *string ,U32 size,U32 Ftimeout,U32 Btimeout,sUART * pdevice);
U32 UartTxString(S8 *string,U32 size,U32 Btimewait,U32 timeout,sUART *pdevice);
void 	UartPrintf(sUART *pdevice,S8 *fmt,...);
sUART * UartOpen(U32 baud,U32 mode,U32 device);

//变量函数
void * ParamRead(const S8* name);
void ParamDelete(const S8* name); 
void ParamEarse(void);
S32  ParamWrite(const S8* name,const void * pdata,U32 len);
void ParamSetWord(U32 index,S32 data);
S32  ParamGetWord(U32 index);

//时间函数
void RtcSetTime(U8 Hour,U8 Minute,U8 Seconds);
void RtcSetAlarm(U8 Hour,U8 Minute, U8 Seconds);
void RtcSetDate( U16 Year, U8 Month,U8 Day);
void RtcGetDate(U8 *year,U8 *month,U8 *day);
void RtcGetWeek(U8 *week);
void RtcGetTime(U8 *hour,U8 *minute,U8 *second);
void RtcGetDateString(S8* pd);
void RtcSetDateString(S8 *pd);
void RtcGetTimeString(S8* pt);
void RtcSetTimeString(S8* pt);
void RtcDisplayOn(U8 x,U8 y,U8 start,U8 end,S8 mode,U8 fonttype);
void RtcDisplayOff(void);


//C库函数
int 	 Lib_sprintf(char * s, const char * format, ...);
double   Lib_atof(const char * nptr);
int 	 Lib_atoi(const char * nptr);
long int Lib_atol(const char * nptr);
int   	 Lib_rand (void);
void  	 Lib_srand (int);
void    *Lib_malloc(unsigned int size);
void     Lib_free(void  *p);
void    *Lib_realloc(void  *p, unsigned int size);
void    *Lib_calloc(unsigned int size, unsigned int len);
int      Lib_puts(const char * s);
int      Lib_printf(const char * format, ...);
int 	 Lib_sscanf(char * s, const char * format, ...);
//调试函数
void BackLightLcd(S32 OnOff);
void BackLightLed(S32 OnOff);
void BackLightKey(S32 OnOff);
void Bell(U32 time,U32 tone);
void LedLeft(S32 onoff);
void LedMiddle(S32 onoff);
void AddSecuritykey(char *string);
void RemarkToFile(S8*filename,S8 * string);
U32 DetectVoltage(void);
S32 DetectTemperature(void);
int Ascii2Hex(S8 *O_data, U8 *N_data, int len);
int Hex2Ascii(U8 *O_data, S8 *N_data, int len);
int ApplyForPower(U32 powerbit,U8 state);
//USB通信
void UsbMain(void);
void UsbSendStringToPC(S8 *string);
void UsbSendKeyToPC(U8 key,U8 control);
void UsbSendAsciiToPC(S8 ascii);
void UsbConnectToPC(U32 type);
void UsbDisconnectToPC(void);
void VirtualComOpen(void);
void VirtualComClose(void);
U32 VirtualComWrite(U8 *data,U32 size,U32 timeout);
U32 VirtualComRead(U8 *data,U32 size,U32 timeout);
U32 VirtualComRxString(U8 * data,U32 size,U32 Ftimeout,U32 Btimeout);
U32 VirtualComTxString(U8 * data,U32 size,U32 Ftimeout,U32 Btimeout);
//电池容量
void BatBarDisplayON(S32 x,S32 y,S32 periods);
void BatBarDisplayOff(void);
void SetSecondIRQ(pExFunction Funtion);
void SetPowerOffFun(pExFunction Funtion);
void SetPowerOnFun(pExFunction Funtion);
void SetKeyFuntion(pExFunction Funtion,S32 Key);
//外部设备
U32 BarcodeGetID(S8 *Buffer,int Maxlen,int Timeout);
U32 GPSGetPostion (S8 *Buffer,int Maxlen,int Timeout);
U32 RFID11784GetID(S8 *Buffer,int Maxlen,int Timeout);
U32 RFID14443AGetID (S8 *Buffer,int Maxlen,int Timeout);
U32 RFID14443BGetID (S8 *Buffer,int Maxlen,int Timeout);
U32 RFID15693GetID (S8 *Buffer,int Maxlen,int Timeout);
U32 RFID180006GetID (S8 *Buffer,int Maxlen,int Timeout);


/////////////////////////////////////////////////////////////////////
//Mifare_One卡片命令字
/////////////////////////////////////////////////////////////////////
#define PICC_REQIDL           0x26               //寻天线区内未进入休眠状态
#define PICC_REQALL           0x52               //寻天线区内全部卡
#define PICC_ANTICOLL1        0x93               //防冲撞
#define PICC_ANTICOLL2        0x95               //防冲撞
#define PICC_AUTHENT1A        0x60               //验证A密钥
#define PICC_AUTHENT1B        0x61               //验证B密钥
#define PICC_READ             0x30               //读块
#define PICC_WRITE            0xA0               //写块
#define PICC_DECREMENT        0xC0               //扣款
#define PICC_INCREMENT        0xC1               //充值
#define PICC_RESTORE          0xC2               //调块数据到缓冲区
#define PICC_TRANSFER         0xB0               //保存缓冲区中数据
#define PICC_HALT             0x50               //休眠

void ISO14443AInit(void);
char ISO14443AReset(void);
char ISO14443ARequest(unsigned char req_code,unsigned char *pTagType);
void ISO14443AAntennaOn(void);
void ISO14443AAntennaOff(void);
char ISO14443AConfigISOType(void);
char ISO14443AAnticoll(unsigned char *pSnr);
char ISO14443ASelect(unsigned char *pSnr);
char ISO14443AAuthState(unsigned char auth_mode,unsigned char addr,unsigned char *pKey,unsigned char *pSnr);
char ISO14443AWrite(unsigned char addr,unsigned char *pData);
char ISO14443ARead(unsigned char addr,unsigned char *pData);
char ISO14443AHalt(void);
char ISO14443AValue(unsigned char dd_mode,unsigned char addr,unsigned char *pValue);
char ISO14443ABakValue(unsigned char sourceaddr, unsigned char goaladdr);
void ISO14443AInitIO(void);
void ISO14443AOpen(void);	
void ISO14443AClose(void);

int RFID14443AReadBlock(int blockno,U8 *psw,U8 *rdata);
int RFID14443AWriteBlock(int blockno,U8 *psw,U8 *wdata); 
int RFID14443AReadData(U8 *psw,U8 *rdata,int size);
int RFID14443AWriteData(U8 *psw,U8 *wdata,int size);


//缓冲区SQL函数

S32 SqlOpen(S8 *sql);
S8 *SqlGotoRecord(U32 record,S8 *sql);
S32 SqlRecordRead(U32 record,S8 *data,S8 *sql);
S32 SqlRecordCount(S8 *sql);
S32 SqlFieldCount(S8 *sql);
S32 SqlFieldInfo(U32 field,S8 *name,S8*sql);
S32 SqlFieldGet(U32 record,U32 field,S8 *data,S8 *sql);

//无线通信
int GprsInit(void); 
int GprsHttpGet(char *url,char *reply,int maxlen);
int GprsHttpPost(char *url,U8*data,int datalen,char *reply,int maxlen);
int GprsNetSignal(void);
int GprsSMSSend(char *phoneno,char *text);
int GprsTcpConnect(S8* nAddress,S8*nPort);
int GprsTcpTx(U8 *data,int len);
int GprsTcpRx(U8 * data,int len,int timeout);

//编码转换

int EncGetUtf8Size(unsigned char c); 
int EncUtf82UnicodeOne(const unsigned char* pInput, unsigned long *Unic);
int EncUtf82Unicode(const unsigned char* pInput, int nMembIn, unsigned long* pOutput, int* nMembOut); 
int EncUtf82UnicodeStr(const unsigned char *pInput, unsigned long *pOutput, int *nMembOut); 
int EncUnicode2Utf8One(unsigned long unic, unsigned char *pOutput, int outSize) ;  
int EncUnicode2Utf8(const unsigned long *pInput, int nMembIn, unsigned char *pOutput, int *nMembOut) ;  
int EncUnicode2Utf8Str(const unsigned long *pInput, unsigned char *pOutput, int *nMembOut) ; 
int EncUtf82GbkStr(const unsigned char *pInput, unsigned char *pOutput, int *nMembOut);
int EncUnicode2GbkStr(const unsigned char *pInput, unsigned char *pOutput, int *nMembOut);
unsigned short EncUnicode2GbkOne(	unsigned short	src	);
unsigned short EncGbk2UnicodeOne(	unsigned short	src	);


#include "FF.h"
#include "GUI.h"
#include "OS.h"
#include "stm32f10x_lib.h"
#include "usb_lib.h"
#include "Redefine.h"
#include "lib.h"
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#endif
