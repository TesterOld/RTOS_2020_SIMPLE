#include "sysDelay.h"

int substep_num = 0;
int speed = 1000 ;
bool clockwise = 1;


//static __IO uint32_t TimingDelay;

//void sys_tick_ini(void){
//if (SysTick_Config(SystemCoreClock / 1000))
//            while (1);
//}
//void delay_from_Brown(uint32_t nTime){
//    TimingDelay = nTime;
//    while(TimingDelay != 0);
//}

//void SysTick_Handler(void){
//    if (TimingDelay != 0x00)
//        TimingDelay --;
//}
