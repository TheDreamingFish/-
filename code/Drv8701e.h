#ifndef _DRV8701E_H
#define _DRV8701E_H

#define PWM_FREQUENCE       17000                                   //pwm的频率设置
#define MAX_DUTY            (50 )                                   // 最大 MAX_DUTY% 占空比
#define DIR_R               (P02_4)
#define PWM_R               (ATOM0_CH5_P02_5)

#define DIR_L               (P02_6)
#define PWM_L               (ATOM0_CH7_P02_7)

#include "zf_common_headfile.h"
#include "Sys.h"

//typedef enum{
//    L_motor=0,
//    R_motor=1,
//}Motor;
extern int DRV_L_PWM;
extern int DRV_R_PWM;

void Drv_Set_PWM(void);
void Drv_init(void);
#endif
// *************************** 例程硬件连接说明 ***************************
// 使用 tc264 核心板直接接线进行测试
//      模块管脚            单片机管脚
//      1DIR                P02_4
//      1PWM                P02_5
//      GND                 GND
//      2DIR                P02_6
//      2PWM                P02_7
//      GND                 GND
//      接线端子 +          电池正极
//      接线端子 -          电池负极
