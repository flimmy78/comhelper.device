/***************************************************
**	ģ�鹦��:	������
**	ģ������:	application.c
**	���ߣ�		�α���
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
