EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L MCU_ST_STM32F1:STM32F103C8Tx U3
U 1 1 5DF5432A
P 8050 3950
F 0 "U3" H 7500 5400 50  0000 C CNN
F 1 "STM32F103C8Tx" H 8600 5400 50  0000 C CNN
F 2 "Package_QFP:LQFP-48_7x7mm_P0.5mm" H 7450 2550 50  0001 R CNN
F 3 "http://www.st.com/st-web-ui/static/active/en/resource/technical/document/datasheet/CD00161566.pdf" H 8050 3950 50  0001 C CNN
	1    8050 3950
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR038
U 1 1 5DF5593B
P 7850 5650
F 0 "#PWR038" H 7850 5400 50  0001 C CNN
F 1 "GND" H 7855 5477 50  0000 C CNN
F 2 "" H 7850 5650 50  0001 C CNN
F 3 "" H 7850 5650 50  0001 C CNN
	1    7850 5650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR040
U 1 1 5DF562A3
P 7950 5650
F 0 "#PWR040" H 7950 5400 50  0001 C CNN
F 1 "GND" H 7955 5477 50  0000 C CNN
F 2 "" H 7950 5650 50  0001 C CNN
F 3 "" H 7950 5650 50  0001 C CNN
	1    7950 5650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR042
U 1 1 5DF562F2
P 8050 5650
F 0 "#PWR042" H 8050 5400 50  0001 C CNN
F 1 "GND" H 8055 5477 50  0000 C CNN
F 2 "" H 8050 5650 50  0001 C CNN
F 3 "" H 8050 5650 50  0001 C CNN
	1    8050 5650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR044
U 1 1 5DF56330
P 8150 5650
F 0 "#PWR044" H 8150 5400 50  0001 C CNN
F 1 "GND" H 8155 5477 50  0000 C CNN
F 2 "" H 8150 5650 50  0001 C CNN
F 3 "" H 8150 5650 50  0001 C CNN
	1    8150 5650
	1    0    0    -1  
$EndComp
Wire Wire Line
	8150 5650 8150 5450
Wire Wire Line
	8050 5650 8050 5450
Wire Wire Line
	7950 5450 7950 5650
Wire Wire Line
	7850 5650 7850 5450
Wire Wire Line
	7950 2450 7950 2300
Wire Wire Line
	8050 2300 8050 2450
Wire Wire Line
	8150 2300 8150 2450
$Comp
L power:PWR_FLAG #FLG01
U 1 1 5DF58D8F
P 6700 850
F 0 "#FLG01" H 6700 925 50  0001 C CNN
F 1 "PWR_FLAG" H 6700 1023 50  0000 C CNN
F 2 "" H 6700 850 50  0001 C CNN
F 3 "~" H 6700 850 50  0001 C CNN
	1    6700 850 
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG02
U 1 1 5DF5934B
P 7200 850
F 0 "#FLG02" H 7200 925 50  0001 C CNN
F 1 "PWR_FLAG" H 7200 1023 50  0000 C CNN
F 2 "" H 7200 850 50  0001 C CNN
F 3 "~" H 7200 850 50  0001 C CNN
	1    7200 850 
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR037
U 1 1 5DF59D94
P 7200 950
F 0 "#PWR037" H 7200 700 50  0001 C CNN
F 1 "GND" H 7205 777 50  0000 C CNN
F 2 "" H 7200 950 50  0001 C CNN
F 3 "" H 7200 950 50  0001 C CNN
	1    7200 950 
	1    0    0    -1  
$EndComp
Wire Wire Line
	7200 950  7200 850 
Wire Wire Line
	6350 850  6350 950 
Wire Wire Line
	6350 950  6700 950 
Wire Wire Line
	6700 950  6700 850 
$Comp
L Device:Crystal_GND2_Small Y1
U 1 1 5DF5AF44
P 6150 3150
F 0 "Y1" H 6150 3375 50  0000 C CNN
F 1 "8MHz" H 6150 3284 50  0000 C CNN
F 2 "" H 6150 3150 50  0001 C CNN
F 3 "~" H 6150 3150 50  0001 C CNN
	1    6150 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	6250 3150 7350 3150
Wire Wire Line
	6050 3150 6000 3150
Wire Wire Line
	6000 3150 6000 3050
Wire Wire Line
	6000 3050 7350 3050
$Comp
L power:GND #PWR029
U 1 1 5DF5C2C2
P 6150 3300
F 0 "#PWR029" H 6150 3050 50  0001 C CNN
F 1 "GND" H 6155 3127 50  0001 C CNN
F 2 "" H 6150 3300 50  0001 C CNN
F 3 "" H 6150 3300 50  0001 C CNN
	1    6150 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	6150 3300 6150 3250
$Comp
L Device:Battery BT1
U 1 1 5DFBDB9B
P 7350 2200
F 0 "BT1" V 7105 2200 50  0000 C CNN
F 1 "Battery" V 7196 2200 50  0000 C CNN
F 2 "Battery:BatteryHolder_ComfortableElectronic_CH273-2450_1x2450" V 7350 2260 50  0001 C CNN
F 3 "~" V 7350 2260 50  0001 C CNN
	1    7350 2200
	0    1    1    0   
$EndComp
Wire Wire Line
	7550 2200 7850 2200
Wire Wire Line
	7850 2200 7850 2450
