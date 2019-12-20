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
L MCU_ST_STM32F1:STM32F103C8Tx U?
U 1 1 5DF5432A
P 5750 3300
F 0 "U?" H 5200 4750 50  0000 C CNN
F 1 "STM32F103C8Tx" H 6300 4750 50  0000 C CNN
F 2 "Package_QFP:LQFP-48_7x7mm_P0.5mm" H 5150 1900 50  0001 R CNN
F 3 "http://www.st.com/st-web-ui/static/active/en/resource/technical/document/datasheet/CD00161566.pdf" H 5750 3300 50  0001 C CNN
	1    5750 3300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5DF5593B
P 5550 5000
F 0 "#PWR?" H 5550 4750 50  0001 C CNN
F 1 "GND" H 5555 4827 50  0000 C CNN
F 2 "" H 5550 5000 50  0001 C CNN
F 3 "" H 5550 5000 50  0001 C CNN
	1    5550 5000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5DF562A3
P 5650 5000
F 0 "#PWR?" H 5650 4750 50  0001 C CNN
F 1 "GND" H 5655 4827 50  0000 C CNN
F 2 "" H 5650 5000 50  0001 C CNN
F 3 "" H 5650 5000 50  0001 C CNN
	1    5650 5000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5DF562F2
P 5750 5000
F 0 "#PWR?" H 5750 4750 50  0001 C CNN
F 1 "GND" H 5755 4827 50  0000 C CNN
F 2 "" H 5750 5000 50  0001 C CNN
F 3 "" H 5750 5000 50  0001 C CNN
	1    5750 5000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5DF56330
P 5850 5000
F 0 "#PWR?" H 5850 4750 50  0001 C CNN
F 1 "GND" H 5855 4827 50  0000 C CNN
F 2 "" H 5850 5000 50  0001 C CNN
F 3 "" H 5850 5000 50  0001 C CNN
	1    5850 5000
	1    0    0    -1  
$EndComp
Wire Wire Line
	5850 5000 5850 4800
Wire Wire Line
	5750 5000 5750 4800
Wire Wire Line
	5650 4800 5650 5000
Wire Wire Line
	5550 5000 5550 4800
Wire Wire Line
	5650 1800 5650 1650
Wire Wire Line
	5750 1650 5750 1800
Wire Wire Line
	5850 1650 5850 1800
$Comp
L power:PWR_FLAG #FLG?
U 1 1 5DF58D8F
P 6700 850
F 0 "#FLG?" H 6700 925 50  0001 C CNN
F 1 "PWR_FLAG" H 6700 1023 50  0000 C CNN
F 2 "" H 6700 850 50  0001 C CNN
F 3 "~" H 6700 850 50  0001 C CNN
	1    6700 850 
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG?
U 1 1 5DF5934B
P 7200 850
F 0 "#FLG?" H 7200 925 50  0001 C CNN
F 1 "PWR_FLAG" H 7200 1023 50  0000 C CNN
F 2 "" H 7200 850 50  0001 C CNN
F 3 "~" H 7200 850 50  0001 C CNN
	1    7200 850 
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5DF59D94
P 7200 950
F 0 "#PWR?" H 7200 700 50  0001 C CNN
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
L Device:Crystal_GND2_Small Y?
U 1 1 5DF5AF44
P 3850 2500
F 0 "Y?" H 3850 2725 50  0000 C CNN
F 1 "8MHz" H 3850 2634 50  0000 C CNN
F 2 "" H 3850 2500 50  0001 C CNN
F 3 "~" H 3850 2500 50  0001 C CNN
	1    3850 2500
	1    0    0    -1  
$EndComp
Wire Wire Line
	3950 2500 5050 2500
Wire Wire Line
	3750 2500 3700 2500
Wire Wire Line
	3700 2500 3700 2400
Wire Wire Line
	3700 2400 5050 2400
