/**
* @addtogroup ppal
* @{
* @file main.c
* @brief Programa principal
*/
#include "main.h"
#include "inicio.h"
#include "macros.h"
#include "gen_pulsos.h"


#include <avr/io.h>
#include <avr/wdt.h>
#include <avr/interrupt.h>
#include <stdbool.h>
#include <avr/pgmspace.h>

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

// Variables para el manejo del PWM y la polaridad de la corriente
extern uint16_t PARAMETROS_PWM[];
extern int16_t SENIAL_PWM[];
uint16_t NRO_DATOS_TABLA_PWM;
volatile uint16_t entrada_a_duty_actual;
volatile sentido_cte polaridad, polaridad_anterior;
volatile uint16_t nuevo_duty;

int main (void) {

	wdt_disable();				/* por las dudas deshabilito el watchdog timer para el inicio del programa */
	cli();					/* Deshabilito las interrupciones globales */
	/* Rutinas de inicio */
	Inicio_Puertos();
	//Inicio_Timer0();			// Timer 0 como marcador de inetrvalos de 0.01ms->50kHz
	//Inicio_Timer2();
//	Inicio_USART_0();
//	Inicio_ADC();
	Inicio_PWM();

	//wdt_enable(WDTO_250MS);		/* prendo el watchdog timer en 250 mseg */
	RUN_TIMER_1
	sei();				/* habilito las interrupciones globales */

	/*
	t_directo = 5;
	t_muerto_a = 1;
	t_inverso = 5;
	t_muerto_b = 1;
	Duty_directo = 100;
	Duty_inverso = 50;
	estado_gen_pulsos = encender;
	*/
	while (1) 
	{	/* ejecuto máquinas de estado */

		//gen_pulsos();
		//wdt_reset();
	}
}


/** @brief Interrupción del timer_1 cuando llega a 0.
*	Se actualiza el valor del duty y de la polaridad
*/
ISR (TIMER1_CAPT_vect)
{
	
	if(polaridad==polaridad_anterior)
	{
		OCR1A=nuevo_duty;
		OCR1B=nuevo_duty;
	}
	else{
		polaridad_anterior=polaridad;
		if(polaridad==CORRIENTE_DIRECTA)
		{
			TCCR1A &=~( (1<<COM1A1)|(1<<COM1A0)|(1<<COM1B1)|(1<<COM1B0) );	// inactivo PWM_1 = OC1A en bajo
			CLEAR_BIT(PULSE2_PORT, PULSE2);			// inactivo PULSO_2
			//OCR1A=nuevo_duty;
			OCR1B=nuevo_duty;
			SET_BIT(PULSE1_PORT, PULSE1);			// activo PULSO_1
			TCCR1A |=( (1<<COM1B1)|(0<<COM1B0) );	// activo PWM_2 = OC1B va a subir y bajar
		}
		else
		{
			TCCR1A &=~( (1<<COM1B1)|(1<<COM1B0)|(1<<COM1A1)|(1<<COM1A0) );	// inactivo PWM_2 = OC1B en bajo
			CLEAR_BIT(PULSE1_PORT, PULSE1);			// inactivo PULSO_1
			OCR1A=nuevo_duty;
			//OCR1B=nuevo_duty;
			SET_BIT(PULSE2_PORT, PULSE2);			// activo PULSO_2
			TCCR1A |=( (1<<COM1A1)|(0<<COM1A0) );	// activo PWM_1	= OC1A va a subir y bajar
		}
	}
}

/** @brief Interrupción del timer_1 cuando llega a ICR1=399.
*	Se busca el próximo valor del duty y se prepara todo 
*	para el siguiente ciclo de PWM.
*/
ISR (TIMER1_OVF_vect )
{
	int16_t aux;
	
	aux =  pgm_read_word(&SENIAL_PWM[entrada_a_duty_actual]);
	POS_INC_MODULO(entrada_a_duty_actual, NRO_DATOS_TABLA_PWM);
	if( aux<0){
		// polaridad invertida
		aux=-aux;
		polaridad=CORRIENTE_INVERSA;
	}
	else{
		polaridad=CORRIENTE_DIRECTA;
	}
	nuevo_duty = aux;	// 10 bits
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

}


// Este timer se usa para controlar la máquina de estados generadora de los pulsos
ISR (TIMER2_OVF_vect ) {

		TCNT2 = 230;  // Para ajustar la frecuencia

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

/** @} fin de main.c en el grupo ppal. */