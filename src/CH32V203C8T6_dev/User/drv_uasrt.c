/**
 * @file drv_uasrt.c
 * @author Chimipupu(https://github.com/Chimipupu)
 * @brief  CH32V203 USARTドライバ＆ラッパー＆API
 * @version 0.1
 * @date 2025-08-06
 * 
 * @copyright Copyright (c) 2025 Chimipupu All Rights Reserved.
 * 
 */

#include "drv_uasrt.h"

static bool s_rx_flg = false;
void USART1_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));

/**
 * @brief USART 割り込みハンドラ
 * 
 */
void USART1_IRQHandler(void)
{
    USART_ClearITPendingBit(USART1, USART_IT_RXNE);
    s_rx_flg = true;
}

/**
 * @brief USART受信ラッパー
 * 
 * @return uint8_t 
 */
uint8_t hw_usart_get_byte(void)
{
    volatile uint8_t val = 0;
    volatile uint16_t tmp = 0;

    if (s_rx_flg != false) {
        tmp = USART_ReceiveData(USART1);
        val = (uint8_t)(tmp & 0x00FF);
        s_rx_flg = false;
    }

    return val;
}

void hw_usart_init(void)
{
    GPIO_InitTypeDef  gpio_pa9;
    GPIO_InitTypeDef  gpio_pa10;
    USART_InitTypeDef usart1;
    NVIC_InitTypeDef nvic;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1 | RCC_APB2Periph_GPIOA, ENABLE);

    // TXピン (PA9)
    gpio_pa9.GPIO_Pin = GPIO_Pin_9;
    gpio_pa9.GPIO_Speed = GPIO_Speed_50MHz;
    gpio_pa9.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOA, &gpio_pa9);

    // RXピン (PA10)
    gpio_pa10.GPIO_Pin = GPIO_Pin_10;
    gpio_pa10.GPIO_Speed = GPIO_Speed_50MHz;
    gpio_pa10.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOA, &gpio_pa10);

    // USART1を115200 8N1で初期化
    usart1.USART_BaudRate = 115200;
    usart1.USART_WordLength = USART_WordLength_8b;
    usart1.USART_StopBits = USART_StopBits_1;
    usart1.USART_Parity = USART_Parity_No;
    usart1.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    usart1.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
    USART_Init(USART1, &usart1);

    // USARTの受信割り込み(RXNE)を有効
    USART1->STATR = 0x00C0;
    USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
    nvic.NVIC_IRQChannel = USART1_IRQn;
    nvic.NVIC_IRQChannelPreemptionPriority = 1;
    nvic.NVIC_IRQChannelSubPriority = 1;
    nvic.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&nvic);
    USART_Cmd(USART1, ENABLE);
}