$Comp
L power:GND #PWR?
U 1 1 5DF5C2C2
P 3850 2650
F 0 "#PWR?" H 3850 2400 50  0001 C CNN
F 1 "GND" H 3855 2477 50  0000 C CNN
F 2 "" H 3850 2650 50  0001 C CNN
F 3 "" H 3850 2650 50  0001 C CNN
	1    3850 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	3850 2650 3850 2600
$Comp
L Device:Battery BT?
U 1 1 5DFBDB9B
P 5050 1550
F 0 "BT?" V 4805 1550 50  0000 C CNN
F 1 "Battery" V 4896 1550 50  0000 C CNN
F 2 "Battery:BatteryHolder_ComfortableElectronic_CH273-2450_1x2450" V 5050 1610 50  0001 C CNN
F 3 "~" V 5050 1610 50  0001 C CNN
	1    5050 1550
	0    1    1    0   
$EndComp
Wire Wire Line
	5250 1550 5550 1550
Wire Wire Line
	5550 1550 5550 1800
$Comp
L power:GND #PWR?
U 1 1 5DFBF182
P 4650 1550
F 0 "#PWR?" H 4650 1300 50  0001 C CNN
F 1 "GND" H 4655 1377 50  0000 C CNN
F 2 "" H 4650 1550 50  0001 C CNN
F 3 "" H 4650 1550 50  0001 C CNN
	1    4650 1550
	0    1    1    0   
$EndComp
Wire Wire Line
	4650 1550 4850 1550
$Comp
L Memory_NVRAM:FM24C64B U?
U 1 1 5DFD159D
P 9500 1500
F 0 "U?" H 9250 1850 50  0000 C CNN
F 1 "FM24C64B" H 9750 1850 50  0000 C CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 9500 1500 50  0001 C CNN
F 3 "http://www.cypress.com/file/41651/download" H 9300 1850 50  0001 C CNN
	1    9500 1500
	1    0    0    -1  
$EndComp
Wire Wire Line
	9500 800  9500 900 
$Comp
L power:GND #PWR?
U 1 1 5DFD2C27
P 9500 2050
F 0 "#PWR?" H 9500 1800 50  0001 C CNN
F 1 "GND" H 9505 1877 50  0000 C CNN
F 2 "" H 9500 2050 50  0001 C CNN
F 3 "" H 9500 2050 50  0001 C CNN
	1    9500 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	9500 2050 9500 1950
Wire Wire Line
	9100 1300 8850 1300
Wire Wire Line
	8850 1300 8850 1400
Wire Wire Line
	8850 1950 9500 1950
Connection ~ 9500 1950
Wire Wire Line
	9500 1950 9500 1900
Wire Wire Line
	9100 1400 8850 1400
Connection ~ 8850 1400
Wire Wire Line
	8850 1400 8850 1500
Wire Wire Line
	9100 1500 8850 1500
Connection ~ 8850 1500
Wire Wire Line
	8850 1500 8850 1700
Wire Wire Line
	9100 1700 8850 1700
Connection ~ 8850 1700
Wire Wire Line
	8850 1700 8850 1950
Wire Wire Line
	9900 1400 10050 1400
Wire Wire Line
	9900 1600 10300 1600
$Comp
L Device:R R?
U 1 1 5DFD5695
P 10050 1200
F 0 "R?" H 10120 1246 50  0000 L CNN
F 1 "4k7" H 10120 1155 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 9980 1200 50  0001 C CNN
F 3 "~" H 10050 1200 50  0001 C CNN
	1    10050 1200
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5DFD5E70
P 10300 1200
F 0 "R?" H 10370 1246 50  0000 L CNN
F 1 "4k7" H 10370 1155 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 10230 1200 50  0001 C CNN
F 3 "~" H 10300 1200 50  0001 C CNN
	1    10300 1200
	1    0    0    -1  
$EndComp
Wire Wire Line
	10050 1350 10050 1400
Connection ~ 10050 1400
Wire Wire Line
	10050 1400 10500 1400
Wire Wire Line
	10300 1350 10300 1600
Connection ~ 10300 1600
Wire Wire Line
	10300 1600 10500 1600
Wire Wire Line
	10300 1050 10300 900 
Wire Wire Line
	10300 900  10050 900 
