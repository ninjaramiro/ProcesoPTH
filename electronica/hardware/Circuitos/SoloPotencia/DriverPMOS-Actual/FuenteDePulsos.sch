EESchema Schematic File Version 4
LIBS:FuenteDePulsos-cache
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
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
L FuenteDePulsos-rescue:R R?
U 1 1 5D82DA65
P 4500 2150
AR Path="/5807F7D2/5D82DA65" Ref="R?"  Part="1" 
AR Path="/5D82DA65" Ref="R4"  Part="1" 
F 0 "R4" V 4580 2150 50  0000 C CNN
F 1 "180" V 4500 2150 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 4430 2150 50  0001 C CNN
F 3 "" H 4500 2150 50  0000 C CNN
	1    4500 2150
	-1   0    0    1   
$EndComp
$Comp
L FuenteDePulsos-rescue:GND #PWR?
U 1 1 5D82DA6B
P 4000 3650
AR Path="/5807F7D2/5D82DA6B" Ref="#PWR?"  Part="1" 
AR Path="/5D82DA6B" Ref="#PWR02"  Part="1" 
F 0 "#PWR02" H 4000 3400 50  0001 C CNN
F 1 "GND" H 4000 3500 50  0000 C CNN
F 2 "" H 4000 3650 50  0000 C CNN
F 3 "" H 4000 3650 50  0000 C CNN
	1    4000 3650
	1    0    0    -1  
$EndComp
$Comp
L FuenteDePulsos-rescue:D D?
U 1 1 5D82DA89
P 1650 2700
AR Path="/5807F7D2/5D82DA89" Ref="D?"  Part="1" 
AR Path="/5D82DA89" Ref="D1"  Part="1" 
F 0 "D1" H 1650 2800 50  0000 C CNN
F 1 "1N4148" H 1650 2600 50  0000 C CNN
F 2 "Diode_THT:D_A-405_P7.62mm_Horizontal" H 1650 2700 50  0001 C CNN
F 3 "" H 1650 2700 50  0000 C CNN
	1    1650 2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	4000 3650 4000 3050
Wire Wire Line
	4500 1950 4500 2000
Wire Wire Line
	3550 2850 3700 2850
$Comp
L Device:D_Zener D?
U 1 1 5D82DAC5
P 4250 2600
AR Path="/5807F7D2/5D82DAC5" Ref="D?"  Part="1" 
AR Path="/5D82DAC5" Ref="D4"  Part="1" 
F 0 "D4" H 4200 2700 50  0000 L CNN
F 1 "12v" H 4200 2500 50  0000 L CNN
F 2 "Diode_THT:D_A-405_P7.62mm_Horizontal" H 4250 2600 50  0001 C CNN
F 3 "~" H 4250 2600 50  0001 C CNN
	1    4250 2600
	-1   0    0    1   
$EndComp
$Comp
L FuenteDePulsos-rescue:R R?
U 1 1 5D82DACB
P 4700 2600
AR Path="/5807F7D2/5D82DACB" Ref="R?"  Part="1" 
AR Path="/5D82DACB" Ref="R5"  Part="1" 
F 0 "R5" V 4780 2600 50  0000 C CNN
F 1 "27" V 4700 2600 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 4630 2600 50  0001 C CNN
F 3 "" H 4700 2600 50  0000 C CNN
	1    4700 2600
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4850 2600 4950 2600
Wire Wire Line
	4500 2300 4500 2600
Wire Wire Line
	4500 2600 4550 2600
Wire Wire Line
	4500 2600 4400 2600
Connection ~ 4500 2600
Wire Wire Line
	4000 2650 4000 2600
Wire Wire Line
	4000 2600 4100 2600
$Comp
L FuenteDePulsos-rescue:R R?
U 1 1 5D82DAD9
P 2900 2450
AR Path="/5807F7D2/5D82DAD9" Ref="R?"  Part="1" 
AR Path="/5D82DAD9" Ref="R2"  Part="1" 
F 0 "R2" V 2980 2450 50  0000 C CNN
F 1 "3k9" V 2900 2450 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 2830 2450 50  0001 C CNN
F 3 "" H 2900 2450 50  0000 C CNN
	1    2900 2450
	-1   0    0    1   
