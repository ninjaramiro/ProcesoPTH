

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



uint32_t uiTemp1;
uint32_t uiTemp2;

/**  5mV = 1bit → medio grado de temperatura en el LM35**/

void ConversionADC(void) {
	if ((ADCSRA & (SET<<ADSC)) != 0) {		// si no terminó la conversión salgo de la funcion
	}
	else {						// si terminó la conversión cargo las variables
		if ((ADMUX & (OFF<<MUX0)) == 0) {	// (ADMUX == ADC0) Si estoy muetreando el ADC0
			uiTemp1 = (ADC*(0.489));
			SET_BIT(ADMUX,MUX0);		//Paso al ADC1 para la próxima conversion	
			SET_BIT(ADCSRA, ADSC);
			}				
		
		else { 					// (ADMUX == ADC1)   Si estoy muetreando el ADC1
			uiTemp2 = (ADC*(0.489));
			CLEAR_BIT(ADMUX,MUX0);		//Paso al ADC0 para la próxima conversion
			SET_BIT(ADCSRA, ADSC);
		}
	}
}

/************************************************************************
* Funcion de inicio del ADC
************************************************************************/
void Inicio_ADC(void){
	// inicio el ADC en modo de conversión simple, con el preescaler en 128 y sin interrupción.
	ADMUX = (OFF<<REFS1)|(SET<<REFS0)|(OFF<<ADLAR)|(OFF<<MUX3)|(OFF<<MUX2)|(OFF<<MUX1)|(OFF<<MUX0);		//Inicialmente arranca en el canal ADC0
	ADCSRA = (OFF<<ADEN)|(OFF<<ADSC)|(OFF<<ADFR)|(SET<<ADIF)|(OFF<<ADIE)|(SET<<ADPS2)|(SET<<ADPS1)|(SET<<ADPS0);
	SET_BIT(ADCSRA, ADEN);		// activo el ADC
	SET_BIT(ADCSRA, ADSC);		// empiezo una conversion
}