$Comp
L power:GND #PWR034
U 1 1 5DFBF182
P 6950 2200
F 0 "#PWR034" H 6950 1950 50  0001 C CNN
F 1 "GND" H 6955 2027 50  0000 C CNN
F 2 "" H 6950 2200 50  0001 C CNN
F 3 "" H 6950 2200 50  0001 C CNN
	1    6950 2200
	0    1    1    0   
$EndComp
Wire Wire Line
	6950 2200 7150 2200
$Comp
L Memory_NVRAM:FM24C64B U4
U 1 1 5DFD159D
P 10050 1500
F 0 "U4" H 9800 1850 50  0000 C CNN
F 1 "FM24C64B" H 10300 1850 50  0000 C CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 10050 1500 50  0001 C CNN
F 3 "http://www.cypress.com/file/41651/download" H 9850 1850 50  0001 C CNN
	1    10050 1500
	1    0    0    -1  
$EndComp
Wire Wire Line
	10050 800  10050 900 
$Comp
L power:GND #PWR046
U 1 1 5DFD2C27
P 10050 2050
F 0 "#PWR046" H 10050 1800 50  0001 C CNN
F 1 "GND" H 10055 1877 50  0000 C CNN
F 2 "" H 10050 2050 50  0001 C CNN
F 3 "" H 10050 2050 50  0001 C CNN
	1    10050 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	10050 2050 10050 1950
Wire Wire Line
	9650 1300 9400 1300
Wire Wire Line
	9400 1300 9400 1400
Wire Wire Line
	9400 1950 10050 1950
Connection ~ 10050 1950
Wire Wire Line
	10050 1950 10050 1900
Wire Wire Line
	9650 1400 9400 1400
Connection ~ 9400 1400
Wire Wire Line
	9400 1400 9400 1500
Wire Wire Line
	9650 1500 9400 1500
Connection ~ 9400 1500
Wire Wire Line
	9400 1500 9400 1700
Wire Wire Line
	9650 1700 9400 1700
Connection ~ 9400 1700
Wire Wire Line
	9400 1700 9400 1950
Wire Wire Line
	10450 1400 10600 1400
Wire Wire Line
	10450 1600 10850 1600
Wire Wire Line
	10600 1300 10600 1400
Connection ~ 10600 1400
Wire Wire Line
	10600 1400 11050 1400
Wire Wire Line
	10850 1300 10850 1600
Connection ~ 10850 1600
Wire Wire Line
	10850 1600 11050 1600
Wire Wire Line
	10850 1100 10850 900 
Wire Wire Line
	10850 900  10600 900 
Connection ~ 10050 900 
Wire Wire Line
	10050 900  10050 1100
Wire Wire Line
	10600 1100 10600 900 
Connection ~ 10600 900 
Wire Wire Line
	10600 900  10050 900 
Text Label 11050 1400 2    50   ~ 0
SDA
Text Label 11050 1600 2    50   ~ 0
SCL
Wire Wire Line
	7350 4350 6950 4350
Wire Wire Line
	7350 4450 6950 4450
Text Label 6950 4350 0    50   ~ 0
SCL
Text Label 6950 4450 0    50   ~ 0
SDA
$Comp
L power:+3.3V #PWR039
U 1 1 5DFEAE74
P 7950 2300
F 0 "#PWR039" H 7950 2150 50  0001 C CNN
F 1 "+3.3V" V 7950 2550 50  0000 C CNN
F 2 "" H 7950 2300 50  0001 C CNN
F 3 "" H 7950 2300 50  0001 C CNN
	1    7950 2300
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR041
U 1 1 5DFEB7E8
P 8050 2300
F 0 "#PWR041" H 8050 2150 50  0001 C CNN
F 1 "+3.3V" V 8050 2550 50  0000 C CNN
F 2 "" H 8050 2300 50  0001 C CNN
F 3 "" H 8050 2300 50  0001 C CNN
	1    8050 2300
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR043
U 1 1 5DFEC263
P 8150 2300
F 0 "#PWR043" H 8150 2150 50  0001 C CNN
F 1 "+3.3V" V 8150 2550 50  0000 C CNN
F 2 "" H 8150 2300 50  0001 C CNN
F 3 "" H 8150 2300 50  0001 C CNN
	1    8150 2300
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR030
U 1 1 5DFEC2CA
P 6350 850
F 0 "#PWR030" H 6350 700 50  0001 C CNN
F 1 "+3.3V" H 6365 1023 50  0000 C CNN
F 2 "" H 6350 850 50  0001 C CNN
F 3 "" H 6350 850 50  0001 C CNN
	1    6350 850 
	1    0    0    -1  
$EndComp
$Comp
L Device:C C8
U 1 1 5DFEC9E2
P 6000 7100
F 0 "C8" H 6050 7200 50  0000 L CNN
F 1 "100n" H 6050 7000 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 6038 6950 50  0001 C CNN
F 3 "~" H 6000 7100 50  0001 C CNN
	1    6000 7100
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR027
U 1 1 5DFEDA04
P 6000 6900
F 0 "#PWR027" H 6000 6750 50  0001 C CNN
F 1 "+3.3V" V 6000 7150 50  0000 C CNN
F 2 "" H 6000 6900 50  0001 C CNN
F 3 "" H 6000 6900 50  0001 C CNN
	1    6000 6900
	1    0    0    -1  
$EndComp
Wire Wire Line
	6000 6900 6000 6950
$Comp
L power:GND #PWR028
U 1 1 5DFEF0A0
P 6000 7350
F 0 "#PWR028" H 6000 7100 50  0001 C CNN
F 1 "GND" H 6005 7177 50  0000 C CNN
F 2 "" H 6000 7350 50  0001 C CNN
F 3 "" H 6000 7350 50  0001 C CNN
	1    6000 7350
	1    0    0    -1  
