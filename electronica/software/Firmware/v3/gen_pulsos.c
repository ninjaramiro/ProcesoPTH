#include "gen_pulsos.h"
#include "macros.h"


uint8_t estado_gen_pulsos;

//Variables para configuracion
uint8_t t_directo;
uint8_t t_muerto_a;
uint8_t t_inverso;
uint8_t t_muerto_b;
uint8_t Duty_directo; // Valor de 0 a 255 que representa el dutycycle de 0 a 100%
uint8_t Duty_inverso; // Valor de 0 a 255 que representa el dutycycle de 0 a 100%

//Contadores de tiempo
uint8_t cont_directo;
uint8_t cont_muerto_a;
uint8_t cont_inverso;
uint8_t cont_muerto_b;

void gen_pulsos(void){

switch (estado_gen_pulsos) {

    case apagado:
    TCCR1A = pwm_apagado; // Apago el pwm
    CLEAR_BIT(PULSE1_PORT, PULSE1);
    CLEAR_BIT(PULSE2_PORT, PULSE2);
    break;

    case encender:
      OCR1AL = Duty_directo;
      OCR1BL = Duty_inverso;
      TCCR1A = pwm_directo;
      estado_gen_pulsos = directo; // Proximo estado
      cont_directo = t_directo;  // Tiempo en el próximo estado
    break;

    case directo:
    OCR1AL = Duty_directo;
    OCR1BL = 0;
    CLEAR_BIT(PULSE1_PORT, PULSE1);
    SET_BIT(PULSE2_PORT, PULSE2);
    if (cont_directo == 0){
      estado_gen_pulsos = muerto_a; // Proximo estado
      cont_muerto_a = t_muerto_a;   // Tiempo en el próximo estado
      TCCR1A = pwm_apagado;
    }

    break;

    case muerto_a:
    OCR1AL = 0;
    OCR1BL = 0;
    CLEAR_BIT(PULSE1_PORT, PULSE1);
    CLEAR_BIT(PULSE2_PORT, PULSE2);
    if (cont_muerto_a == 0){
      estado_gen_pulsos = inverso; // Proximo estado
      cont_inverso = t_inverso;  // Tiempo en el próximo estado
      TCCR1A = pwm_inverso;
    }
    break;


    case inverso:
    OCR1AL = 0;
    OCR1BL = Duty_inverso;
    SET_BIT(PULSE1_PORT, PULSE1);
    CLEAR_BIT(PULSE2_PORT, PULSE2);
    if (cont_inverso == 0){
      estado_gen_pulsos = muerto_b; // Proximo estado
      cont_muerto_b = t_muerto_b;  // Tiempo en el próximo estado
      TCCR1A = pwm_apagado; // Apago el pwm
    }
    break;


    case muerto_b:
    OCR1AL = 0;
    OCR1BL = 0;
    CLEAR_BIT(PULSE1_PORT, PULSE1);
    CLEAR_BIT(PULSE2_PORT, PULSE2);
    if (cont_muerto_b == 0){
      estado_gen_pulsos = directo; // Proximo estado
      cont_directo = t_directo;  // Tiempo en el próximo estado
      TCCR1A = pwm_directo;
    }
    break;

    }
}
