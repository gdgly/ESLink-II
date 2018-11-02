#ifndef __ESLINK_H__
#define __ESLINK_H__


#include "MK22f12810.h"             // Debug Unit Cortex-M Processor Header File
#include "es_common.h"
#include "errno.h"  
#include "eslink_gpio.h"
#include "eslink_config.h"
#include "eslink_def.h"


#define ES_DEBUG   0

#ifdef ES_DEBUG
//#include "daplink_debug.h"
#define printf    debug_msg
#else
#define printf      (...)
#endif

#ifdef __cplusplus
extern "C" {
#endif
//******************************************************************************  
//es_link 调用函数    

// Configurable delay for clock generation
#ifndef ES_DELAY_SLOW_CYCLES
#define ES_DELAY_SLOW_CYCLES       2U      // Number of cycles for one iteration
#endif
static __forceinline void ES_DELAY_SLOW (uint32_t delay) {
  uint32_t count;

  count = delay;
  while (--count);
}
/*
80Mhz:
ES_DELAY_SLOW(1)------>200ns
*/

// Fixed delay for fast clock generation
#ifndef ES_DELAY_FAST_CYCLES
#define ES_DELAY_FAST_CYCLES       2U      // Number of cycles: 0..3
#endif
static __forceinline void ES_DELAY_FAST (void) {
#if (ES_DELAY_FAST_CYCLES >= 1U)
  __nop();
#endif
#if (ES_DELAY_FAST_CYCLES >= 2U)
  __nop();
#endif
#if (ES_DELAY_FAST_CYCLES >= 3U)
  __nop();
#endif
}    

void es_delay_us(uint32_t delay);
void es_delay_ms(uint32_t delay);  
uint32_t prog_process_command(uint8_t *request, uint8_t *response);
error_t es_program_init(prog_intf_type_t type);  
error_t es_prog_set_intf(prog_intf_type_t type);
error_t serial_number_download(uint8_t *data);                                                 
error_t es_erase_chip(uint8_t *data);    
error_t es_check_empty(uint8_t *data);  
error_t es_program_flash(uint8_t sn_enable, uint8_t *data);  
error_t es_program_verify(uint8_t sn_enable,uint8_t *data);  
error_t es_program_encrypt(void);     
error_t es_entry_prog_mode(void );
   
#ifdef __cplusplus
}
#endif

#endif
