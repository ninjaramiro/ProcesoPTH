/**
* @mainpage Firmware de control de metalización de agujeros pasantes.
* @version  0.1
* @author   FIUBA-LCI-varios
* @date     22-May-2019
* @section intro Descripción
* Un microcontrolador (MCU) ATmga328P controla la direcciOn y magnitud de la corriente aplicada a una celda electrolítica\n
* .\n
* - La pestaNia "MOdulos" agrupa las funciones que manejan la pantalla y las que leen la pelIcula sensible
* - La pestaNia "Archivos" muestra todos los archivos del proyecto.
*
*   \defgroup mod mOdulos
*   \{
*	   \defgroup config	ConfiguraciOn de perifEricos
*      \defgroup user	Interfaz con el usuario
*	   \defgroup ctrl	Control del proceso
*   \}
*   \defgroup ppal Principal
**/

#ifndef MAIN_H_
#define MAIN_H_

#define COMPILE_WITH_DEBUG	/*habilita la compilacion con el modo debug */


// fusibles E:0xFD H:0xDE L:0xFF

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