$EndComp
Wire Wire Line
	6000 7350 6000 7250
$Comp
L Device:C C7
U 1 1 5DFF5A63
P 5700 7100
F 0 "C7" H 5750 7200 50  0000 L CNN
F 1 "100n" H 5750 7000 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 5738 6950 50  0001 C CNN
F 3 "~" H 5700 7100 50  0001 C CNN
	1    5700 7100
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR025
U 1 1 5DFF5A6D
P 5700 6900
F 0 "#PWR025" H 5700 6750 50  0001 C CNN
F 1 "+3.3V" V 5700 7150 50  0000 C CNN
F 2 "" H 5700 6900 50  0001 C CNN
F 3 "" H 5700 6900 50  0001 C CNN
	1    5700 6900
	1    0    0    -1  
$EndComp
Wire Wire Line
	5700 6900 5700 6950
$Comp
L power:GND #PWR026
U 1 1 5DFF5A78
P 5700 7350
F 0 "#PWR026" H 5700 7100 50  0001 C CNN
F 1 "GND" H 5705 7177 50  0000 C CNN
F 2 "" H 5700 7350 50  0001 C CNN
F 3 "" H 5700 7350 50  0001 C CNN
	1    5700 7350
	1    0    0    -1  
$EndComp
Wire Wire Line
	5700 7350 5700 7250
$Comp
L Device:C C6
U 1 1 5DFF6F6F
P 5400 7100
F 0 "C6" H 5450 7200 50  0000 L CNN
F 1 "100n" H 5450 7000 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 5438 6950 50  0001 C CNN
F 3 "~" H 5400 7100 50  0001 C CNN
	1    5400 7100
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR023
U 1 1 5DFF6F79
P 5400 6900
F 0 "#PWR023" H 5400 6750 50  0001 C CNN
F 1 "+3.3V" V 5400 7150 50  0000 C CNN
F 2 "" H 5400 6900 50  0001 C CNN
F 3 "" H 5400 6900 50  0001 C CNN
	1    5400 6900
	1    0    0    -1  
$EndComp
Wire Wire Line
	5400 6900 5400 6950
$Comp
L power:GND #PWR024
U 1 1 5DFF6F84
P 5400 7350
F 0 "#PWR024" H 5400 7100 50  0001 C CNN
F 1 "GND" H 5405 7177 50  0000 C CNN
F 2 "" H 5400 7350 50  0001 C CNN
F 3 "" H 5400 7350 50  0001 C CNN
	1    5400 7350
	1    0    0    -1  
$EndComp
Wire Wire Line
	5400 7350 5400 7250
$Comp
L Device:C C5
U 1 1 5DFF6F8F
P 5100 7100
F 0 "C5" H 5150 7200 50  0000 L CNN
F 1 "100n" H 5150 7000 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 5138 6950 50  0001 C CNN
F 3 "~" H 5100 7100 50  0001 C CNN
	1    5100 7100
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR021
U 1 1 5DFF6F99
P 5100 6900
F 0 "#PWR021" H 5100 6750 50  0001 C CNN
F 1 "+3.3V" V 5100 7150 50  0000 C CNN
F 2 "" H 5100 6900 50  0001 C CNN
F 3 "" H 5100 6900 50  0001 C CNN
	1    5100 6900
	1    0    0    -1  
$EndComp
Wire Wire Line
	5100 6900 5100 6950
$Comp
L power:GND #PWR022
U 1 1 5DFF6FA4
P 5100 7350
F 0 "#PWR022" H 5100 7100 50  0001 C CNN
F 1 "GND" H 5105 7177 50  0000 C CNN
F 2 "" H 5100 7350 50  0001 C CNN
F 3 "" H 5100 7350 50  0001 C CNN
	1    5100 7350
	1    0    0    -1  
$EndComp
Wire Wire Line
	5100 7350 5100 7250
$Comp
L Device:C C4
U 1 1 5DFF99A6
P 4800 7100
F 0 "C4" H 4850 7200 50  0000 L CNN
F 1 "100n" H 4850 7000 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 4838 6950 50  0001 C CNN
F 3 "~" H 4800 7100 50  0001 C CNN
	1    4800 7100
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR019
U 1 1 5DFF99B0
P 4800 6900
F 0 "#PWR019" H 4800 6750 50  0001 C CNN
F 1 "+3.3V" V 4800 7150 50  0000 C CNN
F 2 "" H 4800 6900 50  0001 C CNN
F 3 "" H 4800 6900 50  0001 C CNN
	1    4800 6900
	1    0    0    -1  
$EndComp
Wire Wire Line
	4800 6900 4800 6950
$Comp
L power:GND #PWR020
U 1 1 5DFF99BB
P 4800 7350
F 0 "#PWR020" H 4800 7100 50  0001 C CNN
F 1 "GND" H 4805 7177 50  0000 C CNN
F 2 "" H 4800 7350 50  0001 C CNN
F 3 "" H 4800 7350 50  0001 C CNN
	1    4800 7350
	1    0    0    -1  
$EndComp
Wire Wire Line
	4800 7350 4800 7250
