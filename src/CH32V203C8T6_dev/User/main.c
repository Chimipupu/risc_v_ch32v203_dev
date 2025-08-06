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
#include "drv_uasrt.h"

int main(void)
{
    bool ret;
    uint8_t val;

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
    SystemCoreClockUpdate();
    Delay_Init();

    // USRAT初期化
    hw_usart_init();

    printf("SystemClk:%d\r\n", SystemCoreClock);
    printf( "ChipID:%08x\r\n", DBGMCU_GetCHIPID() );

    printf("[DEBUG] CH32V203C8T6 Develop\r\n");

    while(1)
    {
        ret = hw_usart_get_byte(&val);
        if(ret != false) {
            printf("[DEBUG] UASRT RX = %c\r\n", val);
        }
        // Delay_Ms(1000);
    }

    return 0;
}
