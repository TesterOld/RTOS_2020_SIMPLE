#include "stm32f10x.h"
#define T      10 //
#define TauB      2
#define TauA      2
// It is for B0 output blink 
/**
  * @brief  delay
  * @param  int delay is relativly delay 
  * @retval The input port pin value.
  */
void delay(int del);

int main(void){ 
      // I. Enable PORTB Clock    
	RCC -> APB2ENR |= RCC_APB2ENR_IOPBEN;
	RCC -> APB2ENR |= RCC_APB2ENR_IOPAEN;
			// II. Enable  all low port B for output push-pool Mode
	GPIOB -> CRH &= 0; 
	GPIOB -> CRH |= GPIO_CRH_MODE; 
	
	GPIOA -> CRL &= 0; 
	GPIOA -> CRL |= GPIO_CRL_MODE; 
	
	int w;
	w = TauA-TauB;
        for(;;){
		delay(T);
		GPIOB -> ODR |= GPIO_ODR_ODR12;// pin B12 on
		GPIOA -> ODR |= GPIO_ODR_ODR5;// pin A5 on
		
		delay(TauB);// this plase control
                GPIOB -> ODR &= ~(GPIO_ODR_ODR12);// pin B12 off
		delay(w);
		GPIOB -> ODR &= ~(GPIO_ODR_ODR5);// pin A5 off
              }
    }

void delay(int del)
{ 
	int i;
	int k;
	for(k=0; k<del; k++)
	{
	//1ms delay
    	for(i=0;i<0x156;i++);
	}
}


//#include "stm32f10x.h"
//void delay_(int i);

//int main(void){
//    unsigned const int period = 100000;
//      int tau = 0;
//    int sign = 1;
//      RCC -> APB2ENR |= RCC_APB2ENR_IOPBEN;
//      GPIOB -> CRL &= 0; 
//      GPIOB -> CRL |= GPIO_CRL_MODE;
//  
//        for(;;){
//               delay_(tau); 
//                GPIOB -> ODR |= GPIO_ODR_ODR0;
//              delay_(period - tau);// this plase control
//                GPIOB -> ODR &= ~(GPIO_ODR_ODR0);
//        tau += sign * 500;
//        if(tau >= period){
//          tau = period;
//          sign = -1;
//          }
//        else if (tau <= 0){
//          tau = 0;
//          sign = 1;
//         }
//              }
//    }

//void delay_(int del){
//  int i = 0;
//    for(i=0;i<del;i++){
//      ;
//      }
//}
