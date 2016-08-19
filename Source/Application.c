/***************************************************
**	模块功能:	主函数
**	模块名字:	application.c
**	作者：		宋宝善
****************************************************
*/

#include "limits.h"
#include "GUI.h"
#include "EDIT.h"
#include "user.h"
#include "db.h"
#include "interface.h"

int main(void) {
	db_readAllConfig();
	LcdClear();
	comHelper();
	return 0;
}
