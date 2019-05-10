EESchema Schematic File Version 4
LIBS:FuenteDePulsos-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 2
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
L FuenteDePulsos-rescue:FUSE F1
U 1 1 5807F06B
P 1900 850
F 0 "F1" H 2000 900 50  0000 C CNN
F 1 "FUSE" H 1800 800 50  0000 C CNN
F 2 "Fuse_Holders_and_Fuses:Fuseholder5x20_horiz_open_universal_Type-III" H 1900 850 50  0001 C CNN
F 3 "" H 1900 850 50  0000 C CNN
	1    1900 850 
	1    0    0    -1  
$EndComp
Wire Wire Line
	950  850  1650 850 
$Comp
L FuenteDePulsos-rescue:GND #PWR01
U 1 1 5807F4F1
P 1550 1350
F 0 "#PWR01" H 1550 1100 50  0001 C CNN
F 1 "GND" H 1550 1200 50  0000 C CNN
F 2 "" H 1550 1350 50  0000 C CNN
F 3 "" H 1550 1350 50  0000 C CNN
	1    1550 1350
	1    0    0    -1  
$EndComp
Wire Wire Line
	950  950  1550 950 
Wire Wire Line
	1550 950  1550 1250
$Comp
L FuenteDePulsos-rescue:+24V #PWR02
U 1 1 5807F63E
P 2950 750
F 0 "#PWR02" H 2950 600 50  0001 C CNN
F 1 "+24V" H 2950 890 50  0000 C CNN
F 2 "" H 2950 750 50  0000 C CNN
F 3 "" H 2950 750 50  0000 C CNN
	1    2950 750 
	1    0    0    -1  
$EndComp
Wire Wire Line
	2150 850  2250 850 
$Sheet
S 7550 3250 1000 2200
U 5807F7D2
F0 "Circuito_pulsos" 60
F1 "Circuito_pulsos.sch" 60
F2 "Pulso1" I L 7550 3700 60 
F3 "Pulso2" I L 7550 3850 60 
F4 "PWM2" I L 7550 5000 60 
F5 "PWM1" I L 7550 4150 60 
$EndSheet
Text Notes 7800 6800 0    60   ~ 0
FUENTE: http://www.engenhariacaseira.com.br/blog/?p=38
$Comp
L FuenteDePulsos-rescue:PWR_FLAG #FLG03
U 1 1 580F256A
P 1800 1200
F 0 "#FLG03" H 1800 1295 50  0001 C CNN
F 1 "PWR_FLAG" H 1800 1380 50  0000 C CNN
F 2 "" H 1800 1200 50  0000 C CNN
F 3 "" H 1800 1200 50  0000 C CNN
	1    1800 1200
	1    0    0    -1  
$EndComp
Wire Wire Line
	1800 1200 1800 1250
Wire Wire Line
	1800 1250 1550 1250
Connection ~ 1550 1250
$Comp
L FuenteDePulsos-rescue:PWR_FLAG #FLG04
U 1 1 580F3424
P 2250 750
F 0 "#FLG04" H 2250 845 50  0001 C CNN
F 1 "PWR_FLAG" H 2250 930 50  0000 C CNN
F 2 "" H 2250 750 50  0000 C CNN
F 3 "" H 2250 750 50  0000 C CNN
	1    2250 750 
	1    0    0    -1  
$EndComp
Wire Wire Line
	2250 750  2250 850 
Connection ~ 2250 850 
Text Notes 550  1400 0    60   ~ 0
24vDC
$Comp
L FuenteDePulsos-rescue:CP C1
U 1 1 5812E45E
P 2250 1100
F 0 "C1" H 2275 1200 50  0000 L CNN
F 1 "2200uFx35V" H 2275 1000 50  0000 L CNN
F 2 "Capacitors_THT:CP_Radial_D18.0mm_P7.50mm" H 2288 950 50  0001 C CNN
F 3 "" H 2250 1100 50  0000 C CNN
	1    2250 1100
	1    0    0    -1  
$EndComp
$Comp
L FuenteDePulsos-rescue:GND #PWR05
U 1 1 5812E583
P 2250 1300
F 0 "#PWR05" H 2250 1050 50  0001 C CNN
F 1 "GND" H 2250 1150 50  0000 C CNN
F 2 "" H 2250 1300 50  0000 C CNN
F 3 "" H 2250 1300 50  0000 C CNN
	1    2250 1300
	1    0    0    -1  
$EndComp
Wire Wire Line
	2250 1300 2250 1250
Wire Wire Line
	2950 850  2950 750 
$Comp
L FuenteDePulsos-rescue:CP C2
U 1 1 5812F019
P 2850 1100
F 0 "C2" H 2875 1200 50  0000 L CNN
F 1 "2200uFx35V" H 2875 1000 50  0000 L CNN
F 2 "Capacitors_THT:CP_Radial_D18.0mm_P7.50mm" H 2888 950 50  0001 C CNN
F 3 "" H 2850 1100 50  0000 C CNN
	1    2850 1100
	1    0    0    -1  