$EndComp
$Comp
L FuenteDePulsos-rescue:R R?
U 1 1 5D82DADF
P 3400 2850
AR Path="/5807F7D2/5D82DADF" Ref="R?"  Part="1" 
AR Path="/5D82DADF" Ref="R3"  Part="1" 
F 0 "R3" V 3480 2850 50  0000 C CNN
F 1 "120" V 3400 2850 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 3330 2850 50  0001 C CNN
F 3 "" H 3400 2850 50  0000 C CNN
	1    3400 2850
	0    1    1    0   
$EndComp
$Comp
L Device:Q_PNP_CBE Q?
U 1 1 5D82DAE5
P 3900 2850
AR Path="/5807F7D2/5D82DAE5" Ref="Q?"  Part="1" 
AR Path="/5D82DAE5" Ref="Q2"  Part="1" 
F 0 "Q2" H 4090 2804 50  0000 L CNN
F 1 "2n2907 o BC327" H 4090 2895 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline_Wide" H 4100 2950 50  0001 C CNN
F 3 "~" H 3900 2850 50  0001 C CNN
	1    3900 2850
	1    0    0    1   
$EndComp
$Comp
L FuenteDePulsos-rescue:2N2222 Q?
U 1 1 5D82DAEB
P 2800 3150
AR Path="/5807F7D2/5D82DAEB" Ref="Q?"  Part="1" 
AR Path="/5D82DAEB" Ref="Q1"  Part="1" 
F 0 "Q1" H 3100 3200 50  0000 R CNN
F 1 "BC548" H 3200 3100 50  0000 R CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline_Wide" H 3000 3400 50  0001 C CNN
F 3 "" H 2800 3150 50  0000 C CNN
	1    2800 3150
	1    0    0    -1  
$EndComp
$Comp
L FuenteDePulsos-rescue:GND #PWR?
U 1 1 5D82DAF1
P 2900 4300
AR Path="/5807F7D2/5D82DAF1" Ref="#PWR?"  Part="1" 
AR Path="/5D82DAF1" Ref="#PWR01"  Part="1" 
F 0 "#PWR01" H 2900 4050 50  0001 C CNN
F 1 "GND" H 2900 4150 50  0000 C CNN
F 2 "" H 2900 4300 50  0000 C CNN
F 3 "" H 2900 4300 50  0000 C CNN
	1    2900 4300
	1    0    0    -1  
$EndComp
Wire Wire Line
	3250 2850 2900 2850
Wire Wire Line
	2900 2850 2900 2950
Wire Wire Line
	2900 2600 2900 2850
Connection ~ 2900 2850
Wire Wire Line
	2900 2300 2900 1950
Wire Wire Line
	2900 1950 4500 1950
$Comp
L FuenteDePulsos-rescue:R R?
U 1 1 5D82DAFF
P 1650 3150
AR Path="/5807F7D2/5D82DAFF" Ref="R?"  Part="1" 
AR Path="/5D82DAFF" Ref="R1"  Part="1" 
F 0 "R1" V 1730 3150 50  0000 C CNN
F 1 "3k9" V 1650 3150 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 1580 3150 50  0001 C CNN
F 3 "" H 1650 3150 50  0000 C CNN
	1    1650 3150
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1800 3150 1950 3150
Wire Wire Line
	1800 2700 1950 2700
Wire Wire Line
	1950 2700 1950 3150
Connection ~ 1950 3150
$Comp
L FuenteDePulsos-rescue:D D?
U 1 1 5D85757B
P 2900 3850
AR Path="/5807F7D2/5D85757B" Ref="D?"  Part="1" 
AR Path="/5D85757B" Ref="D3"  Part="1" 
F 0 "D3" H 2900 3950 50  0000 C CNN
F 1 "1N4148" H 2900 3750 50  0000 C CNN
F 2 "Diode_THT:D_A-405_P7.62mm_Horizontal" H 2900 3850 50  0001 C CNN
F 3 "" H 2900 3850 50  0000 C CNN
	1    2900 3850
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2900 3350 2900 3700
Wire Wire Line
	2900 4000 2900 4200
