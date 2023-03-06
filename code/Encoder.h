#ifndef _ENCODER_H
#define _ENCODER_H

#include "zf_common_headfile.h"
#include "Sys.h"

#define ENCODER_1                   (TIM5_ENCOEDER)
#define ENCODER_1_A                 (TIM5_ENCOEDER_CH1_P10_3)
#define ENCODER_1_B                 (TIM5_ENCOEDER_CH2_P10_1)

#define ENCODER_2                   (TIM6_ENCOEDER)
#define ENCODER_2_A                 (TIM6_ENCOEDER_CH1_P20_3)
#define ENCODER_2_B                 (TIM6_ENCOEDER_CH2_P20_0)


extern int encoder_data_1;
extern int encoder_data_2;

void Encoder_Init(void);


// ʹ�� USB-TTL ģ������
//      ģ��ܽ�            ��Ƭ���ܽ�
//      USB-TTL-RX          �鿴 zf_common_debug.h �ļ��� DEBUG_UART_TX_PIN �궨������� Ĭ�� P14_0
//      USB-TTL-TX          �鿴 zf_common_debug.h �ļ��� DEBUG_UART_RX_PIN �궨������� Ĭ�� P14_1
//      USB-TTL-GND         ���İ��Դ�� GND
//      USB-TTL-3V3         ���İ� 3V3 ��Դ
// ������������������ 1
//      ģ��ܽ�            ��Ƭ���ܽ�
//      A                   ENCODER_1_A �궨������� Ĭ�� B4
//      B                   ENCODER_1_B �궨������� Ĭ�� B5
//      GND                 ���İ��Դ�� GND
//      3V3                 ���İ� 3V3 ��Դ
// ������������������ 2
//      ģ��ܽ�            ��Ƭ���ܽ�
//      A                   ENCODER_2_A �궨������� Ĭ�� B6
//      B                   ENCODER_2_B �궨������� Ĭ�� B7
//      GND                 ���İ��Դ�� GND
//      3V3                 ���İ� 3V3 ��Դ
#endif
