/** 	USART.c
 *  	Contiene las maquinas de estados correspondientes a la recepción y a la transmisión 
 *	porUSART del uc.
 */

#include "inicio.h"
#include "USART.h"
#include "macros.h"

#include <avr/io.h>

/*****************************************************************************
* Variables comunes a ambas Máquinas de estados
*****************************************************************************/

unsigned int	uContTimeoutUSART0;			/** contador de timeout para espera del USART */

/*****************************************************************************
* Variables Máquina de estados de recepción
*****************************************************************************/

unsigned char	uchEstadoRecepcionUSART0;				/** variable de la maquina de estados del recepción por USART */
char		chBufferRx_USART0[USART0_BUFFER_ZISE];			/** buffer de recepción USART del uc */
unsigned char	uchEstadoBufferRx_USART0;				/** variable de estado del buffer de recepción del UASART, lleno o vacio */
unsigned char	uchContAuxRx_USART0;					/** contador auxiliar de recepción */

/*****************************************************************************
* Variables Máquina de estados de transmisión
*****************************************************************************/

unsigned char	uchEstadoTransmisionUSART0;				/** variable de la maquina de estados del transmisión por USART */
char		chBufferTx_USART0[USART0_BUFFER_ZISE];		/** buffer de transmisión USART del uc */
unsigned char	uchEstadoBufferTx_USART0;				/** variable de estado del buffer de transmisión del USART, lleno o vacio */
unsigned char	uchContAuxTx_USART0;					/** contador auxiliar de transmisión */



/************************************************************************
* Máquina de estados de recepción por USART del uc
************************************************************************/

void Recepcion_USART_0(void) {
	switch (uchEstadoRecepcionUSART0) {
		case STANDBY_USART0_RX:
			if ((!(UCSRA & (SET<<RXC))) || (uchEstadoBufferRx_USART0 == LLENO)) {
				uchEstadoRecepcionUSART0 = STANDBY_USART0_RX;
			}
			else {
				uchContAuxRx_USART0 = 0;
				uchEstadoRecepcionUSART0 = RECIBIR_USART0;
			}
			break;

		case RECIBIR_USART0:
			if (uchContAuxRx_USART0 == 0) {
				if ((UCSRA&(SET<<FE)) || (UCSRA&(SET<<DOR)) || (UCSRA&(SET<<PE))) {	/* Frame Error (FE), Data OverRun (DOR) and Parity Error (UPE) */
					USART0_Flush();
					uchEstadoBufferRx_USART0 = VACIO;
					uchEstadoRecepcionUSART0 = STANDBY_USART0_RX;
				}
				else {
					chBufferRx_USART0[uchContAuxRx_USART0] = UDR;
					if  ((chBufferRx_USART0[uchContAuxRx_USART0] == '\n') || (chBufferRx_USART0[uchContAuxRx_USART0] == '\r')) {	/* chequeo no haber recibido un \0, sino corto la recepción */
						chBufferRx_USART0[uchContAuxRx_USART0 + 1] = '\0';

						/* escribo el enter */
						Esperar_USART_O_TX ();		/* si el registro de envio esta lleno, espero */
						UDR = '\n';
						Esperar_USART_O_TX ();		/* si el registro de envio esta lleno, espero */
						UDR = '\r';

						uchEstadoBufferRx_USART0 = LLENO;
						uchEstadoRecepcionUSART0 = STANDBY_USART0_RX;
					}
					else {
						/* escribo el caracter que llegó*/
						Esperar_USART_O_TX ();		/* si el registro de envio esta lleno, espero */
						UDR = chBufferRx_USART0[uchContAuxRx_USART0];

						uchContAuxRx_USART0 ++;
						uchEstadoRecepcionUSART0 = RECIBIR_USART0;
					}
				}
			}
			else if (!(UCSRA & (SET<<RXC))) {
				uchEstadoRecepcionUSART0 = RECIBIR_USART0;
			}
			else if (uchContAuxRx_USART0 < (USART0_BUFFER_ZISE-1)) {
				if ((UCSRA&(SET<<FE)) || (UCSRA&(SET<<DOR)) || (UCSRA&(SET<<PE))) {	/* Frame Error (FE), Data OverRun (DOR) and Parity Error (PE) */
					USART0_Flush();
					uchEstadoBufferRx_USART0 = VACIO;
					uchEstadoRecepcionUSART0 = STANDBY_USART0_RX;
				}
				else {
					chBufferRx_USART0[uchContAuxRx_USART0] = UDR;
					if  ((chBufferRx_USART0[uchContAuxRx_USART0] == '\n') || (chBufferRx_USART0[uchContAuxRx_USART0] == '\r')) {	/* chequeo no haber recibido un \0, sino corto la recepción */

						chBufferRx_USART0[uchContAuxRx_USART0 + 1] = '\0';

						/* escribo el enter */
						Esperar_USART_O_TX ();		/* si el registro de envio esta lleno, espero */
						UDR = '\n';
						Esperar_USART_O_TX (); 		/* si el registro de envio esta lleno, espero */
						UDR = '\r';

						uchEstadoBufferRx_USART0 = LLENO;
						uchEstadoRecepcionUSART0 = STANDBY_USART0_RX;
					}
					else {
						/* escribo el caracter que llegó*/
						Esperar_USART_O_TX (); 		/* si el registro de envio esta lleno, espero */
						UDR = chBufferRx_USART0[uchContAuxRx_USART0];

						uchContAuxRx_USART0 ++;
						uchEstadoRecepcionUSART0 = RECIBIR_USART0;
					}
				}
			}
			else if (uchContAuxRx_USART0 == (USART0_BUFFER_ZISE-1)) {
				chBufferRx_USART0[uchContAuxRx_USART0] = '\0';
				uchEstadoBufferRx_USART0 = LLENO;
				uchEstadoRecepcionUSART0 = STANDBY_USART0_RX;
			}
			else {
				uchEstadoRecepcionUSART0 = RECIBIR_USART0;
			}
			break;

		default:
			uchEstadoBufferRx_USART0 = VACIO;
			uchEstadoRecepcionUSART0 = STANDBY_USART0_RX;
			break;
	}
}

