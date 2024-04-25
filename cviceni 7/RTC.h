

#ifndef RTC_H_
#define RTC_H_

#pragma once

#include <avr/io.h>
#include "TWI.h"

uint8_t rtc_read_sec();
uint8_t rtc_read_min();
uint8_t rtc_read_hours();
uint8_t rtc_read_days();
uint8_t rtc_read_months();
uint8_t rtc_read_year();

uint8_t rtc_set_sec(uint8_t seconds);
uint8_t rtc_set_min(uint8_t minutes);
uint8_t rtc_set_hour(uint8_t hour);
uint8_t rtc_set_days(uint8_t day);
uint8_t rtc_set_months(uint8_t month);
uint8_t rtc_set_year(uint8_t year);

uint8_t rtc_start_count();
uint8_t rtc_stop_count();
uint8_t rtc_start_gen();
uint8_t rtc_stop_gen();


#endif /* RTC_H_ */