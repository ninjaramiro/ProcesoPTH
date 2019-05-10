#include <18F26k22.h>
#device adc=10

#FUSES NOWDT                    //Watch Dog Timer
#FUSES INTRC_IO                 //Internal RC Osc, no CLKOUT
#FUSES PLLEN                    // 64mhz
#FUSES PUT                      //Power Up Timer
#FUSES MCLR                     //Master Clear pin enabled
#FUSES PROTECT                  //Code protected from reads
#FUSES NOCPD                    //No EE protection
#FUSES BROWNOUT                 //Reset when brownout detected
#FUSES NOIESO                   //Internal External Switch Over mode disabled
#FUSES FCMEN                    //Fail-safe clock monitor enabled
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O
#FUSES NODEBUG                  //No Debug mode for ICD
#FUSES NOWRT                    //Program memory not write protected
#FUSES BORV29                   //Brownout reset at 2.9V
#FUSES CCP2B3
#use delay(clock=64Mhz)

//#priority timer1, ext ,timer5, timer0

#include <stdlib.h>
#include <string.h>

#define LCD_ENABLE_PIN  PIN_C2                                    
#define LCD_RS_PIN      PIN_C3                                  
#define LCD_RW_PIN      PIN_C4                                 
#define LCD_DATA4       PIN_C5                                    
#define LCD_DATA5       PIN_C1                                    
#define LCD_DATA6       PIN_C6                                    
#define LCD_DATA7       PIN_C0
#include <LCD.C>  

#define PULSE1       PIN_B5
#define PULSE2       PIN_B2
#define PWM1         PIN_B4
#define PWM2         PIN_B3

#define KEY1         PIN_B0
#define KEY2         PIN_B1

// versao
unsigned int32 version=20130402;

unsigned int16 pak=0;
unsigned int8  mpak=0;
unsigned int16 pka=0;
unsigned int8  mpka=0;
unsigned int16 rep1=0;
unsigned int8  mrep1=0;
unsigned int16 rep2=0;
unsigned int8  mrep2=0;
unsigned int8 ipak=0;
unsigned int8 dipak=0;
unsigned int8 ipka=0;
unsigned int8 dipka=0;
unsigned int8 ciclo=0;
unsigned int8 key=0;
unsigned int8 segundo=0;
unsigned int8 minuto=0;
unsigned int8 c1s=0;
unsigned int16 I=0;
unsigned int16 adc=0;
int1 adc_ready=0;
int1 t1s=0;
int1 tciclo=0;

