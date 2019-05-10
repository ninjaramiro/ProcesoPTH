/*
 * estados.h
 *
 *  
 *      Author: ninja
 */

#ifndef ESTADOS_H_
#define ESTADOS_H_


// Defino los Maq_estados

#define		Detenido_Standby	0
#define 	Estado_Inicio		1
#define 	Elevando_Temp		2
#define 	Etching 		3
#define		Estado_Pausa		4

#define		Motor_encendido		5
#define		Motor_apagado		6

#define		DELTA_TEMP		3

#define 	COMANDO_CONTROL_NINGUNO 	0
#define 	COMANDO_CONTROL_INICIO 		1
#define 	COMANDO_CONTROL_PARAR 		2
#define 	COMANDO_CONTROL_PAUSA 		3

void Maq_estados(void);
void Control_Temperatura(void);


#endif /* ESTADOS_H_ */