Connection ~ 9500 900 
Wire Wire Line
	9500 900  9500 1100
Wire Wire Line
	10050 1050 10050 900 
Connection ~ 10050 900 
Wire Wire Line
	10050 900  9500 900 
Text Label 10500 1400 2    50   ~ 0
SDA
Text Label 10500 1600 2    50   ~ 0
SCL
Wire Wire Line
	5050 3700 4650 3700
Wire Wire Line
	5050 3800 4650 3800
Text Label 4650 3700 0    50   ~ 0
SCL
Text Label 4650 3800 0    50   ~ 0
SDA
$Comp
L power:+3.3V #PWR?
U 1 1 5DFEAE74
P 5650 1650
F 0 "#PWR?" H 5650 1500 50  0001 C CNN
F 1 "+3.3V" V 5650 1900 50  0000 C CNN
F 2 "" H 5650 1650 50  0001 C CNN
F 3 "" H 5650 1650 50  0001 C CNN
	1    5650 1650
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5DFEB7E8
P 5750 1650
F 0 "#PWR?" H 5750 1500 50  0001 C CNN
F 1 "+3.3V" V 5750 1900 50  0000 C CNN
F 2 "" H 5750 1650 50  0001 C CNN
F 3 "" H 5750 1650 50  0001 C CNN
	1    5750 1650
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5DFEC263
P 5850 1650
F 0 "#PWR?" H 5850 1500 50  0001 C CNN
F 1 "+3.3V" V 5850 1900 50  0000 C CNN
F 2 "" H 5850 1650 50  0001 C CNN
F 3 "" H 5850 1650 50  0001 C CNN
	1    5850 1650
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5DFEC2CA
P 6350 850
F 0 "#PWR?" H 6350 700 50  0001 C CNN
F 1 "+3.3V" H 6365 1023 50  0000 C CNN
F 2 "" H 6350 850 50  0001 C CNN
F 3 "" H 6350 850 50  0001 C CNN
	1    6350 850 
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5DFEC31A
P 9500 800
F 0 "#PWR?" H 9500 650 50  0001 C CNN
F 1 "+3.3V" H 9515 973 50  0000 C CNN
F 2 "" H 9500 800 50  0001 C CNN
F 3 "" H 9500 800 50  0001 C CNN
	1    9500 800 
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5DFEC9E2
P 6000 7100
F 0 "C?" H 6050 7200 50  0000 L CNN
F 1 "100n" H 6050 7000 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 6038 6950 50  0001 C CNN
F 3 "~" H 6000 7100 50  0001 C CNN
	1    6000 7100
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5DFEDA04
P 6000 6900
F 0 "#PWR?" H 6000 6750 50  0001 C CNN
F 1 "+3.3V" V 6000 7150 50  0000 C CNN
F 2 "" H 6000 6900 50  0001 C CNN
F 3 "" H 6000 6900 50  0001 C CNN
	1    6000 6900
	1    0    0    -1  
$EndComp
Wire Wire Line
	6000 6900 6000 6950
$Comp
L power:GND #PWR?
U 1 1 5DFEF0A0
P 6000 7350
F 0 "#PWR?" H 6000 7100 50  0001 C CNN
F 1 "GND" H 6005 7177 50  0000 C CNN
F 2 "" H 6000 7350 50  0001 C CNN
F 3 "" H 6000 7350 50  0001 C CNN
	1    6000 7350
	1    0    0    -1  
$EndComp
Wire Wire Line
	6000 7350 6000 7250
$Comp
L Device:C C?
U 1 1 5DFF5A63
P 5700 7100
F 0 "C?" H 5750 7200 50  0000 L CNN
F 1 "100n" H 5750 7000 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 5738 6950 50  0001 C CNN
F 3 "~" H 5700 7100 50  0001 C CNN
	1    5700 7100
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5DFF5A6D
P 5700 6900
F 0 "#PWR?" H 5700 6750 50  0001 C CNN
F 1 "+3.3V" V 5700 7150 50  0000 C CNN
F 2 "" H 5700 6900 50  0001 C CNN
F 3 "" H 5700 6900 50  0001 C CNN
	1    5700 6900
	1    0    0    -1  
