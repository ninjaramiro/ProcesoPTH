/**
* @addtogroup config
* @{
* @file inicio.c
* @brief configuraciOn de perifEricos
*/
#include "inicio.h"
#include "macros.h"
#include <avr/pgmspace.h>

extern uint16_t PARAMETROS_PWM[];
extern int16_t SENIAL_PWM[];
extern uint16_t NRO_DATOS_TABLA_PWM;
extern volatile uint16_t entrada_a_duty_actual;
extern sentido_cte polaridad, polaridad_anterior;
extern volatile uint16_t nuevo_duty;

/**
* @brief Configura puertos de entrada/salida
*/
void Inicio_Puertos (void) {

/*--------- DIRECCION -----------------------------------------------*/
	DIRECCION_PIN(USART_DDR, USART_RXD, ENTRADA);
	DIRECCION_PIN(USART_DDR, USART_TXD, SALIDA);

/*
	DIRECCION_PIN(BOT_1_DDR, BOT_1, ENTRADA);
	DIRECCION_PIN(BOT_2_DDR, BOT_2, ENTRADA);
	DIRECCION_PIN(BOT_3_DDR, BOT_3, ENTRADA);
	DIRECCION_PIN(BOT_4_DDR, BOT_4, ENTRADA);

	DIRECCION_PIN(POTE_DDR, POTE, ENTRADA);
	DIRECCION_PIN(BUZZER_DDR, BUZZER, SALIDA);
	DIRECCION_PIN(PULSE1_DDR, PULSE1, SALIDA);
	DIRECCION_PIN(PULSE2_DDR, PULSE2, SALIDA);

	DIRECCION_PIN(SENS_CORRIENTE_DDR, SENS_CORRIENTE, ENTRADA);
	*/

	CLEAR_BIT(PULSE1_PORT, PULSE1);
	CLEAR_BIT(PULSE2_PORT, PULSE2);
	CLEAR_BIT(PWM1_PORT, PWM1);
	CLEAR_BIT(PWM2_PORT, PWM2);
	
	DIRECCION_PIN(PULSE1_DDR, PULSE1, SALIDA);
	DIRECCION_PIN(PULSE2_DDR, PULSE2, SALIDA);
	
	DIRECCION_PIN(PWM1_DDR, PWM1, SALIDA);
	DIRECCION_PIN(PWM2_DDR, PWM2, SALIDA);

	//DIRECCION_PIN(LCD_RS_DDR, LCD_RS, SALIDA);
	//DIRECCION_PIN(LCD_RW_DDR, LCD_RW, SALIDA);
	//DIRECCION_PIN(LCD_E_DDR, LCD_E, SALIDA);
	//DIRECCION_PIN(LCD_D4_DDR, LCD_D4, SALIDA);
	//DIRECCION_PIN(LCD_D5_DDR, LCD_D5, SALIDA);
	//DIRECCION_PIN(LCD_D6_DDR, LCD_D6, SALIDA);
	//DIRECCION_PIN(LCD_D7_DDR, LCD_D7, SALIDA);

/*--------------------------------------------------------*/
	// PULL_UP_PIN(USART_PORT, USART_RXD, NO);
	// PULL_UP_PIN(USART_PORT, USART_TXD, NO);

	//PULL_UP_PIN(BOT_1_PORT, BOT_1, SI);  /* LOS BOTONES LLEVAN PULL UP */
	//PULL_UP_PIN(BOT_2_PORT, BOT_2, SI);  /* LOS BOTONES LLEVAN PULL UP */
	//PULL_UP_PIN(BOT_3_PORT, BOT_3, SI);  /* LOS BOTONES LLEVAN PULL UP */
	//PULL_UP_PIN(BOT_4_PORT, BOT_4, SI);  /* LOS BOTONES LLEVAN PULL UP */

	//PULL_UP_PIN(POTE_PORT, POTE, NO);
	//PULL_UP_PIN(BUZZER_PORT, BUZZER, NO);

	//PULL_UP_PIN(SENS_CORRIENTE_PORT, SENS_CORRIENTE, NO);

  // Estado inicial de los puertos

	//CLEAR_BIT(BUZZER_PORT, BUZZER);

	//CLEAR_BIT(LCD_RS_PORT, LCD_RS);
	//CLEAR_BIT(LCD_RW_PORT, LCD_RW);
	//CLEAR_BIT(LCD_E_PORT, LCD_E);
	//CLEAR_BIT(LCD_D4_PORT, LCD_D4);
	//CLEAR_BIT(LCD_D5_PORT, LCD_D5);
	//CLEAR_BIT(LCD_D6_PORT, LCD_D6);
	//CLEAR_BIT(LCD_D7_PORT, LCD_D7);
}

