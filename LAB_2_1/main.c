void delay(int del);

int main(void){ 
    
//the BEGIN of address – GPIOc is 0x4001 1000- the END of address  0x4001 13FF ;
//the BEGIN of address – GPIOb is 0x4001 0C00- the END of address  0x4001 0FFF ;
//the BEGIN of address – GPIOa is 0x4001 0800- the END of address  0x4001 0BFF .

  // 0. Pointers init. NO OS!!!
        //The BEGIN of address  GPIOc is 0x40011000
	//Address offset: 0x00 for (GPIO_C_CRL)
        int *GPIO_A_CRL=(int*)(0x40010800);
        //Address offset for CRH: 0x04 (GPIO_C_CRH)
        int *GPIO_B_CRH = (int*)(0x40010C04);
        //Port output data register (GPIOx_ODR) (x=A..G)
        //Address offset for ODR: 0x0C
        //Bits 31:16 Reserved // Bits 13-15 actual for  ODRy
        int *GPIO_A_ODR = (int*)(0x4001080C);
	int *GPIO_B_ODR = (int*)(0x40010C0C);
        
				//APB2ENR register for clock selection
        int *apb2enr = (int*)0x40021018;
        //delay counter variable
  // I. Enable PORTB and PORTA Clock
        *apb2enr|=0x000C;     // Init fast bus 1100 for A and B
  // II. Enable  GPIO_Pin_5 for output push-pool Mode
	*GPIO_A_CRL=0x00300000;//Set all PC5 ports as output
	*GPIO_B_CRH=0x00300000;
	
        for(;;){
		delay(10);
                *GPIO_A_ODR=0x00000020; //A5 10 0000
		*GPIO_B_ODR=0x00001000; //B12 1 000 000 000
		delay(2);
		*GPIO_B_ODR=0x00000000;
		delay(3);
		*GPIO_A_ODR=0x00001000;
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
