/*
 * FUENTE PTH - CONFIGURACION DE LOS PUERTOS
 * PIN 1 → RESET
 * PIN 2 → RXD - PTO SERIE
 * PIN 3 → TXD - PTO SERIE
 * PIN 4 → PD2 - LCD_RS
 * PIN 5 → PD3 - LCD_RW
 * PIN 6  → PD4 - LCD_E
 * PIN 11 → PD5 - LCD_D4
 * PIN 12 → PD6 - LCD_D5
 * PIN 13 → PD7 - LCD_D6
 * PIN 14 → PB0 - LCD_D7
 * PIN 15 → PB1 - PWM1
 * PIN 16 → PB2 - PWM2
 *
 * PIN 17 → PB3 - MOSI - BOT_4
 * PIN 18 → PB4 - MISO - BOT_3
 * PIN 19 → PB5 - SCK - BOT_2
 *
 * PIN 23 → PC0 - BOT_1
 * PIN 24 → PC1 - POTE
 * PIN 25 → PC2 - BUZZER
 * PIN 26 → PC3 - PULSE_2
 * PIN 27 → PC4 - SENS_CORRIENTE
 * PIN 28 → PC5 - PULSE_1
 *
 */

#ifndef INICIO_H_
#define INICIO_H_

#include <avr/io.h>

#define F_CPU 16000000

/*****************************************************************************
* Prototipos
*****************************************************************************/

void Inicio_Puertos (void);

void Inicio_Timer0 (void);

//void Inicio_Timer1 (void);

void Inicio_Timer2 (void);

void Inicio_PWM (void);



/*****************************************************************************
* Definicion de los nombres de los puertos
*****************************************************************************/

#define USART_PORT				PORTD
#define USART_DDR     		DDRD
#define USART_RXD					PD0
#define USART_TXD					PD1

#define BOT_1					  PC0
#define BOT_1_PORT			PORTC
#define BOT_1_PIN				PINC
#define BOT_1_DDR	      DDRC

#define BOT_2					  PB5
#define BOT_2_PORT			PORTB
#define BOT_2_PIN				PINB
#define BOT_2_DDR	      DDRB

#define BOT_3					  PB4
#define BOT_3_PORT			PORTB
#define BOT_3_PIN				PINB
#define BOT_3_DDR       DDRB

#define BOT_4					  PB3
#define BOT_4_PORT			PORTB
#define BOT_4_PIN				PINB
#define BOT_4_DDR	      DDRB

#define POTE						PC1
#define POTE_PORT				PORTC
#define POTE_PIN				PINC
#define POTE_DDR    		DDRC

#define BUZZER						PC2
#define BUZZER_PORT				PORTC
#define BUZZER_PIN				PINC
#define BUZZER_DDR    		DDRC

#define PULSE2						PC3
#define PULSE2_PORT				PORTC
#define PULSE2_PIN				PINC
#define PULSE2_DDR		DDRC

#define SENS_CORRIENTE						PC4
#define SENS_CORRIENTE_PORT				PORTC
#define SENS_CORRIENTE_PIN				PINC
#define SENS_CORRIENTE_DDR    		DDRC

#define PULSE1						PC5
#define PULSE1_PORT				PORTC
#define PULSE1_PIN				PINC
#define PULSE1_DDR		DDRC

#define PWM1						PB1
#define PWM1_PORT				PORTB
#define PWM1_PIN				PINB
#define PWM1_DDR    		DDRB

#define PWM2						PB2
#define PWM2_PORT				PORTB
#define PWM2_PIN				PINB
#define PWM2_DDR		    DDRB

#define LCD_RS						PD2
#define LCD_RS_PORT			  PORTD
#define LCD_RS_PIN				PIND
#define LCD_RS_DDR    	  DDRD

#define LCD_RW						PD3
#define LCD_RW_PORT			  PORTD
#define LCD_RW_PIN				PIND
#define LCD_RW_DDR    	  DDRD

#define LCD_E						PD4
#define LCD_E_PORT			PORTD
#define LCD_E_PIN				PIND
#define LCD_E_DDR     	DDRD

#define LCD_D4						PD5
#define LCD_D4_PORT			  PORTD
#define LCD_D4_PIN				PIND
#define LCD_D4_DDR	      DDRD

#define LCD_D5						PD6
#define LCD_D5_PORT			  PORTD
#define LCD_D5_PIN				PIND
#define LCD_D5_DDR	      DDRD

#define LCD_D6						PD7
#define LCD_D6_PORT			  PORTD
#define LCD_D6_PIN				PIND
#define LCD_D6_DDR    	  DDRD

#define LCD_D7						PB0
#define LCD_D7_PORT			  PORTB
#define LCD_D7_PIN				PINB
#define LCD_D7_DDR	      DDRB



#endif /* INICIO_H_ */
