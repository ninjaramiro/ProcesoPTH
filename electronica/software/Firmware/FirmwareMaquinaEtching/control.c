/*
 * Control_rutina.c
 *
 *  Created on: 29/10/2013
 *      Author: ninja
 */

#include "estados.h"
#include "USART.h"
#include "macros.h"
#include "inicio.h"
#include "control.h"
#include "configuraciones.h"
#include "eeprom.h"
#include "Botones.h"
#include "estados.h"
#include "main.h"

#include <avr/io.h>

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

extern char		chSTRING_PARAMETROS[USART0_BUFFER_ZISE];	/** buffer de transmisión USART del uc */

extern unsigned char	ucEstadoGeneral;

//Para el beeper
extern unsigned int uContTimeoutBEEP;


//Para modificar las configuraciones
extern unsigned int 				uConfTiempoEtching;
extern unsigned int 				uConfTemperatura;
extern unsigned int 				uConfVelocidad_Motor;

extern unsigned char ucBoton_apretado;
extern unsigned char ucComando_control;
extern unsigned char uContTimeoutALARMA;


unsigned char ucComando_serie;
unsigned int uiParametro;


// Esta funcion recibe datos por puerto serie y modifica el funcionamiento de la máquina con esos datos
void Control_serie(void){

  
// Recepcion de comandos
  
	if (uchEstadoBufferRx_USART0==LLENO){ // Llegó un String de comando
	  ucComando_serie = 0;
	  uiParametro = 0;
	  if((chBufferRx_USART0[0]=='E' || chBufferRx_USART0[0]=='e') && (chBufferRx_USART0[1]=='T' || chBufferRx_USART0[1]=='t')){
	    ucComando_serie = ((chBufferRx_USART0[2]-'0')*10 + (chBufferRx_USART0[3]-'0')); //Transformo los caracteres del comando en un numero	    
	    if (chBufferRx_USART0[4]==' '){ //Si el siguiente caracter es un espacio, entonces viene un parametro
	      uiParametro = (((chBufferRx_USART0[5]-'0')) * 100 + ((chBufferRx_USART0[6]-'0'))*10 + (chBufferRx_USART0[7]-'0')); //Transformo los caracteres del parametro en un numero

	    }
	  }
	    
	uchEstadoBufferRx_USART0 = VACIO; // String leido, vuelvo a activar la recepcion
	}  
	
		switch (ucComando_serie){

		case 01:
		  BEEP(100); //Hace Bip con comando valido
		  ucComando_control = COMANDO_CONTROL_PARAR;
		  uContTimeoutALARMA = 0;
		break;

		case 02:
		  BEEP(100); //Hace Bip con comando valido
		  ucComando_control = COMANDO_CONTROL_INICIO;
		break;

		case 03:
		  ucComando_control = COMANDO_CONTROL_PAUSA;
		break;
  
		case 10:   	//Configuracion del tiempo de etching en segundos de 000 a 999 segundos
		  BEEP(100);    //Hace Bip con comando valido
		  uConfTiempoEtching = uiParametro; 	// Modifica la variable

		  Parametros_a_String ();
		  Guarda_String_en_la_Eeprom ();

		  /******************** Impresion de los estado de deteccion para debug ************************/
		  #ifdef COMPILE_WITH_DEBUG

				  Transmitir_Buffer_USART0 (chSTRING_PARAMETROS, 10);
		  #endif
		  /***********/

		  break;

		case 11:	//Configuracion de temperatura, el parametro es la temperatura en grados
		  BEEP(100); 	//Hace Bip con comando valido
		  uConfTemperatura  = uiParametro; 	// Modifica la variable

		  Parametros_a_String ();  
		  Guarda_String_en_la_Eeprom ();

		  /******************** Impresion de los estado de deteccion para debug ************************/
		  #ifdef COMPILE_WITH_DEBUG
				  Transmitir_Buffer_USART0 (chSTRING_PARAMETROS, 10);
		  #endif
		  /***********/
		  
		  break;
		  
		case 12:	//Configuracion de la velocidad del motor de 000 a 255
		  BEEP(100); 	//Hace Bip con comando valido
		  uConfVelocidad_Motor = uiParametro; 	// Modifica la variable

		  Parametros_a_String ();
		  Guarda_String_en_la_Eeprom ();
		  /******************** Impresion de los estado de deteccion para debug ************************/
		  #ifdef COMPILE_WITH_DEBUG
				  Transmitir_Buffer_USART0 (chSTRING_PARAMETROS, 10);
		  #endif
		  /***********/
		  break;
		  
		default:
		  break;
		}
		ucComando_serie = 0; // Borra el comando
}