$Comp
L Connector_Generic:Conn_01x01 J5
U 1 1 5D85A691
P 5150 2600
F 0 "J5" H 5230 2642 50  0000 L CNN
F 1 "Conn_01x01" H 5230 2551 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x01_P2.54mm_Vertical" H 5150 2600 50  0001 C CNN
F 3 "~" H 5150 2600 50  0001 C CNN
	1    5150 2600
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x01 J3
U 1 1 5D85BA90
P 2900 1600
F 0 "J3" V 2864 1512 50  0000 R CNN
F 1 "Conn_01x01" V 2773 1512 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x01_P2.54mm_Vertical" H 2900 1600 50  0001 C CNN
F 3 "~" H 2900 1600 50  0001 C CNN
	1    2900 1600
	0    -1   -1   0   
$EndComp
$Comp
L Connector_Generic:Conn_01x01 J1
U 1 1 5D85E794
P 1200 2400
F 0 "J1" V 1164 2312 50  0000 R CNN
F 1 "Conn_01x01" V 1073 2312 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x01_P2.54mm_Vertical" H 1200 2400 50  0001 C CNN
F 3 "~" H 1200 2400 50  0001 C CNN
	1    1200 2400
	0    -1   -1   0   
$EndComp
$Comp
L Connector_Generic:Conn_01x01 J2
U 1 1 5D85EAC3
P 1200 2850
F 0 "J2" V 1164 2762 50  0000 R CNN
F 1 "Conn_01x01" V 1073 2762 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x01_P2.54mm_Vertical" H 1200 2850 50  0001 C CNN
F 3 "~" H 1200 2850 50  0001 C CNN
	1    1200 2850
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2900 1950 2900 1800
Connection ~ 2900 1950
Wire Wire Line
	1200 2600 1200 2700
Wire Wire Line
	1200 2700 1500 2700
Wire Wire Line
	1200 3050 1200 3150
Wire Wire Line
	1200 3150 1500 3150
$Comp
L Connector_Generic:Conn_01x01 J4
U 1 1 5D865E15
P 3400 3950
F 0 "J4" V 3364 3862 50  0000 R CNN
F 1 "Conn_01x01" V 3273 3862 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x01_P2.54mm_Vertical" H 3400 3950 50  0001 C CNN
F 3 "~" H 3400 3950 50  0001 C CNN
	1    3400 3950
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3400 4150 3400 4200
Wire Wire Line
	3400 4200 3200 4200
Connection ~ 2900 4200
Wire Wire Line
	2900 4200 2900 4300
$Comp
L Connector_Generic:Conn_01x01 J6
U 1 1 5D870353
P 2200 3950
F 0 "J6" V 2164 3862 50  0000 R CNN
F 1 "Conn_01x01" V 2073 3862 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x01_P2.54mm_Vertical" H 2200 3950 50  0001 C CNN
F 3 "~" H 2200 3950 50  0001 C CNN
	1    2200 3950
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2200 4150 2200 4200
Wire Wire Line
	2200 4200 2900 4200
$Comp
L Mechanical:MountingHole H4
U 1 1 5D81256B
P 1650 7000
F 0 "H4" H 1750 7046 50  0000 L CNN
F 1 "MountingHole" H 1750 6955 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3" H 1650 7000 50  0001 C CNN
F 3 "~" H 1650 7000 50  0001 C CNN
	1    1650 7000
	1    0    0    -1  
$EndComp
$Comp
L FuenteDePulsos-rescue:R R?
U 1 1 5D81B7CF
P 9250 1950
AR Path="/5807F7D2/5D81B7CF" Ref="R?"  Part="1" 
AR Path="/5D81B7CF" Ref="R9"  Part="1" 
F 0 "R9" V 9330 1950 50  0000 C CNN
F 1 "180" V 9250 1950 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 9180 1950 50  0001 C CNN
F 3 "" H 9250 1950 50  0000 C CNN
	1    9250 1950
	-1   0    0    1   