$EndComp
Wire Wire Line
	2850 950  2850 850 
Connection ~ 2850 850 
$Comp
L FuenteDePulsos-rescue:GND #PWR06
U 1 1 5812F251
P 2850 1300
F 0 "#PWR06" H 2850 1050 50  0001 C CNN
F 1 "GND" H 2850 1150 50  0000 C CNN
F 2 "" H 2850 1300 50  0000 C CNN
F 3 "" H 2850 1300 50  0000 C CNN
	1    2850 1300
	1    0    0    -1  
$EndComp
Wire Wire Line
	2850 1300 2850 1250
$Comp
L FuenteDePulsos-rescue:+5V #PWR07
U 1 1 5BF88AFB
P 2300 3250
F 0 "#PWR07" H 2300 3100 50  0001 C CNN
F 1 "+5V" H 2300 3390 50  0000 C CNN
F 2 "" H 2300 3250 50  0000 C CNN
F 3 "" H 2300 3250 50  0000 C CNN
	1    2300 3250
	1    0    0    -1  
$EndComp
$Comp
L FuenteDePulsos-rescue:2N3906 Q1
U 1 1 5BF88B01
P 2200 4000
F 0 "Q1" H 2400 4075 50  0000 L CNN
F 1 "2N3906" H 2400 4000 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-92_Molded_Narrow" H 2400 3925 50  0001 L CIN
F 3 "" H 2200 4000 50  0001 L CNN
	1    2200 4000
	1    0    0    1   
$EndComp
$Comp
L FuenteDePulsos-rescue:R R3
U 1 1 5BF88B08
P 2300 3500
F 0 "R3" V 2380 3500 50  0000 C CNN
F 1 "4k7" V 2300 3500 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 2230 3500 50  0001 C CNN
F 3 "" H 2300 3500 50  0000 C CNN
	1    2300 3500
	1    0    0    -1  
$EndComp
$Comp
L FuenteDePulsos-rescue:R R5
U 1 1 5BF88B0F
P 2700 3700
F 0 "R5" V 2780 3700 50  0000 C CNN
F 1 "1k" V 2700 3700 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 2630 3700 50  0001 C CNN
F 3 "" H 2700 3700 50  0000 C CNN
	1    2700 3700
	0    1    1    0   
$EndComp
$Comp
L FuenteDePulsos-rescue:R R1
U 1 1 5BF88B16
P 1750 4000
F 0 "R1" V 1830 4000 50  0000 C CNN
F 1 "1k" V 1750 4000 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 1680 4000 50  0001 C CNN
F 3 "" H 1750 4000 50  0000 C CNN
	1    1750 4000
	0    1    1    0   
$EndComp
$Comp
L FuenteDePulsos-rescue:GND #PWR08
U 1 1 5BF88B1D
P 2300 4300
F 0 "#PWR08" H 2300 4050 50  0001 C CNN
F 1 "GND" H 2300 4150 50  0000 C CNN
F 2 "" H 2300 4300 50  0000 C CNN
F 3 "" H 2300 4300 50  0000 C CNN
	1    2300 4300
	1    0    0    -1  
$EndComp
$Comp
L FuenteDePulsos-rescue:R R9
U 1 1 5BF88B23
P 3300 4100
F 0 "R9" V 3380 4100 50  0000 C CNN
F 1 "1k8" V 3300 4100 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 3230 4100 50  0001 C CNN
F 3 "" H 3300 4100 50  0000 C CNN
	1    3300 4100
	-1   0    0    1   
$EndComp
$Comp
L FuenteDePulsos-rescue:GND #PWR09
U 1 1 5BF88B2A
P 3300 4300
F 0 "#PWR09" H 3300 4050 50  0001 C CNN
F 1 "GND" H 3300 4150 50  0000 C CNN
F 2 "" H 3300 4300 50  0000 C CNN
F 3 "" H 3300 4300 50  0000 C CNN
	1    3300 4300
	1    0    0    -1  
$EndComp
$Comp
L FuenteDePulsos-rescue:2N3904 Q3
U 1 1 5BF88B30
P 3200 3700
F 0 "Q3" H 3400 3775 50  0000 L CNN
F 1 "2N3904" H 3400 3700 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-92_Molded_Narrow" H 3400 3625 50  0001 L CIN
F 3 "" H 3200 3700 50  0001 L CNN
	1    3200 3700
	1    0    0    -1  
$EndComp
$Comp
L FuenteDePulsos-rescue:BC327 Q5
U 1 1 5BF88B37
P 3900 3100
F 0 "Q5" H 4100 3175 50  0000 L CNN
F 1 "BC327" H 4100 3100 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-92_Molded_Narrow" H 4100 3025 50  0001 L CIN
F 3 "" H 3900 3100 50  0001 L CNN
	1    3900 3100
	1    0    0    1   
