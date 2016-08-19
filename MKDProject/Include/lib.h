#ifndef _LIB_H
#define _LIB_H

int WirelessGetStatus(void);
int WirelessWriteOnly(S8 *string);
int WirelessWriteRead(S8 *string);
void *WirelessReadBack(int timeout);
void WirelessInitTask(void);
void WirelessTaskSuspend(void);
void WirelessTaskResume(void);
void WirelessSetParam(int clinetID,int channel,int airrate);
void WirelessGetParam(int *clinetID,int *channel,int *airrate);
#endif