$EndComp
$Comp
L FuenteDePulsos-rescue:GND #PWR?
U 1 1 5D81B7D5
P 8750 3450
AR Path="/5807F7D2/5D81B7D5" Ref="#PWR?"  Part="1" 
AR Path="/5D81B7D5" Ref="#PWR04"  Part="1" 
F 0 "#PWR04" H 8750 3200 50  0001 C CNN
F 1 "GND" H 8750 3300 50  0000 C CNN
F 2 "" H 8750 3450 50  0000 C CNN
F 3 "" H 8750 3450 50  0000 C CNN
	1    8750 3450
	1    0    0    -1  
$EndComp
$Comp
L FuenteDePulsos-rescue:D D?
U 1 1 5D81B7DB
P 6400 2500
AR Path="/5807F7D2/5D81B7DB" Ref="D?"  Part="1" 
AR Path="/5D81B7DB" Ref="D5"  Part="1" 
F 0 "D5" H 6400 2600 50  0000 C CNN
F 1 "1N4148" H 6400 2400 50  0000 C CNN
F 2 "Diode_THT:D_A-405_P7.62mm_Horizontal" H 6400 2500 50  0001 C CNN
F 3 "" H 6400 2500 50  0000 C CNN
	1    6400 2500
	1    0    0    -1  
$EndComp
Wire Wire Line
	8750 3450 8750 2850
Wire Wire Line
	9250 1750 9250 1800
Wire Wire Line
	8300 2650 8450 2650
$Comp
L FuenteDePulsos-rescue:R R?
U 1 1 5D81B7EA
P 9450 2400
AR Path="/5807F7D2/5D81B7EA" Ref="R?"  Part="1" 
AR Path="/5D81B7EA" Ref="R10"  Part="1" 
F 0 "R10" V 9530 2400 50  0000 C CNN
F 1 "27" V 9450 2400 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 9380 2400 50  0001 C CNN
F 3 "" H 9450 2400 50  0000 C CNN
	1    9450 2400
	0    -1   -1   0   
$EndComp
Wire Wire Line
	9600 2400 9700 2400
Wire Wire Line
	9250 2100 9250 2400
Wire Wire Line
	9250 2400 9300 2400
Connection ~ 9250 2400
Wire Wire Line
	8750 2450 8750 2400
$Comp
L FuenteDePulsos-rescue:R R?
U 1 1 5D81B7F7
P 7650 2250
AR Path="/5807F7D2/5D81B7F7" Ref="R?"  Part="1" 
AR Path="/5D81B7F7" Ref="R7"  Part="1" 
F 0 "R7" V 7730 2250 50  0000 C CNN
F 1 "3k9" V 7650 2250 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 7580 2250 50  0001 C CNN
F 3 "" H 7650 2250 50  0000 C CNN
	1    7650 2250
	-1   0    0    1   
$EndComp
$Comp
L FuenteDePulsos-rescue:R R?
U 1 1 5D81B7FD
P 8150 2650
AR Path="/5807F7D2/5D81B7FD" Ref="R?"  Part="1" 
AR Path="/5D81B7FD" Ref="R8"  Part="1" 
F 0 "R8" V 8230 2650 50  0000 C CNN
F 1 "120" V 8150 2650 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 8080 2650 50  0001 C CNN
F 3 "" H 8150 2650 50  0000 C CNN
	1    8150 2650
	0    1    1    0   
$EndComp
$Comp
L Device:Q_PNP_CBE Q?
U 1 1 5D81B803
P 8650 2650
AR Path="/5807F7D2/5D81B803" Ref="Q?"  Part="1" 
AR Path="/5D81B803" Ref="Q4"  Part="1" 
F 0 "Q4" H 8840 2604 50  0000 L CNN
F 1 "2n2907 o BC327" H 8840 2695 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline_Wide" H 8850 2750 50  0001 C CNN
F 3 "~" H 8650 2650 50  0001 C CNN
	1    8650 2650
	1    0    0    1   
