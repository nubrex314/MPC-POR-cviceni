

#ifndef ENCODER_H_
#define ENCODER_H_

#pragma once
#include <avr/interrupt.h>//preruseni


void init_encoder();

int readbutton(void);

int enco_read();

#endif /* ENCODER_H_ */