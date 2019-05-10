/*
 * estados.c
 *
 *  Created on: 29/10/2013
 *      Author: ninja
 */

#include "estados.h"
#include "USART.h"
#include "macros.h"
#include "inicio.h"
#include "main.h"


#include <avr/io.h>


unsigned char 					ucEstadoGeneral;
unsigned int 					uTiempoEtching;
unsigned int 					uTiempoEtching_BACKUP;
unsigned char 					ucComando_control;

// PARA LA TRANSMISION DEL PUERTO SERIE
extern unsigned char	uchEstadoTransmisionUSART0;			/** variable de la maquina de estados del transmisión por USART */
extern char		chBufferTx_USART0[USART0_BUFFER_ZISE];		/** buffer de transmisión USART del uc */
extern unsigned char	uchEstadoBufferTx_USART0;			/** variable de estado del buffer de transmisión del USART, lleno o vacio */
extern unsigned char	uchContAuxTx_USART0;				/** contador auxiliar de transmisión */


extern unsigned char uContTimeoutALARMA;
extern unsigned int 				uConfTiempoEtching;
extern unsigned int 				uConfTemperatura;
extern unsigned int 				uConfVelocidad_Motor;

extern uint32_t uiTemp1;
extern uint32_t uiTemp2;



void Maq_estados(void){

// #define 	Detenido_Standby	0
// #define	Estado_Inicio		1
// #define 	Elevando_Temp		2
// #define 	Etching 		3
// #define	Estado_Pausa		4
  
	switch (ucEstadoGeneral){

		case Detenido_Standby:
		  pwm(0);
		  CLEAR_BIT(RESISTENCIA_PORT, RESISTENCIA);	
		  if (ucComando_control == COMANDO_CONTROL_INICIO){ //Si recibo un comando para iniciar el proceso
		    ucEstadoGeneral = Elevando_Temp;
		    ucComando_control = COMANDO_CONTROL_NINGUNO;
		  }
		  break;

		case Elevando_Temp:
		  if (ucComando_control == COMANDO_CONTROL_PARAR){ //Si recibo un comando para detener el proceso
		    ucEstadoGeneral = Detenido_Standby;
		    ucComando_control = COMANDO_CONTROL_NINGUNO;
		  }	  		  
		  if (uiTemp1 > uConfTemperatura){ //Si llego a la temperatura deseada
		  uTiempoEtching = uConfTiempoEtching;
		  ucEstadoGeneral = Etching;		    
		  }
		  
		  
		  break;

		case Etching:
		  if (ucComando_control == COMANDO_CONTROL_PARAR){ //Si recibo un comando para detener el proceso
		    ucEstadoGeneral = Detenido_Standby;
		    ucComando_control = COMANDO_CONTROL_NINGUNO;
		  }

		  if (ucComando_control == COMANDO_CONTROL_PAUSA){ //Si recibo un comando para pausar el proceso
		    uTiempoEtching_BACKUP = uTiempoEtching;
		    ucEstadoGeneral = Estado_Pausa;
		    ucComando_control = COMANDO_CONTROL_NINGUNO;
		  }
		  
		  pwm(uConfVelocidad_Motor)
		  ;
		  if (uTiempoEtching == 0){
		    ucEstadoGeneral = Detenido_Standby; 
		    uContTimeoutALARMA = DURACION_ALARMA;
		    pwm(0);
		  }
		    
		  break;

		case Estado_Pausa: // Apaga motores, pero mantiene la temperatura
		  pwm(0);
		  
		  if (ucComando_control == COMANDO_CONTROL_PARAR){ //Si recibo un comando para detener el proceso
		    ucEstadoGeneral = Detenido_Standby;
		    ucComando_control = COMANDO_CONTROL_NINGUNO;
		  }	  

		  if (ucComando_control == COMANDO_CONTROL_PAUSA){ //Si recibo un comando para salir de la pausa
		    
		    ucEstadoGeneral = Etching;
		    ucComando_control = COMANDO_CONTROL_NINGUNO;
		  }		  

		  break;
		  
		default:
		  pwm(0);
		  CLEAR_BIT(RESISTENCIA_PORT, RESISTENCIA);		  
		  break;		    
	}
}


void Control_Temperatura(void){
  
    if(ucEstadoGeneral == Elevando_Temp || ucEstadoGeneral == Etching || ucEstadoGeneral ==Estado_Pausa){ // Estados que mantienen la temperatura
	  if (uiTemp1 > (uConfTemperatura+DELTA_TEMP)){ //Si llego a la temperatura maxima
	    CLEAR_BIT(RESISTENCIA_PORT, RESISTENCIA);   //Apago la resistencia
	  }
	  if (uiTemp1 < (uConfTemperatura-DELTA_TEMP)){ //Si llego a la temperatura minima
	    SET_BIT(RESISTENCIA_PORT, RESISTENCIA);     //Enciendo la resistencia
	  }
    }
    else {	
      CLEAR_BIT(RESISTENCIA_PORT, RESISTENCIA);     
    }

}
