EESchema Schematic File Version 2
LIBS:2N2222
LIBS:irfz46n
LIBS:LM7805
LIBS:ft232rl
LIBS:FuenteDePulsos-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 4
Title "Pulsos para electrolisis"
Date "2016-10-19"
Rev ""
Comp "Laboratorio de Circuitos Impresos - FIUBA"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L CONN_01X02 P1
U 1 1 5807F03F
P 3000 1850
F 0 "P1" H 3000 2000 50  0000 C CNN
F 1 "Entrada_alimentacion" V 3100 1850 50  0000 C CNN
F 2 "Connect:bornier2" H 3000 1850 50  0001 C CNN
F 3 "" H 3000 1850 50  0000 C CNN
	1    3000 1850
	-1   0    0    1   
$EndComp
$Comp
L FUSE F1
U 1 1 5807F06B
P 3650 850
F 0 "F1" H 3750 900 50  0000 C CNN
F 1 "FUSE" H 3550 800 50  0000 C CNN
F 2 "Fuse_Holders_and_Fuses:Fuseholder5x20_horiz_open_universal_Type-III" H 3650 850 50  0001 C CNN
F 3 "" H 3650 850 50  0000 C CNN
	1    3650 850 
	1    0    0    -1  
$EndComp
$Comp
L FUSE F2
U 1 1 5807F0AC
P 3650 1800
F 0 "F2" H 3750 1850 50  0000 C CNN
F 1 "FUSE" H 3550 1750 50  0000 C CNN
F 2 "Fuse_Holders_and_Fuses:Fuseholder5x20_horiz_open_universal_Type-III" H 3650 1800 50  0001 C CNN
F 3 "" H 3650 1800 50  0000 C CNN
	1    3650 1800
	1    0    0    -1  
$EndComp
$Comp
L R R1
U 1 1 5807F0D0
P 4400 1800
F 0 "R1" V 4480 1800 50  0000 C CNN
F 1 "10" V 4400 1800 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Ceramic_Horizontal_L19mm-W8mm-H8mm-p25mm" V 4330 1800 50  0001 C CNN
F 3 "" H 4400 1800 50  0000 C CNN
	1    4400 1800
	0    1    1    0   
$EndComp
$Comp
L CP C1
U 1 1 5807F153
P 5300 2050
F 0 "C1" H 5325 2150 50  0000 L CNN
F 1 "100uF 50v" H 5325 1950 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Radial_D5_L11_P2.5" H 5338 1900 50  0001 C CNN
F 3 "" H 5300 2050 50  0000 C CNN
	1    5300 2050
	1    0    0    -1  
$EndComp
$Comp
L CP C2
U 1 1 5807F28E
P 6850 2050
F 0 "C2" H 6875 2150 50  0000 L CNN
F 1 "100uF 50v" H 6875 1950 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Radial_D5_L11_P2.5" H 6888 1900 50  0001 C CNN
F 3 "" H 6850 2050 50  0000 C CNN
	1    6850 2050
	1    0    0    -1  
$EndComp
$Comp
L C C3
U 1 1 5807F327
P 7300 2050
F 0 "C3" H 7325 2150 50  0000 L CNN
F 1 "100n" H 7325 1950 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Disc_D3_P2.5" H 7338 1900 50  0001 C CNN
F 3 "" H 7300 2050 50  0000 C CNN
	1    7300 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	6550 1800 7300 1800
Wire Wire Line
	6850 1700 6850 1900
Connection ~ 6850 1800
Wire Wire Line
	4550 1800 5750 1800
Wire Wire Line
	4650 2050 4550 2050
Connection ~ 4650 1800
Wire Wire Line
	5300 1750 5300 1900
Connection ~ 5300 1800
Wire Wire Line
	3900 1800 4250 1800
Wire Wire Line
	4050 1800 4050 2050
Wire Wire Line
	4050 2050 4250 2050
Connection ~ 4050 1800
Wire Wire Line
	3200 1800 3400 1800
