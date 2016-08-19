#ifndef INTERFACE_H
#define INTERFACE_H

#include "user.h"
#include "GUI.h"
#include "EDIT.h"
#include "base.h"

#define CL998_LCD_XLEN  240//创伦998手持机屏幕宽度, 参考"手持机光盘(新)\1、文档\C_产品宣传资料\三款产品参数.pdf"
#define CL998_LCD_YLEN  320//创伦998手持机屏幕高度, 参考"手持机光盘(新)\1、文档\C_产品宣传资料\三款产品参数.pdf"

#define ID_FRAMEWIN_0    (GUI_ID_USER + 0x00)//主界面
#define ID_FRAMEWIN_1    (GUI_ID_USER + 0x01)//热量表界面
#define ID_FRAMEWIN_2    (GUI_ID_USER + 0x02)//阀控界面
#define ID_FRAMEWIN_3    (GUI_ID_USER + 0x03)//配置界面
#define ID_FRAMEWIN_4    (GUI_ID_USER + 0x04)//
#define ID_FRAMEWIN_5    (GUI_ID_USER + 0x05)//
#define ID_FRAMEWIN_6    (GUI_ID_USER + 0x06)//
#define ID_FRAMEWIN_7    (GUI_ID_USER + 0x07)//

#define ID_BUTTON_0    (GUI_ID_USER + 0x10)
#define ID_BUTTON_1    (GUI_ID_USER + 0x11)
#define ID_BUTTON_2    (GUI_ID_USER + 0x12)
#define ID_BUTTON_3    (GUI_ID_USER + 0x13)
#define ID_BUTTON_4    (GUI_ID_USER + 0x14)
#define ID_BUTTON_5    (GUI_ID_USER + 0x15)

#define ID_EDIT_0		(GUI_ID_USER + 0x20)
#define ID_EDIT_1		(GUI_ID_USER + 0x21)
#define ID_EDIT_2		(GUI_ID_USER + 0x22)
#define ID_EDIT_3		(GUI_ID_USER + 0x23)
#define ID_EDIT_4		(GUI_ID_USER + 0x24)
#define ID_EDIT_5		(GUI_ID_USER + 0x25)

#define ID_DROPDOWN_0		(GUI_ID_USER + 0x30)
#define ID_DROPDOWN_1		(GUI_ID_USER + 0x31)
#define ID_DROPDOWN_2		(GUI_ID_USER + 0x32)
#define ID_DROPDOWN_3		(GUI_ID_USER + 0x33)
#define ID_DROPDOWN_4		(GUI_ID_USER + 0x34)
#define ID_DROPDOWN_5		(GUI_ID_USER + 0x35)
#define ID_DROPDOWN_6		(GUI_ID_USER + 0x36)

#define ID_TEXT_0		(GUI_ID_USER + 0x40)
#define ID_TEXT_1		(GUI_ID_USER + 0x41)
#define ID_TEXT_2		(GUI_ID_USER + 0x42)
#define ID_TEXT_3		(GUI_ID_USER + 0x43)
#define ID_TEXT_4		(GUI_ID_USER + 0x44)
#define ID_TEXT_5		(GUI_ID_USER + 0x45)
#define ID_TEXT_6		(GUI_ID_USER + 0x46)
#define ID_TEXT_7		(GUI_ID_USER + 0x47)
#define ID_TEXT_8		(GUI_ID_USER + 0x48)

#define ID_MULTILINE_0		(GUI_ID_USER + 0x50)
#define ID_MULTILINE_1		(GUI_ID_USER + 0x51)
#define ID_MULTILINE_2		(GUI_ID_USER + 0x52)
#define ID_MULTILINE_3		(GUI_ID_USER + 0x53)
#define ID_MULTILINE_4		(GUI_ID_USER + 0x54)
#define ID_MULTILINE_5		(GUI_ID_USER + 0x55)

#define ID_LISTVIEW_0		(GUI_ID_USER + 0x60)
#define ID_LISTVIEW_1		(GUI_ID_USER + 0x61)
#define ID_LISTVIEW_2		(GUI_ID_USER + 0x62)
#define ID_LISTVIEW_3		(GUI_ID_USER + 0x63)
#define ID_LISTVIEW_4		(GUI_ID_USER + 0x64)
#define ID_LISTVIEW_5		(GUI_ID_USER + 0x65)

#define ID_CHECKBOX_0		(GUI_ID_USER + 0x70)
#define ID_MULTIPAGE_0		(GUI_ID_USER + 0x80)




extern void comHelper(void);
#endif
