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
Sheet 4 4
Title "Control y potencia para máquina de etching"
Date ""
Rev ""
Comp "LCI - FIUBA"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 8200 2400 2    60   Input ~ 0
RXD
Text HLabel 8200 2250 2    60   Output ~ 0
TXD
Wire Wire Line
	3100 3000 3100 3250
Text Label 3000 3100 3    60   ~ 0
D+
Text Label 2900 3100 3    60   ~ 0
D-
$Comp
L +5V #PWR054
U 1 1 580E7BE8
P 2750 1000
F 0 "#PWR054" H 2750 1090 20  0001 C CNN
F 1 "+5V" H 2750 1090 30  0000 C CNN
F 2 "" H 2750 1000 60  0000 C CNN
F 3 "" H 2750 1000 60  0000 C CNN
	1    2750 1000
	1    0    0    -1  
$EndComp
Wire Wire Line
	6500 4550 6500 4700
Wire Wire Line
	6500 4700 7100 4700
Wire Wire Line
	6950 4700 6950 4550
Wire Wire Line
	6800 4550 6800 4900
Connection ~ 6800 4700
Wire Wire Line
	6650 4550 6650 4700
Connection ~ 6650 4700
Text Label 5250 2850 2    60   ~ 0
D+
Text Label 5250 2700 2    60   ~ 0
D-
Wire Wire Line
	5250 2850 5700 2850
Wire Wire Line
	5700 2700 5250 2700
$Comp
L LED D1
U 1 1 580E7BEA
P 10100 3000
F 0 "D1" H 10100 3100 50  0000 C CNN
F 1 "LED" H 10100 2900 50  0000 C CNN
F 2 "LEDs:LED-5MM" H 10100 3000 60  0001 C CNN
F 3 "" H 10100 3000 60  0000 C CNN
	1    10100 3000
	0    1    1    0   
$EndComp
$Comp
L R R29
U 1 1 580E7BEB
P 10100 3500
F 0 "R29" V 10180 3500 40  0000 C CNN
F 1 "270" V 10107 3501 40  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM7mm" V 10030 3500 30  0001 C CNN
F 3 "" H 10100 3500 30  0000 C CNN
	1    10100 3500
	1    0    0    -1  
$EndComp
Wire Wire Line
	10100 2650 10100 2800
Wire Wire Line
	10100 3200 10100 3350
Text Label 10100 3900 0    60   ~ 0
LED_UART
Wire Wire Line
	10100 3900 10100 3650
Text HLabel 2450 1050 0    60   UnSpc ~ 0
+5v
Text HLabel 2450 1250 0    60   UnSpc ~ 0
GND
Wire Wire Line
	2750 1000 2750 1050
Wire Wire Line
	2750 1050 2450 1050
$Comp
L GND #PWR055
U 1 1 580E7BEC
P 2750 1300
F 0 "#PWR055" H 2750 1300 30  0001 C CNN
F 1 "GND" H 2750 1230 30  0001 C CNN
F 2 "" H 2750 1300 60  0000 C CNN
F 3 "" H 2750 1300 60  0000 C CNN
	1    2750 1300
	1    0    0    -1  
$EndComp
Wire Wire Line
	2450 1250 2750 1250
Wire Wire Line
	2750 1250 2750 1300
$Comp
L R R28
U 1 1 580E7BED
P 2800 4100
F 0 "R28" V 2880 4100 40  0000 C CNN
F 1 "10k" V 2807 4101 40  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM7mm" V 2730 4100 30  0001 C CNN
F 3 "" H 2800 4100 30  0000 C CNN
	1    2800 4100
	1    0    0    -1  
$EndComp
$Comp
L R R27
U 1 1 580E7BEE
P 2800 3550
F 0 "R27" V 2880 3550 40  0000 C CNN
F 1 "4.7k" V 2807 3551 40  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM7mm" V 2730 3550 30  0001 C CNN
F 3 "" H 2800 3550 30  0000 C CNN
	1    2800 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	2800 3700 2800 3950
Connection ~ 2800 3800
Wire Wire Line
	2800 4400 2800 4250
