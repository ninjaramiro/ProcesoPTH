#! /usr/bin/python
# -*- coding: cp1252 -*-
"""
    --------------- Síntesis de forma de onda con PWM -------------------
    Dada una forma de onda periódica, este script genera una tabla de los
    sucesivos ciclos de servicio (duty cycle) de un PWM tal que el valor
    medio (señal de PWM filtrada con un pasabajos) reproduce la forma de
    onda original.

    - Se define la forma de onda a generar como puntos (y=amplitud, t=tiempo)
    - Amplitud expresada en ASD (Amperes por Square Decimeter) y tiempo en uS
    - Se normaliza la amplitud respecto del ASD_MAX*2 de modo que la amplitud
    son valores entre -0.5 y +0.5
    - Se define un período del pwm (T_PWM) en uS (microSegundos)
    - La frecuencia del timer F_CLK en MHz
    - Devuelve el archivo "tabla_pwm.c" que se incluye en el proyecto del
     microcontrolador AVR.

    Ultima Actualización: 24-May-2019
    
    Problemas:
        -- Hay varios bugs aún en la generación de la tabla.
        -- No se eliminan los pulso angostos (el transistor de conmutación
           no puede encender/apagar tan rápido y sólo calienta).
"""
import matplotlib.pyplot as plt
import numpy as np

def Tabula(s, ref, f, Tpwm, archivo):
    """
        Normaliza la señal s respecto de una referencia y genera una tabla
        de valores equivalentes al duty con resolución de nb bits.
        Sintaxis:
            pwm=Tabula(suma, ASD_MAX, F_CLK, T_PWM, 'tabla_pwm')
    """
    # Si se especifica la frecuencia del timer, F_TIMER se sabe qué cuenta
    # represnta T_PWM entonces la resolución en bits, digamos N_PWM
    # nb = log(N_PWM, 2) que en genral no es entero.
    nb=np.log2(f*Tpwm/2) # no cierra, debería ir /2.
    print "bits de resolucion del pwm: %f, aproximados a %f" %(nb,np.ceil(nb))
    t=s[0]; y=s[1];
    n=len(t)
    d=[]    # valores de duties en nro. de cuentas del timer.
    signo=[]
    for i in range(n):
        v=y[i]/ref         # valores normalizados [-0.5, 0.5]
        if v>=0:
            x=v*Tpwm*f/2.  # nro. de cuentas equivalentes
            d.append( np.round(x))
            signo.append(0.5)
        else:
            x=(-v)*Tpwm*f/2
            d.append( 2**16-x )
            signo.append(-0.5)
 
    f=open(archivo+'.c','wt');
    f.write("//-----------------------------------------------------------------\n")
    f.write("// Tabla de ciclos de servicio para generar señal por PWM\n")
    f.write("// entrada: instante de muestreo\n")
    f.write("// salida: duty en %d bits con signo\n" %nb)
    f.write("// Bytes de memoria de programa utilizados: %d\n" %(2*(n+4)) )
    f.write("// 2019-may-22 FIUBA - RA\n")
    f.write("//-----------------------------------------------------------------\n")
    f.write("#if defined(__AVR__)\n")
    f.write("#include <avr/pgmspace.h>\n")
    f.write("#define pwm_duty_type const int16_t\n")
    f.write("#elif defined(__PIC32MX__)\n")
    f.write("#define pwm_duty_type const int\n")
    f.write("#elif defined(__arm__)\n")
    f.write("#define PROGMEM\n")
    f.write("#define pwm_duty_type const int\n")
    f.write("#endif\n")
    f.write("\npwm_duty_type PARAMETROS_PWM[4] PROGMEM={\n")
    f.write("\t%d, // nro. de datos de la tabla SENIAL_PWM\n" %n)
    f.write("\t%d, // nro. de bits de cada dato\n" %nb)
    f.write("\t%d, // perIodo del PWM [uS]\n" %Tpwm)
    f.write("\t%d}; // ASD de normalizaciOn\n" %ref)
    f.write("\npwm_duty_type SENIAL_PWM[%d] PROGMEM={\n" %n)
    lineas=n/8
    print n, lineas, len(d)
    for i in range(lineas):
        f.write("\t0x%04x, 0x%04x, 0x%04x, 0x%04x, 0x%04x, 0x%04x, 0x%04x, 0x%04x, \n"
            %(d[i*8], d[i*8+1], d[i*8+2], d[i*8+3], d[i*8+4], d[i*8+5], d[i*8+6], d[i*8+7]))
    restan=n-8*lineas
    if restan>0:
        for k in range(restan):
             f.write("\t0x%04x, " %d[i*8+k])
    f.write("\n}; \n")
    f.write('//-----------------------------------------------------------------\n')
    f.close()
    return d, signo

