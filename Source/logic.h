#ifndef LOGIC_H
#define LOGIC_H

#include "user.h"


extern U8 logic_saveConfig(U8 device, U32 baud, U8 mode);
extern U8 logic_crcChk(U8* sendbuf);
extern U8 logic_chkSum(U8* sendbuf);
extern U8 logic_sendBuf(U8* sendbuf);

#endif
