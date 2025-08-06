/**
 * @file drv_uasrt.h
 * @author Chimipupu(https://github.com/Chimipupu)
 * @brief  CH32V203 USARTドライバ＆ラッパー＆API
 * @version 0.1
 * @date 2025-08-06
 * 
 * @copyright Copyright (c) 2025 Chimipupu All Rights Reserved.
 * 
 */

#ifndef DRV_UASRT_H
#define DRV_UASRT_H

#include <stdint.h>
#include "stdbool.h"
#include "stdio.h"
#include "ch32v20x.h"

uint8_t hw_usart_get_byte(void);
void hw_usart_init(void);

#endif // DRV_UASRT_H