$Comp
L Device:C C3
U 1 1 5DFF99C6
P 4500 7100
F 0 "C3" H 4550 7200 50  0000 L CNN
F 1 "100n" H 4550 7000 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 4538 6950 50  0001 C CNN
F 3 "~" H 4500 7100 50  0001 C CNN
	1    4500 7100
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR017
U 1 1 5DFF99D0
P 4500 6900
F 0 "#PWR017" H 4500 6750 50  0001 C CNN
F 1 "+3.3V" V 4500 7150 50  0000 C CNN
F 2 "" H 4500 6900 50  0001 C CNN
F 3 "" H 4500 6900 50  0001 C CNN
	1    4500 6900
	1    0    0    -1  
$EndComp
Wire Wire Line
	4500 6900 4500 6950
$Comp
L power:GND #PWR018
U 1 1 5DFF99DB
P 4500 7350
F 0 "#PWR018" H 4500 7100 50  0001 C CNN
F 1 "GND" H 4505 7177 50  0000 C CNN
F 2 "" H 4500 7350 50  0001 C CNN
F 3 "" H 4500 7350 50  0001 C CNN
	1    4500 7350
	1    0    0    -1  
$EndComp
Wire Wire Line
	4500 7350 4500 7250
$Comp
L Device:C C2
U 1 1 5DFF99E6
P 4200 7100
F 0 "C2" H 4250 7200 50  0000 L CNN
F 1 "100n" H 4250 7000 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 4238 6950 50  0001 C CNN
F 3 "~" H 4200 7100 50  0001 C CNN
	1    4200 7100
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR015
U 1 1 5DFF99F0
P 4200 6900
F 0 "#PWR015" H 4200 6750 50  0001 C CNN
F 1 "+3.3V" V 4200 7150 50  0000 C CNN
F 2 "" H 4200 6900 50  0001 C CNN
F 3 "" H 4200 6900 50  0001 C CNN
	1    4200 6900
	1    0    0    -1  
$EndComp
Wire Wire Line
	4200 6900 4200 6950
$Comp
L power:GND #PWR016
U 1 1 5DFF99FB
P 4200 7350
F 0 "#PWR016" H 4200 7100 50  0001 C CNN
F 1 "GND" H 4205 7177 50  0000 C CNN
F 2 "" H 4200 7350 50  0001 C CNN
F 3 "" H 4200 7350 50  0001 C CNN
	1    4200 7350
	1    0    0    -1  
$EndComp
Wire Wire Line
	4200 7350 4200 7250
$Comp
L Device:C C1
U 1 1 5DFF9A06
P 3900 7100
F 0 "C1" H 3950 7200 50  0000 L CNN
F 1 "100n" H 3950 7000 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 3938 6950 50  0001 C CNN
F 3 "~" H 3900 7100 50  0001 C CNN
	1    3900 7100
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR013
U 1 1 5DFF9A10
P 3900 6900
F 0 "#PWR013" H 3900 6750 50  0001 C CNN
F 1 "+3.3V" V 3900 7150 50  0000 C CNN
F 2 "" H 3900 6900 50  0001 C CNN
F 3 "" H 3900 6900 50  0001 C CNN
	1    3900 6900
	1    0    0    -1  
$EndComp
Wire Wire Line
	3900 6900 3900 6950
$Comp
L power:GND #PWR014
U 1 1 5DFF9A1B
P 3900 7350
F 0 "#PWR014" H 3900 7100 50  0001 C CNN
F 1 "GND" H 3905 7177 50  0000 C CNN
F 2 "" H 3900 7350 50  0001 C CNN
F 3 "" H 3900 7350 50  0001 C CNN
	1    3900 7350
	1    0    0    -1  
$EndComp
Wire Wire Line
	3900 7350 3900 7250
Wire Wire Line
	8650 3950 9150 3950
Wire Wire Line
	8650 4050 9150 4050
Wire Wire Line
	8650 4150 9150 4150
Wire Wire Line
	8650 4250 9150 4250
Text Label 9150 3950 2    50   ~ 0
KEY_UP
Text Label 9150 4050 2    50   ~ 0
KEY_DOWN
Text Label 9150 4150 2    50   ~ 0
KEY_LEFT
Text Label 9150 4250 2    50   ~ 0
KEY_RIGHT
Wire Wire Line
	8650 4450 9150 4450
Text Label 9150 4450 2    50   ~ 0
OW
Wire Wire Line
	7350 4550 6950 4550
Wire Wire Line
	7350 4650 6950 4650
Wire Wire Line
	7350 4750 6950 4750
Wire Wire Line
	7350 4850 6950 4850
Wire Wire Line
	7350 4950 6950 4950
Wire Wire Line
	7350 5050 6950 5050
Wire Wire Line
	7350 5150 6950 5150
Wire Wire Line
	7350 5250 6950 5250
Text Label 6950 4550 0    50   ~ 0
LCD_CS1
Text Label 6950 4650 0    50   ~ 0
LCD_CS2
Text Label 6950 4750 0    50   ~ 0
LCD_RST
Text Label 6950 4850 0    50   ~ 0
LCD_DI
Text Label 6950 4950 0    50   ~ 0
LCD_CLK
Text Label 6950 5050 0    50   ~ 0
LCD_SHIFT
Text Label 6950 5150 0    50   ~ 0
LCD_E
Text Label 6950 5250 0    50   ~ 0
LCD_DATA
Wire Wire Line
	8650 4750 9150 4750
Text Label 9150 4750 2    50   ~ 0
USART1_RX
NoConn ~ 7350 4150
NoConn ~ 7350 4250
Wire Wire Line
	8650 5050 9150 5050
Wire Wire Line
	8650 5150 9150 5150
Wire Wire Line
	8650 5250 9150 5250
