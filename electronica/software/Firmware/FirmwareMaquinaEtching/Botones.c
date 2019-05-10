

#include "macros.h"
#include "inicio.h"
#include "USART.h"
#include "Botones.h"
#include "control.h"
#include "estados.h"
#include "main.h"

#include <avr/io.h>
#include <stdint.h>

/*****************************************************************************
* Variables externas
*****************************************************************************/
#ifdef COMPILE_WITH_DEBUG
extern char	chBufferTx_USART0[USART0_BUFFER_ZISE];				/* USART.c, buffer de transmisión USART del uc */
#endif

/*****************************************************************************
* Mensajes para debug en memoria de programa
*****************************************************************************/



unsigned char 	ucTiempoAntirrebote;
unsigned char ucEstadoBotones;
unsigned char ucBoton_apretado;

//Para el beeper
extern unsigned int uContTimeoutBEEP;
extern unsigned char ucComando_control;
extern unsigned char uContTimeoutALARMA;


void Botones(void) {

  
    	switch (ucEstadoBotones){
	  
	  case Esperando:
	    if (bit_is_clear(BOTON_INICIO_PIN, BOTON_INICIO) || bit_is_clear(BOTON_PARAR_PIN, BOTON_PARAR) || bit_is_clear(BOTON_PAUSA_PIN, BOTON_PAUSA)) {
	      //Ejecuto si aprietan un boton
	      ucEstadoBotones = Boton_apretado;
	      ucTiempoAntirrebote = ANTIRREBOTE_MS;
	    }
	    break;
	    
	  case Boton_apretado:
	    if (ucTiempoAntirrebote == 0) { //Si pasó el tiempo del antirrebote
	      if(bit_is_clear(BOTON_INICIO_PIN, BOTON_INICIO)){  //Si sigue estándo apretado el boton INICIO
		ucComando_control = COMANDO_CONTROL_INICIO;
		uContTimeoutALARMA = 0;
		BEEP(100); 
	      }
	      else if(bit_is_clear(BOTON_INICIO_PIN, BOTON_PARAR)){  //Si sigue estándo apretado el boton PARAR
		ucComando_control = COMANDO_CONTROL_PARAR;
		uContTimeoutALARMA = 0;
		BEEP(100); 
	      }
	      else if(bit_is_clear(BOTON_INICIO_PIN, BOTON_PAUSA)){  //Si sigue estándo apretado el boton PAUSA
		ucComando_control = COMANDO_CONTROL_PAUSA;
		uContTimeoutALARMA = 0;
		BEEP(100); 
	      }
	      else{
		ucComando_control = COMANDO_CONTROL_NINGUNO;  //Si no hay botones apretados
		ucEstadoBotones = Esperando; //Vuelvo al estado de prueba
	      }
	      ucEstadoBotones = Boton_soltando;
	    }    
	    break;
	    
	  case Boton_soltando:
	    if (bit_is_set(BOTON_INICIO_PIN, BOTON_INICIO) && bit_is_set(BOTON_PARAR_PIN, BOTON_PARAR) && bit_is_set(BOTON_PAUSA_PIN, BOTON_PAUSA)) {
	      ucEstadoBotones = Botones_sueltos;
	      ucTiempoAntirrebote = ANTIRREBOTE_MS;
	    }	    
	  break;
	  
	  case Botones_sueltos: 
	    if (ucTiempoAntirrebote == 0) {
	      if (bit_is_set(BOTON_INICIO_PIN, BOTON_INICIO) && bit_is_set(BOTON_PARAR_PIN, BOTON_PARAR) && bit_is_set(BOTON_PAUSA_PIN, BOTON_PAUSA)) {
		ucEstadoBotones = Esperando;
	      }
	      
	    }
	  break;  
	  
	  default:
	    ucEstadoBotones = Esperando;
	    ucComando_control = COMANDO_CONTROL_NINGUNO;
	    break;
	}
}

