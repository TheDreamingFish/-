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


// 使用 USB-TTL 模块连接
//      模块管脚            单片机管脚
//      USB-TTL-RX          查看 zf_common_debug.h 文件中 DEBUG_UART_TX_PIN 宏定义的引脚 默认 P14_0
//      USB-TTL-TX          查看 zf_common_debug.h 文件中 DEBUG_UART_RX_PIN 宏定义的引脚 默认 P14_1
//      USB-TTL-GND         核心板电源地 GND
//      USB-TTL-3V3         核心板 3V3 电源
// 接入正交编码器连接 1
//      模块管脚            单片机管脚
//      A                   ENCODER_1_A 宏定义的引脚 默认 B4
//      B                   ENCODER_1_B 宏定义的引脚 默认 B5
//      GND                 核心板电源地 GND
//      3V3                 核心板 3V3 电源
// 接入正交编码器连接 2
//      模块管脚            单片机管脚
//      A                   ENCODER_2_A 宏定义的引脚 默认 B6
//      B                   ENCODER_2_B 宏定义的引脚 默认 B7
//      GND                 核心板电源地 GND
//      3V3                 核心板 3V3 电源
#endif
