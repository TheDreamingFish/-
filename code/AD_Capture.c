#include "AD_Capture.h"
#include "Sys.h"

adc_channel_enum channel_list[CHANNEL_NUMBER] =
{
    ADC_CHANNEL1, ADC_CHANNEL2, ADC_CHANNEL3, ADC_CHANNEL4,
    ADC_CHANNEL5, ADC_CHANNEL6, ADC_CHANNEL7, ADC_CHANNEL8
};

uint8 Voice_sample_buff_list[Sample_point_list_MAX][Sample_point_MAX];    //���òɼ��б�
uint16 AD_Sample_get_Flag = 0;
//-------------------------------------------------------------------------------------------------------------------
// �������     ADC��ʼ��
// ����˵��     pit_indexΪADC���ĸ�ͨ��  ѡ�� ADC ͨ�� (��� zf_driver_adc.h ��ö�� adc_channel_enum ����)
// ����˵��     CH_countΪAD�İ˸�ͨ��
// ���ز���     void
// ʹ��ʾ��     AD_init(8);                                //AD������������AD_Capture.h�ж����趨
// ��ע��Ϣ
//-------------------------------------------------------------------------------------------------------------------
void AD_Init(int CH_count)
{
    for(;CH_count>0;)
    {
        adc_init(channel_list[CH_count-1],ADC_xBIT);
    }

//      adc_init(ADC_CHANNEL1, ADC_12BIT);                                          // ��ʼ����Ӧ ADC ͨ��Ϊ��Ӧ����
//      adc_init(ADC_CHANNEL2, ADC_12BIT);                                          // ��ʼ����Ӧ ADC ͨ��Ϊ��Ӧ����
//      adc_init(ADC_CHANNEL3, ADC_10BIT);                                          // ��ʼ����Ӧ ADC ͨ��Ϊ��Ӧ����
//      adc_init(ADC_CHANNEL4, ADC_8BIT);                                           // ��ʼ����Ӧ ADC ͨ��Ϊ��Ӧ����
//      adc_init(ADC_CHANNEL5, ADC_12BIT);                                          // ��ʼ����Ӧ ADC ͨ��Ϊ��Ӧ����
//      adc_init(ADC_CHANNEL6, ADC_10BIT);                                          // ��ʼ����Ӧ ADC ͨ��Ϊ��Ӧ����
//      adc_init(ADC_CHANNEL7, ADC_8BIT);                                           // ��ʼ����Ӧ ADC ͨ��Ϊ��Ӧ����
//      adc_init(ADC_CHANNEL8, ADC_8BIT);                                           // ��ʼ����Ӧ ADC ͨ��Ϊ��Ӧ����
}

void AD_Sample_get(void)
{
    static int i=0;
    int j=0;
    if((i<Sample_point_MAX)&&(AD_Sample_get_Flag==0))           //��FlagΪ0��buffûװ��
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

