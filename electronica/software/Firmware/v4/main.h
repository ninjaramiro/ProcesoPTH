/** 	main.h
 *
 */

#ifndef MAIN_H_
#define MAIN_H_


#define COMPILE_WITH_DEBUG	/*habilita la compilacion con el modo debug */

#define F_CPU 8000000

/*****************************************************************************
* Definiciones
*****************************************************************************/

/* String que voy a almacenar en la EEPROM con la configuracion
 * 3 chars → segundos de tiempo_etching (Segundos)
 * 3 chars → setpoint de la temperatura (Grados)
 * 3 chars → velocidad del motor
 */
#define LONG_STRING_EPROM 9

#define DURACION_ALARMA 30  	// SEGUNDOS
#define PERIODO_ALARMA 1000 	// MILISEGUNDOS
#define BEEP_ALARMA 200		//MILISEGUNDOS


#endif /* MAIN_H_ */
