#include "otras.h"
#include "macros.h"
#include "inicio.h"
#include "USART.h"

#include <avr/io.h>
#include <stdint.h>


/*****************************************************************************
* Variables externas
*****************************************************************************/
#ifdef COMPILE_WITH_DEBUG
extern char	chBufferTx_USART0[USART0_BUFFER_ZISE];				/* USART.c, buffer de transmisión USART del uc */
#endif

extern unsigned int 	uTiempoEtching;
extern uint32_t uiTemp1;
extern uint32_t uiTemp2;

// void Muestra_temp(void){
//   
// unsigned int aux;	
// unsigned int aux2;	
// 
// 		  /******************** Impresion de los estado de deteccion para debug ************************/
// 		  #ifdef COMPILE_WITH_DEBUG
// 				  chBufferTx_USART0[0] = '\r';
// 				  chBufferTx_USART0[1] = 'T';
// 				  chBufferTx_USART0[2] = 'e';
// 				  chBufferTx_USART0[3] = 'm';
// 				  chBufferTx_USART0[4] = 'p';
// 				  chBufferTx_USART0[5] = ':';
// 				  
// 				  chBufferTx_USART0[6] = ((uiTemp1/10000)+'0');
// aux = uiTemp1%10000;				  
// 				  chBufferTx_USART0[7] = (aux/1000)+'0';
// aux2 = aux%1000;
// 				  chBufferTx_USART0[8] = (aux2/100)+'0';
// aux = aux2%100;
// 				  chBufferTx_USART0[9] = (aux/10)+'0';
// aux2 = aux%10;				  
// 				  chBufferTx_USART0[10] = (aux2)+'0';
// 				  chBufferTx_USART0[11] = '\n';
// 				  chBufferTx_USART0[12] = '\0';
// 				  
// 				  Transmitir_Buffer_USART0 (chBufferTx_USART0, 13);
// 		  #endif
// 		  /***********/
// }


void Muestra_datos(void){
  
unsigned int aux;	
unsigned int aux2;	

		  /******************** Impresion de los estado de deteccion para debug ************************/
		  #ifdef COMPILE_WITH_DEBUG
				  chBufferTx_USART0[0] = '\r';
				  chBufferTx_USART0[1] = 'T';
				  chBufferTx_USART0[2] = 'e';
				  chBufferTx_USART0[3] = 'm';
				  chBufferTx_USART0[4] = 'p';
				  chBufferTx_USART0[5] = 'e';
				  chBufferTx_USART0[6] = 'r';
				  chBufferTx_USART0[7] = 'a';
				  chBufferTx_USART0[8] = 't';
				  chBufferTx_USART0[9] = 'u';
				  chBufferTx_USART0[10] = 'r';
				  chBufferTx_USART0[11] = 'a';
				  chBufferTx_USART0[12] = ':';
				  
				  chBufferTx_USART0[13] = ((uiTemp1/100)+'0');
aux = uiTemp1%100;				  
				  chBufferTx_USART0[14] = (aux/10)+'0';
aux2 = aux%10;
				  chBufferTx_USART0[15] = (aux2)+'0';
			  
				  chBufferTx_USART0[16] = ' ';
				  chBufferTx_USART0[17] = 'T';
				  chBufferTx_USART0[18] = 'i';
				  chBufferTx_USART0[19] = 'e';
				  chBufferTx_USART0[20] = 'm';
				  chBufferTx_USART0[21] = 'p';
				  chBufferTx_USART0[22] = 'o';
				  chBufferTx_USART0[23] = ':';

				  chBufferTx_USART0[24] = ((uTiempoEtching/100)+'0');
aux = uTiempoEtching%100;				  
				  chBufferTx_USART0[25] = (aux/10)+'0';
aux2 = aux%10;
				  chBufferTx_USART0[26] = (aux2)+'0';
				  

				  
				  
				  
				  chBufferTx_USART0[27] = '\n';
				  chBufferTx_USART0[28] = '\0';
				  
				  Transmitir_Buffer_USART0 (chBufferTx_USART0, 29);
		  #endif
		  /***********/
}