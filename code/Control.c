#include "Control.h"

int Encoder_set = 0;
#ifdef INDEPEND_MOTOR_CONTROL
//串级PID控制，小车通过编码器的回读可以根据场地来调整速度机械偏差，因为编码器值是实际转速，所以这个修复相比于PWM修复更加可靠（个人感觉）
//同时需要“偏航角与目标角之差”来自动修正小车方向，需要陀螺仪来给定小车姿态，
//如果小车“偏航角与目标角之差”可以由硅麦快速给予则可省略陀螺仪（对计算速度要求特别高），
//--------------调试值-----------------------
    int velocity_KP = 0;
    int velocity_KI = 0;
    int velocity_KD = 0;
    float velocity_Low_pass_filter = 0.8;
    int turn_up_KP = 0;
    int turn_up_KD = 0;
    float turn_up_Low_pass_filter = 0.8;
    int  Encoder_machine_error = 0;
//-----------------------------------------
    int turn_up_velocity = 0;            //串级速度环输入值
//    int velocity_pwm_L = 0;
//    int velocity_pwm_R = 0;
    int velocity_target_L = 0;
    int velocity_target_R = 0;
#else
//并级PID控制，转向环的输出值作为PWM的分量，需要另外一套PWM控制
//并级PID中，小车主要靠 “偏航角与目标角之差”来修正小车方向，需要陀螺仪来给定小车姿态
//--------------调试值-----------------------
    int velocity_KP = 0;
    int velocity_KI = 0;
    int velocity_KD = 0;
    float velocity_Low_pass_filter = 0.8;
    int turn_up_KP = 0;
    int turn_up_KD = 0;
    float turn_up_Low_pass_filter = 0.8;
//-----------------------------------------
    int velocity_turn_up = 0;            //串级速度环输入值
//    int velocity_pwm = 0;               //速度环输出的PWM
    int turn_up_pwm = 0;
#endif

void Con_PIT_IT_Init(void)
{
    pit_ms_init(CCU60_CH0, 100);                     //通道0  1MS中断   运动控制
    pit_us_init(CCU60_CH1, 1);                      //通道1  1US中断    声音采集
}