Text Label 2400 3800 2    60   ~ 0
Reset
Wire Wire Line
	2400 3800 2800 3800
Wire Wire Line
	5400 1950 5400 2400
Wire Wire Line
	5400 2250 5700 2250
Wire Wire Line
	5400 2400 5700 2400
Connection ~ 5400 2250
$Comp
L C C13
U 1 1 580E7BEF
P 5300 4300
F 0 "C13" H 5300 4400 40  0000 L CNN
F 1 "100n" H 5306 4215 40  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Disc_D3_P2.5" H 5338 4150 30  0001 C CNN
F 3 "" H 5300 4300 60  0000 C CNN
	1    5300 4300
	1    0    0    -1  
$EndComp
Wire Wire Line
	5300 4150 5300 4050
Wire Wire Line
	5300 4050 5700 4050
Wire Wire Line
	5300 4650 5300 4450
Wire Wire Line
	7100 4700 7100 4550
Connection ~ 6950 4700
Text Label 8200 3450 0    60   ~ 0
LED_UART
Wire Wire Line
	5700 3450 4650 3450
Wire Wire Line
	5700 3600 4950 3600
Wire Wire Line
	4950 3600 4950 4050
Wire Wire Line
	4950 4050 4650 4050
NoConn ~ 7900 3300
NoConn ~ 7900 3150
NoConn ~ 7900 3000
NoConn ~ 7900 2850
NoConn ~ 7900 2700
NoConn ~ 7900 2550
Wire Wire Line
	8200 3450 7900 3450
NoConn ~ 7900 3600
NoConn ~ 7900 3750
NoConn ~ 7900 3900
NoConn ~ 7900 4050
Wire Wire Line
	8200 2400 7900 2400
Wire Wire Line
	7900 2250 8200 2250
$Comp
L C C11
U 1 1 580E7BF1
P 2750 5850
F 0 "C11" H 2750 5950 40  0000 L CNN
F 1 "100n" H 2756 5765 40  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Disc_D3_P2.5" H 2788 5700 30  0001 C CNN
F 3 "" H 2750 5850 60  0000 C CNN
	1    2750 5850
	1    0    0    -1  
$EndComp
$Comp
L CP C12
U 1 1 580E7BF2
P 3250 5850
F 0 "C12" H 3300 5950 40  0000 L CNN
F 1 "10uF" H 3300 5750 40  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Radial_D5_L11_P2.5" H 3350 5700 30  0001 C CNN
F 3 "" H 3250 5850 300 0000 C CNN
	1    3250 5850
	1    0    0    -1  
$EndComp
Wire Wire Line
	2750 6000 2750 6150
Wire Wire Line
	2750 6150 3250 6150
Wire Wire Line
	3250 6150 3250 6000
Connection ~ 3000 6150
Wire Wire Line
	2750 5700 2750 5550
Wire Wire Line
	2750 5550 3250 5550
Wire Wire Line
	3250 5550 3250 5700