Text Label 9150 5050 2    50   ~ 0
JTMS
Text Label 9150 5150 2    50   ~ 0
JTCK
Text Label 9150 5250 2    50   ~ 0
JTDI
Wire Wire Line
	7350 4050 6950 4050
Text Label 6950 4050 0    50   ~ 0
JTDO
NoConn ~ 7350 3750
NoConn ~ 7350 3850
NoConn ~ 7350 3950
Wire Wire Line
	8650 4650 9150 4650
Text Label 9150 4650 2    50   ~ 0
USART1_TX
NoConn ~ 8650 4850
NoConn ~ 8650 4950
NoConn ~ 8650 4550
NoConn ~ 7350 3350
$Comp
L Device:Crystal_Small Y2
U 1 1 5E107073
P 6950 3450
F 0 "Y2" H 6950 3675 50  0000 C CNN
F 1 "32678" H 6950 3584 50  0000 C CNN
F 2 "" H 6950 3450 50  0001 C CNN
F 3 "~" H 6950 3450 50  0001 C CNN
	1    6950 3450
	1    0    0    -1  
$EndComp
Wire Wire Line
	7050 3450 7150 3450
Wire Wire Line
	6850 3450 6750 3450
Wire Wire Line
	6750 3450 6750 3550
Wire Wire Line
	6750 3550 7350 3550
$Comp
L power:GND #PWR031
U 1 1 5E12165C
P 6350 3900
F 0 "#PWR031" H 6350 3650 50  0001 C CNN
F 1 "GND" H 6355 3727 50  0001 C CNN
F 2 "" H 6350 3900 50  0001 C CNN
F 3 "" H 6350 3900 50  0001 C CNN
	1    6350 3900
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR033
U 1 1 5E121B1F
P 6550 3900
F 0 "#PWR033" H 6550 3650 50  0001 C CNN
F 1 "GND" H 6555 3727 50  0001 C CNN
F 2 "" H 6550 3900 50  0001 C CNN
F 3 "" H 6550 3900 50  0001 C CNN
	1    6550 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	6550 3900 6550 3750
Wire Wire Line
	6350 3900 6350 3750
Wire Wire Line
	6350 3550 6350 3350
Wire Wire Line
	6350 3350 7150 3350
Wire Wire Line
	7150 3350 7150 3450
Connection ~ 7150 3450
Wire Wire Line
	7150 3450 7350 3450
Wire Wire Line
	6750 3450 6550 3450
Wire Wire Line
	6550 3450 6550 3550
Connection ~ 6750 3450
Wire Wire Line
	7250 2850 7350 2850
$Comp
L power:GND #PWR035
U 1 1 5E13F148
P 6950 2850
F 0 "#PWR035" H 6950 2600 50  0001 C CNN
F 1 "GND" H 6955 2677 50  0001 C CNN
F 2 "" H 6950 2850 50  0001 C CNN
F 3 "" H 6950 2850 50  0001 C CNN
	1    6950 2850
	0    1    1    0   
$EndComp
Wire Wire Line
	6950 2850 7050 2850
$Comp
L Device:C_Small C10
U 1 1 5E152B37
P 6550 2650
F 0 "C10" V 6321 2650 50  0000 C CNN
F 1 "100n" V 6412 2650 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 6550 2650 50  0001 C CNN
F 3 "~" H 6550 2650 50  0001 C CNN
	1    6550 2650
	0    1    1    0   
$EndComp
$Comp
L Device:C_Small C9
U 1 1 5E153396
P 6350 3650
F 0 "C9" H 6258 3604 50  0000 R CNN
F 1 "22p" H 6258 3695 50  0000 R CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 6350 3650 50  0001 C CNN
F 3 "~" H 6350 3650 50  0001 C CNN
	1    6350 3650
	1    0    0    1   
$EndComp
$Comp
L Device:C_Small C11
U 1 1 5E158A36
P 6550 3650
F 0 "C11" H 6642 3696 50  0000 L CNN
F 1 "22p" H 6642 3605 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 6550 3650 50  0001 C CNN
F 3 "~" H 6550 3650 50  0001 C CNN
	1    6550 3650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR032
U 1 1 5E161165
P 6400 2650
F 0 "#PWR032" H 6400 2400 50  0001 C CNN
F 1 "GND" H 6405 2477 50  0001 C CNN
F 2 "" H 6400 2650 50  0001 C CNN
F 3 "" H 6400 2650 50  0001 C CNN
	1    6400 2650
	0    1    1    0   
$EndComp
Wire Wire Line
	6400 2650 6450 2650
Wire Wire Line
	6650 2650 6700 2650
Wire Wire Line
	6750 2500 6700 2500
Wire Wire Line
	6700 2500 6700 2650
Connection ~ 6700 2650
Wire Wire Line
	6700 2650 7350 2650
$Comp
L power:+3.3V #PWR036
U 1 1 5E16A91E
P 7150 2500
F 0 "#PWR036" H 7150 2350 50  0001 C CNN
F 1 "+3.3V" V 7050 2600 50  0000 C CNN
F 2 "" H 7150 2500 50  0001 C CNN
F 3 "" H 7150 2500 50  0001 C CNN
	1    7150 2500
	0    1    1    0   
$EndComp
Wire Wire Line
	7150 2500 6950 2500
$Comp
L Device:R_Small R4
U 1 1 5E16E8C1
P 6850 2500
F 0 "R4" V 6750 2500 50  0000 C CNN
F 1 "100k" V 6950 2500 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" H 6850 2500 50  0001 C CNN
F 3 "~" H 6850 2500 50  0001 C CNN
	1    6850 2500
	0    1    1    0   
