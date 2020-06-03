#include "stm32F10x.h"
#include <cmsis_os.h>
#include "STM32F10x_gpio.h"
#include "STM32F10x_rcc.h"

#define T1ON 300
#define T1ALL 1000
#define T1OFF (T1ALL - T1ON)
#define T2ON 600
#define T2ALL 1100
#define T2OFF (T2ALL - T2ON)


void delay(int ms);
void led_thread1(void const *argument);
void led_thread2(void const *argument);

osThreadId main_ID,led_ID1,led_ID2 ;	
osThreadDef(led_thread2, osPriorityNormal, 1, 0);
osThreadDef(led_thread1, osPriorityNormal, 1, 0);

int main(void) {
		GPIO_InitTypeDef LAB_6_GPIO_B;
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	
		GPIO_StructInit(&LAB_6_GPIO_B);
				LAB_6_GPIO_B.GPIO_Pin =
					GPIO_Pin_8 |
					GPIO_Pin_9;
				LAB_6_GPIO_B.GPIO_Mode = GPIO_Mode_Out_PP;
				LAB_6_GPIO_B.GPIO_Speed = GPIO_Speed_50MHz;
				GPIO_Init(GPIOB, &LAB_6_GPIO_B);
    osKernelInitialize();
    led_ID1 = osThreadCreate(osThread(led_thread1), NULL);
    led_ID2 = osThreadCreate(osThread(led_thread2), NULL);
    osKernelStart();
    while (1) {}
}
void delay(int ms) {
    for (int i = 0; i < 5000 * ms; i++) {
    }
}

void led_thread1(void const *argument) // Flash LED 1
{
    for (;;) {
        GPIO_SetBits(GPIOB, GPIO_Pin_8);
        delay(T1ON);
        GPIO_ResetBits(GPIOB, GPIO_Pin_8);
        delay(T1OFF);
    }
}

void led_thread2(void const *argument) // Flash LED 2
{
    for (;;) {
    	GPIO_SetBits(GPIOB, GPIO_Pin_9);
        delay(T2ON);
        GPIO_ResetBits(GPIOB, GPIO_Pin_9);
        delay(T2OFF);
    }
}