def Integra( s, T, resol ):
    """
        Integra la señal s(t) en intervalos regulares de duración T con
        resolución resol
    """
    t=s[0]; y=s[1];
    k=0
    m=0
    n=len(y)
    tm=[]
    for i in range(resol):
        tm.append( i*T/resol )
    #print tm
    r=0 # muestreos
    suma=[]
    suma.append(0.0)
    tt=[]
    tt.append(T/2)
    while k<n:
        if t[k]<tm[m]:
            #suma[r]=suma[r]+y[k]
            k=k+1
            if k==n:
                print "%d muestras" %r
                #suma[r]=suma[r]+y[k-1]
        else:
            if tm[m]<t[k]:
            # tm está antes que t, suma un valor interpolado en t
                suma[r]=suma[r]+(y[k-1]*(t[k]-tm[m])+y[k]*(tm[m]-t[k-1]))/(t[k]-t[k-1])
            else:
            # tm coincide con un punto de la función
                suma[r]=suma[r]+y[k]
                k=k+1
            m=m+1   
            if m==resol:  # llegó al final de un período de muestreo
                suma[r]=suma[r]/resol
                m=0
                r=r+1
                suma.append(0.0)
                tt.append(T/2+r*T)
                #print "repito T", r                
                for i in range(resol):
                    tm[i]=tm[i]+T
                
    return tt[0:r], suma[0:r]

def Superpone( sa, sb):
    """
        Suma las señales sa(t,y) y sb(t,y) 
    """
    ta=sa[0]; ya=sa[1];
    tb=sb[0]; yb=sb[1];
    tt=[]
    yy=[]
    ka=0 # iterador del vector a
    na=len(ta)
    kb=0 # iterador del vector b
    nb=len(tb)
    rb=0 # repeticiones del vector b
    Tb=tb[nb-1]-tb[0]
    while ka<na:
        # Mientras haya puntos del vector más largo
        if ta[ka]<tb[kb]:
            # ta está antes que tb, agrega un punto en ta
            tt.append(ta[ka])
            yy.append(ya[ka]+ (yb[kb-1]-yb[kb])*(tb[kb]-ta[ka])/(tb[kb]-tb[kb-1]))
            ka=ka+1
            if ka==na:
                print "fin 0", ta[ka-1], ya[ka-1]
                tt.append(ta[ka-1])
                yy.append(ya[ka-1]) #+(yb[kb-1]-yb[kb])*(tb[kb]-ta[ka])/(tb[kb]-tb[kb-1]))

        else:
            tt.append(tb[kb])
            if tb[kb]<ta[ka]:
            # tb está antes que ta, agrega un punto en tb
                if ya[ka-1]==ya[ka]:
                    yy.append(ya[ka]+yb[kb])
                else:
                    yy.append(yb[kb]+(ya[ka-1]-ya[ka])*(ta[ka]-tb[kb])/(ta[ka]-ta[ka-1]))
            else:
                yy.append( ya[ka]+yb[kb] )
                ka=ka+1
            kb=kb+1   
            if kb==nb and ka<na:  # llegó al final del vector b
                kb=0
                rb=rb+1
                print "repito b", rb                
                for i in range(nb):
                    tb[i]=tb[i]+Tb
    return tt, yy

if __name__ == '__main__':
    # Define vector (se grafica al final)
    # Ver pag. 1 de "US6919011_complex_waveform_electroplating.pdf" 
    # La señal A es una triangular positiva con una rectangular invertida
    # a la que se superponene n=6 picos definidos por la señal B.

    td=20.0e3   # duración de la señal positiva (corriente directa) [uS]
    tp=666.667  # perIodo de cada pico [uS]
    asd_p = 11.25 # amplitud de los picos [ASD]
    n=6         # nro. de repeticiones del pico superpuestos a la triangular
    
    tb=[0.0, td/(2*n),  td/(2*n),   td/(2*n)+tp, td/n]
    yb=[0.0, 0.0,       asd_p,      0.0,         0.0]
    
    ti=1.0e3    # duración de la señal negativa (corriente inversa) [uS]
    asd_d = 5.0 # máximo de la triangular [ASD]
    asd_i = -8.0# máximo de la inversa [ASD]
    ta=[0.0,    td,     td,     td+ti]
    ya=[asd_d,  0.0,    asd_i,  asd_i]
    
    s=Superpone( [ta, ya], [tb, yb]) # interpola y devuelve una sola señal.
        
    ASD_MAX=0   # Busca el máximo (absoluto) de la señal
    for i in s[1]:
        if abs(i)>ASD_MAX:
            ASD_MAX=abs(i)
    ASD_MAX =np.ceil(2*ASD_MAX)     # valor de normalización [ASD]
    print "ASD_MAX = %d" %ASD_MAX   # aproximado x un entero.

    T_PWM = 100.    # período del PWM [uS]
    RESOL = 10010   # nro. de subdivisiones de cada T_PWM para aproximar
                    # la integral de la señal.
    suma=Integra(s, T_PWM, RESOL)   # Integra en cada intervalo de T_PWM

    F_CLK = 16      # frecuencia [MHz] del timer del PWM
    N_BITS = 16     # nro. de bits del PWM [numero] con que se guarda
                    # en la tabla.
    [p,signo]=Tabula(suma, ASD_MAX, F_CLK, T_PWM, 'tabla_pwm') # genera la tabla de duties.


    t=np.array(s[0])
    y=np.array(s[1])
    fig = plt.figure(1)
    plt.plot(t,y/ASD_MAX)
    plt.grid(True)
    plt.plot(suma[0],suma[1]/ASD_MAX,'r.')
    plt.plot(suma[0],signo,'g')
    plt.show()


