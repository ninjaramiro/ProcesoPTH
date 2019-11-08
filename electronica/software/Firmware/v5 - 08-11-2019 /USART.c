
/** \file	USART.c
 *  \brief	Contiene las maquinas de estados correspondientes a la recepción y a la transmisión \n
 *	porUSART del uc.
 */

#include "USART.h"
#include "macros.h"


#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>
#include <avr/eeprom.h>
#include <avr/pgmspace.h>



//#ifdef COMPILE_WITH_DEBUG

/*****************************************************************************
* Variables comunes a ambas Máquinas de estados
*****************************************************************************/

unsigned int	uContTimeoutUSART0;			/**< \brief contaDOR0 de timeout para esUPE0ra del USART */

/*****************************************************************************
* Variables Máquina de estados de recepción
*****************************************************************************/

unsigned char	uchEstaDOR0ecepcionUSART0;				/**< \brief variable de la maquina de estados del recepción por USART */
char			chBUFFERx_USART0[USART0_BUFFER_ZISE];	/**< \brief BUFFER de recepción USART del uc */
unsigned char	uchEstadoBUFFERx_USART0;				/**< \brief variable de estado del BUFFER de recepción del UASART, lleno o vacio */
unsigned char	uchContAuxRx_USART0;					/**< \brief contaDOR0 auxiliar de recepción */

/*****************************************************************************
* Variables Máquina de estados de transmisión
*****************************************************************************/

unsigned char	uchEstadoTransmisionUSART0;				/**< \brief variable de la maquina de estados del transmisión por USART */
char			chBufferTx_USART0[USART0_BUFFER_ZISE];	/**< \brief BUFFER de transmisión USART del uc */
unsigned char	uchEstadoBUFFERTx_USART0;				/**< \brief variable de estado del BUFFER de transmisión del USART, lleno o vacio */
unsigned char	uchContAuxTx_USART0;					/**< \brief contaDOR0 auxiliar de transmisión */



/*****************************************************************************
* Variables comunes a ambas Máquinas de estados
*****************************************************************************/

unsigned int	uContTimeoutEsperaUSART0;			/**< \brief contador de timeout para espera del USART */
unsigned int	uContTimeoutLecturaRxUSART0;		/**< \brief contador de timeout para espera de lectura del buffer de Rx del USART */
unsigned int	uContTimeoutRxUSART0;				/**< \brief contador de timeout para espera de Rx del USART, si se vence cierro la recepcion */
unsigned int	uContTimeoutTxUSART0;				/**< \brief contador de timeout para espera de transmision del buffer de Tx del USART */





void Inicio_USART(void)
{
/*Set baud rate */
UBRRH = 0;
UBRRL = 8;

//UCSRA = (1<<U2X);
UCSRA = 0b00000010;
/* Enable receiver and transmitter */
UCSRB=0;
UCSRB = (1<<RXEN)|(1<<TXEN)|(1<<RXCIE); //Interrupcion de recepcion habilitada
/* Set frame format: 8data, 1stop bit */
UCSRC = (1<<URSEL)|(0<<UMSEL)|(0<<UPM1)|(0<<UPM0)|(0<<USBS)|(1<<UCSZ1)|(1<<UCSZ0);
}


void USART_Transmit( unsigned char data )
{
/* Wait for empty transmit buffer */
while ( !(UCSRA & (1<<UDRE)) )
;
/* Put data into buffer, sends the data */
UDR = data;
}


unsigned char USART_Receive( void ){
	/* Wait for data to be received */
	while ( !(UCSRA & (1<<RXC)) );
	/* Get and return received data from buffer */
	return UDR;
}


///************************************************************************
//* USART vacio el BUFFER de recepción
//************************************************************************/
//
void USART_Flush(void) {
	unsigned char	uchDummy;
	unsigned int	uContFlush0 = 0;

	while (UCSRA & (SET<<RXC)) {
		uchDummy = UDR;

		if (uContFlush0 == USART0_BUFFER_ZISE) {
			break;
		}
		uContFlush0 ++;
	}
}


/************************************************************************
* Esperar USART0 para transmitir
************************************************************************/

void Esperar_USART_O_TX (void) {

	uContTimeoutUSART0 = TIMEOUT_USART_0;

	while (!(UCSRA & (SET<<UDRE)) && (uContTimeoutUSART0 != 0));
}



//
///************************************************************************
//* Transmisión BUFFER conpleto por USART0 (de prepo y de corrido)
//************************************************************************/
//

void Transmitir_Buffer_USART0 (char *chBUFFERPtr, int maxBUFFERSize) {

	int i = 0;

	while ((*(chBUFFERPtr + i) != '\0') && (i < (maxBUFFERSize-1))) {
		Esperar_USART_O_TX (); 		/* si el registro de envio esta lleno, esUPE0ro */
		UDR = *(chBUFFERPtr + i);
		i ++;
	}
	Esperar_USART_O_TX (); 			/* si el registro de envio esta lleno, esUPE0ro */
	UDR = '\0';
}
















