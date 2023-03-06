#include "Control.h"

int Encoder_set = 0;
#ifdef INDEPEND_MOTOR_CONTROL
//����PID���ƣ�С��ͨ���������Ļض����Ը��ݳ����������ٶȻ�еƫ���Ϊ������ֵ��ʵ��ת�٣���������޸������PWM�޸����ӿɿ������˸о���
//ͬʱ��Ҫ��ƫ������Ŀ���֮����Զ�����С��������Ҫ������������С����̬��
//���С����ƫ������Ŀ���֮������ɹ�����ٸ������ʡ�������ǣ��Լ����ٶ�Ҫ���ر�ߣ���
//--------------����ֵ-----------------------
    int velocity_KP = 0;
    int velocity_KI = 0;
    int velocity_KD = 0;
    float velocity_Low_pass_filter = 0.8;
    int turn_up_KP = 0;
    int turn_up_KD = 0;
    float turn_up_Low_pass_filter = 0.8;
    int  Encoder_machine_error = 0;
//-----------------------------------------
    int turn_up_velocity = 0;            //�����ٶȻ�����ֵ
//    int velocity_pwm_L = 0;
//    int velocity_pwm_R = 0;
    int velocity_target_L = 0;
    int velocity_target_R = 0;
#else
//����PID���ƣ�ת�򻷵����ֵ��ΪPWM�ķ�������Ҫ����һ��PWM����
//����PID�У�С����Ҫ�� ��ƫ������Ŀ���֮�������С��������Ҫ������������С����̬
//--------------����ֵ-----------------------
    int velocity_KP = 0;
    int velocity_KI = 0;
    int velocity_KD = 0;
    float velocity_Low_pass_filter = 0.8;
    int turn_up_KP = 0;
    int turn_up_KD = 0;
    float turn_up_Low_pass_filter = 0.8;
//-----------------------------------------
    int velocity_turn_up = 0;            //�����ٶȻ�����ֵ
//    int velocity_pwm = 0;               //�ٶȻ������PWM
    int turn_up_pwm = 0;
#endif

void Con_PIT_IT_Init(void)
{
    pit_ms_init(CCU60_CH0, 100);                     //ͨ��0  1MS�ж�   �˶�����
    pit_us_init(CCU60_CH1, 1);                      //ͨ��1  1US�ж�    �����ɼ�
}




//ȡ����ֵ
int myabs(int a)
{
      int temp;
        if(a<0)  temp=-a;
      else temp=a;
      return temp;
}

//-------------------------------------------------------------------------------------------------------------------
// �������     ͨ������ġ�PWM���Ƶ��ת��
// ����˵��     moto_L_pwm��moto_R_pwm��pwm��ֵ�����ٶȻ���ת�򻷺ͱ��ϻ���ӵ�
// ���ز���
// ʹ��ʾ��
// ��ע��Ϣ     DRV_X_PWM��Control.c�ж���  ����ȫ�ֵ�PWM����������ֵ��Drv8701e.c�е�Drv_Set_PWM()��������ʵ����
// ��ע��Ϣ     ��PIT�����е�isr.c����6��PIT�жϺ�����д��
// ��ע��Ϣ*    moto_X_pwm ����PIT�ж�����PID�����ֵ
//-------------------------------------------------------------------------------------------------------------------
void Con_set_PWM(void)
{
    if(DRV_L_PWM<0)       gpio_set_level(DIR_L, GPIO_HIGH);        //����
    else                gpio_set_level(DIR_L, GPIO_LOW);            //����
    DRV_L_PWM=myabs(DRV_L_PWM);                //��-��-PWMֵ

    if(DRV_R_PWM<0)       gpio_set_level(DIR_R, GPIO_HIGH);        //����
    else                gpio_set_level(DIR_R, GPIO_LOW);            //����
    DRV_R_PWM=myabs(DRV_R_PWM);                //��-��-PWMֵ
}