$EndComp
$Comp
L FuenteDePulsos-rescue:2N2222 Q?
U 1 1 5D81B809
P 7550 2950
AR Path="/5807F7D2/5D81B809" Ref="Q?"  Part="1" 
AR Path="/5D81B809" Ref="Q3"  Part="1" 
F 0 "Q3" H 7850 3000 50  0000 R CNN
F 1 "BC548" H 7950 2900 50  0000 R CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline_Wide" H 7750 3200 50  0001 C CNN
F 3 "" H 7550 2950 50  0000 C CNN
	1    7550 2950
	1    0    0    -1  
$EndComp
$Comp
L FuenteDePulsos-rescue:GND #PWR?
U 1 1 5D81B80F
P 7650 4100
AR Path="/5807F7D2/5D81B80F" Ref="#PWR?"  Part="1" 
AR Path="/5D81B80F" Ref="#PWR03"  Part="1" 
F 0 "#PWR03" H 7650 3850 50  0001 C CNN
F 1 "GND" H 7650 3950 50  0000 C CNN
F 2 "" H 7650 4100 50  0000 C CNN
F 3 "" H 7650 4100 50  0000 C CNN
	1    7650 4100
	1    0    0    -1  
$EndComp
Wire Wire Line
	8000 2650 7650 2650
Wire Wire Line
	7650 2650 7650 2750
Wire Wire Line
	7650 2400 7650 2650
Connection ~ 7650 2650
Wire Wire Line
	7650 2100 7650 1750
Wire Wire Line
	7650 1750 9250 1750
$Comp
L FuenteDePulsos-rescue:R R?
U 1 1 5D81B81B
P 6400 2950
AR Path="/5807F7D2/5D81B81B" Ref="R?"  Part="1" 
AR Path="/5D81B81B" Ref="R6"  Part="1" 
F 0 "R6" V 6480 2950 50  0000 C CNN
F 1 "3k9" V 6400 2950 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 6330 2950 50  0001 C CNN
F 3 "" H 6400 2950 50  0000 C CNN
	1    6400 2950
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6550 2950 6700 2950
Wire Wire Line
	6550 2500 6700 2500
Wire Wire Line
	6700 2500 6700 2950
Connection ~ 6700 2950
$Comp
L FuenteDePulsos-rescue:D D?
U 1 1 5D81B82D
P 7650 3650
AR Path="/5807F7D2/5D81B82D" Ref="D?"  Part="1" 
AR Path="/5D81B82D" Ref="D7"  Part="1" 
F 0 "D7" H 7650 3750 50  0000 C CNN
F 1 "1N4148" H 7650 3550 50  0000 C CNN
F 2 "Diode_THT:D_A-405_P7.62mm_Horizontal" H 7650 3650 50  0001 C CNN
F 3 "" H 7650 3650 50  0000 C CNN
	1    7650 3650
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7650 3150 7650 3500
Wire Wire Line
	7650 3800 7650 4000
$Comp
L Connector_Generic:Conn_01x01 J12
U 1 1 5D81B835
P 9900 2400
F 0 "J12" H 9980 2442 50  0000 L CNN
F 1 "Conn_01x01" H 9980 2351 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x01_P2.54mm_Vertical" H 9900 2400 50  0001 C CNN
F 3 "~" H 9900 2400 50  0001 C CNN
	1    9900 2400
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x01 J10
U 1 1 5D81B83B
P 7650 1400
F 0 "J10" V 7614 1312 50  0000 R CNN
F 1 "Conn_01x01" V 7523 1312 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x01_P2.54mm_Vertical" H 7650 1400 50  0001 C CNN
F 3 "~" H 7650 1400 50  0001 C CNN
	1    7650 1400
	0    -1   -1   0   
$EndComp
$Comp
L Connector_Generic:Conn_01x01 J7
U 1 1 5D81B841
P 5950 2200
F 0 "J7" V 5914 2112 50  0000 R CNN
F 1 "Conn_01x01" V 5823 2112 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x01_P2.54mm_Vertical" H 5950 2200 50  0001 C CNN
F 3 "~" H 5950 2200 50  0001 C CNN
	1    5950 2200
	0    -1   -1   0   
