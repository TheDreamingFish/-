#ifndef _CONTROL_H
#define _CONTROL_H

#include "zf_common_headfile.h"
#include "Sys.h"

//单电机控制策略
#define INDEPEND_MOTOR_CONTROL      //---串级PID,独立电机控制
#ifdef  INDEPEND_MOTOR_CONTROL
    //两电机的机械误差值
    extern int  Encoder_machine_error;

    extern int velocity_KP;
    extern int velocity_KI;
    extern int velocity_KD;
    extern float velocity_Low_pass_filter;

    extern int turn_up_KP;
    extern int turn_up_KD;
    extern float turn_up_Low_pass_filter;

//    extern int velocity_pwm_L;
//    extern int velocity_pwm_R;

    extern int turn_up_velocity;
    extern int velocity_target_L;
    extern int velocity_target_R;
    int velocity(int encoder_x,int encoder_target);
#else
    extern int velocity_KP;
    extern int velocity_KI;
    extern int velocity_KD;
    extern float velocity_Low_pass_filter;

    extern int turn_up_KP;
    extern int turn_up_KD;
    extern float turn_up_Low_pass_filter;

    extern int turn_up_velocity;
    extern int velocity_target;
    int velocity(int encoder_left,int encoder_right,int gyro_Z);
#endif

extern int DRV_L_PWM;
extern int DRV_R_PWM;
extern int Encoder_set;

void Con_PIT_IT_Init(void);
int turn_up(float angle_E_last);//偏角
void Con_set_PWM(void);



#endif
