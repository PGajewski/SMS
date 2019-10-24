#include "delay.h"

void DelayTick(void){
	if(msc>0)
		--msc;
}

void Delay(unsigned int ms){
	msc=5000;
	while(msc);
}	

