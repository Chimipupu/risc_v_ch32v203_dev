/**
 * @file main.c
 * @author Chimipupu(https://github.com/Chimipupu)
 * @brief  CH32V203 メイン
 * @version 0.1
 * @date 2025-08-06
 * 
 * @copyright Copyright (c) 2025 Chimipupu All Rights Reserved.
 * 
 */

#include "stdio.h"
#include "ch32v20x.h"

#include "debug.h"
#include "dbg_com.h"
#include "drv_uasrt.h"
#include "drv_tim.h"

int main(void)
{
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
    SystemCoreClockUpdate();
    Delay_Init();

    // [タイマー初期化]
    // クロック源 : 144MHz
    // タイマークロック : 144MHz / プリスケーラで144分周 = 1MHz = 1us
    // カウントアップ : 65535us = 65.535ms
    drv_tim_init(TIM_CKD_DIV1, 65535, 144);

    // USRAT初期化 115200 8N1(TX=PA9ピン, RX=PA10ピン)
    hw_usart_init();

    // printf("[DEBUG] CH32V203F8P6 Develop\r\n");

    // デバッグモニタ 初期化
    dbg_com_init();

    while(1)
    {
        // デバッグモニタ メイン
        dbg_com_main();
    }

    return 0;
}