$EndComp
Wire Wire Line
	5700 6900 5700 6950
$Comp
L power:GND #PWR?
U 1 1 5DFF5A78
P 5700 7350
F 0 "#PWR?" H 5700 7100 50  0001 C CNN
F 1 "GND" H 5705 7177 50  0000 C CNN
F 2 "" H 5700 7350 50  0001 C CNN
F 3 "" H 5700 7350 50  0001 C CNN
	1    5700 7350
	1    0    0    -1  
$EndComp
Wire Wire Line
	5700 7350 5700 7250
$Comp
L Device:C C?
U 1 1 5DFF6F6F
P 5400 7100
F 0 "C?" H 5450 7200 50  0000 L CNN
F 1 "100n" H 5450 7000 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 5438 6950 50  0001 C CNN
F 3 "~" H 5400 7100 50  0001 C CNN
	1    5400 7100
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5DFF6F79
P 5400 6900
F 0 "#PWR?" H 5400 6750 50  0001 C CNN
F 1 "+3.3V" V 5400 7150 50  0000 C CNN
F 2 "" H 5400 6900 50  0001 C CNN
F 3 "" H 5400 6900 50  0001 C CNN
	1    5400 6900
	1    0    0    -1  
$EndComp
Wire Wire Line
	5400 6900 5400 6950
$Comp
L power:GND #PWR?
U 1 1 5DFF6F84
P 5400 7350
F 0 "#PWR?" H 5400 7100 50  0001 C CNN
F 1 "GND" H 5405 7177 50  0000 C CNN
F 2 "" H 5400 7350 50  0001 C CNN
F 3 "" H 5400 7350 50  0001 C CNN
	1    5400 7350
	1    0    0    -1  
$EndComp
Wire Wire Line
	5400 7350 5400 7250
$Comp
L Device:C C?
U 1 1 5DFF6F8F
P 5100 7100
F 0 "C?" H 5150 7200 50  0000 L CNN
F 1 "100n" H 5150 7000 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 5138 6950 50  0001 C CNN
F 3 "~" H 5100 7100 50  0001 C CNN
	1    5100 7100
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5DFF6F99
P 5100 6900
F 0 "#PWR?" H 5100 6750 50  0001 C CNN
F 1 "+3.3V" V 5100 7150 50  0000 C CNN
F 2 "" H 5100 6900 50  0001 C CNN
F 3 "" H 5100 6900 50  0001 C CNN
	1    5100 6900
	1    0    0    -1  
$EndComp
Wire Wire Line
	5100 6900 5100 6950
$Comp
L power:GND #PWR?
U 1 1 5DFF6FA4
P 5100 7350
F 0 "#PWR?" H 5100 7100 50  0001 C CNN
F 1 "GND" H 5105 7177 50  0000 C CNN
F 2 "" H 5100 7350 50  0001 C CNN
F 3 "" H 5100 7350 50  0001 C CNN
	1    5100 7350
	1    0    0    -1  
$EndComp
Wire Wire Line
	5100 7350 5100 7250
$Comp
L Device:C C?
U 1 1 5DFF99A6
P 4800 7100
F 0 "C?" H 4850 7200 50  0000 L CNN
F 1 "100n" H 4850 7000 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 4838 6950 50  0001 C CNN
F 3 "~" H 4800 7100 50  0001 C CNN
	1    4800 7100
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5DFF99B0
P 4800 6900
F 0 "#PWR?" H 4800 6750 50  0001 C CNN
F 1 "+3.3V" V 4800 7150 50  0000 C CNN
F 2 "" H 4800 6900 50  0001 C CNN
F 3 "" H 4800 6900 50  0001 C CNN
	1    4800 6900
	1    0    0    -1  
$EndComp
Wire Wire Line
	4800 6900 4800 6950
