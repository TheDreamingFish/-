#ifndef AD_CAPTURE_H
#define AD_CAPTURE_H

/* 控制voice_buff 与采集精度的长度 */
#define ADC_xBIT    ADC_12BIT
//#define ADC_xBIT    ADC_10BIT
//#define ADC_xBIT    ADC_8BIT

/* 设置采集一组样本的数量 */
#define Sample_point_MAX    500
/* 设置分组数量 */
#define Sample_point_list_MAX    8


#define CHANNEL_NUMBER          (8)

#define ADC_CHANNEL1            (ADC0_CH0_A0)
#define ADC_CHANNEL2            (ADC0_CH1_A1)
#define ADC_CHANNEL3            (ADC0_CH2_A2)
#define ADC_CHANNEL4            (ADC0_CH3_A3)

#define ADC_CHANNEL5            (ADC0_CH4_A4)
#define ADC_CHANNEL6            (ADC0_CH5_A5)
#define ADC_CHANNEL7            (ADC0_CH6_A6)
#define ADC_CHANNEL8            (ADC0_CH7_A7)

//extern uint16 AD_Sample_get_Flag;
//extern uint8 Voice_sample_buff_list[Sample_point_list_MAX][Sample_point_MAX];

//#if(ADC_xBIT==ADC_8BIT)
//    typedef uint8 Sample_buff;
//#else
//    typedef uint16 Sample_buff;
//#endif


void AD_Sample_get(void);
void AD_Init(int CH_count);     //选择麦克风数量
#endif

