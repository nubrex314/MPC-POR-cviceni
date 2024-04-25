

#ifndef RTC_H_
#define RTC_H_

#pragma once
#include <avr/interrupt.h>


#define START_ACK		 0x08 // Start byl odesl�n
#define REP_START_ACK	 0x10 // Opakovan� start byl odesl�n
#define SLA_W_ACK		 0x18 // SLA+W byl odesl�n a ACK p�ijat
//#define SLA_W_NACK		 0x20 // SLA+W byl odesl�n a NACK p�ijat
#define DATA_W_ACK		 0x28 // Data byte byl odesl�n a ACK p�ijat
//#define DATA_W_NACK		 0x30 // Data byte byl odesl�n a NACK p�ijat
#define LOST_ARB		 0x38 // Ztr�ta arbitr�e v SLA+W nebo data byte

#define SLA_R_ACK		0x40 // SLA+R byl odesl�n a ACK p�ijat
//#define SLA_R_NACK		0x48 // SLA+R byl odesl�n a NACK p�ijat
#define DATA_R_ACK		0x50 // Data byte byl p�ijat a ACK odesl�n
#define DATA_R_NACK		0x58 // Data byte byl p�ijat a NACK odesl�n

typedef enum {
	NO_ERROR = 0, // ��dn� chyba
	START_ACK_ERROR=-1, // Chyba p�i odes�l�n� startu
	REP_START_ACK_ERROR=-2, // Chyba p�i odes�l�n� opakovan�ho startu
	SLA_W_ACK_ERROR=-3, // Chyba p�i odes�l�n� SLA+W
	DATA_ACK_ERROR=-4, // Chyba p�i odes�l�n� dat a p�ijet� ACK
	LOST_ARB_ERROR=-5, // Chyba p�i ztr�t� arbitr�e
	SLA_R_ACK_ERROR=-6, // Chyba p�i odes�l�n� SLA+R a p�ijet� ACK
	DATA_READ_ACK_ERROR=-7, // Chyba p�i �ten� dat a odes�l�n� ACK
} I2C_ErrorCode;

void initTWI(uint32_t Hz);

void twi_start(void);
void twi_restart(void);
void twi_stop(void) ;

void twi_addres_write_ack(void);
void twi_data_write_ack(void);
void twi_addres_read_ack(void);
void twi_data_read_ack(int enable);

void twi_write(uint8_t *data, uint8_t addres, uint8_t regis,uint16_t leng);
void twi_read(uint8_t *data, uint8_t addres, uint8_t regis,uint16_t leng);

void error(int8_t err);

#endif /* RTC_H_ */