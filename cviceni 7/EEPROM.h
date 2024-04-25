#ifndef EEPROM_H_
#define EEPROM_H_

#pragma once
#include <avr/interrupt.h>


void eeprom_write(uint16_t add,uint8_t *data,uint16_t size);


void eeprom_read(uint16_t add,uint8_t *data,uint16_t size);

#endif /* EEPROM_H_ */