$Comp
L power:GND #PWR?
U 1 1 5DFF99BB
P 4800 7350
F 0 "#PWR?" H 4800 7100 50  0001 C CNN
F 1 "GND" H 4805 7177 50  0000 C CNN
F 2 "" H 4800 7350 50  0001 C CNN
F 3 "" H 4800 7350 50  0001 C CNN
	1    4800 7350
	1    0    0    -1  
$EndComp
Wire Wire Line
	4800 7350 4800 7250
$Comp
L Device:C C?
U 1 1 5DFF99C6
P 4500 7100
F 0 "C?" H 4550 7200 50  0000 L CNN
F 1 "100n" H 4550 7000 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 4538 6950 50  0001 C CNN
F 3 "~" H 4500 7100 50  0001 C CNN
	1    4500 7100
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5DFF99D0
P 4500 6900
F 0 "#PWR?" H 4500 6750 50  0001 C CNN
F 1 "+3.3V" V 4500 7150 50  0000 C CNN
F 2 "" H 4500 6900 50  0001 C CNN
F 3 "" H 4500 6900 50  0001 C CNN
	1    4500 6900
	1    0    0    -1  
$EndComp
Wire Wire Line
	4500 6900 4500 6950
$Comp
L power:GND #PWR?
U 1 1 5DFF99DB
P 4500 7350
F 0 "#PWR?" H 4500 7100 50  0001 C CNN
F 1 "GND" H 4505 7177 50  0000 C CNN
F 2 "" H 4500 7350 50  0001 C CNN
F 3 "" H 4500 7350 50  0001 C CNN
	1    4500 7350
	1    0    0    -1  
$EndComp
Wire Wire Line
	4500 7350 4500 7250
$Comp
L Device:C C?
U 1 1 5DFF99E6
P 4200 7100
F 0 "C?" H 4250 7200 50  0000 L CNN
F 1 "100n" H 4250 7000 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 4238 6950 50  0001 C CNN
F 3 "~" H 4200 7100 50  0001 C CNN
	1    4200 7100
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5DFF99F0
P 4200 6900
F 0 "#PWR?" H 4200 6750 50  0001 C CNN
F 1 "+3.3V" V 4200 7150 50  0000 C CNN
F 2 "" H 4200 6900 50  0001 C CNN
F 3 "" H 4200 6900 50  0001 C CNN
	1    4200 6900
	1    0    0    -1  
$EndComp
Wire Wire Line
	4200 6900 4200 6950
$Comp
L power:GND #PWR?
U 1 1 5DFF99FB
P 4200 7350
F 0 "#PWR?" H 4200 7100 50  0001 C CNN
F 1 "GND" H 4205 7177 50  0000 C CNN
F 2 "" H 4200 7350 50  0001 C CNN
F 3 "" H 4200 7350 50  0001 C CNN
	1    4200 7350
	1    0    0    -1  
$EndComp
Wire Wire Line
	4200 7350 4200 7250
$Comp
L Device:C C?
U 1 1 5DFF9A06
P 3900 7100
F 0 "C?" H 3950 7200 50  0000 L CNN
F 1 "100n" H 3950 7000 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 3938 6950 50  0001 C CNN
F 3 "~" H 3900 7100 50  0001 C CNN
	1    3900 7100
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5DFF9A10
P 3900 6900
F 0 "#PWR?" H 3900 6750 50  0001 C CNN
F 1 "+3.3V" V 3900 7150 50  0000 C CNN
F 2 "" H 3900 6900 50  0001 C CNN
F 3 "" H 3900 6900 50  0001 C CNN
	1    3900 6900
	1    0    0    -1  
$EndComp
Wire Wire Line
	3900 6900 3900 6950
$Comp
L power:GND #PWR?
U 1 1 5DFF9A1B
P 3900 7350
F 0 "#PWR?" H 3900 7100 50  0001 C CNN
F 1 "GND" H 3905 7177 50  0000 C CNN
F 2 "" H 3900 7350 50  0001 C CNN
F 3 "" H 3900 7350 50  0001 C CNN
	1    3900 7350
	1    0    0    -1  
$EndComp
Wire Wire Line
	3900 7350 3900 7250
$EndSCHEMATC
