//-----------------------------------------------------------------
// Tabla de ciclos de servicio para generar se�al por PWM
// entrada: instante de muestreo
// salida: duty en 9 bits con signo
// Bytes de memoria de programa utilizados: 428
// 2019-may-22 FIUBA - RA
//-----------------------------------------------------------------
#if defined(__AVR__)
#include <avr/pgmspace.h>
#define pwm_duty_type const int16_t
#elif defined(__PIC32MX__)
#define pwm_duty_type const int
#elif defined(__arm__)
#define PROGMEM
#define pwm_duty_type const int
#endif

pwm_duty_type PARAMETROS_PWM[4] PROGMEM={
	210, // nro. de datos de la tabla SENIAL_PWM
	9, // nro. de bits de cada dato
	100, // perIodo del PWM [uS]
	32}; // ASD de normalizaciOn

pwm_duty_type SENIAL_PWM[210] PROGMEM={
	0x007d, 0x007c, 0x007b, 0x007b, 0x007a, 0x007a, 0x0079, 0x0078, 
	0x0078, 0x0077, 0x0076, 0x0076, 0x0075, 0x0075, 0x0074, 0x0073, 
	0x00ce, 0x0168, 0x013d, 0x0113, 0x00e8, 0x00bd, 0x0092, 0x0071, 
	0x006e, 0x006d, 0x006c, 0x006c, 0x006b, 0x006b, 0x006a, 0x0069, 
	0x0069, 0x0068, 0x0067, 0x0067, 0x0066, 0x0066, 0x0065, 0x0064, 
	0x0064, 0x0063, 0x0062, 0x0062, 0x0061, 0x0061, 0x0060, 0x005f, 
	0x005f, 0x005e, 0x0162, 0x0137, 0x010c, 0x00e1, 0x00b6, 0x008c, 
	0x0063, 0x0059, 0x0058, 0x0058, 0x0057, 0x0057, 0x0056, 0x0055, 
	0x0055, 0x0054, 0x0053, 0x0053, 0x0052, 0x0052, 0x0051, 0x0050, 
	0x0050, 0x004f, 0x004e, 0x004e, 0x004d, 0x004d, 0x004c, 0x004b, 
	0x004b, 0x004a, 0x0049, 0x00fb, 0x0130, 0x0105, 0x00db, 0x00b0, 
	0x0085, 0x005a, 0x0044, 0x0044, 0x0043, 0x0043, 0x0042, 0x0041, 
	0x0041, 0x0040, 0x003f, 0x003f, 0x003e, 0x003e, 0x003d, 0x003c, 
	0x003c, 0x003b, 0x003a, 0x003a, 0x0039, 0x0039, 0x0038, 0x0037, 
	0x0037, 0x0036, 0x0035, 0x0035, 0x0090, 0x012a, 0x00ff, 0x00d4, 
	0x00a9, 0x007e, 0x0054, 0x0032, 0x002f, 0x002f, 0x002e, 0x002d, 
	0x002d, 0x002c, 0x002b, 0x002b, 0x002a, 0x002a, 0x0029, 0x0028, 
	0x0028, 0x0027, 0x0026, 0x0026, 0x0025, 0x0025, 0x0024, 0x0023, 
	0x0023, 0x0022, 0x0021, 0x0021, 0x0020, 0x0020, 0x0123, 0x00f8, 
	0x00cd, 0x00a3, 0x0078, 0x004d, 0x0025, 0x001b, 0x001a, 0x0019, 
	0x0019, 0x0018, 0x0017, 0x0017, 0x0016, 0x0016, 0x0015, 0x0014, 
	0x0014, 0x0013, 0x0012, 0x0012, 0x0011, 0x0011, 0x0010, 0x000f, 
	0x000f, 0x000e, 0x000d, 0x000d, 0x000c, 0x000c, 0x000b, 0x00bc, 
	0x00f2, 0x00c7, 0x009c, 0x0071, 0x0046, 0x001c, 0x0006, 0x0005, 
	0x0005, 0x0004, 0x0003, 0x0003, 0x0002, 0x0002, 0x0001, 0x0000, 
	0xff38, 0xff38, 0xff38, 0xff38, 0xff38, 0xff38, 0xff38, 0xff38, 
	0xff38, 	0xff38, 
}; 
//-----------------------------------------------------------------
