#include "Encoder.h"

/*PITͨ����
    CCU60_CH0, <-
    CCU60_CH1,
    CCU61_CH0,
    CCU61_CH1,
*/
int encoder_data_1 = 0;
int encoder_data_2 = 0;

void Encoder_Init(void)
{
    encoder_dir_init(ENCODER_1, ENCODER_1_A, ENCODER_1_B);                      // ��ʼ��������ģ�������� ������������ģʽ
     encoder_dir_init(ENCODER_2, ENCODER_2_A, ENCODER_2_B);                      // ��ʼ��������ģ�������� ������������ģʽ
}