Wire Wire Line
	3300 850  3300 1800
Wire Wire Line
	3300 850  3400 850 
Connection ~ 3300 1800
$Comp
L GND #PWR01
U 1 1 5807F4F1
P 3300 2300
F 0 "#PWR01" H 3300 2050 50  0001 C CNN
F 1 "GND" H 3300 2150 50  0000 C CNN
F 2 "" H 3300 2300 50  0000 C CNN
F 3 "" H 3300 2300 50  0000 C CNN
	1    3300 2300
	1    0    0    -1  
$EndComp
Wire Wire Line
	3200 1900 3300 1900
Wire Wire Line
	3300 1900 3300 2300
$Comp
L GND #PWR02
U 1 1 5807F54E
P 6150 2400
F 0 "#PWR02" H 6150 2150 50  0001 C CNN
F 1 "GND" H 6150 2250 50  0000 C CNN
F 2 "" H 6150 2400 50  0000 C CNN
F 3 "" H 6150 2400 50  0000 C CNN
	1    6150 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	5300 2200 5300 2250
Wire Wire Line
	5300 2250 7300 2250
Wire Wire Line
	7300 2250 7300 2200
Wire Wire Line
	6850 2200 6850 2250
Connection ~ 6850 2250
Wire Wire Line
	6150 2100 6150 2400
Connection ~ 6150 2250
$Comp
L +24V #PWR03
U 1 1 5807F63E
P 4700 750
F 0 "#PWR03" H 4700 600 50  0001 C CNN
F 1 "+24V" H 4700 890 50  0000 C CNN
F 2 "" H 4700 750 50  0000 C CNN
F 3 "" H 4700 750 50  0000 C CNN
	1    4700 750 
	1    0    0    -1  
$EndComp
Wire Wire Line
	3900 850  4700 850 
$Comp
L +5V #PWR04
U 1 1 5807F6C1
P 6850 1700
F 0 "#PWR04" H 6850 1550 50  0001 C CNN
F 1 "+5V" H 6850 1840 50  0000 C CNN
F 2 "" H 6850 1700 50  0000 C CNN
F 3 "" H 6850 1700 50  0000 C CNN
	1    6850 1700
	1    0    0    -1  
$EndComp
$Sheet
S 5900 3350 2400 2300
U 5807F7D2
F0 "Circuito_pulsos" 60
F1 "Circuito_pulsos.sch" 60
F2 "Pulso1" I L 5900 3800 60 
F3 "PWM1" I L 5900 4000 60 
F4 "Pulso2" I L 5900 4200 60 
F5 "PWM2" I L 5900 4400 60 
F6 "SENS_CORRIENTE" I L 5900 4600 60 
$EndSheet
$Sheet
S 2150 3300 2000 2300
U 5807F7F9
F0 "Logica" 60
F1 "Logica.sch" 60
F2 "PWM1" I R 4150 4000 60 
F3 "Pulse1" I R 4150 3800 60 
F4 "Pulse2" I R 4150 4200 60 
F5 "PWM2" I R 4150 4400 60 
F6 "SENS_CORRIENTE" I R 4150 4600 60 
$EndSheet
Text Notes 7500 6800 0    60   ~ 0
FUENTE: http://www.engenhariacaseira.com.br/blog/?p=38
Wire Wire Line
	4150 3800 5900 3800
Wire Wire Line
	4150 4000 5900 4000
Wire Wire Line
	5900 4200 4150 4200
Wire Wire Line
	4150 4400 5900 4400
Wire Wire Line
	5900 4600 4150 4600
$Comp
L PWR_FLAG #FLG05
U 1 1 580F23CE
P 5300 1750
F 0 "#FLG05" H 5300 1845 50  0001 C CNN
F 1 "PWR_FLAG" H 5300 1930 50  0000 C CNN
F 2 "" H 5300 1750 50  0000 C CNN
F 3 "" H 5300 1750 50  0000 C CNN
	1    5300 1750
	1    0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG06