/************************************************************************
* Máquina de estados de transmisión por USART del uc
************************************************************************/
void Transmision_USART_0(void) {
	switch (uchEstadoTransmisionUSART0) {
		case STANDBY_USART0_TX:
			if (uchEstadoBufferTx_USART0 == VACIO) {
				uchEstadoTransmisionUSART0 = STANDBY_USART0_TX;
			}
			else {
				uchContAuxTx_USART0 = 0;
				uchEstadoTransmisionUSART0 = TRANSMITIR_USART0;
			}
			break;

		case TRANSMITIR_USART0:
			if ((chBufferTx_USART0[uchContAuxTx_USART0] != '\0') && (uchContAuxTx_USART0 < (USART0_BUFFER_ZISE-1))) {
				if (!( UCSRA & (SET<<UDRE))) {	/* si el registro de envio esta lleno, espero */
					uchEstadoTransmisionUSART0 = TRANSMITIR_USART0;
				}
				else {
					UDR = chBufferTx_USART0[uchContAuxTx_USART0];
					uchContAuxTx_USART0 ++;
					uchEstadoTransmisionUSART0 = TRANSMITIR_USART0;
				}
			}
			else {
				UDR = '\0';
				uchEstadoBufferTx_USART0 = VACIO;
				uchEstadoTransmisionUSART0 = STANDBY_USART0_TX;
			}
			break;

		default:
			uchEstadoBufferTx_USART0 = VACIO;
			uchEstadoTransmisionUSART0 = STANDBY_USART0_TX;
			break;
	}
}

/************************************************************************
* Inicio del USART
************************************************************************/
/* La velocidad de transmisión es de 115,200 kbps, 8 bit de datos, sin control de paridad y 1 bit de parada. */

void Inicio_USART_0 (void) {
	/* cargo el UBRR necesario para el baudrate escogido */
	UBRRH = (UBRR>>8) & BYTE_MASK;
	UBRRL = UBRR & BYTE_MASK;

	/* limpio el flag de transmisión y no multiprocessor mode */
	UCSRA = (OFF<<TXC)|(VALOR_U2X0<<U2X)|(OFF<<MPCM);

	/* deshabilito la interrupción por recepción, por transmisión y por buffer vacio. Habilito la transmisión y la recepicón, 8n bit de datos y pongo en 0 el noveno bit */
	UCSRB = (OFF<<RXCIE)|(OFF<<TXCIE)|(OFF<<UDRIE)|(SET<<RXEN)|(SET<<TXEN)|(OFF<<UCSZ2)|(OFF<<TXB8);

	/* Modo asincronico, sin bit de paridad, un bit de stop, 8 bit de datos */
	UCSRC = (SET<<URSEL)|(OFF<<UMSEL)|(OFF<<UPM1)|(OFF<<UPM0)|(OFF<<USBS)|(SET<<UCSZ1)|(SET<<UCSZ0)|(OFF<<UCPOL);

	uchEstadoBufferRx_USART0 = VACIO;
	uchEstadoBufferTx_USART0 = VACIO;
	
	USART0_Flush();
}

/************************************************************************
* USART vacio el buffer de recepción
************************************************************************/

void USART0_Flush(void) {
	unsigned char	uchDummy;
	unsigned int	uContFlush0 = 0;

	while (UCSRA & (SET<<RXC)) {
		uchDummy = UDR; // Hay que vaciar el buffer para desactivar la interrupción del puerto serie

		if (uContFlush0 == USART0_BUFFER_ZISE) {
			break;
		}
		uContFlush0 ++;
	}
	
}

/************************************************************************
* Transmisión buffer conpleto por USART0 (de prepo y de corrido)
************************************************************************/

void Transmitir_Buffer_USART0 (char *chBufferPtr, int maxBufferSize) {

	int i = 0;

	while ((*(chBufferPtr + i) != '\0') && (i < (maxBufferSize-1))) {
		Esperar_USART_O_TX (); 		/* si el registro de envio esta lleno, espero */
		UDR = *(chBufferPtr + i);
		i ++;
	}
	Esperar_USART_O_TX (); 			/* si el registro de envio esta lleno, espero */
	UDR = '\0';
}


/************************************************************************
* Esperar USART0 para transmitir
************************************************************************/

void Esperar_USART_O_TX (void) {

	uContTimeoutUSART0 = TIMEOUT_USART_0;

	while (!(UCSRA & (SET<<UDRE)) && (uContTimeoutUSART0 != 0));
}

