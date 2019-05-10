

#include "inicio.h"
#include "macros.h"
#include "USART.h"


#include <avr/io.h>

/************************************************************************
* Inicio de los puertos
************************************************************************/

void Inicio_Puertos (void) {	/* Funcion de inicio de los puertos de entrada/salida */


  
	DIRECCION_PIN(DIR_MOTORES_PORT, MOTORES, SALIDA);  
	DIRECCION_PIN(DIR_RESISTENCIA_PORT, RESISTENCIA, SALIDA);
	DIRECCION_PIN(DIR_SENSORTEMP1_PORT, SENSORTEMP1, ENTRADA);
	DIRECCION_PIN(DIR_SENSORTEMP2_PORT, SENSORTEMP2, ENTRADA);
	DIRECCION_PIN(DIR_BUZZER_PORT, BUZZER, SALIDA);
	DIRECCION_PIN(DIR_LED_RESISTENCIA_PORT, LED_RESISTENCIA, SALIDA);  
	
	DIRECCION_PIN(DIR_USART_PORT, USART_RXD, ENTRADA);
	DIRECCION_PIN(DIR_USART_PORT, USART_TXD, SALIDA);

	DIRECCION_PIN(DIR_SPI_PORT, SPI_SCK, ENTRADA);
	DIRECCION_PIN(DIR_SPI_PORT, SPI_MOSI, ENTRADA);
	DIRECCION_PIN(DIR_SPI_PORT, SPI_MISO, ENTRADA);

	DIRECCION_PIN(DIR_BOTON_INICIO_PORT, BOTON_INICIO, ENTRADA);	
	DIRECCION_PIN(DIR_BOTON_PARAR_PORT, BOTON_PARAR, ENTRADA);
	DIRECCION_PIN(DIR_BOTON_PAUSA_PORT, BOTON_PAUSA, ENTRADA);

	PULL_UP_PIN(BOTON_INICIO_PORT, BOTON_INICIO, SI);	//Los botones tienen que tener pull-up
	PULL_UP_PIN(BOTON_PARAR_PORT, BOTON_PARAR, SI);		//Los botones tienen que tener pull-up
	PULL_UP_PIN(BOTON_PAUSA_PORT, BOTON_PAUSA, SI);		//Los botones tienen que tener pull-up
	
	PULL_UP_PIN(SENSORTEMP1_PORT, SENSORTEMP1, NO);
	PULL_UP_PIN(SENSORTEMP2_PORT, SENSORTEMP2, NO);

}


/************************************************************************
* Inicio Timer
************************************************************************/
/* Inicio el Timer 0 */

void Inicio_Timer0 (void) {
	TCCR0 = 0b00000011;	// prescaler 64
	SET_BIT (TIMSK,TOIE0);	// habilito la interrupción por overflow 
	CLEAR_BIT (TIFR, TOV0);		// aseguro que no haya ninguna interrupción por overflow 
}


/************************************************************************
* Inicio PWM
************************************************************************/
void Inicio_PWM (void) {
TCCR1A = 0b10000001; // Habilito el PWM Modo 1 Salida por OC1A puerto 15
TCCR1B = 0b00000100;  // Prescaler 256 y clock source
}