// config
void config() {
   setup_oscillator( OSC_64MHZ );
   
   // Configura Portas
   port_b_pullups( false );

   // A0 - ENTRADA    AN0 I
   // A1 - ENTRADA    AN1 POT
   // A2 - ENTRADA    NC
   // A3 - ENTRADA    NC
   // A4 - ENTRADA    NC
   // A5 - ENTRADA    NC
   // A6 - ENTRADA    NC
   // A7 - ENTRADA    NC
   set_tris_a(0b11111111);

   // B0 - ENTRADA    INT0 CHAVE 1
   // B1 - ENTRADA    INT1 CHAVE 1
   // B2 - SAIDA      PULSE2
   // B3 - SAIDA      PWM2
   // B4 - SAIDA      PWM1
   // B5 - SAIDA      PULSE1
   // B6 - ENTRADA    ICSP C
   // B7 - ENTRADA    ICSP D
   set_tris_b(0b11000011);

   // C0 - SAIDA      LCD_D7
   // C1 - SAIDA      LCD_D5
   // C2 - SAIDA      LCD_E
   // C3 - SAIDA      LCD_RS
   // C4 - ENTRADA    LCD_RW
   // C5 - SAIDA      LCD_D4
   // C6 - SAIDA      LCD_D6
   // C7 - ENTRADA    NC
   set_tris_c(0b10010000);

   // DESLIGA TRANSISTORES
   output_low(PULSE1);
   output_low(PULSE2);
   output_low(PWM1);
   output_low(PWM2);
   
   // seta ADC
   setup_adc_ports( sAN0 | sAN1 | VSS_VDD );
   setup_adc( ADC_CLOCK_INTERNAL );

   // timer 0 
   // contador incremental rodando a 62.5KHz
   // seta contador para dividir por 250 (256 - 250 = 6) 
   // estouro a 250Hz - 4mS
   setup_timer_0( RTCC_INTERNAL | RTCC_DIV_256 | RTCC_8_BIT );
   set_timer0( 6 );

   // timer 1
   // contador incremental rodando a 2Mhz
   // estouro a 30.517Hz - 32.768mS
   setup_timer_1( T1_DISABLED | T1_DIV_BY_8 );

   // timer 3
   // contador incremental rodando a 2Mhz
   // estouro a 30.517Hz - 32.768mS
   setup_timer_3( T3_DISABLED | T3_DIV_BY_8 );

   // timer 5 
   // contador incremental rodando a 2Mhz
   // estouro a 30.517Hz - 32.768mS
   setup_timer_5( T5_DISABLED | T5_DIV_BY_8 );

   // direciona PWM1 para RB4
   setup_ccp1( CCP_PWM | CCP_PULSE_STEERING_D );   
   setup_ccp2( CCP_PWM );

   // Ajusta frequencia e resolucao PWM
   // 64Mhz / 4 = 16Mhz / 4 = 4Mhz
   // 4MHz / 40 = 100Khz
   setup_timer_2( T2_DIV_BY_4,39,1 );

   // DESLIGADO
   setup_timer_4( T4_DISABLED,99,1 );

   setup_timer_6( T6_DISABLED,255,16 );
   
   // desliga pwm
   set_pwm1_duty(0);
   set_pwm2_duty(0);

   // desativa interrupcoes;
   disable_interrupts( INT_RB );
   disable_interrupts( INT_EXT );
   disable_interrupts( INT_EXT1 );
   disable_interrupts( INT_AD );
   disable_interrupts( INT_TBE );
   disable_interrupts( INT_RDA );
   disable_interrupts( INT_TIMER0 );   
   disable_interrupts( INT_TIMER1 );
   disable_interrupts( INT_TIMER3 );
   disable_interrupts( INT_TIMER5 );
   disable_interrupts( INT_TIMER2 );
   disable_interrupts( INT_TIMER4 );
   disable_interrupts( INT_TIMER6 );
   disable_interrupts( INT_CCP1 );
   disable_interrupts( INT_CCP2 );
   disable_interrupts( INT_SSP );
   disable_interrupts( INT_BUSCOL );
   disable_interrupts( INT_EEPROM );
   disable_interrupts( INT_COMP );
   disable_interrupts( INT_COMP2 );

   setup_wdt ( WDT_OFF );
   // seta interrupcao na borda de descida
   ext_int_edge(0, H_TO_L );      // configura interrupcao para ativar ao pressionar o botao
   ext_int_edge(1, H_TO_L );      // configura interrupcao para ativar ao pressionar o botao 
}


//=========================================================
//    interpolacao linear
//=========================================================
signed long interp(signed long x,signed long x1,signed long x2,signed long y1,signed long y2) {
   float tmp1, tmp2, tmp3;   
   signed long ret_val;

   if (x <= x1) {
      ret_val = y1;
   } else if (x >= x2) {
      ret_val = y2;
   } else if ((x > x1) && (x < x2)) {
      tmp1 = y2 - y1;
      tmp2 = x2 - x1;
      tmp1 /= tmp2;
      //
      tmp3 = x - x1;
      tmp1 *= tmp3;
      tmp1 += y1;
      ret_val = (long)tmp1;
   }
   return ret_val;
}

// memoria
// 1-2   = pulso A-K de 0 a 32.768mS
// 3     = multiplicador do pulso A->K de 0 a 255 (repeticao)
// 4-5   = repouso de 0 a 32.768mS
// 6     = multiplicador do repouso de 0 a 255 (repeticao)
// 7-8   = pulso K-A de 0 a 32.768mS
// 9     = multiplicador do pulso K->A de 0 a 255 (repeticao) 
// 10-11 = repouso de 0 a 32.768mS
// 12    = multiplicador do repouso de 0 a 255 (repeticao)
// 13    = intensidade do pulso A->K de 0 a 40
// 14    = intensidade do pulso K->A de 0 a 40
// 15    = tempo do ciclo de 0 a 60 min

