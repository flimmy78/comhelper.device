

#ifndef  __APP_CFG_H__
#define  __APP_CFG_H__

/*
*********************************************************************************************************
*                                       MODULE ENABLE / DISABLE
*********************************************************************************************************
*/

//#define  APP_OS_PROBE_EN                         DEF_ENABLED
//#define  APP_PROBE_COM_EN                        DEF_ENABLED

/*
*********************************************************************************************************
*                                              TASKS NAMES
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                            TASK PRIORITIES
*********************************************************************************************************
*/

#define  APP_TASK_START_PRIO                               3
#define  APP_TASK_KBD_PRIO                                 4

#define  APP_TASK_USER_IF_PRIO                            12

#define  OS_PROBE_TASK_PRIO              (OS_LOWEST_PRIO - 3)
#define  OS_TASK_TMR_PRIO                (OS_LOWEST_PRIO - 2)

/*
*********************************************************************************************************
*                                            TASK STACK SIZES
*                             Size of the task stacks (# of OS_STK entries)
*********************************************************************************************************
*/

#define  APP_TASK_START_STK_SIZE                         512
#define  APP_TASK_KBD_STK_SIZE                           128

#define  APP_TASK_USER_IF_STK_SIZE                       256

#define  OS_PROBE_TASK_STK_SIZE                          128

/*
*********************************************************************************************************
*                                                  LIB
*********************************************************************************************************
*/

#define  uC_CFG_OPTIMIZE_ASM_EN                 DEF_ENABLED
#define  LIB_STR_CFG_FP_EN                      DEF_DISABLED

/*
*********************************************************************************************************
*                                                 PROBE
*********************************************************************************************************
*/

#define  OS_PROBE_TASK                                     0   /* Task will be created for uC/Probe OS Plug-In.        */
#define  OS_PROBE_TMR_32_BITS                              0    /* uC/Probe OS Plugin timer is a 16-bit timer.          */
#define  OS_PROBE_TIMER_SEL                                2    /* Select timer 2.                                      */
#define  OS_PROBE_HOOKS_EN                                 0    /* Hooks to update OS_TCB profiling members included.   */
#define  OS_PROBE_USE_FP                                   0




#endif
