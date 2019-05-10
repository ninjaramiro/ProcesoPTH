
/** 	eeprom.c
 *  	Contiene las funciones para el manejo de datos desde y hacia la eeprom.
 */

#include "eeprom.h"
#include "macros.h"
#include "inicio.h"
#include "main.h"
#include "USART.h"

#include <avr/io.h>
#include <inttypes.h>
#include <avr/eeprom.h>
#include <avr/wdt.h>
#include <avr/interrupt.h>


/*****************************************************************************
* Variables
*****************************************************************************/

unsigned int	uCRC;							/**  Checksum */
unsigned int	uCRC_Eeprom;						/**  Checksum eeprom */
unsigned int	uCRC_BK;						/**  Checksum backup */
unsigned int	uCRC_Eeprom_BK;						/**  Checksum eeprom backup */

char		chBufferEeprom[BUFFER_EERPOM];				/**  buffer de variables char para lectura y escritur de eeprom */
unsigned int 	uContIntentosValidacionChecksum;			/**  contador de intentos de validación del checksum */

/* Variables externas */
/* Variables a guardar en la eeprom */
extern char chSTRING_PARAMETROS[LONG_STRING_EPROM];		



// PARA LA RECEPCION DEL PUERTO SERIE
extern unsigned char	uchEstadoRecepcionUSART0;			/** variable de la maquina de estados del recepción por USART */
extern char		chBufferRx_USART0[USART0_BUFFER_ZISE];		/** buffer de recepción USART del uc */
extern unsigned char	uchEstadoBufferRx_USART0;			/** variable de estado del buffer de recepción del UASART, lleno o vacio */
extern unsigned char	uchContAuxRx_USART0;				/** contador auxiliar de recepción */

// PARA LA TRANSMISION DEL PUERTO SERIE
extern unsigned char	uchEstadoTransmisionUSART0;			/** variable de la maquina de estados del transmisión por USART */
extern char		chBufferTx_USART0[USART0_BUFFER_ZISE];		/** buffer de transmisión USART del uc */
extern unsigned char	uchEstadoBufferTx_USART0;			/** variable de estado del buffer de transmisión del USART, lleno o vacio */
extern unsigned char	uchContAuxTx_USART0;				/** contador auxiliar de transmisión */







/*****************************************************************************
* Variables en eeprom
*****************************************************************************/

/* asigno para cada veriable un lugar en la eeprom  y le doy un valor por defecto para el inicio despues de grabar el uc */

/*  Variables en la eeprom */
char			chSTRING_PARAMETROSEeprom[LONG_STRING_EPROM]		EEMEM;				/**  cadena de caracteres con el string. Guardado en la eeprom */
unsigned int		uChecksumEeprom 					EEMEM = CHECKSUM_EEPROM;	/**  checksum de datos en eeprom de llenado de tanque, lo inicializo con basura */

/*****************************************************************************
* Variables en eeprom, copias de back up
*****************************************************************************/

/* asigno para cada veriable de backup un lugar en la eeprom  y le doy un valor por defecto para el inicio despues de grabar el uc */

/* Variables de backup en la eeprom */
char			chSTRING_PARAMETROSEeprom_BK[LONG_STRING_EPROM]		EEMEM;				/**  cadena de caracteres con el string. Guardado en la eeprom */
unsigned int		uChecksumEeprom_BK 					EEMEM = CHECKSUM_EEPROM;	/**  checksum de datos en eeprom de llenado de tanque, lo inicializo con basura */

/*----------------------------------*/
float			flDireccionVaciaEeprom					EEMEM;				/**  dirección vacia en la eeprom por si hay un error y se modifica algo, siempre dejo apuntado a ella */


/*****************************************************************************
* Funcion de carga de variables desde eeprom al inicio
*****************************************************************************/

