void delay1(void);
void delay2(void);
void delay3(void);

int main(void){ 
    
//the BEGIN of address – GPIOc is 0x4001 1000- the END of address  0x4001 13FF ;
//the BEGIN of address – GPIOb is 0x4001 0C00- the END of address  0x4001 0FFF ;
//the BEGIN of address – GPIOa is 0x4001 0800- the END of address  0x4001 0BFF .

  // 0. Pointers init. NO OS!!!
        //The BEGIN of address  GPIOc is 0x40011000
	//Address offset: 0x00 for (GPIO_C_CRL)
        int *GPIO_A_CRL=(int*)(0x40010800);
        //Address offset for CRH: 0x04 (GPIO_C_CRH)
        //int *GPIO_C_CRH = (int*)(0x40011004);
        //Port output data register (GPIOx_ODR) (x=A..G)
        //Address offset for ODR: 0x0C
        //Bits 31:16 Reserved // Bits 13-15 actual for  ODRy
        int *GPIO_A_ODR = (int*)(0x4001080C);
        
				//APB2ENR register for clock selection
        int *apb2enr = (int*)0x40021018;
        //delay counter variable
   
				int i;
  // I. Enable PORTC Clock
        *apb2enr|=0x0004;     // Init fast bus 1100 for A
  // II. Enable  GPIO_Pin_5 for output push-pool Mode
				*GPIO_A_CRL=0x00300000;//Set all PC5 ports as output

        for(;;){
                delay3();
		
		//Three long signals
                *GPIO_A_ODR=0x00000020;// for A5         10 0000
		delay2(); //Long signal interval
                *GPIO_A_ODR=0x00000000;
		delay1(); //Interval between signals in one symbol
		*GPIO_A_ODR=0x00000020;// for A5         10 0000
		delay2();
		 *GPIO_A_ODR=0x00000000;
		delay1();
		*GPIO_A_ODR=0x00000020;// for A5         10 0000
		delay2();
		 *GPIO_A_ODR=0x00000000;
		delay1();
		
		delay3(); //Interval between symbols
		
		//One short two long signals
		 *GPIO_A_ODR=0x00000020;// for A5         10 0000
		delay1(); //Short signal interval
                *GPIO_A_ODR=0x00000000;
		delay1(); //Interval between signals in one symbol
		*GPIO_A_ODR=0x00000020;// for A5         10 0000
		delay2();
		 *GPIO_A_ODR=0x00000000;
		delay1();
		*GPIO_A_ODR=0x00000020;// for A5         10 0000
		delay2();
		 *GPIO_A_ODR=0x00000000;
		delay1();
      }
    }

void delay1(void)
{ 
	//1s delay
	int i;
    	for(i=0;i<0xD5555;i++);
}

void delay2(void)
{
	//2s delay
	 int i;
    	for(i=0;i<0x1AAAAA;i++);
}
void delay3(void)
{ 
	//4s delay
	int i;
    	for(i=0;i<0x355554;i++);
}
