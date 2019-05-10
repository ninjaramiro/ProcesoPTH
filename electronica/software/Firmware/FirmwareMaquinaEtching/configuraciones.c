/** 	configuraciones.c
 *  	Contiene las funciones que manejan la configuracion. 
 */

#include "inicio.h"
#include "macros.h"
#include "USART.h"
#include "eeprom.h"
#include "configuraciones.h"
#include "main.h"

#include <avr/io.h>

// Variables de configuracion
unsigned int 			uConfTiempoEtching;
unsigned int 			uConfTemperatura;
unsigned int 			uConfVelocidad_Motor;


/* String que voy a almacenar en la EEPROM con la configuracion
 * 3 chars → segundos de tiempo_etching (Segundos)
 * 3 chars → setpoint de la temperatura (Grados)
 * 3 chars → velocidad del motor
 */


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

extern char chSTRING_PARAMETROS[LONG_STRING_EPROM]; //Definido en main.h		

/************************************************************************
* Carga la configuracion del equipo al encenderse
************************************************************************/
void Configuracion_Inicial (void) {

//Cargo los valores definidos en el firmware en configuraciones.h
  uConfTiempoEtching   =  TIEMPO_ETCHING_DEFECTO;
  uConfTemperatura     =  TEMPERATURA_DEFECTO;
  uConfVelocidad_Motor = VELOCIDAD_DEFECTO;

  Parametros_a_String(); // Cargo el string con los valores por defecto

  Carga_String_Desde_Eeprom ();  // Carga las configuraciones de la EEPROM, y si no están ahí carga la EEPROM con la configuracion por defecto
  String_a_Parametros(); 	 // Actualizo los parametros con el String de la eeprom
  
}

void String_a_Parametros (void) {
uConfTiempoEtching = (chSTRING_PARAMETROS[0]-'0')*100 + (chSTRING_PARAMETROS[1]-'0')*10 + (chSTRING_PARAMETROS[2]-'0');
uConfTemperatura = (chSTRING_PARAMETROS[3]-'0')*100 + (chSTRING_PARAMETROS[4]-'0')*10 + (chSTRING_PARAMETROS[5]-'0');
uConfVelocidad_Motor = (chSTRING_PARAMETROS[6]-'0')*100 + (chSTRING_PARAMETROS[7]-'0')*10 + (chSTRING_PARAMETROS[8]-'0');
}

void Parametros_a_String (void) {

unsigned int uAuxTiempoEtching = uConfTiempoEtching;
unsigned int uAuxTemperatura = uConfTemperatura;
unsigned int uAuxVelocidad = uConfVelocidad_Motor;
unsigned int aux;

aux = uAuxTiempoEtching /100;
chSTRING_PARAMETROS[0] = aux + '0';
uAuxTiempoEtching = uAuxTiempoEtching-(aux * 100);
aux = uAuxTiempoEtching /10;
chSTRING_PARAMETROS[1] = aux + '0';
uAuxTiempoEtching = uAuxTiempoEtching-(aux * 10);
chSTRING_PARAMETROS[2] = (uAuxTiempoEtching+'0');

aux = uAuxTemperatura /100;
chSTRING_PARAMETROS[3] = aux + '0';
uAuxTemperatura = uAuxTemperatura-(aux * 100);
aux = uAuxTemperatura /10;
chSTRING_PARAMETROS[4] = aux + '0';
uAuxTemperatura = uAuxTemperatura-(aux * 10);
chSTRING_PARAMETROS[5] = (uAuxTemperatura+'0');

aux = uAuxVelocidad /100;
chSTRING_PARAMETROS[6] = aux + '0';
uAuxVelocidad = uAuxVelocidad-(aux * 100);
aux = uAuxVelocidad /10;
chSTRING_PARAMETROS[7] = aux + '0';
uAuxVelocidad = uAuxVelocidad-(aux * 10);
chSTRING_PARAMETROS[8] = (uAuxVelocidad+'0');

}

