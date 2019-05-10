


/*
 * MAQUINA DE ETCHING - CONFIGURACION DE LOS PUERTOS
 * PIN 1 → RESET
 * PIN 2 → RXD - PTO SERIE
 * PIN 3 → TXD - PTO SERIE
 * PIN 4 → PD2 - Buzzer
 * PIN 5 → PD3 - GPIO_6
 * PIN 6  → PD4 - GPIO_7
 * PIN 11 → PD5 - GPIO_8
 * PIN 12 → PD6 - GPIO_9
 * PIN 13 → PD7 - GPIO_10
 * PIN 14 → PB0 - GPIO_11
 * PIN 15 → PB1 - PWM_MOTOR
 * PIN 16 → PB2 - PWM_RESISTENCIA
 *
 * PIN 17 → MOSI - PROGRAMADOR 
 * PIN 18 → MISO - PROGRAMADOR 
 * PIN 19 → SCK  - PROGRAMADOR 
 *
 * PIN 23 → PC0 - SENSORTEMP1
 * PIN 24 → PC1 - GPIO_1 - SENSORTEMP2
 * PIN 25 → PC2 - GPIO_2
 * PIN 26 → PC3 - GPIO_3
 * PIN 27 → PC4 - GPIO_4
 * PIN 28 → PC5 - GPIO_5
 *
 */

#ifndef INICIO_H_
#define INICIO_H_

#define COMPILE_WITH_DEBUG	/*habilita la compilacion con el modo debug */

/*****************************************************************************
* Prototipos
*****************************************************************************/



void Inicio_Puertos (void);

void Inicio_Timer0 (void);

void Inicio_Timer1 (void);

void Inicio_PWM (void);



/*****************************************************************************
* Definicion de los nombres de los puertos
*****************************************************************************/

#define MOTORES						PB1
#define MOTORES_PORT					PORTB
#define MOTORES_PIN					PINB
#define DIR_MOTORES_PORT				DDRB

#define RESISTENCIA					PB2
#define RESISTENCIA_PORT				PORTB
#define RESISTENCIA_PIN					PINB
#define DIR_RESISTENCIA_PORT				DDRB

#define SENSORTEMP1					PC0
#define SENSORTEMP1_PORT				PORTC
#define SENSORTEMP1_PIN					PINC
#define DIR_SENSORTEMP1_PORT				DDRC

#define SENSORTEMP2					PC1
#define SENSORTEMP2_PORT				PORTC
#define SENSORTEMP2_PIN					PINC
#define DIR_SENSORTEMP2_PORT				DDRC

#define BUZZER						PD2
#define BUZZER_PORT					PORTD
#define BUZZER_PIN					PIND
#define DIR_BUZZER_PORT					DDRD

#define MOSI						PB3
#define MISO						PB4
#define SCK						PB5

#define USART_PORT					PORTD
#define DIR_USART_PORT					DDRD
#define USART_RXD					PD0
#define USART_TXD					PD1

#define	 SPI_PORT					PORTB 
#define	 DIR_SPI_PORT				        DDRB
#define	 SPI_SCK					PB5
#define	 SPI_MISO					PB4
#define	 SPI_MOSI					PB3

#define LED_RESISTENCIA					PB0
#define LED_RESISTENCIA_PORT				PORTB
#define LED_RESISTENCIA_PIN				PINB
#define DIR_LED_RESISTENCIA_PORT			DDRB

#define BOTON_INICIO					PC5
#define BOTON_INICIO_PORT				PORTC
#define BOTON_INICIO_PIN				PINC
#define DIR_BOTON_INICIO_PORT				DDRC

#define BOTON_PARAR					PC4
#define BOTON_PARAR_PORT				PORTC
#define BOTON_PARAR_PIN					PINC
#define DIR_BOTON_PARAR_PORT				DDRC

#define BOTON_PAUSA					PC3
#define BOTON_PAUSA_PORT				PORTC
#define BOTON_PAUSA_PIN					PINC
#define DIR_BOTON_PAUSA_PORT				DDRC


#define F_CPU 8000000

#endif /* INICIO_H_ */