void loadmem() {
   pak = read_eeprom(1);
   pak <<= 8;
   pak += read_eeprom(2);
   if (pak > 500) pak = 500;

   mpak = read_eeprom(3);

   rep1 = read_eeprom(4);
   rep1 <<= 8;
   rep1 += read_eeprom(5);
   if (rep1 > 500) rep1 = 500;

   mrep1 = read_eeprom(6);

   pka = read_eeprom(7);
   pka <<= 8;
   pka += read_eeprom(8);
   if (pka > 500) pka = 500;

   mpka = read_eeprom(9);
   
   rep2 = read_eeprom(10);
   rep2 <<= 8;
   rep2 += read_eeprom(11);
   if (rep2 > 500) rep2 = 500;

   mrep2 = read_eeprom(12);

   dipak = read_eeprom(13);
   if (dipak > 100) dipak = 50;
   ipak = interp(dipak,0,100,0,39);

   dipka = read_eeprom(14);
   if (dipka > 100) dipka = 50;
   ipka = interp(dipka,0,100,0,39);

   ciclo = read_eeprom(15);
   if (ciclo > 120) ciclo = 120;   
}

void setup() {
   int1 retval=0;
   unsigned int8 disp=0;
   unsigned int16 old_adc=0;
   int1 changed = 0;
   printf(lcd_putc,"\f SETUP! ");
   
   while (!input(KEY2));
   set_adc_channel(1);
   delay_ms(250);
   printf(lcd_putc,"\fA>K +Wid");
   old_adc = read_adc();
   changed = 0;
   key = 0;
   while (key != 2) { 
      adc = read_adc(); 
      if (((adc > (old_adc + 10)) || ((adc + 10) < old_adc)) || (changed == true)) {
         pak = interp(adc,0,1023,0,50);
         pak *= 10;
         changed = true;
      }         
      lcd_gotoxy(1,2);
      printf(lcd_putc," %3lu us ",pak);
      if (key == 1) {
         printf(lcd_putc,"\f CANCEL ");
         delay_ms(1000);
         key = 0;         
         lcd_putc("\f");
         retval=1;
         return;
      }
   }

   while (!input(KEY2));
   delay_ms(250);
   printf(lcd_putc,"\fA>K Mult");
   old_adc = read_adc();
   changed = 0;
   key = 0;
   while (key != 2) {
      adc = read_adc(); 
      if (((adc > (old_adc + 10)) || ((adc + 10) < old_adc)) || (changed == true)) {
         mpak = interp(adc,0,1023,1,255);
         changed = true;
      }         
      lcd_gotoxy(1,2);
      printf(lcd_putc,"+W x %3u",mpak);
      if (key == 1) {
         printf(lcd_putc,"\f CANCEL ");
         delay_ms(1000);
         key = 0;         
         lcd_putc("\f");
         retval=1;
         return;
      }      
   }
   
   while (!input(KEY2));
   delay_ms(250);
   printf(lcd_putc,"\fA>K -Wid");
   old_adc = read_adc();
   changed = 0;
   key = 0;
   while (key != 2) {
      adc = read_adc(); 
      if (((adc > (old_adc + 10)) || ((adc + 10) < old_adc)) || (changed == true)) {
         rep1 = interp(adc,0,1023,0,50);
         rep1 *= 10;
         changed = true;
      }         
      lcd_gotoxy(1,2);
      printf(lcd_putc," %3lu us ",rep1);
      if (key == 1) {
         printf(lcd_putc,"\f CANCEL ");
         delay_ms(1000);
         key = 0;         
         lcd_putc("\f");
         retval=1;
         return;
      }
   }

   while (!input(KEY2));
   delay_ms(250);
   printf(lcd_putc,"\fA>K Mult");
   old_adc = read_adc();
   changed = 0;
   key = 0;
   while (key != 2) {
      adc = read_adc(); 
      if (((adc > (old_adc + 10)) || ((adc + 10) < old_adc)) || (changed == true)) {
         mrep1 = interp(adc,0,1023,1,255);
         changed = true;
      }         
      lcd_gotoxy(1,2);
      printf(lcd_putc,"-W x %3u ",mrep1);
      if (key == 1) {
         printf(lcd_putc,"\f CANCEL ");
         delay_ms(1000);
         key = 0;         
         lcd_putc("\f");
         retval=1;
         return;
      }
   }   

   while (!input(KEY2));
   delay_ms(250);
   printf(lcd_putc,"\fK>A +Wid");
   old_adc = read_adc();
   changed = 0;
   key = 0;
   while (key != 2) {
      adc = read_adc(); 
      if (((adc > (old_adc + 10)) || ((adc + 10) < old_adc)) || (changed == true)) {
         pka = interp(adc,0,1023,0,50);
         pka *= 10;
         changed = true;
      }         
      lcd_gotoxy(1,2);
      printf(lcd_putc," %3lu us ",pka);
      if (key == 1) {
         printf(lcd_putc,"\f CANCEL ");
         delay_ms(1000);
         key = 0;         
         lcd_putc("\f");
         retval=1;
         return;
      }
   }

   while (!input(KEY2));
   delay_ms(250);
   printf(lcd_putc,"\fK>A Mult");
   old_adc = read_adc();
   changed = 0;
   key = 0;
   while (key != 2) {
      adc = read_adc(); 
      if (((adc > (old_adc + 10)) || ((adc + 10) < old_adc)) || (changed == true)) {
         mpka = interp(adc,0,1023,1,255);
         changed = true;
      }         
      lcd_gotoxy(1,2);
      printf(lcd_putc,"+W x %3u ",mpka);
      if (key == 1) {
         printf(lcd_putc,"\f CANCEL ");
         delay_ms(1000);
         key = 0;         
         lcd_putc("\f");
         retval=1;
         return;
      }
   }

   while (!input(KEY2));
   delay_ms(250);
   printf(lcd_putc,"\fK>A -Wid");
   old_adc = read_adc();
   changed = 0;
   key = 0;
   while (key != 2) {
      adc = read_adc(); 
      if (((adc > (old_adc + 10)) || ((adc + 10) < old_adc)) || (changed == true)) {
         rep2 = interp(adc,0,1023,0,50);
         rep2 *= 10;
         changed = true;
      }         
      lcd_gotoxy(1,2);
      printf(lcd_putc," %3lu us ",rep2);
      if (key == 1) {
         printf(lcd_putc,"\f CANCEL ");
         delay_ms(1000);
         key = 0;         
         lcd_putc("\f");
         retval=1;
         return;
      }
   }

   while (!input(KEY2));
   delay_ms(250);
   printf(lcd_putc,"\fK>A Mult");
   old_adc = read_adc();
   changed = 0;
   key = 0;
   while (key != 2) {
      adc = read_adc(); 
      if (((adc > (old_adc + 10)) || ((adc + 10) < old_adc)) || (changed == true)) {
         mrep2 = interp(adc,0,1023,1,255);
         changed = true;
      }         
      lcd_gotoxy(1,2);
      printf(lcd_putc,"-W x %3u ",mrep2);
      if (key == 1) {
         printf(lcd_putc,"\f CANCEL ");
         delay_ms(1000);
         key = 0;         
         lcd_putc("\f");
         retval=1;
         return;
      }
   }   

   while (!input(KEY2));
   delay_ms(250);
   printf(lcd_putc,"\fA>K +W%%I");
   old_adc = read_adc();
   changed = 0;
   key = 0;
   while (key != 2) {
      adc = read_adc(); 
      if (((adc > (old_adc + 10)) || ((adc + 10) < old_adc)) || (changed == true)) {
         dipak = interp(adc,0,1023,0,100);
         ipak = interp(dipak,0,100,0,39);
         changed = true;
      }         
      lcd_gotoxy(1,2);
      printf(lcd_putc,"  %3u%%  ",dipak);
      if (key == 1) {
         printf(lcd_putc,"\f CANCEL ");
         delay_ms(1000);
         key = 0;         
         lcd_putc("\f");
         retval=1;
         return;
      }
   }   

   while (!input(KEY2));
   delay_ms(250);
   printf(lcd_putc,"\fK>A +W%%I");
   old_adc = read_adc();
   changed = 0;
   key = 0;
   while (key != 2) {
      adc = read_adc(); 
      if (((adc > (old_adc + 10)) || ((adc + 10) < old_adc)) || (changed == true)) {
         dipka = interp(adc,0,1023,0,100);
         ipka = interp(dipka,0,100,0,39);
         changed = true;
      }         
      lcd_gotoxy(1,2);
      printf(lcd_putc,"  %3u%%  ",dipka);
      if (key == 1) {
         printf(lcd_putc,"\f CANCEL ");
         delay_ms(1000);
         key = 0;         
         lcd_putc("\f");
         retval=1;
         return;
      }
   }   

   while (!input(KEY2));
   delay_ms(250);
   printf(lcd_putc,"\fRun Time");
   old_adc = read_adc();
   changed = 0;
   key = 0;
   while (key != 2) {
      adc = read_adc(); 
      if (((adc > (old_adc + 10)) || ((adc + 10) < old_adc)) || (changed == true)) {
         ciclo = interp(adc,0,1023,1,120);
         changed = true;
      }         
      lcd_gotoxy(1,2);
      printf(lcd_putc," %3u min",ciclo);
      if (key == 1) {
         printf(lcd_putc,"\f CANCEL ");
         delay_ms(1000);
         key = 0;         
         lcd_putc("\f");
         retval=1;
         return;
      }
   }   

   if (retval == 0) {
      write_eeprom(1,make8(pak,1));
      write_eeprom(2,make8(pak,0));
   
      write_eeprom(3,mpak);   
   
      write_eeprom(4,make8(rep1,1));
      write_eeprom(5,make8(rep1,0));
   
      write_eeprom(6,mrep1);   
   
      write_eeprom(7,make8(pka,1));
      write_eeprom(8,make8(pka,0));
   
      write_eeprom(9,mpka);   
   
      write_eeprom(10,make8(rep2,1));
      write_eeprom(11,make8(rep2,0));
   
      write_eeprom(12,mrep2);   
   
      write_eeprom(13,dipak);   
   
      write_eeprom(14,dipka);
   
      write_eeprom(15,ciclo);   
   
      printf(lcd_putc,"\f SAVED! ");
      key = 0;
      delay_ms(1000);
   }
   lcd_putc("\f");
}

