

#include "ADC.h"
#include "macros.h"
#include "inicio.h"
#include "USART.h"

#include <avr/io.h>
#include <stdint.h>

/*****************************************************************************
* Variables externas
*****************************************************************************/
#ifdef COMPILE_WITH_DEBUG
extern char	chBufferTx_USART0[USART0_BUFFER_ZISE];				/* USART.c, buffer de transmisión USART del uc */
#endif

/*****************************************************************************
* Mensajes para debug en memoria de programa
*****************************************************************************/

/**  5mV = 1bit **/

void Leds(void) {
  
if (bit_is_clear(RESISTENCIA_PIN, RESISTENCIA)) {
    CLEAR_BIT(LED_RESISTENCIA_PORT, LED_RESISTENCIA);
   }  
   else{
    SET_BIT(LED_RESISTENCIA_PORT, LED_RESISTENCIA);
   }  
  
}



