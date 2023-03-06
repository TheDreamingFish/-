#include "AD_Capture.h"
#include "Sys.h"

adc_channel_enum channel_list[CHANNEL_NUMBER] =
{
    ADC_CHANNEL1, ADC_CHANNEL2, ADC_CHANNEL3, ADC_CHANNEL4,
    ADC_CHANNEL5, ADC_CHANNEL6, ADC_CHANNEL7, ADC_CHANNEL8
};

uint8 Voice_sample_buff_list[Sample_point_list_MAX][Sample_point_MAX];    //设置采集列表
uint16 AD_Sample_get_Flag = 0;

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     ADC初始化
// 参数说明     pit_index为ADC的四个通道  选择 ADC 通道 (详见 zf_driver_adc.h 中枚举 adc_channel_enum 定义)
// 参数说明     CH_count为AD的八个通道
// 返回参数     void
// 使用示例     AD_init(8);                                //AD的其他设置在AD_Capture.h中定义设定
// 备注信息
//-------------------------------------------------------------------------------------------------------------------
void AD_Init(int CH_count)
{
    for(;CH_count>0;)
    {
        adc_init(channel_list[CH_count-1],ADC_xBIT);
    }

//      adc_init(ADC_CHANNEL1, ADC_12BIT);                                          // 初始化对应 ADC 通道为对应精度
//      adc_init(ADC_CHANNEL2, ADC_12BIT);                                          // 初始化对应 ADC 通道为对应精度
//      adc_init(ADC_CHANNEL3, ADC_10BIT);                                          // 初始化对应 ADC 通道为对应精度
//      adc_init(ADC_CHANNEL4, ADC_8BIT);                                           // 初始化对应 ADC 通道为对应精度
//      adc_init(ADC_CHANNEL5, ADC_12BIT);                                          // 初始化对应 ADC 通道为对应精度
//      adc_init(ADC_CHANNEL6, ADC_10BIT);                                          // 初始化对应 ADC 通道为对应精度
//      adc_init(ADC_CHANNEL7, ADC_8BIT);                                           // 初始化对应 ADC 通道为对应精度
//      adc_init(ADC_CHANNEL8, ADC_8BIT);                                           // 初始化对应 ADC 通道为对应精度
}

void AD_Sample_get(void)
{
    static int i=0;
    int j=0;
    if((i<Sample_point_MAX)&&(AD_Sample_get_Flag==0))           //当Flag为0且buff没装满
    {
        for(;j<Sample_point_list_MAX;j++)
        {
            Voice_sample_buff_list[j][i]=adc_convert(channel_list[j]);
        }
       i++;
    }
    else
    {
        i=0;
        AD_Sample_get_Flag=1;
    }

}

