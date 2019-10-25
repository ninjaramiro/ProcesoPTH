/** \file	USART.h
 *  \brief	Contiene los prototipos de las maquinas de estados correspondiente a la recepción y \n
 *	transmisión por USART.
 */

#ifndef	_USART_H
#define	_USART_H


#include <inttypes.h>

#define TRANSMITIR_NULL_AL_FINAL	/** \brief define si deseo transmitir \0 al final de la transmisión del buffer */
#define TRANSMITIR_ECO				/** \brief define si transmito el eco del caracter recibido */
//#define RECIBIR_NULL_AL_FINAL		/** \brief define si termino la recepción al recibir un \0 o sino cuando recibo \n o \r */



void Inicio_USART(void);


/** \brief	Máquina de estados de recepción por el USART del uc.
 *
 *	Esta máquina de estados verifica permanentemente el comienzo de recepción de un mensaje por USART. \n
 *	En caso de que el buffer de recepción se encuentre lleno espera a que este se vacíe para comenzar a recibir. \n
 *	La máquina va recibiendo y llenando el buffer de recepción hasta que se reciba un caracter NULL ('\0') o se llegue \n
 *	máximo espacio asignado al buffer de recepción. \n
 *	Cuendo da por finalizada la recepción marca al buffer de recepción como lleno para su posterior procesamiento en otra \n
 *	máquina de estados.
 */
void Recepcion_USART_0(void);

/** \brief	Máquina de estados de transmisión por el USART del uc.
 *
 *	Esta máquina de estados al detectar el flag de buffer de transmisión lleno comienza el envío de la información. \n
 *	El envío se da por finalizado al encontrar el primer caracter NULL ('\0') o al llegar a la máxima dimensión permitida \n
 *	del buffer, por lo que se trunca el mensaje y de agrega un caracter NULL al final. Una vez enviado el mensaje se marca como \n
 *	vacio el buffer.
 */

void USART_Transmit( unsigned char data );

void Esperar_USART_O_TX (void);

unsigned char USART_Receive( void );



void Transmision_USART_0(void);

/** \brief	USART0 vacio el buffer de recepción.
 *
 *	Purga cualquir cosa que pueda haber quedado en el buffer de recepción.
 */
void USART0_Flush(void);

/** \brief	USART0 fuerzo la transmisión del buffer completo.
 *
 *	Fuerza la transmisión del buffer completo de corrido hasta '\0' o hasta el tamaño máximo del buffer indicado \n
 *	para el cual trunca la transmisión y la termina con \'0'.
 *	\param[in] char *chBufferPtr, puntero al buffer a transmitir.
 *	\param[in] int maxBufferSize, máximo tamaño del buffer a transmitir.
 */
void Transmitir_Buffer_USART0 (char *chBufferPtr, int maxBufferSize);




#define USART0_BUFFER_ZISE	30	/**< \brief tamaño máximo del buffer de datos del USART */
#define TIMEOUT_USART_0		30	/**< \brief timepo de timeout de espera para USART en milesimas segundo (timer2) */

/*****************************************************************************
* Definiciones máquina de estado de recepción
*****************************************************************************/
#define	 STANDBY_USART0_RX	02
#define	 RECIBIR_USART0		1

/*****************************************************************************
* Definiciones máquina de estado de transmisión
*****************************************************************************/
#define	 STANDBY_USART0_TX	0
#define	 TRANSMITIR_USART0	1

#endif /* _USART_H */