$EndComp
$Comp
L FuenteDePulsos-rescue:2N3906 Q7
U 1 1 5BF88B3E
P 4650 3900
F 0 "Q7" H 4850 3975 50  0000 L CNN
F 1 "2N3906" H 4850 3900 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-92_Molded_Narrow" H 4850 3825 50  0001 L CIN
F 3 "" H 4650 3900 50  0001 L CNN
	1    4650 3900
	1    0    0    1   
$EndComp
$Comp
L FuenteDePulsos-rescue:1N4148 D1
U 1 1 5BF88B45
P 4400 3650
F 0 "D1" H 4400 3750 50  0000 C CNN
F 1 "1N4148" H 4400 3550 50  0000 C CNN
F 2 "Diodes_THT:D_A-405_P7.62mm_Horizontal" H 4400 3475 50  0001 C CNN
F 3 "" H 4400 3650 50  0001 C CNN
	1    4400 3650
	-1   0    0    1   
$EndComp
Text Label 7300 900  0    60   ~ 0
Pulso1
Text Label 7300 1300 0    60   ~ 0
Pulso2
Text Label 7300 1000 0    60   ~ 0
PWM1
Text Label 7300 1200 0    60   ~ 0
PWM2
Wire Wire Line
	7100 1300 7300 1300
Wire Wire Line
	7300 1200 7100 1200
Wire Wire Line
	7100 1000 7300 1000
Wire Wire Line
	7300 900  7100 900 
$Comp
L FuenteDePulsos-rescue:GND #PWR010
U 1 1 5BF89051
P 7200 1550
F 0 "#PWR010" H 7200 1300 50  0001 C CNN
F 1 "GND" H 7200 1400 50  0000 C CNN
F 2 "" H 7200 1550 50  0000 C CNN
F 3 "" H 7200 1550 50  0000 C CNN
	1    7200 1550
	1    0    0    -1  
$EndComp
Wire Wire Line
	7100 1100 7200 1100
Wire Wire Line
	7200 1100 7200 1550
$Comp
L FuenteDePulsos-rescue:+5V #PWR011
U 1 1 5BF89060
P 1550 1900
F 0 "#PWR011" H 1550 1750 50  0001 C CNN
F 1 "+5V" H 1550 2040 50  0000 C CNN
F 2 "" H 1550 1900 50  0000 C CNN
F 3 "" H 1550 1900 50  0000 C CNN
	1    1550 1900
	1    0    0    -1  
$EndComp
$Comp
L FuenteDePulsos-rescue:GND #PWR012
U 1 1 5BF89068
P 1550 2400
F 0 "#PWR012" H 1550 2150 50  0001 C CNN
F 1 "GND" H 1550 2250 50  0000 C CNN
F 2 "" H 1550 2400 50  0000 C CNN
F 3 "" H 1550 2400 50  0000 C CNN
	1    1550 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	1550 2350 1550 2400
$Comp
L FuenteDePulsos-rescue:C C5
U 1 1 5BF89070
P 1550 2200
F 0 "C5" H 1575 2300 50  0000 L CNN
F 1 "100nF" H 1575 2100 50  0000 L CNN
F 2 "Capacitors_THT:C_Disc_D5.0mm_W2.5mm_P2.50mm" H 1588 2050 50  0001 C CNN
F 3 "" H 1550 2200 50  0000 C CNN
	1    1550 2200
	1    0    0    -1  
$EndComp
$Comp
L FuenteDePulsos-rescue:R R15
U 1 1 5BF8959B
P 5150 3650
F 0 "R15" V 5230 3650 50  0000 C CNN
F 1 "22" V 5150 3650 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 5080 3650 50  0001 C CNN
F 3 "" H 5150 3650 50  0000 C CNN
	1    5150 3650
	0    1    1    0   
$EndComp
$Comp
L FuenteDePulsos-rescue:R R17
U 1 1 5BF89668
P 5550 4100
F 0 "R17" V 5630 4100 50  0000 C CNN
F 1 "1k8" V 5550 4100 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 5480 4100 50  0001 C CNN
F 3 "" H 5550 4100 50  0000 C CNN
	1    5550 4100
	-1   0    0    1   
$EndComp
$Comp
L FuenteDePulsos-rescue:GND #PWR013
U 1 1 5BF896DC
P 4750 4300
F 0 "#PWR013" H 4750 4050 50  0001 C CNN
F 1 "GND" H 4750 4150 50  0000 C CNN
F 2 "" H 4750 4300 50  0000 C CNN
F 3 "" H 4750 4300 50  0000 C CNN
	1    4750 4300
	1    0    0    -1  
$EndComp
$Comp
L FuenteDePulsos-rescue:GND #PWR014
U 1 1 5BF8971D
P 5550 4300
F 0 "#PWR014" H 5550 4050 50  0001 C CNN
F 1 "GND" H 5550 4150 50  0000 C CNN
F 2 "" H 5550 4300 50  0000 C CNN
F 3 "" H 5550 4300 50  0000 C CNN
	1    5550 4300
	1    0    0    -1  
