#include "comandos.h"
#include "macros.h"
#include "gen_pulsos.h"


#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>
#include <avr/pgmspace.h>

extern uint8_t volatile valor_comando;
extern uint8_t volatile contador_comando;
extern uint8_t volatile id_comando;

extern uint8_t estado_gen_pulsos;
extern uint8_t t_directo;
extern uint8_t t_muerto_a;
extern uint8_t t_inverso;
extern uint8_t t_muerto_b;
extern uint8_t cont_directo;
extern uint8_t cont_muerto_a;
extern uint8_t cont_inverso;
extern uint8_t cont_muerto_b;
extern uint8_t Duty_directo; // Valor de 0 a 255 que representa el dutycycle de 0 a 100%
extern uint8_t Duty_inverso; // Valor de 0 a 255 que representa el dutycycle de 0 a 100%

char volatile caracter_uart;
char volatile fl_caracter_recibido;

char texto_usart[20];

void comandos(void){

	switch (contador_comando) {

	case 0:
		if (caracter_uart == 'c'){  // Si recibo un comando
			contador_comando = 1;
		}
		break;

	case 1:

		if ((caracter_uart >= '1') && (caracter_uart <= '8')){  // Si id valido
			id_comando = caracter_uart-48;
			contador_comando = 2;
		}
		else{
			contador_comando =0;
			id_comando = 0;
		}
		break;

	case 2:
		if ((caracter_uart >= '0') && (caracter_uart <= '9')){// Si llega un digito
			valor_comando=caracter_uart-48;

			contador_comando = 3;
		}
		else if ( (caracter_uart == 0x0A || caracter_uart == 0x0D) && (id_comando==1 || id_comando==2)){ // Si ingresaron un comando corto y apretaron enter
			contador_comando =6;
			fl_caracter_recibido = 1; //Mantengo el flag
		}
		else{
			contador_comando =0;
			id_comando = 0;
		}
		break;

	case 3:
		if ((caracter_uart >= '0') && (caracter_uart <= '9')){  //si llega un segundo digito
			valor_comando=valor_comando *10;
			valor_comando=valor_comando + (caracter_uart-48);
			contador_comando = 4;
		}
		else if ( caracter_uart == 0x0A || caracter_uart == 0x0D){ // Si apretaron enter
			contador_comando =6;
			fl_caracter_recibido = 1; //Mantengo el flag

		}
		else{
			contador_comando =0;
			id_comando = 0;
		}
		break;

	case 4:
		if ((caracter_uart >= '0') && (caracter_uart <= '9')){  // Si llega un tercer digito
			valor_comando=valor_comando *10;
			valor_comando=valor_comando + (caracter_uart-48);
			contador_comando = 5;

		}
		else if ( caracter_uart == 0x0A || caracter_uart == 0x0D){ // Si apretaron enter
			contador_comando =6;
			fl_caracter_recibido = 1; //Mantengo el flag

		}
		else{
			contador_comando = 0;
			id_comando = 0;
		}
		break;

	case 5:
		if (caracter_uart == 0x0A || caracter_uart == 0x0D){  // Si apretaron enter
			contador_comando = 6;
			fl_caracter_recibido = 1; //Mantengo el flag


		}
		else{
			contador_comando =0;
			id_comando = 0;
		}
		break;

	case 6:

		sprintf(texto_usart,"CMD: c%d%d \n\r",id_comando,valor_comando);
		Transmitir_Buffer_USART0 (texto_usart, 20);

		switch (id_comando){
		case 1:
			estado_gen_pulsos = apagado;
			break;
		case 2:
			estado_gen_pulsos = encender;
			break;
		case 3:
			t_directo = valor_comando;
			break;
		case 4:
			t_inverso = valor_comando;
			break;
		case 5:
			t_muerto_a = valor_comando;
			break;
		case 6:
			t_muerto_b = valor_comando;
			break;
		case 7:
			Duty_directo = valor_comando;
			break;
		case 8:
			Duty_inverso = valor_comando;
			break;

		default:
			break;
		}


		sprintf(texto_usart,"Ok \n\r",id_comando,valor_comando);
		Transmitir_Buffer_USART0 (texto_usart, 10);



		valor_comando = 0;
		contador_comando =0;
		id_comando = 0;
		break;

	default:
		break;


	}

}