#int_TIMER1
void  TIMER1_isr(void) {

}

#int_EXT
void EXT_isr(void) {
   key = 1;
}

#int_EXT1
void EXT1_isr(void) {
   key = 2;
}

#int_TIMER0
void TIMER0_isr() {
   static unsigned char conta=0;

   set_timer0(6);

   if (conta == 250) {
      conta = 0;
      if (tciclo) {
         if (segundo < 59) segundo++;
         else {
            segundo = 0;
            minuto++;
         }
      }
      if (t1s) if (c1s < 255) c1s++;
   } else conta++;
}

#int_AD 
void ADC_isr() { 
   adc = read_adc(ADC_READ_ONLY); 
   adc_ready = 1;
}

void main () {
   int x=0;
   unsigned int8 olds=0;
   
   config();
   lcd_init();
   loadmem();

   // ativa interrupcoes
   enable_interrupts( GLOBAL );
   enable_interrupts( INT_AD );
   enable_interrupts( INT_TIMER0 );   
   enable_interrupts( INT_EXT );
   enable_interrupts( INT_EXT1 );
   
   printf(lcd_putc,"\fE-PLATER\n%lu",version);
   delay_ms(1000);
   printf(lcd_putc,"\f");
   // reseta variaveis
   key = 0;
   t1s = 0;
   c1s = 0;
   while (true) {
      if (key > 0) {
         switch (key) {
            case 2:
               t1s=0;
               c1s=0;
               t1s=1;
               while ((!input(KEY2)) && (c1s < 5));
               if ((!input(KEY2)) && (c1s >= 5)) {
                  t1s = 0;
                  c1s = 0;
                  setup();
               } else {
                  printf(lcd_putc,"\f START? \n<-N  Y->");
                  while (!input(KEY2));
                  delay_ms(100);
                  key = 0;
                  while (key == 0);
                  switch (key) {
                     case 1:           // CANCELA  
                        printf(lcd_putc,"\f CANCEL ");
                        delay_ms(1000);
                        key = 0;                        
                        lcd_putc("\f");
                        break;
                     case 2:           // RODA  
                        printf(lcd_putc,"\fRUNNING!");
                        delay_ms(500);
                        key = 0;
                        // desliga saidas
                        set_pwm1_duty(0);
                        set_pwm2_duty(0);
                        output_low(PULSE1);
                        output_low(PULSE2);
                        // zera timer
                        tciclo=0;
                        minuto=0;
                        segundo=0;
                        // inicializa AD
                        set_adc_channel(0);
                        adc = 0;
                        I=0;
                        // inicia timer
                        tciclo=1;
                        // loop do gerador de pulsos
                        while ((I < 4500) && (key == 0) && (minuto < ciclo)){
                           if (olds != segundo) {
                              olds = segundo;                                                        
                              if (adc_ready == 1) {
                                 adc_ready = 0;
                                 I = adc;
                                 I *= 15;
                                 adc=0;
                              }
                              lcd_gotoxy(1,1);
                              printf(lcd_putc,"I=%01.3wA",I);
                              lcd_gotoxy(1,2);
                              printf(lcd_putc," %03u:%02u",minuto,segundo);
                           }
                           
                           // nivel alto A->K
                           if (pak > 0) {
                              set_pwm2_duty(ipak);
                              output_high(PULSE1);
                              for (x=0;x<mpak;x++) {
                                delay_us(pak); 
                              }
                              output_low(PULSE1);
                              set_pwm2_duty(0);
                              read_adc(ADC_START_ONLY);
                              delay_cycles(25);    // aguarda 1.25uS para desligamento do transistor
                           }
                           
                           // nivel baixo A->K
                           if (rep1 > 0) {
                              for (x=0;x<mrep1;x++) {
                                delay_us(rep1); 
                              }
                           }
                           
                           // nivel alto K->A
                           if (pka > 0) {
                              set_pwm1_duty(ipka);
                              output_high(PULSE2);
                              for (x=0;x<mpka;x++) {
                                delay_us(pka); 
                              }
                              output_low(PULSE2);
                              set_pwm1_duty(0);
                              read_adc(ADC_START_ONLY);
                              delay_cycles(25);
                           }
                           
                           // nivel baixo K->A
                           if (rep2 > 0) {
                              for (x=0;x<mrep2;x++) {
                                delay_us(rep2); 
                              }
                           }
                        }
                        
                        // desliga tudo
                        output_low(PULSE1);
                        output_low(PULSE2);
                        set_pwm1_duty(0);
                        set_pwm2_duty(0);
                        
                        // se parou por intercessao mostra STOP
                        if (I > 4500) {                        
                           printf(lcd_putc,"\fWARNING!\nI=%01.3wA",I);
                           // zera timer para indicar que foi parado!
                           minuto = 0;
                           segundo = 0;
                           delay_ms(5000);
                        } else {
                           if (key > 0) {
                              lcd_gotoxy(1,1);
                              printf(lcd_putc,"  STOP  ");
                              // zera timer para indicar que foi parado!
                              minuto = 0;
                              segundo = 0;
                           } else {
                              lcd_gotoxy(1,1);
                              printf(lcd_putc," FINISH ");
                           }
                        }
                        
                        // reseta variaveis
                        tciclo=0;
                        delay_ms(1000);
                        key = 0;
                        lcd_putc("\f");
                        break;
                  }
               }
               break;
         }
      }
      
      lcd_gotoxy(1,1);
      printf(lcd_putc,"  IDLE  ");      
      lcd_gotoxy(1,2);
      printf(lcd_putc," %03u:%02u ",minuto,segundo);
      if (c1s >= 2) {
         t1s = 0;
         c1s = 0;
         lcd_putc("\f");
      }
   }
}
