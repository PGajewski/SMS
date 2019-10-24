#include "stm32f10x.h"
#include "lcd_hd44780.h"
#include "main.h"
#include "delay.h"
#include "stdio.h"
#include <stdbool.h>   // true, false

bool RCC_Config(void);
void GPIO_Config(void);
void GPIO_SW0_Config(void); 
void GPIO_TIM4_Config(void); 
void ADC_Config(void);
void GPIO_KB_Config(void);
void NVIC_Config(void);
void refreshLCD(void);

char KB2char(void);

int main(void) {	
  RCC_Config();	      // konfiguracja RCC
  NVIC_Config();      // konfiguracja NVIC
  GPIO_Config();      // konfiguracja GPIO
  GPIO_TIM4_Config(); // konfiguracja TIM4
  GPIO_SW0_Config();  // konfiguracja SW0
  ADC_Config();       // konfiguracja ADC
  GPIO_KB_Config();   // konfiguracja KB
	
  LCD_Initialize();   // inicjalizacja LCD
	
	//SysTick_Config(TODO);
	//SysTick_CLKSourceConfig(TODO);
	//NVIC_SetPriority(SysTick_IRQn, TODO);
	
	while(1) {
		// TODO
	}
}

void refreshLCD(void){
	// TODO
}

bool RCC_Config(void) {
  ErrorStatus HSEStartUpStatus;                          // zmienna opisujaca rezultat 
																												 // uruchomienia HSE
  // konfigurowanie sygnalow taktujacych
  RCC_DeInit();                                          // reset ustawień RCC
  RCC_HSEConfig(RCC_HSE_ON);                             // wlacz HSE
  HSEStartUpStatus = RCC_WaitForHSEStartUp();            // czekaj na gotowosc HSE
  if(HSEStartUpStatus == SUCCESS) {
    FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);//
    FLASH_SetLatency(FLASH_Latency_2);                   // zwloka Flasha: 2 takty 
    
    RCC_HCLKConfig(RCC_SYSCLK_Div1);                     // HCLK=SYSCLK/1
    RCC_PCLK2Config(RCC_HCLK_Div1);                      // PCLK2=HCLK/1
    RCC_PCLK1Config(RCC_HCLK_Div2);                      // PCLK1=HCLK/2
    RCC_PLLConfig(RCC_PLLSource_HSE_Div1, RCC_PLLMul_9); // PLLCLK = (HSE/1)*9 
																												 // czyli 8MHz * 9 = 72 MHz
    RCC_PLLCmd(ENABLE);                                  // wlacz PLL
    while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET);  // czekaj na uruchomienie PLL
    RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);           // ustaw PLL jako zrodlo 
											                                   // sygnalu zegarowego
    while(RCC_GetSYSCLKSource() != 0x08);                // czekaj az PLL bedzie 
                                                         // sygnalem zegarowym systemu    
		RCC_ADCCLKConfig(RCC_PCLK2_Div6);
		
    // konfiguracja sygnalow taktujacych uzywanych peryferii 
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);// wlacz taktowanie portu GPIO A
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);// wlacz taktowanie portu GPIO B
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);// wlacz taktowanie portu GPIO C
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);// wlacz taktowanie portu GPIO D
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);// wlacz taktowanie timera TIM2
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);// wlacz taktowanie timera TIM3
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);// wlacz taktowanie timera TIM4
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);// wlacz taktowanie AFIO
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);// wlacz taktowanie przetwornika ADC1
    return true;
  }
  return false;
}

void ADC_Config(void){
	ADC_InitTypeDef  ADC_InitStructure;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_OCInitTypeDef TIM_OCInitStructure;
	
  // konfiguracja timera TIM2
	// TODO
  
  // konfiguracja kanalu 2 timera TIM2
	// TODO
	
	// wlaczenie przerwan timera TIM2
	// TODO	
	
	// konfiguracja ADC1
	// TODO
	
	// konfiguracja przerwań ADC1
	// TODO
	
	// kalibracja ADC1
	// TODO
	
	// wlaczyc czujnik temperatury
	// TODO
}

