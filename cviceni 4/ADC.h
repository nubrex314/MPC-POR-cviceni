

#ifndef ADC_H_
#define ADC_H_

#pragma once
#include <avr/interrupt.h>

void initADC(void);

void ADC_start(uint8_t ADCport);

int16_t ADC_read(uint8_t ADCport);

float ADC_normtemp(uint16_t raw);

void printfloat(float in);

#endif /* ADC_H_ */