$EndComp
$Comp
L FuenteDePulsos-rescue:C C3
U 1 1 5BF89920
P 4700 2950
F 0 "C3" H 4725 3050 50  0000 L CNN
F 1 "100nF" H 4725 2850 50  0000 L CNN
F 2 "Capacitors_THT:C_Disc_D5.0mm_W2.5mm_P2.50mm" H 4738 2800 50  0001 C CNN
F 3 "" H 4700 2950 50  0000 C CNN
	1    4700 2950
	1    0    0    -1  
$EndComp
$Comp
L FuenteDePulsos-rescue:+24V #PWR015
U 1 1 5BF89B8B
P 5300 2900
F 0 "#PWR015" H 5300 2750 50  0001 C CNN
F 1 "+24V" H 5300 3040 50  0000 C CNN
F 2 "" H 5300 2900 50  0000 C CNN
F 3 "" H 5300 2900 50  0000 C CNN
	1    5300 2900
	1    0    0    -1  
$EndComp
Wire Wire Line
	3300 2700 4000 2700
Wire Wire Line
	4700 2700 4700 2800
Wire Wire Line
	4000 2700 4000 2900
$Comp
L FuenteDePulsos-rescue:GND #PWR016
U 1 1 5BF89C82
P 4700 3150
F 0 "#PWR016" H 4700 2900 50  0001 C CNN
F 1 "GND" H 4700 3000 50  0000 C CNN
F 2 "" H 4700 3150 50  0000 C CNN
F 3 "" H 4700 3150 50  0000 C CNN
	1    4700 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	4700 3100 4700 3150
$Comp
L FuenteDePulsos-rescue:R R13
U 1 1 5BF89DEB
P 4000 4100
F 0 "R13" V 4080 4100 50  0000 C CNN
F 1 "4k7" V 4000 4100 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 3930 4100 50  0001 C CNN
F 3 "" H 4000 4100 50  0000 C CNN
	1    4000 4100
	1    0    0    -1  
$EndComp
$Comp
L FuenteDePulsos-rescue:R R8
U 1 1 5BF89E75
P 3300 3300
F 0 "R8" V 3380 3300 50  0000 C CNN
F 1 "1k" V 3300 3300 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 3230 3300 50  0001 C CNN
F 3 "" H 3300 3300 50  0000 C CNN
	1    3300 3300
	-1   0    0    1   
$EndComp
$Comp
L FuenteDePulsos-rescue:R R7
U 1 1 5BF89EEA
P 3300 2900
F 0 "R7" V 3380 2900 50  0000 C CNN
F 1 "4k7" V 3300 2900 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 3230 2900 50  0001 C CNN
F 3 "" H 3300 2900 50  0000 C CNN
	1    3300 2900
	1    0    0    -1  
$EndComp
Wire Wire Line
	3300 2700 3300 2750
Connection ~ 4000 2700
Wire Wire Line
	3700 3100 3300 3100
Wire Wire Line
	3300 3050 3300 3100
Connection ~ 3300 3100
Wire Wire Line
	3300 3450 3300 3500
Wire Wire Line
	4000 3300 4000 3650
Wire Wire Line
	4000 3650 4250 3650
Wire Wire Line
	4550 3650 4750 3650
Wire Wire Line
	4750 3650 4750 3700
Connection ~ 4750 3650
Wire Wire Line
	4000 3900 4450 3900
Connection ~ 4000 3650
Connection ~ 4000 3900
$Comp
L FuenteDePulsos-rescue:GND #PWR017
U 1 1 5BF8A378
P 4000 4300
F 0 "#PWR017" H 4000 4050 50  0001 C CNN
F 1 "GND" H 4000 4150 50  0000 C CNN
F 2 "" H 4000 4300 50  0000 C CNN
F 3 "" H 4000 4300 50  0000 C CNN
	1    4000 4300
	1    0    0    -1  
$EndComp
Wire Wire Line
	4000 4300 4000 4250
Wire Wire Line
	4750 4300 4750 4100
Wire Wire Line
	5550 4300 5550 4250
Wire Wire Line
	5550 3950 5550 3650
Wire Wire Line
	5300 3650 5550 3650
Connection ~ 5550 3650
Text Label 1400 4000 2    60   ~ 0
PWM1
Wire Wire Line
	1400 4000 1600 4000
Wire Wire Line
	1900 4000 2000 4000
Wire Wire Line
	2300 4200 2300 4300
Wire Wire Line
	2300 3650 2300 3700
Wire Wire Line
	2300 3250 2300 3350
Wire Wire Line
	2550 3700 2300 3700
Connection ~ 2300 3700
Wire Wire Line
	2850 3700 3000 3700
Wire Wire Line
	3300 3900 3300 3950
Wire Wire Line
	3300 4250 3300 4300
Wire Wire Line
	5300 2900 5300 3000
Wire Wire Line
	5300 3000 5050 3000
Wire Wire Line
	5050 3000 5050 2700
