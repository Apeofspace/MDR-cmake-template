#ifndef __DELAY_H
#define __DELAY_H
#include "MDR32Fx.h"
#include "stdbool.h"

volatile uint32_t msSinceStart;
bool SysTickInitialized;

#define GetMs() (msSinceStart)

void SysTick_Handler(void);
void init_SysTick();
uint8_t MDR_Delay(uint32_t ms);

#endif
