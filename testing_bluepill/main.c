#include "RTE_Components.h"
#include CMSIS_device_header

void wait(){
	int d;
	for (d=0; d < 1500000; d++);
}



int main (){
	
	RCC->APB2ENR |= (1UL << 2);
	
	GPIOA->CRL  = 0x33333333;
	
	GPIOA->CRH  = 0x33333333;
	
	while(1){
		for (int i = 0; i < 8; i++){
			GPIOA->BSRR = 1UL << i;
			wait();
			GPIOA->BRR = 1UL << i;
		}

		for (int i = 7; i >= 0; i--){
			GPIOA->BSRR = 1UL << i;
			wait();
			GPIOA->BRR = 1UL << i;
		}
	}
	
}