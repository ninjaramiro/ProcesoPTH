#include "main.h"
#include "inicio.h"
#include "macros.h"
#include "gen_pulsos.h"
#include "USART.h"
#include "comandos.h"

#include <avr/io.h>
#include <avr/wdt.h>
#include <avr/interrupt.h>
#include <stdbool.h>

// Variables externas para el generador de pulsos
extern uint8_t estado_gen_pulsos;
extern uint8_t t_directo;
extern uint8_t t_muerto_a;
extern uint8_t t_inverso;
extern uint8_t t_muerto_b;
extern uint8_t cont_directo;
extern uint8_t cont_muerto_a;
extern uint8_t cont_inverso;
extern uint8_t cont_muerto_b;
extern uint8_t Duty_directo; // Valor de 0 a 255 que representa el dutycycle de 0 a 100%
extern uint8_t Duty_inverso; // Valor de 0 a 255 que representa el dutycycle de 0 a 100%

extern char volatile caracter_uart;
extern char volatile fl_caracter_recibido;
extern unsigned int	uContTimeoutUSART0;

//char valor_comando[10];
uint8_t volatile valor_comando;
uint8_t volatile contador_comando;
uint8_t volatile id_comando;

int main (void) {

	wdt_disable();				/* por las dudas deshabilito el watchdog timer para el inicio del programa */
	cli();					/* Deshabilito las interrupciones globales */
	/* Rutinas de inicio */
	Inicio_Puertos();
	Inicio_Timer0();			// Timer 0 como marcador de inetrvalos de 0.01ms->50kHz
	Inicio_Timer2();
	Inicio_PWM();
	Inicio_USART();

wdt_enable(WDTO_250MS);		/* prendo el watchdog timer en 250 mseg */
sei();				/* habilito las interrupciones globales */

t_directo = 15;
t_muerto_a = 1;
t_inverso = 10;
t_muerto_b = 1;
Duty_directo = 100;
Duty_inverso = 50;
estado_gen_pulsos = encender;


	while (1) {	/* ejecuto máquinas de estado */
		gen_pulsos();
		wdt_reset();
		if 	(fl_caracter_recibido == 1){
			fl_caracter_recibido = 0;
			comandos();
		}
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


		if (uContTimeoutUSART0 != 0){
			uContTimeoutUSART0 --;
		}

}


// Este timer se usa para controlar la máquina de estados generadora de los pulsos
ISR (TIMER2_OVF_vect ) {

		TCNT2 = 233;  // Para ajustar la frecuencia

		if (cont_directo > 0){
			cont_directo --;
		}

		if (cont_muerto_a > 0){
			cont_muerto_a --;
		}

		if (cont_inverso > 0){
			cont_inverso --;
		}

		if (cont_muerto_b > 0){
			cont_muerto_b --;
		}

	}



// Interrupcion de recepcion de caracter por puerto serie
ISR (USART_RXC_vect) {

	caracter_uart = UDR;
	fl_caracter_recibido = 1;



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