Connection ~ 4700 2700
$Comp
L FuenteDePulsos-rescue:+5V #PWR018
U 1 1 5BF8B89C
P 2300 5400
F 0 "#PWR018" H 2300 5250 50  0001 C CNN
F 1 "+5V" H 2300 5540 50  0000 C CNN
F 2 "" H 2300 5400 50  0000 C CNN
F 3 "" H 2300 5400 50  0000 C CNN
	1    2300 5400
	1    0    0    -1  
$EndComp
$Comp
L FuenteDePulsos-rescue:2N3906 Q2
U 1 1 5BF8B8A2
P 2200 6150
F 0 "Q2" H 2400 6225 50  0000 L CNN
F 1 "2N3906" H 2400 6150 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-92_Molded_Narrow" H 2400 6075 50  0001 L CIN
F 3 "" H 2200 6150 50  0001 L CNN
	1    2200 6150
	1    0    0    1   
$EndComp
$Comp
L FuenteDePulsos-rescue:R R4
U 1 1 5BF8B8A8
P 2300 5650
F 0 "R4" V 2380 5650 50  0000 C CNN
F 1 "4k7" V 2300 5650 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 2230 5650 50  0001 C CNN
F 3 "" H 2300 5650 50  0000 C CNN
	1    2300 5650
	1    0    0    -1  
$EndComp
$Comp
L FuenteDePulsos-rescue:R R6
U 1 1 5BF8B8AE
P 2700 5850
F 0 "R6" V 2780 5850 50  0000 C CNN
F 1 "1k" V 2700 5850 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 2630 5850 50  0001 C CNN
F 3 "" H 2700 5850 50  0000 C CNN
	1    2700 5850
	0    1    1    0   
$EndComp
$Comp
L FuenteDePulsos-rescue:R R2
U 1 1 5BF8B8B4
P 1750 6150
F 0 "R2" V 1830 6150 50  0000 C CNN
F 1 "1k" V 1750 6150 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 1680 6150 50  0001 C CNN
F 3 "" H 1750 6150 50  0000 C CNN
	1    1750 6150
	0    1    1    0   
$EndComp
$Comp
L FuenteDePulsos-rescue:GND #PWR019
U 1 1 5BF8B8BA
P 2300 6450
F 0 "#PWR019" H 2300 6200 50  0001 C CNN
F 1 "GND" H 2300 6300 50  0000 C CNN
F 2 "" H 2300 6450 50  0000 C CNN
F 3 "" H 2300 6450 50  0000 C CNN
	1    2300 6450
	1    0    0    -1  
$EndComp
$Comp
L FuenteDePulsos-rescue:R R12
U 1 1 5BF8B8C0
P 3300 6250
F 0 "R12" V 3380 6250 50  0000 C CNN
F 1 "1k8" V 3300 6250 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 3230 6250 50  0001 C CNN
F 3 "" H 3300 6250 50  0000 C CNN
	1    3300 6250
	-1   0    0    1   
$EndComp
$Comp
L FuenteDePulsos-rescue:GND #PWR020
U 1 1 5BF8B8C6
P 3300 6450
F 0 "#PWR020" H 3300 6200 50  0001 C CNN
F 1 "GND" H 3300 6300 50  0000 C CNN
F 2 "" H 3300 6450 50  0000 C CNN
F 3 "" H 3300 6450 50  0000 C CNN
	1    3300 6450
	1    0    0    -1  
$EndComp
$Comp
L FuenteDePulsos-rescue:2N3904 Q4
U 1 1 5BF8B8CC
P 3200 5850
F 0 "Q4" H 3400 5925 50  0000 L CNN
F 1 "2N3904" H 3400 5850 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-92_Molded_Narrow" H 3400 5775 50  0001 L CIN
F 3 "" H 3200 5850 50  0001 L CNN
	1    3200 5850
	1    0    0    -1  
$EndComp
$Comp
L FuenteDePulsos-rescue:BC327 Q6
U 1 1 5BF8B8D2
P 3900 5250
F 0 "Q6" H 4100 5325 50  0000 L CNN
F 1 "BC327" H 4100 5250 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-92_Molded_Narrow" H 4100 5175 50  0001 L CIN
F 3 "" H 3900 5250 50  0001 L CNN
	1    3900 5250
	1    0    0    1   
$EndComp
$Comp
L FuenteDePulsos-rescue:2N3906 Q8
U 1 1 5BF8B8D8
P 4650 6050
F 0 "Q8" H 4850 6125 50  0000 L CNN
F 1 "2N3906" H 4850 6050 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-92_Molded_Narrow" H 4850 5975 50  0001 L CIN
F 3 "" H 4650 6050 50  0001 L CNN
	1    4650 6050
	1    0    0    1   
$EndComp
$Comp
L FuenteDePulsos-rescue:1N4148 D2
U 1 1 5BF8B8DE
P 4400 5800
F 0 "D2" H 4400 5900 50  0000 C CNN
F 1 "1N4148" H 4400 5700 50  0000 C CNN
F 2 "Diodes_THT:D_A-405_P7.62mm_Horizontal" H 4400 5625 50  0001 C CNN
F 3 "" H 4400 5800 50  0001 C CNN
	1    4400 5800
	-1   0    0    1   