//取绝对值
int myabs(int a)
{
      int temp;
        if(a<0)  temp=-a;
      else temp=a;
      return temp;
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     通过输入的±PWM控制电机转动
// 参数说明     moto_L_pwm，moto_R_pwm是pwm的值，由速度环和转向环和避障环相加得
// 返回参数
// 使用示例
// 备注信息     DRV_X_PWM在Control.c中定义  这是全局的PWM变量，他的值在Drv8701e.c中的Drv_Set_PWM()函数中落实更改
// 备注信息     在PIT例程中的isr.c中有6个PIT中断函数的写法
// 备注信息*    moto_X_pwm 是在PIT中断中用PID计算的值
//-------------------------------------------------------------------------------------------------------------------
void Con_set_PWM(void)
{
    if(DRV_L_PWM<0)       gpio_set_level(DIR_L, GPIO_HIGH);        //拉高
    else                gpio_set_level(DIR_L, GPIO_LOW);            //拉低
    DRV_L_PWM=myabs(DRV_L_PWM);                //改-左-PWM值

    if(DRV_R_PWM<0)       gpio_set_level(DIR_R, GPIO_HIGH);        //拉高
    else                gpio_set_level(DIR_R, GPIO_LOW);            //拉低
    DRV_R_PWM=myabs(DRV_R_PWM);                //改-右-PWM值
}


//-------------------------------------------------------------------------------------------------------------------
// 函数简介     控制电机速度目标值
// 参数说明
// 参数说明
// 返回参数     PWM的实际占空比
// 使用示例
// 备注信息     encoder_left和encoder_right 由 encoder_data_1和encoder_data_2在Encoder.c中定义
// 备注信息     在PIT例程中的isr.c中有6个PIT中断函数的写法
// 备注信息*    encoder_data_x 需要根据实际情况进行取反
// 备注信息     单电机控制 和 双电机控制是两个策略
//-------------------------------------------------------------------------------------------------------------------
#ifdef INDEPEND_MOTOR_CONTROL
int velocity(int encoder_x,int encoder_target)
{
    static float Velocity_PWM,Encoder_Least,Encoder;
      static float Encoder_Integral,Encoder_Devided;
   //=============速度PID控制器=======================//
        Encoder_Least =(float)(encoder_target-encoder_x);//-target;                    //===获取最新速度偏差==测量速度（）目标速度-测量速度=速度差
        Encoder *= (1-velocity_Low_pass_filter);                                                     //===一阶低通滤波器
        Encoder += Encoder_Least*(velocity_Low_pass_filter);                                       //===一阶低通滤波器
        Encoder_Integral +=Encoder;                                       //===积分出位移 积分时间：10ms     增量式积分
        Encoder_Devided =Encoder-Encoder_Devided;                       //===微分出加速度

        if(Encoder_Integral>10000)      Encoder_Integral=10000;             //===积分限幅
        if(Encoder_Integral<-10000)     Encoder_Integral=-10000;            //===积分限幅
        Velocity_PWM=Encoder*velocity_KP+Encoder_Integral*velocity_KI+Encoder_Devided*velocity_KP;        //===速度控制
//      if(pitch<-40||pitch>40)           Encoder_Integral=0;                             //===电机关闭后清除积分
      return Velocity_PWM;
}

#else
int velocity(int encoder_left,int encoder_right,int encoder_target)
{
    static float Velocity_PWM,Encoder_Least,Encoder;
      static float Encoder_Integral,Encoder_Devided;
   //=============速度PID控制器=======================//
        Encoder_Least =(encoder_data_1+encoder_data_2)-encoder_target;//-target;                    //===获取最新速度偏差==测量速度（左右编码器之和）-目标速度
        Encoder *= (1-velocity_Low_pass_filter);                                                     //===一阶低通滤波器
        Encoder += Encoder_Least*(velocity_Low_pass_filter);                                       //===一阶低通滤波器
        Encoder_Integral +=Encoder;                                       //===积分出位移 积分时间：10ms     增量式积分
        Encoder_Devided =Encoder-Encoder_Devided;                       //===微分出加速度

        if(Encoder_Integral>10000)      Encoder_Integral=10000;             //===积分限幅
        if(Encoder_Integral<-10000)     Encoder_Integral=-10000;            //===积分限幅
        Velocity_PWM=Encoder*velocity_KP+Encoder_Integral*velocity_KI+Encoder_Devided*velocity_KP;        //===速度控制
//      if(pitch<-40||pitch>40)           Encoder_Integral=0;                             //===电机关闭后清除积分
      return Velocity_PWM;
}
#endif
//-------------------------------------------------------------------------------------------------------------------
// 函数简介     修正偏角接近0
// 参数说明     angle_E_last由硅麦定位公式测量计算
// 参数说明
// 返回参数     速度环的输入值(独立电机，串级PID)，pwm的输入量之一(合并电机控制，并级PID)
// 使用示例
// 备注信息
//-------------------------------------------------------------------------------------------------------------------
#ifdef  INDEPEND_MOTOR_CONTROL
int turn_up(float angle_E_last)//偏角
{
    static float angle_E_Devided,angle_E;
    static int turn_up_velocity;

    angle_E *= (1-turn_up_Low_pass_filter);
    angle_E += (turn_up_Low_pass_filter)*angle_E_last;            //===一阶低通滤波

    angle_E_Devided = angle_E-angle_E_Devided;
    turn_up_velocity = angle_E*turn_up_KP+angle_E_Devided*turn_up_KD;
    return (int)turn_up_velocity;
}

#else
int turn_up(float angle_E_last)//偏角
{
    static float angle_E_Devided,angle_E;
    static int turn_up_velocity;

    angle_E *= (1-turn_up_Low_pass_filter);
    angle_E += (turn_up_Low_pass_filter)*angle_E_last;            //===一阶低通滤波

    angle_E_Devided = angle_E-angle_E_Devided;
    turn_up_velocity = angle_E*turn_up_KP+angle_E_Devided*turn_up_KD;
    return (int)turn_up_velocity;
}

#endif