U 1 1 580F256A
P 3600 2150
F 0 "#FLG06" H 3600 2245 50  0001 C CNN
F 1 "PWR_FLAG" H 3600 2330 50  0000 C CNN
F 2 "" H 3600 2150 50  0000 C CNN
F 3 "" H 3600 2150 50  0000 C CNN
	1    3600 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	3600 2150 3600 2200
Wire Wire Line
	3600 2200 3300 2200
Connection ~ 3300 2200
Wire Wire Line
	7300 1800 7300 1900
$Comp
L PWR_FLAG #FLG07
U 1 1 580F3424
P 4000 750
F 0 "#FLG07" H 4000 845 50  0001 C CNN
F 1 "PWR_FLAG" H 4000 930 50  0000 C CNN
F 2 "" H 4000 750 50  0000 C CNN
F 3 "" H 4000 750 50  0000 C CNN
	1    4000 750 
	1    0    0    -1  
$EndComp
Wire Wire Line
	4000 750  4000 950 
Connection ~ 4000 850 
Text Notes 5500 1050 0    60   ~ 0
FUENTE DE ALIMENTACION
Text Notes 2800 2350 0    60   ~ 0
24vDC
$Comp
L CP C16
U 1 1 5812E45E
P 4000 1100
F 0 "C16" H 4025 1200 50  0000 L CNN
F 1 "2200uFx35V" H 4025 1000 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Radial_D18_L36_P7.5" H 4038 950 50  0001 C CNN
F 3 "" H 4000 1100 50  0000 C CNN
	1    4000 1100
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR08
U 1 1 5812E583
P 4000 1300
F 0 "#PWR08" H 4000 1050 50  0001 C CNN
F 1 "GND" H 4000 1150 50  0000 C CNN
F 2 "" H 4000 1300 50  0000 C CNN
F 3 "" H 4000 1300 50  0000 C CNN
	1    4000 1300
	1    0    0    -1  
$EndComp
Wire Wire Line
	4000 1300 4000 1250
Wire Wire Line
	4700 850  4700 750 
$Comp
L CP C17
U 1 1 5812F019
P 4600 1100
F 0 "C17" H 4625 1200 50  0000 L CNN
F 1 "2200uFx35V" H 4625 1000 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Radial_D18_L36_P7.5" H 4638 950 50  0001 C CNN
F 3 "" H 4600 1100 50  0000 C CNN
	1    4600 1100
	1    0    0    -1  
$EndComp
Wire Wire Line
	4600 950  4600 850 
Connection ~ 4600 850 
$Comp
L GND #PWR09
U 1 1 5812F251
P 4600 1300
F 0 "#PWR09" H 4600 1050 50  0001 C CNN
F 1 "GND" H 4600 1150 50  0000 C CNN
F 2 "" H 4600 1300 50  0000 C CNN
F 3 "" H 4600 1300 50  0000 C CNN
	1    4600 1300
	1    0    0    -1  
$EndComp
Wire Wire Line
	4600 1300 4600 1250
Wire Wire Line
	4650 1800 4650 2050
$Comp
L LM7805 U1
U 1 1 5853151E
P 6150 1850
F 0 "U1" H 6300 1654 50  0000 C CNN
F 1 "LM7805" H 6150 2050 50  0000 C CNN
F 2 "TO_SOT_Packages_THT:TO-220_Neutral123_Vertical" H 6150 2350 50  0001 C CNN
F 3 "" H 6150 1850 50  0000 C CNN
	1    6150 1850
	1    0    0    -1  
$EndComp
$Comp
L R R2
U 1 1 5853279D
P 4400 2050
F 0 "R2" V 4480 2050 50  0000 C CNN
F 1 "10" V 4400 2050 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Ceramic_Horizontal_L19mm-W8mm-H8mm-p25mm" V 4330 2050 50  0001 C CNN
F 3 "" H 4400 2050 50  0000 C CNN
	1    4400 2050
	0    1    1    0   
$EndComp
$EndSCHEMATC