/************************************************************************
* Inicio Timer
************************************************************************/
/* Inicio el Timer 0 */

void Inicio_Timer0 (void) {
	
	TCCR0A = 0b00000000;
	TCCR0B = 0b00000011;	// prescaler 64
	SET_BIT (TIMSK0,TOIE0);	// habilito la interrupción por overflow
	CLEAR_BIT (TIFR0, TOV0);		// aseguro que no haya ninguna interrupción por overflow
}

/**
* @brief Configura PWM y dos interrupciones asociadas.\n
*	Se usa el timer_1 de 16 bits y el modo PWM de frecuencia y fase correctas.\n
*	El reloj del timer es igual al del sistema (8MHz) i.e. sin pre-escalamiento.\n
*   En modo 8 el PWM (WGM1.3-0= 0b1000) aumenta el TCNT1 (de 16 bits) desde 0\n
*   hasta ICR1=400-1, y luego desciende hacia 0.  Al llegar TCNT1 al valor del\n
*	ICR1 genera una interrupción, atendida en TIMER1_CAPT_vect en la que se lee\n
*	el siguiente duty desde la tabla SENIAL_PWM (en forma circular), se escala\n
*	si hace falta y se verifica la polaridad (si es negativo hay que invertir \n
*	dirección de la corriente).  Además se debería verificar que el duty sea \n
*	"realizable", es decir no nulo, ni constante y menor a 400-1.
*	El valor del duty se escribe tanto en OCR1A como en OCR1B.
*
*   Cuanto TCNT1 llega a cero, otra interrupción, atendida en TIMER1_OVF_vect,\n
*   hace efectivo el nuevo duty y si es necesario el cambio de polaridad. \n
*	Esto se hace modificando COM1A.1-0 y COM1B.1-0 activando uno y desactivando\n
*	el otro.
*		Cada ciclo PWM tarda 400*2/8=100uS.\n
*	Durante el ascenso del TCNT1 si coincide con OCR1B/OCR1B sube OC1A=PWM1\n
*	u OC1B=PWM2 según sea la polaridad y durante el descenso, al coincidir baja.\n
*	Esta configuración se logra con COM1X.1-0 = b11, para el modo inverso se usa
*	b10 y para desconectar (PORT lo controla) 0b00.
*
*		TODO: Según la implementación hay que deteminar el duty mínimo y máximo
*	que puede manejar este esquema.
*/
void Inicio_PWM (void) {

	int16_t aux;
	
	TCCR1A &=~((1<<COM1A1)|(1<<COM1A0)|(1<<COM1B1)|(1<<COM1B0)|(1<<WGM11)|(1<<WGM10));
	TCCR1B &=~((1<<CS12)|(1<<CS11)|(1<<CS10));
	TCCR1B |=((1<<WGM13));	// WGM1.3-0=0b1000=MODO_8, TIMER_1 detenido, OC1A=OC1B=0 (=PB.1=PB.2)
	TCNT1= 0;
	//aux = pgm_read_word(&PARAMETROS_PWM[2]);
	ICR1 = (F_CPU*50/1000000-1);			// PerIodo del PWM = 100us
	// Puntero a tabla, longitud de tabla y 1er valor del duty en OCR1A y OCR1B
	NRO_DATOS_TABLA_PWM =  pgm_read_word(&PARAMETROS_PWM[0]);
	entrada_a_duty_actual = 0;		// iterador para recorrer la tabla
									// va de 0 a NRO_DATOS_TABLA_PWM-1
	aux = pgm_read_word(&SENIAL_PWM[entrada_a_duty_actual]);
	POS_INC_MODULO(entrada_a_duty_actual, NRO_DATOS_TABLA_PWM);
	if( aux<0){
		// polaridad invertida
		aux=-aux;
		polaridad=CORRIENTE_INVERSA;
	}
	else{
		polaridad=CORRIENTE_DIRECTA;
	}
	polaridad_anterior=polaridad;
	nuevo_duty = aux;
	OCR1A = aux;
	OCR1B = aux;
	TIMSK1 |=((1<<ICIE1)|(1<<TOIE1));	// Interrumpe al llegar al tope ICR1 y a 0 (OV).
}


/************************************************************************
* Inicio Timer
************************************************************************/
/* Inicio el Timer 2 */

void Inicio_Timer2 (void) {
  TCCR2A = 0b00000000;
	TCCR2B = 0b00000010;	// prescaler 8
	SET_BIT (TIMSK2,TOIE2);	// habilito la interrupción por overflow
	CLEAR_BIT (TIFR2, TOV2);		// aseguro que no haya ninguna interrupción por overflow
}

/** @} fin de inicio.c en el grupo config. */