$EndComp
$Comp
L Device:R_Small R6
U 1 1 5E172DF0
P 10600 1200
F 0 "R6" H 10659 1246 50  0000 L CNN
F 1 "4k7" H 10659 1155 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" H 10600 1200 50  0001 C CNN
F 3 "~" H 10600 1200 50  0001 C CNN
	1    10600 1200
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R7
U 1 1 5E173299
P 10850 1200
F 0 "R7" H 10909 1246 50  0000 L CNN
F 1 "4k7" H 10909 1155 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" H 10850 1200 50  0001 C CNN
F 3 "~" H 10850 1200 50  0001 C CNN
	1    10850 1200
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R5
U 1 1 5E17EF1A
P 7150 2850
F 0 "R5" V 7050 2850 50  0000 C CNN
F 1 "100k" V 7250 2850 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" H 7150 2850 50  0001 C CNN
F 3 "~" H 7150 2850 50  0001 C CNN
	1    7150 2850
	0    1    1    0   
$EndComp
$Comp
L Connector:Conn_01x03_Male J2
U 1 1 5E1A2BD9
P 750 6800
F 0 "J2" H 858 6989 50  0000 C CNN
F 1 "Conn_01x03_Male" H 858 6990 50  0001 C CNN
F 2 "" H 750 6800 50  0001 C CNN
F 3 "~" H 750 6800 50  0001 C CNN
	1    750  6800
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x03_Male J3
U 1 1 5E1A3006
P 750 7250
F 0 "J3" H 858 7439 50  0000 C CNN
F 1 "Conn_01x03_Male" H 858 7440 50  0001 C CNN
F 2 "" H 750 7250 50  0001 C CNN
F 3 "~" H 750 7250 50  0001 C CNN
	1    750  7250
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR01
U 1 1 5E1A393F
P 1100 7450
F 0 "#PWR01" H 1100 7200 50  0001 C CNN
F 1 "GND" H 1105 7277 50  0001 C CNN
F 2 "" H 1100 7450 50  0001 C CNN
F 3 "" H 1100 7450 50  0001 C CNN
	1    1100 7450
	1    0    0    -1  
$EndComp
Wire Wire Line
	1100 6450 1100 6900
Wire Wire Line
	950  6900 1100 6900
Connection ~ 1100 6900
Wire Wire Line
	1100 6900 1100 7350
Wire Wire Line
	950  7350 1100 7350
Connection ~ 1100 7350
Wire Wire Line
	1100 7350 1100 7450
Wire Wire Line
	1300 7250 950  7250
Wire Wire Line
	950  6450 1100 6450
Wire Wire Line
	1300 6350 1300 6800
$Comp
L Connector:Conn_01x03_Male J1
U 1 1 5E1A0727
P 750 6350
F 0 "J1" H 858 6539 50  0000 C CNN
F 1 "Conn_01x03_Male" H 858 6540 50  0001 C CNN
F 2 "" H 750 6350 50  0001 C CNN
F 3 "~" H 750 6350 50  0001 C CNN
	1    750  6350
	1    0    0    -1  
$EndComp
Wire Wire Line
	950  6350 1300 6350
Wire Wire Line
	1200 6700 1200 7150
Connection ~ 1200 6700
Wire Wire Line
	950  6700 1200 6700
Wire Wire Line
	1200 6250 1200 6700
Connection ~ 1200 6250
Wire Wire Line
	950  6250 1200 6250
Wire Wire Line
	1200 7150 950  7150
Wire Wire Line
	1200 5900 1200 6250
$Comp
L power:+3.3V #PWR04
U 1 1 5E1AE3E6
P 1200 5900
F 0 "#PWR04" H 1200 5750 50  0001 C CNN
F 1 "+3.3V" V 1200 6150 50  0000 C CNN
F 2 "" H 1200 5900 50  0001 C CNN
F 3 "" H 1200 5900 50  0001 C CNN
	1    1200 5900
	1    0    0    -1  
$EndComp
Wire Wire Line
	950  6800 1300 6800
Connection ~ 1300 6800
Wire Wire Line
	1300 6800 1300 7250
Wire Wire Line
	1300 6800 1650 6800
Text Label 1650 6800 2    50   ~ 0
OW
$Comp
L Device:R_Small R2
U 1 1 5E1D8713
P 1300 6200
F 0 "R2" H 1200 6100 50  0000 C CNN
F 1 "4k7" H 1200 6200 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" H 1300 6200 50  0001 C CNN
F 3 "~" H 1300 6200 50  0001 C CNN
	1    1300 6200
	-1   0    0    1   
$EndComp
$Comp
L power:+3.3V #PWR05
U 1 1 5E1DD930
P 1300 5900
F 0 "#PWR05" H 1300 5750 50  0001 C CNN
F 1 "+3.3V" V 1300 6150 50  0000 C CNN
F 2 "" H 1300 5900 50  0001 C CNN
F 3 "" H 1300 5900 50  0001 C CNN
	1    1300 5900
	1    0    0    -1  
$EndComp
Wire Wire Line
	1300 5900 1300 6100
Wire Wire Line
	1300 6300 1300 6350
Connection ~ 1300 6350
$Comp
L Connector:Conn_ARM_JTAG_SWD_10 J4
U 1 1 5E21B409
P 10500 3400
F 0 "J4" H 10056 3400 50  0000 R CNN
F 1 "Conn_ARM_JTAG_SWD_10" H 10056 3355 50  0001 R CNN
F 2 "Connector_IDC:IDC-Header_2x05_P2.54mm_Vertical" H 10500 3400 50  0001 C CNN
F 3 "http://infocenter.arm.com/help/topic/com.arm.doc.ddi0314h/DDI0314H_coresight_components_trm.pdf" V 10150 2150 50  0001 C CNN
	1    10500 3400
	-1   0    0    -1  
