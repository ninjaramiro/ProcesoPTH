 /*
 * configuraciones.h
 *
 *  
 *      Author: ninja
 */

#ifndef CONFIGURACIONES_H_
#define CONFIGURACIONES_H_



#define TIEMPO_ETCHING_DEFECTO			15	
#define TEMPERATURA_DEFECTO			30	
#define VELOCIDAD_DEFECTO			12	


// Carga la configuracion por defecto o la almacenada en la eeprom cuando se activa la alimentacion
void Configuracion_Inicial (void);


// Carga los parametros de la configuracion a partir del string de parametros
void String_a_Parametros (void);

// Carga los parametros actuales en el string de parametros
void Parametros_a_String (void);

#endif /* CONFIGURACIONES_H_ */
