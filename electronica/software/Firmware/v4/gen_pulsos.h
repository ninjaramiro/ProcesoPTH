#ifndef GEN_PULSOS_H_
#define GEN_PULSOS_H_

#include <avr/io.h>
#include "inicio.h"



#define apagado 0
#define encender 1
#define directo 2
#define muerto_a 3
#define inverso 4
#define muerto_b 5

#define pwm_apagado 0b00000001
#define pwm_directo 0b10000001
#define pwm_inverso 0b00100001

void gen_pulsos(void);


#endif /* GEN_PULSOS_H_ */
