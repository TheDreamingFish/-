#include "Drv8701e.h"

int DRV_L_PWM = 0;
int DRV_R_PWM = 0;

void Drv_init(void)
{
    gpio_init(DIR_R, GPO, GPIO_HIGH, GPO_PUSH_PULL);                            // GPIO 初始化为输出 默认上拉输出高
    pwm_init(PWM_R, PWM_FREQUENCE, 0);                                                  // PWM 通道初始化频率 17KHz 占空比初始为 0

    gpio_init(DIR_L, GPO, GPIO_HIGH, GPO_PUSH_PULL);                            // GPIO 初始化为输出 默认上拉输出高
    pwm_init(PWM_L, PWM_FREQUENCE, 0);                                                  // PWM 通道初始化频率 17KHz 占空比初始为 0

}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     PWM的占空比
// 参数说明     Dir       L_motor/R_motor 0/1       选择电机
// 参数说明     duty            设置占空比（10000/10000）
// 返回参数     void
// 使用示例     Drv_control(L_motor,40)
// 备注信息     最大占空比是 PWM_DUTY_MAX 宏定义在zf_driver_pwm.h  默认为10000
//-------------------------------------------------------------------------------------------------------------------
void Drv_Set_PWM(void)
{
//    if(motor_select==L_motor)
//        pwm_set_duty(PWM_L, duty * (PWM_DUTY_MAX / 100));                   // 计算占空比
//    else
//       pwm_set_duty(PWM_R, duty * (PWM_DUTY_MAX / 100));                   // 计算占空比
       pwm_set_duty(PWM_L, DRV_L_PWM);                   // 计算占空比10000
       pwm_set_duty(PWM_R, DRV_R_PWM);                   // 计算占空比10000

}
