#include <stm32f10x.h>
#include <stm32f10x_rcc.h>
#include <stm32f10x_gpio.h>
#include "misc.h"                       // Keil::Device:StdPeriph Drivers:Framework
#include "stm32f10x_tim.h"              // Keil::Device:StdPeriph Drivers:TIM
#include "GPIO_STM32F10x.h"             // Keil::Device:GPIO

#define	PIN_1A	GPIO_Pin_2
#define	PIN_1B	GPIO_Pin_3
#define PIN_2A	GPIO_Pin_4
#define PIN_2B	GPIO_Pin_5
#define MOTOR_PORT GPIOA
#define MOTOR_PORT_BUS RCC_APB2Periph_GPIOA

#define PRESCALER 8000 //1000 timer ticks per second
//one full step equals 1.8°, 360° = 200 steps
//our halfstep = 0.9°,  360° = 400 steps  
extern int substep_num;
//Maximum freq = 10 (100Hz)
extern int speed;//1000 ; //number of ticks before IRQ
extern bool clockwise;
//0x7 = 0b1001
//0x3 = 0b0011
//0x2 = 0b0010
//0x6 = 0b0110
//0x4 = 0b0100
//0x8 = 0b1000
