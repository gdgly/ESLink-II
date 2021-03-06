
#ifndef MAIN_H
#define MAIN_H

#include "stdint.h"
#include "stdbool.h"
#include "target_program_config.h"

// LED state
typedef enum main_led_state {
    MAIN_LED_DEF = 0,
    MAIN_LED_FLASH,
    MAIN_LED_FLASH_PERMANENT
} main_led_state_t;

void main_cdc_send_event(void);
void main_reset(void );
void main_reset_target(uint8_t send_unique_id);

uint8_t rtc_out_mode(uint8_t enable);

#endif