$EndComp
$Comp
L FuenteDePulsos-rescue:R R16
U 1 1 5BF8B8E4
P 5150 5800
F 0 "R16" V 5230 5800 50  0000 C CNN
F 1 "22" V 5150 5800 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 5080 5800 50  0001 C CNN
F 3 "" H 5150 5800 50  0000 C CNN
	1    5150 5800
	0    1    1    0   
$EndComp
$Comp
L FuenteDePulsos-rescue:R R18
U 1 1 5BF8B8EA
P 5550 6250
F 0 "R18" V 5630 6250 50  0000 C CNN
F 1 "1k8" V 5550 6250 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 5480 6250 50  0001 C CNN
F 3 "" H 5550 6250 50  0000 C CNN
	1    5550 6250
	-1   0    0    1   
$EndComp
$Comp
L FuenteDePulsos-rescue:GND #PWR021
U 1 1 5BF8B8F0
P 4750 6450
F 0 "#PWR021" H 4750 6200 50  0001 C CNN
F 1 "GND" H 4750 6300 50  0000 C CNN
F 2 "" H 4750 6450 50  0000 C CNN
F 3 "" H 4750 6450 50  0000 C CNN
	1    4750 6450
	1    0    0    -1  
$EndComp
$Comp
L FuenteDePulsos-rescue:GND #PWR022
U 1 1 5BF8B8F6
P 5550 6450
F 0 "#PWR022" H 5550 6200 50  0001 C CNN
F 1 "GND" H 5550 6300 50  0000 C CNN
F 2 "" H 5550 6450 50  0000 C CNN
F 3 "" H 5550 6450 50  0000 C CNN
	1    5550 6450
	1    0    0    -1  
$EndComp
$Comp
L FuenteDePulsos-rescue:C C4
U 1 1 5BF8B8FC
P 4700 5100
F 0 "C4" H 4725 5200 50  0000 L CNN
F 1 "100nF" H 4725 5000 50  0000 L CNN
F 2 "Capacitors_THT:C_Disc_D5.0mm_W2.5mm_P2.50mm" H 4738 4950 50  0001 C CNN
F 3 "" H 4700 5100 50  0000 C CNN
	1    4700 5100
	1    0    0    -1  
$EndComp
$Comp
L FuenteDePulsos-rescue:+24V #PWR023
U 1 1 5BF8B902
P 5300 5050
F 0 "#PWR023" H 5300 4900 50  0001 C CNN
F 1 "+24V" H 5300 5190 50  0000 C CNN
F 2 "" H 5300 5050 50  0000 C CNN
F 3 "" H 5300 5050 50  0000 C CNN
	1    5300 5050
	1    0    0    -1  
$EndComp
Wire Wire Line
	3300 4850 4000 4850
Wire Wire Line
	4700 4850 4700 4950
Wire Wire Line
	4000 4850 4000 5050
$Comp
L FuenteDePulsos-rescue:GND #PWR024
U 1 1 5BF8B90D
P 4700 5300
F 0 "#PWR024" H 4700 5050 50  0001 C CNN
F 1 "GND" H 4700 5150 50  0000 C CNN
F 2 "" H 4700 5300 50  0000 C CNN
F 3 "" H 4700 5300 50  0000 C CNN
	1    4700 5300
	1    0    0    -1  
$EndComp
Wire Wire Line
	4700 5250 4700 5300
$Comp
L FuenteDePulsos-rescue:R R14
U 1 1 5BF8B914
P 4000 6250
F 0 "R14" V 4080 6250 50  0000 C CNN
F 1 "4k7" V 4000 6250 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 3930 6250 50  0001 C CNN
F 3 "" H 4000 6250 50  0000 C CNN
	1    4000 6250
	1    0    0    -1  
$EndComp
$Comp
L FuenteDePulsos-rescue:R R11
U 1 1 5BF8B91A
P 3300 5450
F 0 "R11" V 3380 5450 50  0000 C CNN
F 1 "1k" V 3300 5450 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 3230 5450 50  0001 C CNN
F 3 "" H 3300 5450 50  0000 C CNN
	1    3300 5450
	-1   0    0    1   
$EndComp
$Comp
L FuenteDePulsos-rescue:R R10
U 1 1 5BF8B920
P 3300 5050
F 0 "R10" V 3380 5050 50  0000 C CNN
F 1 "4k7" V 3300 5050 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 3230 5050 50  0001 C CNN
F 3 "" H 3300 5050 50  0000 C CNN
	1    3300 5050
	1    0    0    -1  
$EndComp
Wire Wire Line
	3300 4850 3300 4900
Connection ~ 4000 4850
Wire Wire Line
	3700 5250 3300 5250
Wire Wire Line
	3300 5200 3300 5250