Connection ~ 3000 5550
Text Notes 5600 1400 0    118  ~ 0
Configuracion Self Powered\n
$Comp
L GND #PWR056
U 1 1 580E7BF3
P 2800 4400
F 0 "#PWR056" H 2800 4400 30  0001 C CNN
F 1 "GND" H 2800 4330 30  0001 C CNN
F 2 "" H 2800 4400 60  0000 C CNN
F 3 "" H 2800 4400 60  0000 C CNN
	1    2800 4400
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR057
U 1 1 580E7BF4
P 3000 6300
F 0 "#PWR057" H 3000 6300 30  0001 C CNN
F 1 "GND" H 3000 6230 30  0001 C CNN
F 2 "" H 3000 6300 60  0000 C CNN
F 3 "" H 3000 6300 60  0000 C CNN
	1    3000 6300
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR058
U 1 1 580E7BF5
P 5300 4650
F 0 "#PWR058" H 5300 4650 30  0001 C CNN
F 1 "GND" H 5300 4580 30  0001 C CNN
F 2 "" H 5300 4650 60  0000 C CNN
F 3 "" H 5300 4650 60  0000 C CNN
	1    5300 4650
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR059
U 1 1 580E7BF6
P 6800 4900
F 0 "#PWR059" H 6800 4900 30  0001 C CNN
F 1 "GND" H 6800 4830 30  0001 C CNN
F 2 "" H 6800 4900 60  0000 C CNN
F 3 "" H 6800 4900 60  0000 C CNN
	1    6800 4900
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR060
U 1 1 580E7BF7
P 5400 1950
F 0 "#PWR060" H 5400 2040 20  0001 C CNN
F 1 "+5V" H 5400 2040 30  0000 C CNN
F 2 "" H 5400 1950 60  0000 C CNN
F 3 "" H 5400 1950 60  0000 C CNN
	1    5400 1950
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR061
U 1 1 580E7BF8
P 3000 5350
F 0 "#PWR061" H 3000 5440 20  0001 C CNN
F 1 "+5V" H 3000 5440 30  0000 C CNN
F 2 "" H 3000 5350 60  0000 C CNN
F 3 "" H 3000 5350 60  0000 C CNN
	1    3000 5350
	1    0    0    -1  
$EndComp
Wire Wire Line
	3000 6150 3000 6300
Wire Wire Line
	3000 5550 3000 5350
$Comp
L +5V #PWR062
U 1 1 580E7BF9
P 10100 2650
F 0 "#PWR062" H 10100 2740 20  0001 C CNN
F 1 "+5V" H 10100 2740 30  0000 C CNN
F 2 "" H 10100 2650 60  0000 C CNN
F 3 "" H 10100 2650 60  0000 C CNN
	1    10100 2650
	1    0    0    -1  
$EndComp
Text Label 5250 3150 2    60   ~ 0
Reset
Wire Wire Line
	5250 3150 5700 3150
$Comp
L GND #PWR063
U 1 1 580E7BFA
P 3100 3250
F 0 "#PWR063" H 3100 3250 30  0001 C CNN
F 1 "GND" H 3100 3180 30  0001 C CNN
F 2 "" H 3100 3250 60  0000 C CNN
F 3 "" H 3100 3250 60  0000 C CNN
	1    3100 3250
	1    0    0    -1  
$EndComp
$Comp
L Crystal Y2
U 1 1 580E7FC0
P 4650 3750
F 0 "Y2" H 4650 3900 50  0000 C CNN
F 1 "Cristal 12MHz" H 4650 3600 50  0000 C CNN
F 2 "Crystals:Crystal_HC50-U_Vertical" H 4650 3750 50  0001 C CNN
F 3 "" H 4650 3750 50  0000 C CNN
	1    4650 3750
	0    1    1    0   
$EndComp
Wire Wire Line
	4650 3450 4650 3600
Wire Wire Line
	4650 4050 4650 3900
$Comp
L USB_B P7
U 1 1 580E82D5
P 3000 2700
F 0 "P7" H 3200 2500 50  0000 C CNN
F 1 "USB_B" H 2950 2900 50  0000 C CNN
F 2 "Connect:USB_B" V 2950 2600 50  0001 C CNN
F 3 "" V 2950 2600 50  0000 C CNN
	1    3000 2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	2900 3100 2900 3000
Wire Wire Line
	3000 3000 3000 3100
Wire Wire Line
	3100 3100 3400 3100
Wire Wire Line
	3400 3100 3400 2600
Wire Wire Line
	3400 2600 3300 2600
Connection ~ 3100 3100
Wire Wire Line
	2800 3000 2800 3400
$Comp
L FT232RL U3
U 1 1 58569D9F
P 6800 3150
F 0 "U3" H 6050 4350 60  0000 C CNN
F 1 "FT232RL" H 6800 3150 60  0000 C CNN
F 2 "Housings_SSOP:SSOP-28_5.3x10.2mm_Pitch0.65mm" H 6800 3150 60  0001 C CNN
F 3 "" H 6800 3150 60  0001 C CNN
	1    6800 3150
	1    0    0    -1  
$EndComp
$EndSCHEMATC
