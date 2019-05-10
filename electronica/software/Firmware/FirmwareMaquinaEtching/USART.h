/**	USART.h
 *	Contiene los prototipos de las maquinas de estados correspondiente a la recepción y 
 *	transmisión por USART.
 */

#ifndef	_USART_H
#define	_USART_H

/*****************************************************************************
* Prototipos
*****************************************************************************/
void Inicio_USART_0 (void);
void Recepcion_USART_0(void);
void Transmision_USART_0(void);
void USART0_Flush(void);
void Transmitir_Buffer_USART0 (char *chBufferPtr, int maxBufferSize);
void Esperar_USART_O_TX (void);

/*****************************************************************************
* Definiciones varias
*****************************************************************************/
#define	UBRR			8	/** UBRR para una velocidad de transmisión de 115200bps con: fosc = 8MHz, U2X = 1 */
#define VALOR_U2X0		1
#define	USART0_BUFFER_ZISE	100	/** tamaño máximo del buffer de datos del USART */
#define TIMEOUT_USART_0		10	/** timepo de timeout de espera para USART en milesimas segundo (timer2) */

/*****************************************************************************
* Definiciones máquina de estado de recepción
*****************************************************************************/
#define	STANDBY_USART0_RX	0
#define	RECIBIR_USART0		1

/*****************************************************************************
* Definiciones máquina de estado de transmisión
*****************************************************************************/
#define	STANDBY_USART0_TX	0
#define	TRANSMITIR_USART0	1

#endif /* _USART_H */