Connection ~ 3300 5250
Wire Wire Line
	3300 5600 3300 5650
Wire Wire Line
	4000 5450 4000 5800
Wire Wire Line
	4000 5800 4250 5800
Wire Wire Line
	4550 5800 4750 5800
Wire Wire Line
	4750 5800 4750 5850
Connection ~ 4750 5800
Wire Wire Line
	4000 6050 4450 6050
Connection ~ 4000 5800
Connection ~ 4000 6050
$Comp
L FuenteDePulsos-rescue:GND #PWR025
U 1 1 5BF8B938
P 4000 6450
F 0 "#PWR025" H 4000 6200 50  0001 C CNN
F 1 "GND" H 4000 6300 50  0000 C CNN
F 2 "" H 4000 6450 50  0000 C CNN
F 3 "" H 4000 6450 50  0000 C CNN
	1    4000 6450
	1    0    0    -1  
$EndComp
Wire Wire Line
	4000 6450 4000 6400
Wire Wire Line
	4750 6450 4750 6250
Wire Wire Line
	5550 6450 5550 6400
Wire Wire Line
	5550 6100 5550 5800
Wire Wire Line
	5300 5800 5550 5800
Connection ~ 5550 5800
Text Label 1400 6150 2    60   ~ 0
PWM2
Wire Wire Line
	1400 6150 1600 6150
Wire Wire Line
	1900 6150 2000 6150
Wire Wire Line
	2300 6350 2300 6450
Wire Wire Line
	2300 5800 2300 5850
Wire Wire Line
	2300 5400 2300 5500
Wire Wire Line
	2550 5850 2300 5850
Connection ~ 2300 5850
Wire Wire Line
	2850 5850 3000 5850
Wire Wire Line
	3300 6050 3300 6100
Wire Wire Line
	3300 6400 3300 6450
Wire Wire Line
	5300 5050 5300 5150
Wire Wire Line
	5300 5150 5050 5150
Wire Wire Line
	5050 5150 5050 4850
Connection ~ 4700 4850
Text Label 7450 3700 2    60   ~ 0
Pulso1
Text Label 7450 3850 2    60   ~ 0
Pulso2
Wire Wire Line
	7450 3850 7550 3850
Wire Wire Line
	7550 3700 7450 3700
Wire Wire Line
	7550 4150 6550 4150
Wire Wire Line
	6550 4150 6550 3650
Wire Wire Line
	7550 5000 6550 5000
Wire Wire Line
	6550 5000 6550 5800
$Comp
L FuenteDePulsos-rescue:D_Zener D6
U 1 1 5BF95E93
P 6050 6150
F 0 "D6" H 6050 6250 50  0000 C CNN
F 1 "Dz 18v" H 6050 6050 50  0000 C CNN
F 2 "Diodes_THT:D_A-405_P7.62mm_Horizontal" H 6050 6150 50  0001 C CNN
F 3 "" H 6050 6150 50  0001 C CNN
	1    6050 6150
	0    1    1    0   
$EndComp
Wire Wire Line
	6050 6000 6050 5800
Connection ~ 6050 5800
$Comp
L FuenteDePulsos-rescue:GND #PWR026
U 1 1 5BF96199
P 6050 6450
F 0 "#PWR026" H 6050 6200 50  0001 C CNN
F 1 "GND" H 6050 6300 50  0000 C CNN
F 2 "" H 6050 6450 50  0000 C CNN
F 3 "" H 6050 6450 50  0000 C CNN
	1    6050 6450
	1    0    0    -1  
$EndComp
Wire Wire Line
	6050 6300 6050 6450
$Comp
L FuenteDePulsos-rescue:D_Zener D7
U 1 1 5BF962DC
P 6100 4050
F 0 "D7" H 6100 4150 50  0000 C CNN
F 1 "Dz 18v" H 6100 3950 50  0000 C CNN
F 2 "Diodes_THT:D_A-405_P7.62mm_Horizontal" H 6100 4050 50  0001 C CNN
F 3 "" H 6100 4050 50  0001 C CNN
	1    6100 4050
	0    1    1    0   
$EndComp
$Comp
L FuenteDePulsos-rescue:GND #PWR027
U 1 1 5BF965A1
P 6100 4300
F 0 "#PWR027" H 6100 4050 50  0001 C CNN
F 1 "GND" H 6100 4150 50  0000 C CNN
F 2 "" H 6100 4300 50  0000 C CNN
F 3 "" H 6100 4300 50  0000 C CNN
	1    6100 4300
	1    0    0    -1  
$EndComp
Wire Wire Line
	6100 4200 6100 4300
Wire Wire Line
	6100 3900 6100 3650
Connection ~ 6100 3650
$Comp
L FuenteDePulsos-rescue:PWR_FLAG #FLG028
U 1 1 5BF988F1
P 1800 1900
F 0 "#FLG028" H 1800 1995 50  0001 C CNN
F 1 "PWR_FLAG" H 1800 2080 50  0000 C CNN
F 2 "" H 1800 1900 50  0000 C CNN
F 3 "" H 1800 1900 50  0000 C CNN
	1    1800 1900
	1    0    0    -1  