void Carga_String_Desde_Eeprom (void) {
	uContIntentosValidacionChecksum = 0;


	while (uContIntentosValidacionChecksum <= CANT_INTENTOS_VALIDACION_CHECKSUM) {


	  
		Cargar_Datos_Original();


		  	
	
		if (uCRC == uCRC_Eeprom) {	//Datos Originales Ok													/* si esta bien el original paso los valores a las variables y verifico la copia */



		  
			Copio_Buffer_a_Variables();

			Cargar_Datos_Backup();

			if (uCRC_BK != uCRC_Eeprom_BK) {	/* si la copia da mal, copio los valores del original a la copia */

			  
			  
				int i=0;
				for (i=0; i<LONG_STRING_EPROM; i++)
					Char_a_Eeprom(&chSTRING_PARAMETROSEeprom_BK[i], &chSTRING_PARAMETROS[i]);

				UnsignedInt_a_Eeprom (&uChecksumEeprom_BK, &uCRC);
			}
			else {		//Datos backup OK
			  /* si la copia esta bien también no hago nada */


			}
			break;
		}
		else {	//Error en los datos originales . Si el original da mal, verifico la copia */

			  
			Cargar_Datos_Backup();

			if (uCRC_BK == uCRC_Eeprom_BK) {	/* si la copia da bien, copio los valores de la copia al original y a las variables */

				Copio_Buffer_a_Variables();

				int i=0;
				for (i=0; i<LONG_STRING_EPROM; i++)
					Char_a_Eeprom(&chSTRING_PARAMETROSEeprom[i], &chSTRING_PARAMETROS[i]);

				UnsignedInt_a_Eeprom (&uChecksumEeprom, &uCRC_BK);
				break;
			}
			else {		/* si ambas dan mal inicializo a valores por defecto */

				if (uContIntentosValidacionChecksum < CANT_INTENTOS_VALIDACION_CHECKSUM) {
					uContIntentosValidacionChecksum ++;
					continue;
				}
				else {  // Cargo los datos de originales, por ahora '\0'
					int i=0;
					
					for (i=0; i<LONG_STRING_EPROM; i++){
						Char_a_Eeprom(&chSTRING_PARAMETROSEeprom[i], &chSTRING_PARAMETROS[i]);
						Char_a_Eeprom(&chSTRING_PARAMETROSEeprom_BK[i], &chSTRING_PARAMETROS[i]);
					}

					Escribir_Checksum_Eeprom (GRUPO_CONFIGURACION);
					break;
				}
			}
		}
	}
}

/*****************************************************************************
* Funcion que guarda el string de parametros en la eeprom
*****************************************************************************/
void Guarda_String_en_la_Eeprom (void){
	int i=0;
	for (i=0; i<LONG_STRING_EPROM; i++){							/* grabo el nuevo numero en la eeprom */
		Char_a_Eeprom(&chSTRING_PARAMETROSEeprom[i], &chSTRING_PARAMETROS[i]);		/* grabo original */
		Char_a_Eeprom(&chSTRING_PARAMETROSEeprom_BK[i], &chSTRING_PARAMETROS[i]);	/* grabo backup */
	}
	Escribir_Checksum_Eeprom (GRUPO_CONFIGURACION);
	

}



/*****************************************************************************
* Copio buffer a variables, solo para optimizar codigo
*****************************************************************************/
void Copio_Buffer_a_Variables (void) {
	int i=0;
	for (i=0; i<LONG_STRING_EPROM; i++)
		chSTRING_PARAMETROS[i] = chBufferEeprom[i];
}

/*****************************************************************************
* Carga los datos originales y checksum, solo para optimizar codigo
*****************************************************************************/

void Cargar_Datos_Original (void) {
					
	int i=0;
	uCRC = 0;
	for (i=0; i<LONG_STRING_EPROM; i++){
		Eeprom_a_Char(&chSTRING_PARAMETROSEeprom[i], &chBufferEeprom[i]);		/* leeo los valores originales de la eeprom */
		uCRC += Char_a_Checksum(&chBufferEeprom[i]);					/* calculo el checksum de los valores lebantados a la ram */
	}

	Eeprom_a_UnsignedInt (&uChecksumEeprom, &uCRC_Eeprom);					/* levanto el checksum de la eeprom */
}

/*****************************************************************************
* Carga los datos de backup y checksum, solo para optimizar codigo
*****************************************************************************/

void Cargar_Datos_Backup (void) {

	int i=0;
	uCRC_BK = 0;
	
	for (i=0; i<LONG_STRING_EPROM; i++){
		Eeprom_a_Char(&chSTRING_PARAMETROSEeprom_BK[i], &chBufferEeprom[i]);		/* leeo los valores originales de la eeprom */
		uCRC_BK += Char_a_Checksum(&chBufferEeprom[i]);				/* calculo el checksum de los valores lebantados a la ram */
	}

	Eeprom_a_UnsignedInt (&uChecksumEeprom_BK, &uCRC_Eeprom_BK);				/* levanto el checksum de la eeprom */
}

/*****************************************************************************
* Actualiza en checksum del original y de la copia de la eeprom
*****************************************************************************/

void Escribir_Checksum_Eeprom (char chGrupo) {
	unsigned int uChecksum = 0;


	if (chGrupo == GRUPO_CONFIGURACION) { /* -1- */
		int i=0;
		for (i=0; i<LONG_STRING_EPROM; i++)
			uChecksum += Char_a_Checksum(&chSTRING_PARAMETROS[i]);
		
		// Guardo el checksum en la eeprom para el original y el backup
		UnsignedInt_a_Eeprom (&uChecksumEeprom, &uChecksum); 
		UnsignedInt_a_Eeprom (&uChecksumEeprom_BK, &uChecksum);
	}
}

