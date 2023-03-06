#include "Drv8701e.h"

int DRV_L_PWM = 0;
int DRV_R_PWM = 0;

void Drv_init(void)
{
    gpio_init(DIR_R, GPO, GPIO_HIGH, GPO_PUSH_PULL);                            // GPIO ��ʼ��Ϊ��� Ĭ�����������
    pwm_init(PWM_R, PWM_FREQUENCE, 0);                                                  // PWM ͨ����ʼ��Ƶ�� 17KHz ռ�ձȳ�ʼΪ 0

    gpio_init(DIR_L, GPO, GPIO_HIGH, GPO_PUSH_PULL);                            // GPIO ��ʼ��Ϊ��� Ĭ�����������
    pwm_init(PWM_L, PWM_FREQUENCE, 0);                                                  // PWM ͨ����ʼ��Ƶ�� 17KHz ռ�ձȳ�ʼΪ 0

}

//-------------------------------------------------------------------------------------------------------------------
// �������     PWM��ռ�ձ�
// ����˵��     Dir       L_motor/R_motor 0/1       ѡ����
// ����˵��     duty            ����ռ�ձȣ�10000/10000��
// ���ز���     void
// ʹ��ʾ��     Drv_control(L_motor,40)
// ��ע��Ϣ     ���ռ�ձ��� PWM_DUTY_MAX �궨����zf_driver_pwm.h  Ĭ��Ϊ10000
//-------------------------------------------------------------------------------------------------------------------
void Drv_Set_PWM(void)
{
//    if(motor_select==L_motor)
//        pwm_set_duty(PWM_L, duty * (PWM_DUTY_MAX / 100));                   // ����ռ�ձ�
//    else
//       pwm_set_duty(PWM_R, duty * (PWM_DUTY_MAX / 100));                   // ����ռ�ձ�
       pwm_set_duty(PWM_L, DRV_L_PWM);                   // ����ռ�ձ�10000
       pwm_set_duty(PWM_R, DRV_R_PWM);                   // ����ռ�ձ�10000

}
