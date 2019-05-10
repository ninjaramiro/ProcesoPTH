

#include "main.h"
#include "inicio.h"
#include "macros.h"
#include "USART.h"
#include "estados.h"
#include "control.h"
#include "ADC.h"
#include "eeprom.h"
#include "configuraciones.h"
#include "Leds.h"
#include "Botones.h"
#include "otras.h"


#include <avr/io.h>
#include <avr/wdt.h>
#include <avr/interrupt.h>
#include <avr/eeprom.h> 


/*****************************************************************************
* Variables
*****************************************************************************/
unsigned int 	uContador_Milisegundos;
unsigned char 	ucBuzzer;
volatile unsigned int uContTimeoutBEEP;

extern unsigned char	ucEstadoGeneral;
extern unsigned int 	uTiempoEtching;
extern unsigned char 	ucTiempoAntirrebote;


unsigned char uContTimeoutALARMA;
uint32_t uContPeriodoALARMA;



uint32_t ulTiempo = 0;


// Variables configurables
int 	tiempo_etching;
int 	temp_set;
char	vel_motor;

// Los parametros se concentran en un string antes de guardarlos en la EEPROM (detalle en main.h)
char	chSTRING_PARAMETROS[LONG_STRING_EPROM];


/*****************************************************************************
* Variables externas
*****************************************************************************/

extern unsigned int		uContTimeoutEsperaUSART0;	/* USART0.c, contador de timeout para espera del USART0 */
extern unsigned int		uContTimeoutLecturaRxUSART0;	/* USART0.c, contador de timeout para espera de lectura del buffer de Rx del USART */
extern unsigned int		uContTimeoutRxUSART0;		/* USART0.c, contador de timeout para espera de Rx del USART, si se vence cierro la recepcion */

extern unsigned char  		uchContAuxRx_USART0;
extern char			chBUFFERx_USART0[];		/* USART0.c, buffer de recepción USART del uc */
extern unsigned char		uchEstadoBUFFERx_USART0;	/* USART0.c, variable de estado del buffer de recepción del UASART, lleno o vacio */

extern volatile unsigned int	uContTimeoutUSART0;			/* USART.c, contador de timeout para espera del USART */
extern char			chBufferTx_USART0[USART0_BUFFER_ZISE];	/* USART.c, buffer de transmisión USART del uc */
extern unsigned char ucEstadoBotones;


/*****************************************************************************
* Main
*****************************************************************************/
/** 	Función de entrada del programa
 *
 *	Se inicializan todos los parifericos y las máquinas de estado, y se entra en un bucle infinito
 *	donde se ejecutan las mismas.
 */

int main (void) {
	wdt_disable();				/* por las dudas deshabilito el watchdog timer para el inicio del programa */
	cli();					/* Deshabilito las interrupciones globales */

	/* Rutinas de inicio */
	Inicio_Puertos();
	Inicio_Timer0();			// Timer 0 como marcador de inetrvalos de 0.01ms->50kHz
	Inicio_USART_0();
	Inicio_ADC();
	Inicio_PWM();

	//Inicializo variables
	ucEstadoGeneral = Detenido_Standby;
	uContador_Milisegundos = 0;
	uTiempoEtching = 0;
	uchContAuxRx_USART0 = 0;
	ucEstadoBotones = Esperando;
	uContTimeoutALARMA = 0;

	BEEP(300); //Bip Largo al encenderse

	Configuracion_Inicial ();

	wdt_enable(WDTO_250MS);		/* prendo el watchdog timer en 250 mseg */
	sei();				/* habilito las interrupciones globales */


	while (1) {	/* ejecuto máquinas de estado */
	  ConversionADC();  // Recibe info de los sensores de temperatura y los almacena en Temp1 y Temp2
	  Control_serie();
	  Botones();
	  Maq_estados();
	  Recepcion_USART_0();
	  Leds();
	  Control_Temperatura();

	  wdt_reset();
	}
}


/*****************************************************************************
* Interrupcion Timer 0
*****************************************************************************/
/** 	Rutina de interrupción del Timer 0.
 *
 *	Este timer genera una interrupción cada 1ms, en el se incrementan diferentes
 *	contadores de cada máquina de estados.
 */

ISR (TIMER0_OVF_vect ) {

	TCNT0 = 130;  // Para ajustar la frecuencia

	uContador_Milisegundos ++;

	if (uContador_Milisegundos == 1000){ // Creo un contador de segundos
	  uContador_Milisegundos = 0;

	  if (uTiempoEtching != 0)
	  uTiempoEtching --;

	  // Para la duracion de la alarma
	  if (uContTimeoutALARMA > 0){
		  uContTimeoutALARMA --;
	  }
	  Muestra_datos();

	}

/////////////////////////////////////////////////////////
// Para los botones
	if (ucTiempoAntirrebote > 0){
	  ucTiempoAntirrebote --;
	}
/////////////////////////////////////////////////////////

// Para el beeper///////////////////////////////////////
	if (uContTimeoutBEEP > 0){  // Beeper sonando

	if (ucBuzzer == 0 ){
	  ucBuzzer = 1;
	  SET_BIT(BUZZER_PORT, BUZZER);
	}
	else{
	  ucBuzzer = 0;
  	  CLEAR_BIT(BUZZER_PORT, BUZZER);
	}

	}
/////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////
// Para la longitud del BEEP
	if (uContTimeoutBEEP > 0){
		uContTimeoutBEEP --;
	}
	else{
	    	  CLEAR_BIT(BUZZER_PORT, BUZZER); // Para dejar el buzzer sin alimentacion
	}
/////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////


	if (uContPeriodoALARMA > 0){
		uContPeriodoALARMA --;
	}
	else if(uContPeriodoALARMA == 0 && uContTimeoutALARMA > 0){
	  BEEP(BEEP_ALARMA);
	  uContPeriodoALARMA = PERIODO_ALARMA;
	}


/////////////////////////////////////////////////////////

#ifdef COMPILE_WITH_DEBUG
	/* descuento del timeout de USART */
	if (uContTimeoutUSART0 > 0)
		uContTimeoutUSART0 --;
#endif


}



/*****************************************************************************
* Interrupcion por defecto
*****************************************************************************/
/**
 *
 *	En caso de alguna falla en el codigo y se activa una interrupción no deseada, o sea
 *	que no tiene su vector con su rutina asociada, cae en este vector por defecto que no
 *	hace nada.
 */

ISR(__vector_default) {
}
