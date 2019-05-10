

#ifndef MACROS_H_
#define MACROS_H_

/*****************************************************************************
* Defniciones varias
*****************************************************************************/
/* mascaras */
/*--------------------------------------------------------------------------*/
#define	BIT_0_MASK			1				/**  mascara para tomar el primer bit */
#define	BIT_1_MASK			2				/**  mascara para tomar el segundo bit */
#define	BIT_2_MASK			4				/**  mascara para tomar el tercer bit */
#define	BIT_3_MASK			8				/**  mascara para tomar el primer bit */
#define	BIT_4_MASK			16				/**  mascara para tomar el segundo bit */
#define	BIT_5_MASK			32				/**  mascara para tomar el tercer bit */
#define	BIT_6_MASK			64				/**  mascara para tomar el segundo bit */
#define	BIT_7_MASK			128				/**  mascara para tomar el tercer bit */




#define NIBBLE_MASK			0x0F			/**   mascara para tomar el primer nibble */
#define UPPER_NIBBLE_MASK	0xF0				/**   mascara para tomar el segundo nibble */
#define	BYTE_MASK			0x000000FF		/**   mascara para tomar el primer byte */
#define TWO_BYTE_MASK		0x0000FFFF			/**   mascara para tomar dos bytes */
#define NUM_MASK			0x000003FF		/**   mascara para detectar solo presion de numeros en un teclado matricial representados cada uno con un bit */

/* otras */
/*--------------------------------------------------------------------------*/
//#define	F_CPU				8000000UL	/**   frecuencia del oscilador en Hz */
//#define	DE_MILESIMA_A_SEG	0.001f			/**  pasaje de 1mseg a seg para el contador de tiempo */
//#define	DE_SEG_A_MILESIMA	1000.0f			/**  pasaje de seg a 1mseg */

/* Definiciones previas */
/*--------------------------------------------------------------------------*/

#define	ERROR	1
#define OK	0

#define	SET	1
#define	CLEAR	0

#define	HIGH	1
#define	LOW	0

#define	ON	1
#define	OFF	0

#define	SI	1
#define	NO	0

#define	LLENO	1
#define	VACIO	0

#define	OCUPADO	1
#define	LIBRE	0

#define ABRIR	2
#define CERRAR	3

#define	CERO	0x00
#define	UNOS	0xFF

#define	ENTRADA	0
#define	SALIDA	1

/*****************************************************************************
* Defnición de macros
*****************************************************************************/
// 
// #define	BEEP(Tiempo_ms)		uContTimeoutBEEP = Tiempo_ms
// #define pwm(valor) OCR1A=valor; // Duty cycle  para el PWM
//



/** Activa un bit determinado en el registro.
 */
#define	SET_BIT(registro, bitNumero)		registro |= (SET<<bitNumero)

/** Pasiva un bit determinado en n registro.
 */
#define	CLEAR_BIT(registro, bitNumero)		registro &= ~(SET<<bitNumero)

/**  Define la dirección de un pin determinado de un puerto.
 */
#define	DIRECCION_PIN(DDR_puerto, pinNumero, direccion)	if (direccion == SALIDA) { DDR_puerto |= (SALIDA<<pinNumero); } else { DDR_puerto &= ~(SALIDA<<pinNumero); }	\

/**  Activa o desactiba el pull up de un pin determiando de entrada.
 */
#define	PULL_UP_PIN(puerto, pinNumero, pullUp)	if (pullUp == ON) { puerto |= (ON<<pinNumero); } else { puerto &= ~(ON<<pinNumero);	}	\

/**  Retardos.
 */
#define NO_OPERATION	for (unsigned int uRet = 2; uRet != 0; uRet--)

//#define	RETARDO_1		for (unsigned int uRet = 4000; uRet != 0; uRet--)
//
//#define	RETARDO_5		for (unsigned int uRet = 20000; uRet != 0; uRet--)
//
//#define	RETARDO_10		for (unsigned int uRet = 40000; uRet != 0; uRet--)
//
//#define	RETARDO_15		for (unsigned int uRet = 60000; uRet != 0; uRet--)




#endif /* MACROS_H_ */
