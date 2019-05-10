/** 	eeprom.h
 *  	Contiene los prototipos de las funciones para el manejo de datos desde y hacia la eeprom.
 */

#ifndef EEPROM_H_
#define EEPROM_H_

/*****************************************************************************
* Prototipos
*****************************************************************************/

void Carga_String_Desde_Eeprom (void);


void Guarda_String_en_la_Eeprom (void);


void UnsignedInt_a_Eeprom (unsigned int *uEepromPtr, unsigned int *uDatoEscritoPtr);


void Eeprom_a_UnsignedInt (unsigned int *uEepromPtr, unsigned int *uDatoLeidoPtr);

void Char_a_Eeprom (char *chEepromPtr, char *chDatoEscritoPtr);

void Eeprom_a_Char (char *chEepromPtr, char *chDatoLeidoPtr);


unsigned int Calculo_Checksum (char *flInicioEepromPtr, unsigned int *uChecksumEepromPtr);

unsigned int Char_a_Checksum (char *chDatoPtr);

void Escribir_Checksum_Eeprom (char chGrupo);

void Cargar_Datos_Original (void);

void Cargar_Datos_Backup (void);

void Copio_Buffer_a_Variables (void);

/*****************************************************************************
* Definiciones varias
*****************************************************************************/

#define 	CANT_INTENTOS_ESCRITURA_EEPROM		100	/**< \brief cantidad máxima de intentos de escritura en eeprom */
#define 	CANT_INTENTOS_LECTURA_EEPROM		100	/**< \brief cantidad máxima de intentos de lectura de eeprom */
#define 	CANT_INTENTOS_VALIDACION_CHECKSUM	10	/**< \brief cantidad de intentos de validar el checksum en caso de dar error en la integridad de datos */

/*****************************************************************************
* Definiciones de valores por defecto
*****************************************************************************/

#define 	CHECKSUM_EEPROM			10000			/**< \brief valor cualquiera de inicio de checksum para que sea distinto que 0 */
#define 	BUFFER_EERPOM			20				/**< \brief tamaño de los buffers para lectura y ecritura de eeprom */

/* grupos de checksum */
#define 	GRUPO_CONFIGURACION	1				/**< \brief grupo 1 para el cual se calcula el checksum */

/* GRUPO_CONFIGURACION */
#define	MODO_OPERACION_DEFAULT		MODO_STANDBY	/**< \brief modo de operación por defecto */


#endif /* EEPROM_H_ */