//-------------------------------------------------------------------------------------------------------------------
// �������     ���Ƶ���ٶ�Ŀ��ֵ
// ����˵��
// ����˵��
// ���ز���     PWM��ʵ��ռ�ձ�
// ʹ��ʾ��
// ��ע��Ϣ     encoder_left��encoder_right �� encoder_data_1��encoder_data_2��Encoder.c�ж���
// ��ע��Ϣ     ��PIT�����е�isr.c����6��PIT�жϺ�����д��
// ��ע��Ϣ*    encoder_data_x ��Ҫ����ʵ���������ȡ��
// ��ע��Ϣ     ��������� �� ˫�����������������
//-------------------------------------------------------------------------------------------------------------------
#ifdef INDEPEND_MOTOR_CONTROL
int velocity(int encoder_x,int encoder_target)
{
    static float Velocity_PWM,Encoder_Least,Encoder;
      static float Encoder_Integral,Encoder_Devided;
   //=============�ٶ�PID������=======================//
        Encoder_Least =(float)(encoder_target-encoder_x);//-target;                    //===��ȡ�����ٶ�ƫ��==�����ٶȣ���Ŀ���ٶ�-�����ٶ�=�ٶȲ�
        Encoder *= (1-velocity_Low_pass_filter);                                                     //===һ�׵�ͨ�˲���
        Encoder += Encoder_Least*(velocity_Low_pass_filter);                                       //===һ�׵�ͨ�˲���
        Encoder_Integral +=Encoder;                                       //===���ֳ�λ�� ����ʱ�䣺10ms     ����ʽ����
        Encoder_Devided =Encoder-Encoder_Devided;                       //===΢�ֳ����ٶ�

        if(Encoder_Integral>10000)      Encoder_Integral=10000;             //===�����޷�
        if(Encoder_Integral<-10000)     Encoder_Integral=-10000;            //===�����޷�
        Velocity_PWM=Encoder*velocity_KP+Encoder_Integral*velocity_KI+Encoder_Devided*velocity_KP;        //===�ٶȿ���
//      if(pitch<-40||pitch>40)           Encoder_Integral=0;                             //===����رպ��������
      return Velocity_PWM;
}

#else
int velocity(int encoder_left,int encoder_right,int encoder_target)
{
    static float Velocity_PWM,Encoder_Least,Encoder;
      static float Encoder_Integral,Encoder_Devided;
   //=============�ٶ�PID������=======================//
        Encoder_Least =(encoder_data_1+encoder_data_2)-encoder_target;//-target;                    //===��ȡ�����ٶ�ƫ��==�����ٶȣ����ұ�����֮�ͣ�-Ŀ���ٶ�
        Encoder *= (1-velocity_Low_pass_filter);                                                     //===һ�׵�ͨ�˲���
        Encoder += Encoder_Least*(velocity_Low_pass_filter);                                       //===һ�׵�ͨ�˲���
        Encoder_Integral +=Encoder;                                       //===���ֳ�λ�� ����ʱ�䣺10ms     ����ʽ����
        Encoder_Devided =Encoder-Encoder_Devided;                       //===΢�ֳ����ٶ�

        if(Encoder_Integral>10000)      Encoder_Integral=10000;             //===�����޷�
        if(Encoder_Integral<-10000)     Encoder_Integral=-10000;            //===�����޷�
        Velocity_PWM=Encoder*velocity_KP+Encoder_Integral*velocity_KI+Encoder_Devided*velocity_KP;        //===�ٶȿ���
//      if(pitch<-40||pitch>40)           Encoder_Integral=0;                             //===����رպ��������
      return Velocity_PWM;
}
#endif
//-------------------------------------------------------------------------------------------------------------------
// �������     ����ƫ�ǽӽ�0
// ����˵��     angle_E_last�ɹ���λ��ʽ��������
// ����˵��
// ���ز���     �ٶȻ�������ֵ(�������������PID)��pwm��������֮һ(�ϲ�������ƣ�����PID)
// ʹ��ʾ��
// ��ע��Ϣ
//-------------------------------------------------------------------------------------------------------------------
#ifdef  INDEPEND_MOTOR_CONTROL
int turn_up(float angle_E_last)//ƫ��
{
    static float angle_E_Devided,angle_E;
    static int turn_up_velocity;

    angle_E *= (1-turn_up_Low_pass_filter);
    angle_E += (turn_up_Low_pass_filter)*angle_E_last;            //===һ�׵�ͨ�˲�

    angle_E_Devided = angle_E-angle_E_Devided;
    turn_up_velocity = angle_E*turn_up_KP+angle_E_Devided*turn_up_KD;
    return (int)turn_up_velocity;
}

#else
int turn_up(float angle_E_last)//ƫ��
{
    static float angle_E_Devided,angle_E;
    static int turn_up_velocity;

    angle_E *= (1-turn_up_Low_pass_filter);
    angle_E += (turn_up_Low_pass_filter)*angle_E_last;            //===һ�׵�ͨ�˲�

    angle_E_Devided = angle_E-angle_E_Devided;
    turn_up_velocity = angle_E*turn_up_KP+angle_E_Devided*turn_up_KD;
    return (int)turn_up_velocity;
}

#endif