/*****************************************************************************
* Calcula el checksum de un char
*****************************************************************************/

unsigned int Char_a_Checksum (char *chDatoPtr) {
	unsigned int *uDatoPtr = (unsigned int *) chDatoPtr;
	unsigned int CRC;

	CRC = *uDatoPtr & BYTE_MASK; //And binario entre el dato y 0x000000FF

	return CRC;
}


/*****************************************************************************
* Funcion de escritura de un char a la eeprom
*****************************************************************************/

void Char_a_Eeprom (char *chEepromPtr, char *chDatoEscritoPtr) {
	int i = 0;
	char chDatoLeido;

	while (i < CANT_INTENTOS_ESCRITURA_EEPROM) {
		wdt_reset();
		eeprom_busy_wait ();
		cli();
		eeprom_write_byte ((uint8_t *) chEepromPtr, *chDatoEscritoPtr); // Escribe byte
		sei();
		eeprom_busy_wait ();
		cli();
		chDatoLeido = eeprom_read_byte ((uint8_t *) chEepromPtr); 	// Lee byte
		(chDatoLeido == *chDatoEscritoPtr) ? (i = CANT_INTENTOS_ESCRITURA_EEPROM + 1) : (i ++);  //Comparo lo que leí con lo que grabé
	}
	
	EEAR = (uint16_t) &flDireccionVaciaEeprom;  // Dejo la eeprom apuntando a una direccion vacía por si hay un error que escriba en la eeprom
}

/*****************************************************************************
* Funcion de lectura de un char de la eeprom
*****************************************************************************/

void Eeprom_a_Char (char *chEepromPtr, char *chDatoLeidoPtr) {
	int i = 0;
	char chDatoLeido2;

	while (i < CANT_INTENTOS_ESCRITURA_EEPROM) {  // En cada ciclo lee 2 veces la misma direccion en laa eeprom
		wdt_reset();
		eeprom_busy_wait ();
		cli();  // Deshabilita interrupciones
		*chDatoLeidoPtr = eeprom_read_byte ((uint8_t *) chEepromPtr);
		sei();	// Habilita interrupciones
		eeprom_busy_wait ();
		cli();	// Deshabilita interrupciones
		chDatoLeido2 = eeprom_read_byte ((uint8_t *) chEepromPtr);
		(*chDatoLeidoPtr == chDatoLeido2) ? (i = CANT_INTENTOS_ESCRITURA_EEPROM + 1) : (i ++);  // Si las dos lecturas son iguales entonces salgo del while
	}

	EEAR = (uint16_t) &flDireccionVaciaEeprom;
}


/*****************************************************************************
* Funcion de escritura de un unsigned int a la eeprom
*****************************************************************************/

void UnsignedInt_a_Eeprom (unsigned int *uEepromPtr, unsigned int *uDatoEscritoPtr) {
	int i = 0;
	unsigned int uDatoLeido;

	while (i < CANT_INTENTOS_ESCRITURA_EEPROM) {
		wdt_reset();
		eeprom_busy_wait ();
		cli();
		eeprom_write_word ((uint16_t *) uEepromPtr, *uDatoEscritoPtr);
		sei();
		eeprom_busy_wait ();
		cli();
		uDatoLeido = eeprom_read_word ((uint16_t *) uEepromPtr);
		sei();
		(uDatoLeido == *uDatoEscritoPtr) ? (i = CANT_INTENTOS_ESCRITURA_EEPROM + 1) : (i ++);
	}

	EEAR = (uint16_t) &flDireccionVaciaEeprom;
}

/*****************************************************************************
* Funcion de lectura de un unsigned int a la eeprom
*****************************************************************************/

void Eeprom_a_UnsignedInt (unsigned int *uEepromPtr, unsigned int *uDatoLeidoPtr) {
	int i = 0;
	unsigned int uDatoLeido2;

	while (i < CANT_INTENTOS_ESCRITURA_EEPROM) {
		wdt_reset();
		eeprom_busy_wait ();
		cli();
		*uDatoLeidoPtr = eeprom_read_word ((uint16_t *) uEepromPtr);
		sei();
		eeprom_busy_wait ();
		cli();
		uDatoLeido2 = eeprom_read_word ((uint16_t *) uEepromPtr);
		sei();
		(*uDatoLeidoPtr == uDatoLeido2) ? (i = CANT_INTENTOS_ESCRITURA_EEPROM + 1) : (i ++);
	}

	EEAR = (uint16_t) &flDireccionVaciaEeprom;
}