$EndComp
$Comp
L power:GND #PWR048
U 1 1 5E221A10
P 10500 4150
F 0 "#PWR048" H 10500 3900 50  0001 C CNN
F 1 "GND" H 10505 3977 50  0001 C CNN
F 2 "" H 10500 4150 50  0001 C CNN
F 3 "" H 10500 4150 50  0001 C CNN
	1    10500 4150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR049
U 1 1 5E222029
P 10600 4150
F 0 "#PWR049" H 10600 3900 50  0001 C CNN
F 1 "GND" H 10605 3977 50  0001 C CNN
F 2 "" H 10600 4150 50  0001 C CNN
F 3 "" H 10600 4150 50  0001 C CNN
	1    10600 4150
	1    0    0    -1  
$EndComp
Wire Wire Line
	10500 4150 10500 4000
Wire Wire Line
	10600 4150 10600 4000
Text Label 7000 2650 0    50   ~ 0
NRESET
$Comp
L power:+3.3V #PWR045
U 1 1 5DFEC31A
P 10050 800
F 0 "#PWR045" H 10050 650 50  0001 C CNN
F 1 "+3.3V" H 10065 973 50  0000 C CNN
F 2 "" H 10050 800 50  0001 C CNN
F 3 "" H 10050 800 50  0001 C CNN
	1    10050 800 
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR047
U 1 1 5E243E63
P 10500 2700
F 0 "#PWR047" H 10500 2550 50  0001 C CNN
F 1 "+3.3V" H 10515 2873 50  0000 C CNN
F 2 "" H 10500 2700 50  0001 C CNN
F 3 "" H 10500 2700 50  0001 C CNN
	1    10500 2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	10500 2700 10500 2800
Wire Wire Line
	10000 3100 9650 3100
Wire Wire Line
	10000 3300 9650 3300
Wire Wire Line
	10000 3400 9650 3400
Wire Wire Line
	10000 3500 9650 3500
Wire Wire Line
	10000 3600 9650 3600
Text Label 9650 3100 0    50   ~ 0
NRESET
Text Label 9650 3300 0    50   ~ 0
JTCK
Text Label 9650 3400 0    50   ~ 0
JTMS
Text Label 9650 3500 0    50   ~ 0
JTDO
Text Label 9650 3600 0    50   ~ 0
JTDI
$Comp
L lcd:WG12864A U2
U 1 1 5E2A8ECE
P 2750 1150
F 0 "U2" H 3778 1188 50  0000 L CNN
F 1 "WG12864A" H 3778 1097 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x20_P2.54mm_Vertical" H 2750 1150 50  0001 C CNN
F 3 "https://img.ozdisan.com/ETicaret_Dosya/41089_4001252.pdf" H 2750 1150 50  0001 C CNN
	1    2750 1150
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC595 U1
U 1 1 5E2D703C
P 1650 3350
F 0 "U1" H 1750 4000 50  0000 C CNN
F 1 "74HC595" H 1850 3900 50  0000 C CNN
F 2 "Package_SO:SOIC-16_3.9x9.9mm_P1.27mm" H 1650 3350 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74hc595.pdf" H 1650 3350 50  0001 C CNN
	1    1650 3350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR09
U 1 1 5E2D84F1
P 1800 2050
F 0 "#PWR09" H 1800 1800 50  0001 C CNN
F 1 "GND" H 1805 1877 50  0001 C CNN
F 2 "" H 1800 2050 50  0001 C CNN
F 3 "" H 1800 2050 50  0001 C CNN
	1    1800 2050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR010
U 1 1 5E2D8F1E
P 2200 2050
F 0 "#PWR010" H 2200 1800 50  0001 C CNN
F 1 "GND" H 2205 1877 50  0001 C CNN
F 2 "" H 2200 2050 50  0001 C CNN
F 3 "" H 2200 2050 50  0001 C CNN
	1    2200 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 2050 2200 1600
Wire Wire Line
	1800 2050 1800 1600
Wire Wire Line
	2100 1600 2100 2050
Wire Wire Line
	2300 1600 2300 2050
Wire Wire Line
	3200 1600 3200 2050
Wire Wire Line
	3300 1600 3300 2050
Wire Wire Line
	3400 1600 3400 2050
Text Label 2100 2050 1    50   ~ 0
LCD_DI
Text Label 2300 2050 1    50   ~ 0
LCD_E
Text Label 3200 2050 1    50   ~ 0
LCD_CS1
Text Label 3300 2050 1    50   ~ 0
LCD_CS2
Text Label 3400 2050 1    50   ~ 0
LCD_RST
Wire Wire Line
	2050 2950 2400 2950
Wire Wire Line
	2400 2950 2400 1600
Wire Wire Line
	2050 3050 2500 3050
Wire Wire Line
	2500 3050 2500 1600
Wire Wire Line
	2050 3150 2600 3150
Wire Wire Line
	2600 3150 2600 1600
Wire Wire Line
	2050 3250 2700 3250
Wire Wire Line
	2700 3250 2700 1600
Wire Wire Line
	2050 3350 2800 3350
Wire Wire Line
	2800 3350 2800 1600
Wire Wire Line
	2050 3450 2900 3450
