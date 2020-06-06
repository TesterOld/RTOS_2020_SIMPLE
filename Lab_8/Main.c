#include "stm32F10x.h"
#include <cmsis_os.h>
#include "STM32F10x_gpio.h"
#include "STM32F10x_rcc.h"

#define T1 100
#define T2 200
#define T3 300
#define T4 400
#define T5 500

void led_thread1(void const *argument);
void led_thread2(void const *argument);
void led_thread3(void const *argument);
void led_thread4(void const *argument);
void led_thread5(void const *argument);

osThreadId main_ID,led_ID1,led_ID2,led_ID3,led_ID4,led_ID5 ;	
osThreadDef(led_thread5, osPriorityHigh, 1, configMINIMAL_STACK_SIZE);
osThreadDef(led_thread4, osPriorityAboveNormal, 1, configMINIMAL_STACK_SIZE);
osThreadDef(led_thread3, osPriorityNormal, 1, configMINIMAL_STACK_SIZE);
osThreadDef(led_thread2, osPriorityBelowNormal, 1, configMINIMAL_STACK_SIZE);
osThreadDef(led_thread1, osPriorityLow, 1, configMINIMAL_STACK_SIZE);

int main(void) {
		GPIO_InitTypeDef LAB_8_GPIO_B;
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	
		GPIO_StructInit(&LAB_8_GPIO_B);
				LAB_8_GPIO_B.GPIO_Pin =
					GPIO_Pin_5 |
					GPIO_Pin_6 |
					GPIO_Pin_7 |
					GPIO_Pin_8 |
					GPIO_Pin_9;
				LAB_8_GPIO_B.GPIO_Mode = GPIO_Mode_Out_PP;
				LAB_8_GPIO_B.GPIO_Speed = GPIO_Speed_50MHz;
				GPIO_Init(GPIOB, &LAB_8_GPIO_B);
    osKernelInitialize();
    led_ID1 = osThreadCreate(osThread(led_thread1), NULL);
    led_ID2 = osThreadCreate(osThread(led_thread2), NULL);
		led_ID3 = osThreadCreate(osThread(led_thread3), NULL);
		led_ID4 = osThreadCreate(osThread(led_thread4), NULL);
		led_ID5 = osThreadCreate(osThread(led_thread5), NULL);
    osKernelStart();
    while (1) {}
}

void led_thread1(void const *argument) // Flash LED 1
{
		portTickType LWT1;
		LWT1 = xTaskGetTickCount();
    for (;;) {
        GPIO_SetBits(GPIOB, GPIO_Pin_5);
        vTaskDelayUntil( &LWT1, ( T1/portTICK_RATE_MS ) );
        GPIO_ResetBits(GPIOB, GPIO_Pin_5);
        vTaskDelayUntil( &LWT1, ( T1/portTICK_RATE_MS ) );
    }
}

void led_thread2(void const *argument) // Flash LED 2
{
		portTickType LWT2;
		LWT2 = xTaskGetTickCount();
    for (;;) {
    	GPIO_SetBits(GPIOB, GPIO_Pin_6);
        vTaskDelayUntil( &LWT2, ( T2/portTICK_RATE_MS ) );
        GPIO_ResetBits(GPIOB, GPIO_Pin_6);
        vTaskDelayUntil( &LWT2, ( T2/portTICK_RATE_MS ) );
    }
}

void led_thread3(void const *argument) // Flash LED 1
{
		portTickType LWT3;
		LWT3= xTaskGetTickCount();
    for (;;) {
        GPIO_SetBits(GPIOB, GPIO_Pin_7);
        vTaskDelayUntil( &LWT3, ( T3/portTICK_RATE_MS ) );
        GPIO_ResetBits(GPIOB, GPIO_Pin_7);
        vTaskDelayUntil( &LWT3, ( T3/portTICK_RATE_MS ) );
    }
}

void led_thread4(void const *argument) // Flash LED 1
{
		portTickType LWT4;
		LWT4 = xTaskGetTickCount();
    for (;;) {
        GPIO_SetBits(GPIOB, GPIO_Pin_8);
        vTaskDelayUntil( &LWT4, ( T4/portTICK_RATE_MS ) );
        GPIO_ResetBits(GPIOB, GPIO_Pin_8);
        vTaskDelayUntil( &LWT4, ( T4/portTICK_RATE_MS ) );
    }
}

void led_thread5(void const *argument) // Flash LED 1
{
		portTickType LWT5;
		LWT5 = xTaskGetTickCount();
    for (;;) {
        GPIO_SetBits(GPIOB, GPIO_Pin_9);
        vTaskDelayUntil( &LWT5, ( T5/portTICK_RATE_MS ) );
        GPIO_ResetBits(GPIOB, GPIO_Pin_9);
        vTaskDelayUntil( &LWT5, ( T5/portTICK_RATE_MS ) );
    }
}