void NVIC_Config(void) {
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_SetVectorTable(NVIC_VectTab_FLASH, 0x0);
	//NVIC_PriorityGroupConfig(TODO);
	
	// konfiguracja NVIC dla ADC1
	// TODO
	
	// konfiguracja NVIC dla EXTI0
	// TODO
	
	// konfiguracja NVIC dla EXTI9_5
	// TODO
	
	// konfiguracja NVIC dla TIM3
	// TODO
	
	// konfiguracja NVIC dla TIM4
	// TODO
}

void GPIO_Config(void) {
  // konfigurowanie portow GPIO
  GPIO_InitTypeDef  GPIO_InitStructure; 
  
	// PB6 -- przycisk zewnetrzny bez podciagniecia
	// TODO
	
	// PD10-13 -- klawiatura
	// TODO
	
	// PD6-9 -- klawiatura
	// TODO
	
	// LEDALL -- wszystkie diody swiecace (port B)
	// TODO
	
	// PA0 -- przycisk z podciagnieciem (SW0)
	// TODO
}

void GPIO_TIM4_Config(void) {
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_OCInitTypeDef TIM_OCInitStructure;
    
  // konfiguracja timera TIM4
	// TODO
  
  // konfiguracja kanalu 1 timera TIM4
	// TODO
	
  // konfiguracja kanalu 2 timera TIM4
	// TODO
	
	// wlaczenie przerwan timera TIM4
	// TODO	
}

void GPIO_SW0_Config(void) {
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	EXTI_InitTypeDef EXTI_InitStructure;
	
	// konfiguracja EXTI dla PA0
	// TODO
	
  // konfiguracja timera TIM3 do realizacji opoznienia
	// TODO	
}

void GPIO_KB_Config(void) {
	EXTI_InitTypeDef EXTI_InitStructure;
	
	// konfiguracja EXTI dla PD6
	// TODO
	
	// konfiguracja EXTI dla PD7
	// TODO
	
	// konfiguracja EXTI dla PD8
	// TODO
	
	// konfiguracja EXTI dla PD9
	// TODO
}

char KB2char(void){
	unsigned int GPIO_Pin_row, GPIO_Pin_col, i, j;
	const unsigned char KBkody[16] = {'1','2','3','A',\
							  '4','5','6','B',\
							  '7','8','9','C',\
							  '*','0','#','D'};
	GPIO_SetBits(GPIOD, GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_13);
	GPIO_Pin_row = GPIO_Pin_10;
	for(i=0;i<4;++i){
		GPIO_ResetBits(GPIOD, GPIO_Pin_row);
		Delay(5); // opoznienie 5 ms na ustalenie sygnalow
		GPIO_Pin_col = GPIO_Pin_6;
		for(j=0;j<4;++j){
			if(GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_col) == 0){
				GPIO_ResetBits(GPIOD, GPIO_Pin_10|GPIO_Pin_11|
				  GPIO_Pin_12|GPIO_Pin_13);
				return KBkody[4*i+j];
			}
			GPIO_Pin_col = GPIO_Pin_col << 1;
		}
		GPIO_SetBits(GPIOD, GPIO_Pin_row);
		GPIO_Pin_row = GPIO_Pin_row << 1;
	}
	GPIO_ResetBits(GPIOD, GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_13);
	return 0;
}

void LED(uint16_t led, enum LED_ACTION act) {
	switch(act){
		case LED_ON: GPIO_SetBits(GPIOB, led); break;
		case LED_OFF: GPIO_ResetBits(GPIOB, led); break;
		case LED_TOGGLE: GPIO_WriteBit(GPIOB, led, 
			(GPIO_ReadOutputDataBit(GPIOB, led) == Bit_SET?Bit_RESET:Bit_SET));
	}
}