Wire Wire Line
	2900 3450 2900 1600
Wire Wire Line
	2050 3550 3000 3550
Wire Wire Line
	3000 3550 3000 1600
Wire Wire Line
	2050 3650 3100 3650
Wire Wire Line
	3100 3650 3100 1600
NoConn ~ 2050 3850
$Comp
L power:GND #PWR03
U 1 1 5E34A835
P 1150 3550
F 0 "#PWR03" H 1150 3300 50  0001 C CNN
F 1 "GND" H 1155 3377 50  0001 C CNN
F 2 "" H 1150 3550 50  0001 C CNN
F 3 "" H 1150 3550 50  0001 C CNN
	1    1150 3550
	0    1    1    0   
$EndComp
Wire Wire Line
	1150 3550 1250 3550
$Comp
L power:GND #PWR08
U 1 1 5E35237B
P 1650 4200
F 0 "#PWR08" H 1650 3950 50  0001 C CNN
F 1 "GND" H 1655 4027 50  0001 C CNN
F 2 "" H 1650 4200 50  0001 C CNN
F 3 "" H 1650 4200 50  0001 C CNN
	1    1650 4200
	1    0    0    -1  
$EndComp
Wire Wire Line
	1650 4200 1650 4050
$Comp
L Device:R_Small R1
U 1 1 5E35A5E3
P 1150 2700
F 0 "R1" H 1209 2746 50  0000 L CNN
F 1 "1k" H 1209 2655 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" H 1150 2700 50  0001 C CNN
F 3 "~" H 1150 2700 50  0001 C CNN
	1    1150 2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	1150 2800 1150 3250
Wire Wire Line
	1150 3250 1250 3250
$Comp
L power:VCC #PWR02
U 1 1 5E36A66F
P 1150 2450
F 0 "#PWR02" H 1150 2300 50  0001 C CNN
F 1 "VCC" H 1167 2623 50  0000 C CNN
F 2 "" H 1150 2450 50  0001 C CNN
F 3 "" H 1150 2450 50  0001 C CNN
	1    1150 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	1150 2450 1150 2600
$Comp
L power:VCC #PWR07
U 1 1 5E3725FD
P 1650 2450
F 0 "#PWR07" H 1650 2300 50  0001 C CNN
F 1 "VCC" H 1667 2623 50  0000 C CNN
F 2 "" H 1650 2450 50  0001 C CNN
F 3 "" H 1650 2450 50  0001 C CNN
	1    1650 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	1650 2450 1650 2750
Wire Wire Line
	1250 2950 650  2950
Wire Wire Line
	1250 3150 650  3150
Wire Wire Line
	1250 3450 650  3450
Text Label 650  2950 0    50   ~ 0
LCD_DATA
Text Label 650  3150 0    50   ~ 0
LCD_SHIFT
Text Label 650  3450 0    50   ~ 0
LCD_CLK
$Comp
L power:VCC #PWR06
U 1 1 5E394682
P 1500 1450
F 0 "#PWR06" H 1500 1300 50  0001 C CNN
F 1 "VCC" H 1517 1623 50  0000 C CNN
F 2 "" H 1500 1450 50  0001 C CNN
F 3 "" H 1500 1450 50  0001 C CNN
	1    1500 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	1500 1450 1500 1650
Wire Wire Line
	1500 1650 1900 1650
Wire Wire Line
	1900 1650 1900 1600
$Comp
L power:VCC #PWR012
U 1 1 5E39D4D0
P 3900 1450
F 0 "#PWR012" H 3900 1300 50  0001 C CNN
F 1 "VCC" H 3917 1623 50  0000 C CNN
F 2 "" H 3900 1450 50  0001 C CNN
F 3 "" H 3900 1450 50  0001 C CNN
	1    3900 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	3900 1450 3900 1750
Wire Wire Line
	3900 1750 3600 1750
Wire Wire Line
	3600 1750 3600 1600
$Comp
L Device:R_Small R3
U 1 1 5E3A6715
P 3700 1950
F 0 "R3" H 3759 1996 50  0000 L CNN
F 1 "10" H 3759 1905 50  0000 L CNN
F 2 "Resistor_SMD:R_1210_3225Metric" H 3700 1950 50  0001 C CNN
F 3 "~" H 3700 1950 50  0001 C CNN
	1    3700 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	3700 1850 3700 1600
$Comp
L power:GND #PWR011
U 1 1 5E3AFB93
P 3700 2200
F 0 "#PWR011" H 3700 1950 50  0001 C CNN
F 1 "GND" H 3705 2027 50  0001 C CNN
F 2 "" H 3700 2200 50  0001 C CNN
F 3 "" H 3700 2200 50  0001 C CNN
	1    3700 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	3700 2200 3700 2050
$Comp
L Device:R_POT_Small RV1
U 1 1 5E3C3741
P 1500 1850
F 0 "RV1" H 1440 1896 50  0000 R CNN
F 1 "10k" H 1440 1805 50  0000 R CNN
F 2 "" H 1500 1850 50  0001 C CNN
F 3 "~" H 1500 1850 50  0001 C CNN
	1    1500 1850
	1    0    0    -1  
$EndComp
Wire Wire Line
	1500 1750 1500 1650
Connection ~ 1500 1650
Wire Wire Line
	1600 1850 2000 1850
Wire Wire Line
	2000 1850 2000 1600
Wire Wire Line
	1500 1950 1500 2200
Wire Wire Line
	1500 2200 3500 2200
Wire Wire Line
	3500 2200 3500 1600
$EndSCHEMATC