$EndComp
$Comp
L Connector_Generic:Conn_01x01 J8
U 1 1 5D81B847
P 5950 2650
F 0 "J8" V 5914 2562 50  0000 R CNN
F 1 "Conn_01x01" V 5823 2562 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x01_P2.54mm_Vertical" H 5950 2650 50  0001 C CNN
F 3 "~" H 5950 2650 50  0001 C CNN
	1    5950 2650
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7650 1750 7650 1600
Connection ~ 7650 1750
Wire Wire Line
	5950 2400 5950 2500
Wire Wire Line
	5950 2500 6250 2500
Wire Wire Line
	5950 2850 5950 2950
Wire Wire Line
	5950 2950 6250 2950
$Comp
L Connector_Generic:Conn_01x01 J11
U 1 1 5D81B853
P 8150 3750
F 0 "J11" V 8114 3662 50  0000 R CNN
F 1 "Conn_01x01" V 8023 3662 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x01_P2.54mm_Vertical" H 8150 3750 50  0001 C CNN
F 3 "~" H 8150 3750 50  0001 C CNN
	1    8150 3750
	0    -1   -1   0   
$EndComp
Wire Wire Line
	8150 3950 8150 4000
Wire Wire Line
	8150 4000 7650 4000
Connection ~ 7650 4000
Wire Wire Line
	7650 4000 7650 4100
$Comp
L Connector_Generic:Conn_01x01 J9
U 1 1 5D81B85D
P 6950 3750
F 0 "J9" V 6914 3662 50  0000 R CNN
F 1 "Conn_01x01" V 6823 3662 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x01_P2.54mm_Vertical" H 6950 3750 50  0001 C CNN
F 3 "~" H 6950 3750 50  0001 C CNN
	1    6950 3750
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6950 3950 6950 4000
Wire Wire Line
	6950 4000 7650 4000
$Comp
L Mechanical:MountingHole H2
U 1 1 5D83ECF7
P 1650 6600
F 0 "H2" H 1750 6646 50  0000 L CNN
F 1 "MountingHole" H 1750 6555 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3" H 1650 6600 50  0001 C CNN
F 3 "~" H 1650 6600 50  0001 C CNN
	1    1650 6600
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H1
U 1 1 5D83EF38
P 1650 6400
F 0 "H1" H 1750 6446 50  0000 L CNN
F 1 "MountingHole" H 1750 6355 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3" H 1650 6400 50  0001 C CNN
F 3 "~" H 1650 6400 50  0001 C CNN
	1    1650 6400
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H3
U 1 1 5D83F3B9
P 1650 6800
F 0 "H3" H 1750 6846 50  0000 L CNN
F 1 "MountingHole" H 1750 6755 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3" H 1650 6800 50  0001 C CNN
F 3 "~" H 1650 6800 50  0001 C CNN
	1    1650 6800
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 5D841A6B
P 3200 4200
F 0 "#FLG0101" H 3200 4275 50  0001 C CNN
F 1 "PWR_FLAG" H 3200 4373 50  0000 C CNN
F 2 "" H 3200 4200 50  0001 C CNN
F 3 "~" H 3200 4200 50  0001 C CNN
	1    3200 4200
	-1   0    0    1   
$EndComp
Connection ~ 3200 4200
Wire Wire Line
	3200 4200 2900 4200
Wire Wire Line
	1950 3150 2600 3150
Wire Wire Line
	6700 2950 7350 2950
Wire Wire Line
	8750 2400 8850 2400
Wire Wire Line
	9250 2400 9150 2400
$Comp
L Device:D_Zener D?
U 1 1 5D81B7E4
P 9000 2400
AR Path="/5807F7D2/5D81B7E4" Ref="D?"  Part="1" 
AR Path="/5D81B7E4" Ref="D8"  Part="1" 
F 0 "D8" H 8950 2500 50  0000 L CNN
F 1 "12v" H 8950 2300 50  0000 L CNN
F 2 "Diode_THT:D_A-405_P7.62mm_Horizontal" H 9000 2400 50  0001 C CNN
F 3 "~" H 9000 2400 50  0001 C CNN
	1    9000 2400
	-1   0    0    1   
$EndComp
$EndSCHEMATC