$EndComp
$Comp
L FuenteDePulsos-rescue:Conn_01x05 J2
U 1 1 5BFC5656
P 6900 1100
F 0 "J2" H 6900 1400 50  0000 C CNN
F 1 "Conn_01x05" H 6900 800 50  0000 C CNN
F 2 "Connectors_Terminal_Blocks:TerminalBlock_bornier-5_P5.08mm" H 6900 1100 50  0001 C CNN
F 3 "" H 6900 1100 50  0001 C CNN
	1    6900 1100
	-1   0    0    1   
$EndComp
$Comp
L FuenteDePulsos-rescue:Conn_01x03 J1
U 1 1 5BFCC548
P 750 950
F 0 "J1" H 750 1150 50  0000 C CNN
F 1 "Conn_01x03" H 750 750 50  0000 C CNN
F 2 "Connectors_Terminal_Blocks:TerminalBlock_bornier-3_P5.08mm" H 750 950 50  0001 C CNN
F 3 "" H 750 950 50  0001 C CNN
	1    750  950 
	-1   0    0    1   
$EndComp
Wire Wire Line
	1550 1900 1550 2000
Wire Wire Line
	1150 2000 1550 2000
Wire Wire Line
	1800 2000 1800 1900
Connection ~ 1550 2000
Wire Wire Line
	1150 2000 1150 1050
Wire Wire Line
	1150 1050 950  1050
$Comp
L FuenteDePulsos-rescue:Conn_01x01 J5
U 1 1 5BFD8C17
P 9350 800
F 0 "J5" H 9350 900 50  0000 C CNN
F 1 "Agujero" H 9350 700 50  0000 C CNN
F 2 "Mounting_Holes:MountingHole_3.7mm" H 9350 800 50  0001 C CNN
F 3 "" H 9350 800 50  0001 C CNN
	1    9350 800 
	0    -1   -1   0   
$EndComp
$Comp
L FuenteDePulsos-rescue:Conn_01x01 J6
U 1 1 5BFD9133
P 9650 800
F 0 "J6" H 9650 900 50  0000 C CNN
F 1 "Agujero" H 9650 700 50  0000 C CNN
F 2 "Mounting_Holes:MountingHole_3.7mm" H 9650 800 50  0001 C CNN
F 3 "" H 9650 800 50  0001 C CNN
	1    9650 800 
	0    -1   -1   0   
$EndComp
$Comp
L FuenteDePulsos-rescue:Conn_01x01 J7
U 1 1 5BFD91EF
P 9950 800
F 0 "J7" H 9950 900 50  0000 C CNN
F 1 "Agujero" H 9950 700 50  0000 C CNN
F 2 "Mounting_Holes:MountingHole_3.7mm" H 9950 800 50  0001 C CNN
F 3 "" H 9950 800 50  0001 C CNN
	1    9950 800 
	0    -1   -1   0   
$EndComp
$Comp
L FuenteDePulsos-rescue:Conn_01x01 J8
U 1 1 5BFD929A
P 10250 800
F 0 "J8" H 10250 900 50  0000 C CNN
F 1 "Agujero" H 10250 700 50  0000 C CNN
F 2 "Mounting_Holes:MountingHole_3.7mm" H 10250 800 50  0001 C CNN
F 3 "" H 10250 800 50  0001 C CNN
	1    10250 800 
	0    -1   -1   0   
$EndComp
NoConn ~ 10250 1000
NoConn ~ 9950 1000
NoConn ~ 9650 1000
NoConn ~ 9350 1000
Wire Wire Line
	1550 1250 1550 1350
Wire Wire Line
	2250 850  2850 850 
Wire Wire Line
	2250 850  2250 950 
Wire Wire Line
	2850 850  2950 850 
Wire Wire Line
	4000 2700 4700 2700
Wire Wire Line
	3300 3100 3300 3150
Wire Wire Line
	4750 3650 5000 3650
Wire Wire Line
	4000 3650 4000 3900
Wire Wire Line
	4000 3900 4000 3950
Wire Wire Line
	5550 3650 6100 3650
Wire Wire Line
	2300 3700 2300 3800
Wire Wire Line
	4700 2700 5050 2700
Wire Wire Line
	4000 4850 4700 4850
Wire Wire Line
	3300 5250 3300 5300
Wire Wire Line
	4750 5800 5000 5800
Wire Wire Line
	4000 5800 4000 6050
Wire Wire Line
	4000 6050 4000 6100
Wire Wire Line
	5550 5800 6050 5800
Wire Wire Line
	2300 5850 2300 5950
Wire Wire Line
	4700 4850 5050 4850
Wire Wire Line
	6050 5800 6550 5800
Wire Wire Line
	6100 3650 6550 3650
Wire Wire Line
	1550 2000 1550 2050
Wire Wire Line
	1550 2000 1800 2000
$EndSCHEMATC
