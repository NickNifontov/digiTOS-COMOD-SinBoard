EESchema Schematic File Version 4
LIBS:digiTOS-COMOD-SinBoard-cache
EELAYER 29 0
EELAYER END
$Descr A3 16535 11693
encoding utf-8
Sheet 1 1
Title "digiTOS-COMOD-SinBoard"
Date "2018-12-25"
Rev "Rev B"
Comp "GALS-S PP"
Comment1 "Nick Nifontov"
Comment2 "nifontov@gmail.com"
Comment3 "http://www.leoton.ua/"
Comment4 "based on STM32F030K6T6"
$EndDescr
$Comp
L Mechanical:MountingHole H1
U 1 1 5C1428CF
P 850 750
F 0 "H1" H 950 796 50  0000 L CNN
F 1 "MountingHole" H 950 705 50  0000 L CNN
F 2 "MountingHole:MountingHole_4.3mm_M4" H 850 750 50  0001 C CNN
F 3 "~" H 850 750 50  0001 C CNN
	1    850  750 
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H2
U 1 1 5C142F8F
P 850 950
F 0 "H2" H 950 996 50  0000 L CNN
F 1 "MountingHole" H 950 905 50  0000 L CNN
F 2 "MountingHole:MountingHole_4.3mm_M4" H 850 950 50  0001 C CNN
F 3 "~" H 850 950 50  0001 C CNN
	1    850  950 
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H3
U 1 1 5C14364D
P 1550 750
F 0 "H3" H 1650 796 50  0000 L CNN
F 1 "MountingHole" H 1650 705 50  0000 L CNN
F 2 "MountingHole:MountingHole_4.3mm_M4" H 1550 750 50  0001 C CNN
F 3 "~" H 1550 750 50  0001 C CNN
	1    1550 750 
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H4
U 1 1 5C143F1B
P 1550 950
F 0 "H4" H 1650 996 50  0000 L CNN
F 1 "MountingHole" H 1650 905 50  0000 L CNN
F 2 "MountingHole:MountingHole_4.3mm_M4" H 1550 950 50  0001 C CNN
F 3 "~" H 1550 950 50  0001 C CNN
	1    1550 950 
	1    0    0    -1  
$EndComp
Text Notes 1100 600  0    50   ~ 0
Mounting Holes
Text Notes 3000 600  0    50   ~ 0
Input Dev Power Supply
$Comp
L Connector:Conn_01x02_Male RAW-GND1
U 1 1 5C143153
P 3100 850
F 0 "RAW-GND1" H 3208 1031 50  0000 C CNN
F 1 "Conn_01x02_Male" H 3200 950 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x02_P2.54mm_Vertical" H 3100 850 50  0001 C CNN
F 3 "~" H 3100 850 50  0001 C CNN
	1    3100 850 
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR0101
U 1 1 5C143B57
P 3650 850
F 0 "#PWR0101" H 3650 700 50  0001 C CNN
F 1 "+12V" H 3665 1023 50  0000 C CNN
F 2 "" H 3650 850 50  0001 C CNN
F 3 "" H 3650 850 50  0001 C CNN
	1    3650 850 
	1    0    0    -1  
$EndComp
Wire Wire Line
	3300 850  3650 850 
$Comp
L power:GND #PWR0102
U 1 1 5C144092
P 3400 1000
F 0 "#PWR0102" H 3400 750 50  0001 C CNN
F 1 "GND" H 3405 827 50  0000 C CNN
F 2 "" H 3400 1000 50  0001 C CNN
F 3 "" H 3400 1000 50  0001 C CNN
	1    3400 1000
	1    0    0    -1  
$EndComp
Wire Wire Line
	3300 950  3400 950 
Wire Wire Line
	3400 950  3400 1000
Text Notes 1100 1750 0    50   ~ 0
IDC_0
$Comp
L Connector:Conn_01x10_Female J1
U 1 1 5C14513A
P 750 2350
F 0 "J1" H 642 2935 50  0000 C CNN
F 1 "Conn_01x10_Female" H 642 2844 50  0000 C CNN
F 2 "Connector_IDC:IDC-Header_2x05_P2.54mm_Vertical" H 750 2350 50  0001 C CNN
F 3 "~" H 750 2350 50  0001 C CNN
	1    750  2350
	-1   0    0    -1  
$EndComp
$Comp
L power:GND #PWR0103
U 1 1 5C146187
P 1550 2050
F 0 "#PWR0103" H 1550 1800 50  0001 C CNN
F 1 "GND" H 1555 1877 50  0000 C CNN
F 2 "" H 1550 2050 50  0001 C CNN
F 3 "" H 1550 2050 50  0001 C CNN
	1    1550 2050
	0    -1   -1   0   
$EndComp
$Comp
L digiTOS-COMOD-SinBoard-rescue:BV202S09006-Device T1
U 1 1 5C157781
P 5000 950
F 0 "T1" H 5000 1331 50  0000 C CNN
F 1 "BV202S09006" H 5000 1240 50  0000 C CNN
F 2 "BV_Discon:BV202S09006" H 5000 950 50  0001 C CNN
F 3 "~" H 5000 950 50  0001 C CNN
	1    5000 950 
	1    0    0    -1  
$EndComp
$Comp
L digiTOS-COMOD-SinBoard-rescue:BV302S18020-bv202s09006 T2
U 1 1 5C143A42
P 5050 1750
F 0 "T2" H 5050 2131 50  0000 C CNN
F 1 "BV302S18020" H 5050 2040 50  0000 C CNN
F 2 "BV_Discon:BV302S18020" H 5050 1750 50  0001 C CNN
F 3 "~" H 5050 1750 50  0001 C CNN
	1    5050 1750
	1    0    0    -1  
$EndComp
$Comp
L power:NEUT #PWR04
U 1 1 5C145E00
P 4250 1550
F 0 "#PWR04" H 4250 1400 50  0001 C CNN
F 1 "NEUT" H 4267 1723 50  0000 C CNN
F 2 "" H 4250 1550 50  0001 C CNN
F 3 "" H 4250 1550 50  0001 C CNN
	1    4250 1550
	1    0    0    -1  
$EndComp
$Comp
L power:NEUT #PWR02
U 1 1 5C146404
P 4350 750
F 0 "#PWR02" H 4350 600 50  0001 C CNN
F 1 "NEUT" H 4367 923 50  0000 C CNN
F 2 "" H 4350 750 50  0001 C CNN
F 3 "" H 4350 750 50  0001 C CNN
	1    4350 750 
	1    0    0    -1  
$EndComp
Wire Wire Line
	4350 1150 4600 1150
Text GLabel 6100 1950 2    50   Input ~ 0
V_Trans_out1
Text GLabel 6100 1550 2    50   Input ~ 0
V_Trans_out2
Text GLabel 5850 750  2    50   Input ~ 0
V_Trans_out2
Text GLabel 5850 1150 2    50   Input ~ 0
V_Trans_out1
Wire Wire Line
	5400 1150 5850 1150
Wire Wire Line
	5400 750  5850 750 
Wire Wire Line
	5450 1550 6100 1550
Wire Wire Line
	5450 1950 6100 1950
Text Notes 5100 2300 2    50   ~ 0
V_Sensor
Text Notes 13650 1150 2    50   ~ 0
I_Sensor
Text GLabel 13650 1550 2    50   Input ~ 0
CT_out2
$Comp
L digiTOS-COMOD-SinBoard-rescue:ZMCT116A-Transformer T3
U 1 1 5C15D30A
P 12600 1850
F 0 "T3" H 12600 2090 50  0000 C CNN
F 1 "ZMCT116A" H 12600 1999 50  0000 C CNN
F 2 "ZMCT116A:ZMCT116A" H 12600 1850 50  0001 C CNN
F 3 "" H 12600 1850 50  0001 C CNN
	1    12600 1850
	0    -1   -1   0   
$EndComp
Text Notes 10250 2850 0    50   ~ 0
AC Input
$Comp
L Connector:Screw_Terminal_01x02 NEUT-LINE_IN1
U 1 1 5C14DCFC
P 9600 2950
F 0 "NEUT-LINE_IN1" H 9680 2942 50  0000 L CNN
F 1 "Screw_Terminal_01x02" H 9680 2851 50  0000 L CNN
F 2 "TerminalBlock:TerminalBlock_bornier-2_P5.08mm" H 9600 2950 50  0001 C CNN
F 3 "~" H 9600 2950 50  0001 C CNN
	1    9600 2950
	1    0    0    -1  
$EndComp
$Comp
L power:AC #PWR05
U 1 1 5C14E5DE
P 7950 2900
F 0 "#PWR05" H 7950 2800 50  0001 C CNN
F 1 "AC" H 7950 3175 50  0000 C CNN
F 2 "" H 7950 2900 50  0001 C CNN
F 3 "" H 7950 2900 50  0001 C CNN
	1    7950 2900
	1    0    0    -1  
$EndComp
$Comp
L power:NEUT #PWR06
U 1 1 5C14EC60
P 9100 3300
F 0 "#PWR06" H 9100 3150 50  0001 C CNN
F 1 "NEUT" H 9117 3473 50  0000 C CNN
F 2 "" H 9100 3300 50  0001 C CNN
F 3 "" H 9100 3300 50  0001 C CNN
	1    9100 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	9100 3300 9400 3300
Wire Wire Line
	9400 3300 9400 3050
$Comp
L Device:Fuse F1
U 1 1 5C14FE8B
P 9050 2950
F 0 "F1" V 9247 2950 50  0000 C CNN
F 1 "Fuse" V 9156 2950 50  0000 C CNN
F 2 "Fuse:Fuseholder_Blade_Mini_Keystone_3568" V 8980 2950 50  0001 C CNN
F 3 "~" H 9050 2950 50  0001 C CNN
	1    9050 2950
	0    -1   -1   0   
$EndComp
Wire Wire Line
	9200 2950 9400 2950
Wire Wire Line
	8900 2950 8900 3000
$Comp
L Connector:Conn_01x01_Female J4
U 1 1 5C156814
P 9550 3950
F 0 "J4" H 9578 3976 50  0000 L CNN
F 1 "Conn_01x01_Female" H 9578 3885 50  0000 L CNN
F 2 "Connector_Wire:SolderWirePad_1x01_Drill2.5mm" H 9550 3950 50  0001 C CNN
F 3 "~" H 9550 3950 50  0001 C CNN
	1    9550 3950
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female J3
U 1 1 5C156BF3
P 8650 2550
F 0 "J3" H 8678 2576 50  0000 L CNN
F 1 "Conn_01x01_Female" H 8678 2485 50  0000 L CNN
F 2 "Connector_Wire:SolderWirePad_1x01_Drill2.5mm" H 8650 2550 50  0001 C CNN
F 3 "~" H 8650 2550 50  0001 C CNN
	1    8650 2550
	1    0    0    -1  
$EndComp
$Comp
L Connector:Screw_Terminal_01x02 NEUT-LINE_OUT1
U 1 1 5C159FA7
P 9600 4250
F 0 "NEUT-LINE_OUT1" H 9680 4242 50  0000 L CNN
F 1 "Screw_Terminal_01x02" H 9680 4151 50  0000 L CNN
F 2 "TerminalBlock:TerminalBlock_bornier-2_P5.08mm" H 9600 4250 50  0001 C CNN
F 3 "~" H 9600 4250 50  0001 C CNN
	1    9600 4250
	1    0    0    -1  
$EndComp
$Comp
L power:LINE #PWR07
U 1 1 5C15A745
P 9150 3950
F 0 "#PWR07" H 9150 3800 50  0001 C CNN
F 1 "LINE" H 9167 4123 50  0000 C CNN
F 2 "" H 9150 3950 50  0001 C CNN
F 3 "" H 9150 3950 50  0001 C CNN
	1    9150 3950
	1    0    0    -1  
$EndComp
$Comp
L power:NEUT #PWR08
U 1 1 5C15ABC2
P 9150 4500
F 0 "#PWR08" H 9150 4350 50  0001 C CNN
F 1 "NEUT" H 9167 4673 50  0000 C CNN
F 2 "" H 9150 4500 50  0001 C CNN
F 3 "" H 9150 4500 50  0001 C CNN
	1    9150 4500
	1    0    0    -1  
$EndComp
Wire Wire Line
	9150 4500 9400 4500
Wire Wire Line
	9400 4500 9400 4350
Wire Wire Line
	9350 3950 9350 4250
Wire Wire Line
	9350 4250 9400 4250
Wire Wire Line
	9150 3950 9350 3950
Connection ~ 9350 3950
Wire Wire Line
	8450 3000 8450 2550
Wire Wire Line
	8450 3000 8900 3000
Wire Wire Line
	8450 2550 8100 2550
Wire Wire Line
	8100 2550 8100 2900
Wire Wire Line
	8100 2900 7950 2900
Connection ~ 8450 2550
$Comp
L power:LINE #PWR0104
U 1 1 5C16651D
P 4200 1950
F 0 "#PWR0104" H 4200 1800 50  0001 C CNN
F 1 "LINE" H 4217 2123 50  0000 C CNN
F 2 "" H 4200 1950 50  0001 C CNN
F 3 "" H 4200 1950 50  0001 C CNN
	1    4200 1950
	1    0    0    -1  
$EndComp
$Comp
L power:LINE #PWR0105
U 1 1 5C16733D
P 4350 1150
F 0 "#PWR0105" H 4350 1000 50  0001 C CNN
F 1 "LINE" H 4367 1323 50  0000 C CNN
F 2 "" H 4350 1150 50  0001 C CNN
F 3 "" H 4350 1150 50  0001 C CNN
	1    4350 1150
	1    0    0    -1  
$EndComp
Wire Wire Line
	4350 750  4600 750 
Wire Wire Line
	4200 1950 4650 1950
Wire Wire Line
	4250 1550 4650 1550
$Comp
L power:+12V #PWR0106
U 1 1 5C17A010
P 1600 2850
F 0 "#PWR0106" H 1600 2700 50  0001 C CNN
F 1 "+12V" H 1615 3023 50  0000 C CNN
F 2 "" H 1600 2850 50  0001 C CNN
F 3 "" H 1600 2850 50  0001 C CNN
	1    1600 2850
	0    1    1    0   
$EndComp
Wire Wire Line
	950  2050 1550 2050
Wire Wire Line
	950  2850 1600 2850
$Comp
L Device:LED D4
U 1 1 5C1805EC
P 2100 4450
F 0 "D4" V 2139 4333 50  0000 R CNN
F 1 "LED" V 2048 4333 50  0000 R CNN
F 2 "LED_SMD:LED_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 2100 4450 50  0001 C CNN
F 3 "~" H 2100 4450 50  0001 C CNN
	1    2100 4450
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED D3
U 1 1 5C180F41
P 1750 4450
F 0 "D3" V 1789 4333 50  0000 R CNN
F 1 "LED" V 1698 4333 50  0000 R CNN
F 2 "LED_SMD:LED_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 1750 4450 50  0001 C CNN
F 3 "~" H 1750 4450 50  0001 C CNN
	1    1750 4450
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED D2
U 1 1 5C1813FF
P 1400 4450
F 0 "D2" V 1439 4333 50  0000 R CNN
F 1 "LED" V 1348 4333 50  0000 R CNN
F 2 "LED_SMD:LED_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 1400 4450 50  0001 C CNN
F 3 "~" H 1400 4450 50  0001 C CNN
	1    1400 4450
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED D1
U 1 1 5C1816B3
P 1050 4450
F 0 "D1" V 1089 4333 50  0000 R CNN
F 1 "LED" V 998 4333 50  0000 R CNN
F 2 "LED_SMD:LED_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 1050 4450 50  0001 C CNN
F 3 "~" H 1050 4450 50  0001 C CNN
	1    1050 4450
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR01
U 1 1 5C181B2D
P 1700 5450
F 0 "#PWR01" H 1700 5200 50  0001 C CNN
F 1 "GND" H 1705 5277 50  0000 C CNN
F 2 "" H 1700 5450 50  0001 C CNN
F 3 "" H 1700 5450 50  0001 C CNN
	1    1700 5450
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 5C182002
P 1050 4900
F 0 "R1" H 1120 4946 50  0000 L CNN
F 1 "330 Ohm" H 1120 4855 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 980 4900 50  0001 C CNN
F 3 "~" H 1050 4900 50  0001 C CNN
	1    1050 4900
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 5C1824B7
P 1400 4900
F 0 "R2" H 1470 4946 50  0000 L CNN
F 1 "330 Ohm" H 1470 4855 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 1330 4900 50  0001 C CNN
F 3 "~" H 1400 4900 50  0001 C CNN
	1    1400 4900
	1    0    0    -1  
$EndComp
$Comp
L Device:R R3
U 1 1 5C182801
P 1750 4900
F 0 "R3" H 1820 4946 50  0000 L CNN
F 1 "330 Ohm" H 1820 4855 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 1680 4900 50  0001 C CNN
F 3 "~" H 1750 4900 50  0001 C CNN
	1    1750 4900
	1    0    0    -1  
$EndComp
$Comp
L Device:R R4
U 1 1 5C182B75
P 2100 4900
F 0 "R4" H 2170 4946 50  0000 L CNN
F 1 "330 Ohm" H 2170 4855 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 2030 4900 50  0001 C CNN
F 3 "~" H 2100 4900 50  0001 C CNN
	1    2100 4900
	1    0    0    -1  
$EndComp
Wire Wire Line
	2100 5050 2100 5300
Wire Wire Line
	1750 5050 1750 5300
Wire Wire Line
	1400 5050 1400 5300
Wire Wire Line
	1400 5300 1700 5300
Connection ~ 1750 5300
Wire Wire Line
	1050 5050 1050 5300
Wire Wire Line
	1050 5300 1400 5300
Connection ~ 1400 5300
Wire Wire Line
	1050 4750 1050 4600
Wire Wire Line
	1400 4750 1400 4600
Wire Wire Line
	1750 4750 1750 4600
Wire Wire Line
	2100 4750 2100 4600
Text GLabel 1050 4150 1    50   Input ~ 0
LED1
Text GLabel 1400 4150 1    50   Input ~ 0
LED2
Text GLabel 1750 4150 1    50   Input ~ 0
LED3
Text GLabel 2100 4150 1    50   Input ~ 0
LED4
Wire Wire Line
	1050 4150 1050 4300
Wire Wire Line
	1400 4150 1400 4300
Wire Wire Line
	1750 4150 1750 4300
Wire Wire Line
	2100 4150 2100 4300
Text Notes 850  4800 1    50   ~ 0
LEDs
Text Notes 650  7300 1    50   ~ 0
Power Supply 3.3V
$Comp
L Regulator_Linear:AMS1117-3.3 U1
U 1 1 5C18DAB8
P 2000 7100
F 0 "U1" H 2000 7342 50  0000 C CNN
F 1 "AMS1117-3.3" H 2000 7251 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-223-3_TabPin2" H 2000 7300 50  0001 C CNN
F 3 "http://www.advanced-monolithic.com/pdf/ds1117.pdf" H 2100 6850 50  0001 C CNN
	1    2000 7100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR03
U 1 1 5C18E4E0
P 2000 7550
F 0 "#PWR03" H 2000 7300 50  0001 C CNN
F 1 "GND" H 2005 7377 50  0000 C CNN
F 2 "" H 2000 7550 50  0001 C CNN
F 3 "" H 2000 7550 50  0001 C CNN
	1    2000 7550
	1    0    0    -1  
$EndComp
Wire Wire Line
	2000 7400 2000 7550
$Comp
L Device:C C3
U 1 1 5C18F2EE
P 2550 7250
F 0 "C3" H 2665 7296 50  0000 L CNN
F 1 "0,1uf" H 2665 7205 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 2588 7100 50  0001 C CNN
F 3 "~" H 2550 7250 50  0001 C CNN
	1    2550 7250
	1    0    0    -1  
$EndComp
$Comp
L Device:C C4
U 1 1 5C18F62C
P 3000 7250
F 0 "C4" H 3115 7296 50  0000 L CNN
F 1 "22uf" H 3115 7205 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 3038 7100 50  0001 C CNN
F 3 "~" H 3000 7250 50  0001 C CNN
	1    3000 7250
	1    0    0    -1  
$EndComp
$Comp
L Device:C C2
U 1 1 5C18FBB2
P 1500 7250
F 0 "C2" H 1615 7296 50  0000 L CNN
F 1 "0,1uf" H 1615 7205 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 1538 7100 50  0001 C CNN
F 3 "~" H 1500 7250 50  0001 C CNN
	1    1500 7250
	1    0    0    -1  
$EndComp
$Comp
L Device:C C1
U 1 1 5C190046
P 1150 7250
F 0 "C1" H 1265 7296 50  0000 L CNN
F 1 "22uf" H 1265 7205 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 1188 7100 50  0001 C CNN
F 3 "~" H 1150 7250 50  0001 C CNN
	1    1150 7250
	1    0    0    -1  
$EndComp
Wire Wire Line
	1500 7400 1150 7400
Wire Wire Line
	1500 7400 1500 7550
Wire Wire Line
	1500 7550 2000 7550
Connection ~ 1500 7400
Connection ~ 2000 7550
Wire Wire Line
	2000 7550 2550 7550
Wire Wire Line
	2550 7550 2550 7400
Wire Wire Line
	2550 7400 3000 7400
Connection ~ 2550 7400
Wire Wire Line
	2550 7100 3000 7100
Wire Wire Line
	2550 7100 2300 7100
Connection ~ 2550 7100
$Comp
L power:+12V #PWR0107
U 1 1 5C197809
P 800 6750
F 0 "#PWR0107" H 800 6600 50  0001 C CNN
F 1 "+12V" H 815 6923 50  0000 C CNN
F 2 "" H 800 6750 50  0001 C CNN
F 3 "" H 800 6750 50  0001 C CNN
	1    800  6750
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0108
U 1 1 5C19A5D5
P 3150 6900
F 0 "#PWR0108" H 3150 6750 50  0001 C CNN
F 1 "+3.3V" H 3165 7073 50  0000 C CNN
F 2 "" H 3150 6900 50  0001 C CNN
F 3 "" H 3150 6900 50  0001 C CNN
	1    3150 6900
	1    0    0    -1  
$EndComp
Wire Wire Line
	3150 6900 3150 7100
Wire Wire Line
	3150 7100 3000 7100
Connection ~ 3000 7100
$Comp
L power:+3.3V #PWR0109
U 1 1 5C19BEE4
P 1400 1850
F 0 "#PWR0109" H 1400 1700 50  0001 C CNN
F 1 "+3.3V" H 1415 2023 50  0000 C CNN
F 2 "" H 1400 1850 50  0001 C CNN
F 3 "" H 1400 1850 50  0001 C CNN
	1    1400 1850
	1    0    0    -1  
$EndComp
Wire Wire Line
	1400 1850 1400 1950
Wire Wire Line
	1400 1950 950  1950
Text GLabel 1900 2150 2    50   Input ~ 0
CH1
Text GLabel 1900 2350 2    50   Input ~ 0
CH2
Text GLabel 1900 2550 2    50   Input ~ 0
CH3
Text GLabel 1900 2750 2    50   Input ~ 0
CH4
Wire Wire Line
	950  2150 1900 2150
Wire Wire Line
	1900 2350 950  2350
Wire Wire Line
	1900 2550 950  2550
Wire Wire Line
	1900 2750 950  2750
Text GLabel 2250 2250 2    50   Input ~ 0
FAULT_FEEDBACK
Text GLabel 2250 2450 2    50   Input ~ 0
RST
Text GLabel 2250 2650 2    50   Input ~ 0
DC_FEEDBACK
Wire Wire Line
	2250 2650 950  2650
Wire Wire Line
	2250 2450 950  2450
Wire Wire Line
	2250 2250 950  2250
$Comp
L power:+12V #PWR09
U 1 1 5C1BD75A
P 4000 3250
F 0 "#PWR09" H 4000 3100 50  0001 C CNN
F 1 "+12V" H 4015 3423 50  0000 C CNN
F 2 "" H 4000 3250 50  0001 C CNN
F 3 "" H 4000 3250 50  0001 C CNN
	1    4000 3250
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR010
U 1 1 5C1BF102
P 4000 4800
F 0 "#PWR010" H 4000 4650 50  0001 C CNN
F 1 "+12V" H 4015 4973 50  0000 C CNN
F 2 "" H 4000 4800 50  0001 C CNN
F 3 "" H 4000 4800 50  0001 C CNN
	1    4000 4800
	-1   0    0    1   
$EndComp
$Comp
L STM32F030K6T6_BOARD:STM32F030K6T6_BoardA STM321
U 1 1 5C158A18
P 5050 4050
F 0 "STM321" H 6328 4171 50  0000 L CNN
F 1 "STM32F030K6T6_BoardA" H 6328 4080 50  0000 L CNN
F 2 "STM32F030K6T6_BoardA:STM32F030K6T6_BoardA" H 4800 4050 50  0001 C CNN
F 3 "" H 4800 4050 50  0001 C CNN
	1    5050 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	4000 3250 4000 3350
Wire Wire Line
	4000 4800 4000 4600
$Comp
L power:GND #PWR012
U 1 1 5C15E15B
P 6100 4800
F 0 "#PWR012" H 6100 4550 50  0001 C CNN
F 1 "GND" H 6105 4627 50  0000 C CNN
F 2 "" H 6100 4800 50  0001 C CNN
F 3 "" H 6100 4800 50  0001 C CNN
	1    6100 4800
	1    0    0    -1  
$EndComp
Wire Wire Line
	6100 4800 6100 4600
$Comp
L power:GND #PWR011
U 1 1 5C16071A
P 6100 3200
F 0 "#PWR011" H 6100 2950 50  0001 C CNN
F 1 "GND" H 6105 3027 50  0000 C CNN
F 2 "" H 6100 3200 50  0001 C CNN
F 3 "" H 6100 3200 50  0001 C CNN
	1    6100 3200
	-1   0    0    1   
$EndComp
Wire Wire Line
	6100 3200 6100 3350
Text GLabel 4900 4950 3    50   Input ~ 0
LED1
Text GLabel 5200 3100 1    50   Input ~ 0
LED2
Text GLabel 5350 5250 3    50   Input ~ 0
LED3
Text GLabel 5500 4900 3    50   Input ~ 0
LED4
Text GLabel 4750 2850 1    50   Input ~ 0
TX
Text GLabel 4750 5000 3    50   Input ~ 0
RX
$Comp
L Connector:Conn_01x03_Male RX-TX-GND1
U 1 1 5C187EEC
P 9850 5500
F 0 "RX-TX-GND1" H 9958 5781 50  0000 C CNN
F 1 "Conn_01x03_Male" H 9958 5690 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x03_P2.54mm_Vertical" H 9850 5500 50  0001 C CNN
F 3 "~" H 9850 5500 50  0001 C CNN
	1    9850 5500
	1    0    0    -1  
$EndComp
Text GLabel 11000 5400 2    50   Input ~ 0
RX
Text GLabel 11000 5650 2    50   Input ~ 0
TX
$Comp
L power:GND #PWR0110
U 1 1 5C189177
P 10100 5750
F 0 "#PWR0110" H 10100 5500 50  0001 C CNN
F 1 "GND" H 10105 5577 50  0000 C CNN
F 2 "" H 10100 5750 50  0001 C CNN
F 3 "" H 10100 5750 50  0001 C CNN
	1    10100 5750
	1    0    0    -1  
$EndComp
Wire Wire Line
	10500 5500 10450 5500
$Comp
L Device:R R5
U 1 1 5C19354A
P 10600 5350
F 0 "R5" V 10807 5350 50  0000 C CNN
F 1 "100 Ohm" V 10716 5350 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 10530 5350 50  0001 C CNN
F 3 "~" H 10600 5350 50  0001 C CNN
	1    10600 5350
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R6
U 1 1 5C196493
P 10600 5650
F 0 "R6" V 10500 5650 50  0000 C CNN
F 1 "100 Ohm" V 10400 5650 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 10530 5650 50  0001 C CNN
F 3 "~" H 10600 5650 50  0001 C CNN
	1    10600 5650
	0    -1   -1   0   
$EndComp
Wire Wire Line
	10050 5600 10100 5600
Wire Wire Line
	10100 5600 10100 5750
Wire Wire Line
	10050 5400 10450 5400
Wire Wire Line
	10450 5400 10450 5350
Wire Wire Line
	10050 5500 10450 5500
Wire Wire Line
	10450 5500 10450 5650
Connection ~ 10450 5500
Wire Wire Line
	10750 5350 10900 5350
Wire Wire Line
	11000 5350 11000 5400
Wire Wire Line
	10750 5650 10900 5650
$Comp
L Device:D_Zener_ALT D5
U 1 1 5C1AF149
P 10900 5000
F 0 "D5" V 10946 4921 50  0000 R CNN
F 1 "Zener" V 10855 4921 50  0000 R CNN
F 2 "Diode_SMD:D_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 10900 5000 50  0001 C CNN
F 3 "~" H 10900 5000 50  0001 C CNN
	1    10900 5000
	0    -1   -1   0   
$EndComp
$Comp
L Device:D_Zener_ALT D6
U 1 1 5C1B4576
P 10900 5900
F 0 "D6" V 10854 5979 50  0000 L CNN
F 1 "Zener" V 10945 5979 50  0000 L CNN
F 2 "Diode_SMD:D_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 10900 5900 50  0001 C CNN
F 3 "~" H 10900 5900 50  0001 C CNN
	1    10900 5900
	0    1    1    0   
$EndComp
Wire Wire Line
	10900 5650 10900 5750
Connection ~ 10900 5650
Wire Wire Line
	10900 5650 11000 5650
Wire Wire Line
	10900 5150 10900 5350
Connection ~ 10900 5350
Wire Wire Line
	10900 5350 11000 5350
$Comp
L power:GND #PWR013
U 1 1 5C1BE17A
P 10700 4850
F 0 "#PWR013" H 10700 4600 50  0001 C CNN
F 1 "GND" H 10705 4677 50  0000 C CNN
F 2 "" H 10700 4850 50  0001 C CNN
F 3 "" H 10700 4850 50  0001 C CNN
	1    10700 4850
	1    0    0    -1  
$EndComp
Wire Wire Line
	10700 4850 10900 4850
$Comp
L power:GND #PWR014
U 1 1 5C1C0BDD
P 10900 6150
F 0 "#PWR014" H 10900 5900 50  0001 C CNN
F 1 "GND" H 10905 5977 50  0000 C CNN
F 2 "" H 10900 6150 50  0001 C CNN
F 3 "" H 10900 6150 50  0001 C CNN
	1    10900 6150
	1    0    0    -1  
$EndComp
Wire Wire Line
	10900 6150 10900 6050
Text GLabel 5050 2900 1    50   Input ~ 0
_CH4
Text GLabel 5350 2900 1    50   Input ~ 0
_CH2
Text GLabel 4600 2650 1    50   Input ~ 0
_CH3
Text GLabel 5500 3000 1    50   Input ~ 0
_CH1
Text GLabel 5800 4850 3    50   Input ~ 0
_V_OUT
Text GLabel 5950 4850 3    50   Input ~ 0
_CT_out2
Text GLabel 5950 2900 1    50   Input ~ 0
_FAULT_FEEDBACK
Text GLabel 5200 4900 3    50   Input ~ 0
_RST
Text GLabel 5650 3150 1    50   Input ~ 0
_DC_FEEDBACK
Text GLabel 4900 2900 1    50   Input ~ 0
DEV_MODE1
Text GLabel 5800 2600 1    50   Input ~ 0
DEV_MODE2
Text GLabel 4650 5700 0    50   Input ~ 0
_V_OUT
Text GLabel 5350 5700 2    50   Input ~ 0
V_OUT
$Comp
L Device:D_Zener_ALT D7
U 1 1 5C1FC735
P 5000 5700
F 0 "D7" V 5046 5621 50  0000 R CNN
F 1 "Zener" V 4955 5621 50  0000 R CNN
F 2 "Diode_SMD:D_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 5000 5700 50  0001 C CNN
F 3 "~" H 5000 5700 50  0001 C CNN
	1    5000 5700
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR015
U 1 1 5C1FD278
P 4850 5550
F 0 "#PWR015" H 4850 5300 50  0001 C CNN
F 1 "GND" V 4855 5422 50  0000 R CNN
F 2 "" H 4850 5550 50  0001 C CNN
F 3 "" H 4850 5550 50  0001 C CNN
	1    4850 5550
	0    1    1    0   
$EndComp
Wire Wire Line
	4850 5550 5000 5550
Wire Wire Line
	4650 5700 4650 6000
Wire Wire Line
	4650 6000 5000 6000
Wire Wire Line
	5350 6000 5350 5700
Wire Wire Line
	5000 5850 5000 6000
Wire Wire Line
	5000 6000 5350 6000
Connection ~ 5000 6000
Text GLabel 4750 6400 0    50   Input ~ 0
_CT_out2
Text GLabel 5450 6400 2    50   Input ~ 0
CT_out2
$Comp
L Device:D_Zener_ALT D8
U 1 1 5C256938
P 5100 6400
F 0 "D8" V 5146 6321 50  0000 R CNN
F 1 "Zener" V 5055 6321 50  0000 R CNN
F 2 "Diode_SMD:D_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 5100 6400 50  0001 C CNN
F 3 "~" H 5100 6400 50  0001 C CNN
	1    5100 6400
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR016
U 1 1 5C256942
P 4950 6250
F 0 "#PWR016" H 4950 6000 50  0001 C CNN
F 1 "GND" V 4955 6122 50  0000 R CNN
F 2 "" H 4950 6250 50  0001 C CNN
F 3 "" H 4950 6250 50  0001 C CNN
	1    4950 6250
	0    1    1    0   
$EndComp
Wire Wire Line
	4950 6250 5100 6250
Wire Wire Line
	4750 6400 4750 6700
Wire Wire Line
	4750 6700 5100 6700
Wire Wire Line
	5450 6700 5450 6400
Wire Wire Line
	5100 6550 5100 6700
Wire Wire Line
	5100 6700 5450 6700
Connection ~ 5100 6700
Text GLabel 6800 5450 0    50   Input ~ 0
_DC_FEEDBACK
Text GLabel 7500 5450 2    50   Input ~ 0
DC_FEEDBACK
$Comp
L Device:D_Zener_ALT D9
U 1 1 5C263A62
P 7150 5450
F 0 "D9" V 7196 5371 50  0000 R CNN
F 1 "Zener" V 7105 5371 50  0000 R CNN
F 2 "Diode_SMD:D_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 7150 5450 50  0001 C CNN
F 3 "~" H 7150 5450 50  0001 C CNN
	1    7150 5450
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR017
U 1 1 5C263A6C
P 7000 5300
F 0 "#PWR017" H 7000 5050 50  0001 C CNN
F 1 "GND" V 7005 5172 50  0000 R CNN
F 2 "" H 7000 5300 50  0001 C CNN
F 3 "" H 7000 5300 50  0001 C CNN
	1    7000 5300
	0    1    1    0   
$EndComp
Wire Wire Line
	7000 5300 7150 5300
Wire Wire Line
	6800 5450 6800 5750
Wire Wire Line
	6800 5750 7150 5750
Wire Wire Line
	7500 5750 7500 5450
Wire Wire Line
	7150 5600 7150 5750
Wire Wire Line
	7150 5750 7500 5750
Connection ~ 7150 5750
Text GLabel 4700 7250 0    50   Input ~ 0
_FAULT_FEEDBACK
Text GLabel 5400 7250 2    50   Input ~ 0
FAULT_FEEDBACK
$Comp
L Device:D_Zener_ALT D10
U 1 1 5C27070B
P 5050 7250
F 0 "D10" V 5096 7171 50  0000 R CNN
F 1 "Zener" V 5005 7171 50  0000 R CNN
F 2 "Diode_SMD:D_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 5050 7250 50  0001 C CNN
F 3 "~" H 5050 7250 50  0001 C CNN
	1    5050 7250
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR018
U 1 1 5C270715
P 4900 7100
F 0 "#PWR018" H 4900 6850 50  0001 C CNN
F 1 "GND" V 4905 6972 50  0000 R CNN
F 2 "" H 4900 7100 50  0001 C CNN
F 3 "" H 4900 7100 50  0001 C CNN
	1    4900 7100
	0    1    1    0   
$EndComp
Wire Wire Line
	4900 7100 5050 7100
Wire Wire Line
	4700 7250 4700 7550
Wire Wire Line
	4700 7550 5050 7550
Wire Wire Line
	5400 7550 5400 7250
Wire Wire Line
	5050 7400 5050 7550
Wire Wire Line
	5050 7550 5400 7550
Connection ~ 5050 7550
Text GLabel 2200 6050 0    50   Input ~ 0
_RST
Text GLabel 2900 6050 2    50   Input ~ 0
RST
$Comp
L Device:D_Zener_ALT D11
U 1 1 5C292E44
P 2550 6050
F 0 "D11" V 2596 5971 50  0000 R CNN
F 1 "Zener" V 2505 5971 50  0000 R CNN
F 2 "Diode_SMD:D_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 2550 6050 50  0001 C CNN
F 3 "~" H 2550 6050 50  0001 C CNN
	1    2550 6050
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR019
U 1 1 5C292E4E
P 2400 5900
F 0 "#PWR019" H 2400 5650 50  0001 C CNN
F 1 "GND" V 2405 5772 50  0000 R CNN
F 2 "" H 2400 5900 50  0001 C CNN
F 3 "" H 2400 5900 50  0001 C CNN
	1    2400 5900
	0    1    1    0   
$EndComp
Wire Wire Line
	2400 5900 2550 5900
Wire Wire Line
	2200 6050 2200 6350
Wire Wire Line
	2200 6350 2550 6350
Wire Wire Line
	2900 6350 2900 6050
Wire Wire Line
	2550 6200 2550 6350
Wire Wire Line
	2550 6350 2900 6350
Connection ~ 2550 6350
Text GLabel 800  6000 0    50   Input ~ 0
_CH1
Text GLabel 1500 6000 2    50   Input ~ 0
CH1
$Comp
L Device:D_Zener_ALT D12
U 1 1 5C29E460
P 1150 6000
F 0 "D12" V 1196 5921 50  0000 R CNN
F 1 "Zener" V 1105 5921 50  0000 R CNN
F 2 "Diode_SMD:D_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 1150 6000 50  0001 C CNN
F 3 "~" H 1150 6000 50  0001 C CNN
	1    1150 6000
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0111
U 1 1 5C29E46A
P 1000 5850
F 0 "#PWR0111" H 1000 5600 50  0001 C CNN
F 1 "GND" V 1005 5722 50  0000 R CNN
F 2 "" H 1000 5850 50  0001 C CNN
F 3 "" H 1000 5850 50  0001 C CNN
	1    1000 5850
	0    1    1    0   
$EndComp
Wire Wire Line
	1000 5850 1150 5850
Wire Wire Line
	800  6000 800  6300
Wire Wire Line
	800  6300 1150 6300
Wire Wire Line
	1500 6300 1500 6000
Wire Wire Line
	1150 6150 1150 6300
Wire Wire Line
	1150 6300 1500 6300
Connection ~ 1150 6300
Text GLabel 2850 5150 0    50   Input ~ 0
_CH2
Text GLabel 3550 5150 2    50   Input ~ 0
CH2
$Comp
L Device:D_Zener_ALT D13
U 1 1 5C2AAB19
P 3200 5150
F 0 "D13" V 3246 5071 50  0000 R CNN
F 1 "Zener" V 3155 5071 50  0000 R CNN
F 2 "Diode_SMD:D_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 3200 5150 50  0001 C CNN
F 3 "~" H 3200 5150 50  0001 C CNN
	1    3200 5150
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0112
U 1 1 5C2AAB23
P 3050 5000
F 0 "#PWR0112" H 3050 4750 50  0001 C CNN
F 1 "GND" V 3055 4872 50  0000 R CNN
F 2 "" H 3050 5000 50  0001 C CNN
F 3 "" H 3050 5000 50  0001 C CNN
	1    3050 5000
	0    1    1    0   
$EndComp
Wire Wire Line
	3050 5000 3200 5000
Wire Wire Line
	2850 5150 2850 5450
Wire Wire Line
	2850 5450 3200 5450
Wire Wire Line
	3550 5450 3550 5150
Wire Wire Line
	3200 5300 3200 5450
Wire Wire Line
	3200 5450 3550 5450
Connection ~ 3200 5450
Text GLabel 8200 5850 0    50   Input ~ 0
_CH3
Text GLabel 8900 5850 2    50   Input ~ 0
CH3
$Comp
L Device:D_Zener_ALT D15
U 1 1 5C2BC10E
P 8550 5850
F 0 "D15" V 8596 5771 50  0000 R CNN
F 1 "Zener" V 8505 5771 50  0000 R CNN
F 2 "Diode_SMD:D_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 8550 5850 50  0001 C CNN
F 3 "~" H 8550 5850 50  0001 C CNN
	1    8550 5850
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0113
U 1 1 5C2BC118
P 8400 5700
F 0 "#PWR0113" H 8400 5450 50  0001 C CNN
F 1 "GND" V 8405 5572 50  0000 R CNN
F 2 "" H 8400 5700 50  0001 C CNN
F 3 "" H 8400 5700 50  0001 C CNN
	1    8400 5700
	0    1    1    0   
$EndComp
Wire Wire Line
	8400 5700 8550 5700
Wire Wire Line
	8200 5850 8200 6150
Wire Wire Line
	8200 6150 8550 6150
Wire Wire Line
	8900 6150 8900 5850
Wire Wire Line
	8550 6000 8550 6150
Wire Wire Line
	8550 6150 8900 6150
Connection ~ 8550 6150
Text GLabel 7600 4750 0    50   Input ~ 0
_CH4
Text GLabel 8300 4750 2    50   Input ~ 0
CH4
$Comp
L Device:D_Zener_ALT D14
U 1 1 5C2D0023
P 7950 4750
F 0 "D14" V 7996 4671 50  0000 R CNN
F 1 "Zener" V 7905 4671 50  0000 R CNN
F 2 "Diode_SMD:D_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 7950 4750 50  0001 C CNN
F 3 "~" H 7950 4750 50  0001 C CNN
	1    7950 4750
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0114
U 1 1 5C2D002D
P 7800 4600
F 0 "#PWR0114" H 7800 4350 50  0001 C CNN
F 1 "GND" V 7805 4472 50  0000 R CNN
F 2 "" H 7800 4600 50  0001 C CNN
F 3 "" H 7800 4600 50  0001 C CNN
	1    7800 4600
	0    1    1    0   
$EndComp
Wire Wire Line
	7800 4600 7950 4600
Wire Wire Line
	7600 4750 7600 5050
Wire Wire Line
	7600 5050 7950 5050
Wire Wire Line
	8300 5050 8300 4750
Wire Wire Line
	7950 4900 7950 5050
Wire Wire Line
	7950 5050 8300 5050
Connection ~ 7950 5050
$Comp
L Connector:Conn_01x02_Male DEV1
U 1 1 5C2DCD60
P 8950 850
F 0 "DEV1" H 9058 1031 50  0000 C CNN
F 1 "Conn_01x02_Male" H 9050 950 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x02_P2.54mm_Vertical" H 8950 850 50  0001 C CNN
F 3 "~" H 8950 850 50  0001 C CNN
	1    8950 850 
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR020
U 1 1 5C2DE95F
P 9400 1100
F 0 "#PWR020" H 9400 850 50  0001 C CNN
F 1 "GND" H 9405 927 50  0000 C CNN
F 2 "" H 9400 1100 50  0001 C CNN
F 3 "" H 9400 1100 50  0001 C CNN
	1    9400 1100
	1    0    0    -1  
$EndComp
Wire Wire Line
	9150 950  9400 950 
Wire Wire Line
	9400 950  9400 1100
$Comp
L power:+3.3V #PWR021
U 1 1 5C2E6637
P 9850 750
F 0 "#PWR021" H 9850 600 50  0001 C CNN
F 1 "+3.3V" H 9865 923 50  0000 C CNN
F 2 "" H 9850 750 50  0001 C CNN
F 3 "" H 9850 750 50  0001 C CNN
	1    9850 750 
	1    0    0    -1  
$EndComp
$Comp
L Device:R R7
U 1 1 5C2E8549
P 9850 1050
F 0 "R7" H 9780 1004 50  0000 R CNN
F 1 "10kOhm" H 9780 1095 50  0000 R CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 9780 1050 50  0001 C CNN
F 3 "~" H 9850 1050 50  0001 C CNN
	1    9850 1050
	-1   0    0    1   
$EndComp
Wire Wire Line
	9850 750  9850 900 
Wire Wire Line
	9850 1200 9750 1200
Wire Wire Line
	9600 1200 9600 850 
Wire Wire Line
	9600 850  9150 850 
Text GLabel 9750 1350 3    50   Input ~ 0
DEV_MODE1
Wire Wire Line
	9750 1350 9750 1200
Connection ~ 9750 1200
Wire Wire Line
	9750 1200 9600 1200
$Comp
L Connector:Conn_01x02_Male DEV2
U 1 1 5C30BBCD
P 10750 1200
F 0 "DEV2" H 10858 1381 50  0000 C CNN
F 1 "Conn_01x02_Male" H 10850 1300 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x02_P2.54mm_Vertical" H 10750 1200 50  0001 C CNN
F 3 "~" H 10750 1200 50  0001 C CNN
	1    10750 1200
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR022
U 1 1 5C30BBD7
P 11200 1450
F 0 "#PWR022" H 11200 1200 50  0001 C CNN
F 1 "GND" H 11205 1277 50  0000 C CNN
F 2 "" H 11200 1450 50  0001 C CNN
F 3 "" H 11200 1450 50  0001 C CNN
	1    11200 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	10950 1300 11200 1300
Wire Wire Line
	11200 1300 11200 1450
$Comp
L power:+3.3V #PWR023
U 1 1 5C30BBE3
P 11650 1100
F 0 "#PWR023" H 11650 950 50  0001 C CNN
F 1 "+3.3V" H 11665 1273 50  0000 C CNN
F 2 "" H 11650 1100 50  0001 C CNN
F 3 "" H 11650 1100 50  0001 C CNN
	1    11650 1100
	1    0    0    -1  
$EndComp
$Comp
L Device:R R8
U 1 1 5C30BBED
P 11650 1400
F 0 "R8" H 11580 1354 50  0000 R CNN
F 1 "10kOhm" H 11580 1445 50  0000 R CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 11580 1400 50  0001 C CNN
F 3 "~" H 11650 1400 50  0001 C CNN
	1    11650 1400
	-1   0    0    1   
$EndComp
Wire Wire Line
	11650 1100 11650 1250
Wire Wire Line
	11650 1550 11550 1550
Wire Wire Line
	11400 1550 11400 1200
Wire Wire Line
	11400 1200 10950 1200
Text GLabel 11550 1700 3    50   Input ~ 0
DEV_MODE2
Wire Wire Line
	11550 1700 11550 1550
Connection ~ 11550 1550
Wire Wire Line
	11550 1550 11400 1550
$Comp
L Device:R R9
U 1 1 5C32CDDC
P 13550 1800
F 0 "R9" V 13400 1800 50  0000 C CNN
F 1 "18 Ohm" V 13450 1800 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 13480 1800 50  0001 C CNN
F 3 "~" H 13550 1800 50  0001 C CNN
	1    13550 1800
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR024
U 1 1 5C3AEC79
P 13750 2800
F 0 "#PWR024" H 13750 2550 50  0001 C CNN
F 1 "GND" H 13755 2627 50  0000 C CNN
F 2 "" H 13750 2800 50  0001 C CNN
F 3 "" H 13750 2800 50  0001 C CNN
	1    13750 2800
	1    0    0    -1  
$EndComp
$Comp
L Device:C C5
U 1 1 5C3B8983
P 13750 2200
F 0 "C5" H 13865 2246 50  0000 L CNN
F 1 "10uf" H 13865 2155 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 13788 2050 50  0001 C CNN
F 3 "~" H 13750 2200 50  0001 C CNN
	1    13750 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	13550 2050 13550 1950
Wire Wire Line
	13550 2050 13750 2050
Connection ~ 13550 2050
Wire Wire Line
	13750 2050 14250 2050
Connection ~ 13750 2050
$Comp
L Device:R R11
U 1 1 5C40BE5F
P 14250 2400
F 0 "R11" V 14100 2400 50  0000 C CNN
F 1 "10  kOhm" V 14150 2400 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 14180 2400 50  0001 C CNN
F 3 "~" H 14250 2400 50  0001 C CNN
	1    14250 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	14250 2250 14250 2050
Wire Wire Line
	13750 2350 13750 2700
Wire Wire Line
	14250 2550 14250 2700
Wire Wire Line
	14250 2700 13750 2700
Connection ~ 13750 2700
Wire Wire Line
	13750 2700 13750 2800
$Comp
L Device:R R10
U 1 1 5C42697E
P 14250 1600
F 0 "R10" V 14100 1600 50  0000 C CNN
F 1 "10  kOhm" V 14150 1600 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 14180 1600 50  0001 C CNN
F 3 "~" H 14250 1600 50  0001 C CNN
	1    14250 1600
	1    0    0    -1  
$EndComp
Wire Wire Line
	14250 1750 14250 2050
Connection ~ 14250 2050
$Comp
L power:+3.3V #PWR025
U 1 1 5C42F5C8
P 14500 1400
F 0 "#PWR025" H 14500 1250 50  0001 C CNN
F 1 "+3.3V" H 14515 1573 50  0000 C CNN
F 2 "" H 14500 1400 50  0001 C CNN
F 3 "" H 14500 1400 50  0001 C CNN
	1    14500 1400
	1    0    0    -1  
$EndComp
Wire Wire Line
	14250 1450 14500 1450
Wire Wire Line
	14500 1450 14500 1400
Wire Wire Line
	12950 1650 12950 1400
Wire Wire Line
	12950 1400 13550 1400
Wire Wire Line
	13550 1400 13550 1550
Wire Wire Line
	13650 1550 13550 1550
Connection ~ 13550 1550
Wire Wire Line
	13550 1550 13550 1650
Text GLabel 12850 3750 0    50   Input ~ 0
V_Trans_out2
Text GLabel 12850 4100 0    50   Input ~ 0
V_Trans_out1
$Comp
L Device:R R12
U 1 1 5C4B16D5
P 13250 3900
F 0 "R12" V 13100 3900 50  0000 C CNN
F 1 "2 kOhm" V 13150 3900 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 13180 3900 50  0001 C CNN
F 3 "~" H 13250 3900 50  0001 C CNN
	1    13250 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	12850 3750 13250 3750
Wire Wire Line
	12850 4100 13250 4100
Wire Wire Line
	13250 4100 13250 4050
$Comp
L Device:R R13
U 1 1 5C4C4E6C
P 13900 3400
F 0 "R13" V 13750 3400 50  0000 C CNN
F 1 "100  kOhm" V 13800 3400 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 13830 3400 50  0001 C CNN
F 3 "~" H 13900 3400 50  0001 C CNN
	1    13900 3400
	1    0    0    -1  
$EndComp
$Comp
L Device:R R14
U 1 1 5C4C5389
P 13900 4700
F 0 "R14" V 13750 4700 50  0000 C CNN
F 1 "10  kOhm" V 13800 4700 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 13830 4700 50  0001 C CNN
F 3 "~" H 13900 4700 50  0001 C CNN
	1    13900 4700
	1    0    0    -1  
$EndComp
Wire Wire Line
	13250 4100 13400 4100
Wire Wire Line
	13400 4100 13400 4950
Wire Wire Line
	13400 4950 13900 4950
Connection ~ 13250 4100
$Comp
L Device:C C6
U 1 1 5C4E27C2
P 13900 5400
F 0 "C6" H 14015 5446 50  0000 L CNN
F 1 "1uf" H 14015 5355 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 13938 5250 50  0001 C CNN
F 3 "~" H 13900 5400 50  0001 C CNN
	1    13900 5400
	1    0    0    -1  
$EndComp
Wire Wire Line
	13900 4950 13900 5150
$Comp
L power:GND #PWR026
U 1 1 5C4ECE4B
P 14150 5950
F 0 "#PWR026" H 14150 5700 50  0001 C CNN
F 1 "GND" H 14155 5777 50  0000 C CNN
F 2 "" H 14150 5950 50  0001 C CNN
F 3 "" H 14150 5950 50  0001 C CNN
	1    14150 5950
	1    0    0    -1  
$EndComp
Wire Wire Line
	13900 5550 13900 5750
Text GLabel 15450 4300 2    50   Input ~ 0
V_OUT
Wire Wire Line
	13900 5150 14450 5150
Connection ~ 13900 5150
Wire Wire Line
	13900 5150 13900 5250
$Comp
L Device:R R16
U 1 1 5C50CBC3
P 14450 5500
F 0 "R16" V 14300 5500 50  0000 C CNN
F 1 "470  kOhm" V 14350 5500 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 14380 5500 50  0001 C CNN
F 3 "~" H 14450 5500 50  0001 C CNN
	1    14450 5500
	1    0    0    -1  
$EndComp
Wire Wire Line
	14450 5150 14450 5350
Wire Wire Line
	13900 5750 14150 5750
Wire Wire Line
	14150 5750 14150 5950
Wire Wire Line
	14450 5650 14450 5750
Wire Wire Line
	14450 5750 14150 5750
Connection ~ 14150 5750
$Comp
L Device:R R15
U 1 1 5C52DF73
P 14450 4750
F 0 "R15" V 14300 4750 50  0000 C CNN
F 1 "470  kOhm" V 14350 4750 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 14380 4750 50  0001 C CNN
F 3 "~" H 14450 4750 50  0001 C CNN
	1    14450 4750
	1    0    0    -1  
$EndComp
Wire Wire Line
	14450 5150 14450 4900
Connection ~ 14450 5150
$Comp
L power:+3.3V #PWR027
U 1 1 5C539094
P 14800 4600
F 0 "#PWR027" H 14800 4450 50  0001 C CNN
F 1 "+3.3V" H 14815 4773 50  0000 C CNN
F 2 "" H 14800 4600 50  0001 C CNN
F 3 "" H 14800 4600 50  0001 C CNN
	1    14800 4600
	0    1    1    0   
$EndComp
Wire Wire Line
	14450 4600 14800 4600
$Comp
L Device:D_Schottky_Small_ALT D16
U 1 1 5C56348B
P 900 7100
F 0 "D16" H 900 6895 50  0000 C CNN
F 1 "Schottky" H 900 6986 50  0000 C CNN
F 2 "Diode_SMD:D_SMB" V 900 7100 50  0001 C CNN
F 3 "~" V 900 7100 50  0001 C CNN
	1    900  7100
	-1   0    0    1   
$EndComp
Wire Wire Line
	800  6750 800  7100
Wire Wire Line
	12600 1650 12950 1650
Wire Wire Line
	12600 2050 13550 2050
$Comp
L Device:R_POT_US RV1
U 1 1 5C1A98F1
P 14900 4000
F 0 "RV1" H 14832 4046 50  0000 R CNN
F 1 "47 kOhm" H 15300 4150 50  0000 R CNN
F 2 "Potentiometer_THT:Potentiometer_Bourns_3296W_Vertical" H 14900 4000 50  0001 C CNN
F 3 "~" H 14900 4000 50  0001 C CNN
	1    14900 4000
	1    0    0    -1  
$EndComp
$Comp
L Device:R R17
U 1 1 5C1AA4B3
P 15300 4000
F 0 "R17" V 15150 4000 50  0000 C CNN
F 1 "R0" V 15200 4000 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 15230 4000 50  0001 C CNN
F 3 "~" H 15300 4000 50  0001 C CNN
	1    15300 4000
	0    1    1    0   
$EndComp
$Comp
L Device:R R18
U 1 1 5C1AA72F
P 14950 4350
F 0 "R18" V 14800 4350 50  0000 C CNN
F 1 "R0" V 14850 4350 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 14880 4350 50  0001 C CNN
F 3 "~" H 14950 4350 50  0001 C CNN
	1    14950 4350
	0    1    1    0   
$EndComp
Wire Wire Line
	13250 3750 13250 3150
Wire Wire Line
	13250 3150 13900 3150
Wire Wire Line
	13900 3150 13900 3250
Connection ~ 13250 3750
$Comp
L Device:R R19
U 1 1 5C1FBC8A
P 13900 4050
F 0 "R19" V 13750 4050 50  0000 C CNN
F 1 "R0" V 13800 4050 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 13830 4050 50  0001 C CNN
F 3 "~" H 13900 4050 50  0001 C CNN
	1    13900 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	13900 4950 13900 4850
Connection ~ 13900 4950
Wire Wire Line
	14400 3850 14400 3550
Wire Wire Line
	14400 3550 13900 3550
Connection ~ 13900 3550
Wire Wire Line
	13900 3550 13900 3900
Wire Wire Line
	13900 4200 13900 4300
Wire Wire Line
	13900 4300 14400 4300
Wire Wire Line
	14400 4300 14400 4150
Connection ~ 13900 4300
Wire Wire Line
	14400 3850 14900 3850
Wire Wire Line
	14400 4150 14900 4150
Wire Wire Line
	15450 4300 15100 4300
Wire Wire Line
	15100 4300 15100 4350
Wire Wire Line
	15150 4000 15050 4000
Wire Wire Line
	15450 4000 15450 4300
Wire Wire Line
	13900 4300 13900 4550
Wire Wire Line
	14800 4350 14400 4350
Wire Wire Line
	14400 4350 14400 4300
Connection ~ 14400 4300
Wire Wire Line
	1700 5450 1700 5300
Connection ~ 1700 5300
Wire Wire Line
	1700 5300 1750 5300
Wire Wire Line
	1750 5300 2100 5300
Wire Wire Line
	1000 7100 1000 7000
Wire Wire Line
	1000 7000 1150 7000
Wire Wire Line
	1700 7000 1700 7100
Wire Wire Line
	1500 7100 1500 7000
Connection ~ 1500 7000
Wire Wire Line
	1500 7000 1700 7000
Wire Wire Line
	1150 7100 1150 7000
Connection ~ 1150 7000
Wire Wire Line
	1150 7000 1500 7000
Wire Wire Line
	5200 4900 5200 4600
Wire Wire Line
	4900 4950 4900 4600
Wire Wire Line
	5800 4850 5800 4600
Wire Wire Line
	5950 4850 5950 4600
Wire Wire Line
	5950 3350 5950 2900
Wire Wire Line
	5200 3100 5200 3350
Wire Wire Line
	4750 3350 4750 2850
Text GLabel 4450 4750 3    50   Input ~ 0
E3
Text GLabel 4600 4750 3    50   Input ~ 0
E4
Text GLabel 5050 4850 3    50   Input ~ 0
E5
Wire Wire Line
	4600 4750 4600 4600
Wire Wire Line
	4450 4750 4450 4600
Text GLabel 5650 4800 3    50   Input ~ 0
E6
Wire Wire Line
	5650 4800 5650 4600
Text GLabel 4450 3200 1    50   Input ~ 0
E2
Text GLabel 4300 3200 1    50   Input ~ 0
E1
$Comp
L Connector:Conn_01x02_Female J2
U 1 1 5C245A4A
P 6900 8500
F 0 "J2" H 6927 8476 50  0000 L CNN
F 1 "Conn_01x02_Female" H 6927 8385 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x02_P2.54mm_Vertical" H 6900 8500 50  0001 C CNN
F 3 "~" H 6900 8500 50  0001 C CNN
	1    6900 8500
	1    0    0    -1  
$EndComp
Text GLabel 6550 8700 3    50   Input ~ 0
E2
Wire Wire Line
	6550 8700 6550 8600
Wire Wire Line
	6550 8600 6700 8600
Wire Wire Line
	6550 8600 6550 8500
Wire Wire Line
	6550 8500 6700 8500
Connection ~ 6550 8600
Wire Wire Line
	6950 7800 7100 7800
Wire Wire Line
	6950 7900 6950 7800
Wire Wire Line
	6950 7900 7100 7900
Connection ~ 6950 7900
Wire Wire Line
	6950 8000 6950 7900
Text GLabel 6950 8000 3    50   Input ~ 0
E1
$Comp
L Connector:Conn_01x02_Female J5
U 1 1 5C2DD5D1
P 7300 7800
F 0 "J5" H 7327 7776 50  0000 L CNN
F 1 "Conn_01x02_Female" H 7327 7685 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x02_P2.54mm_Vertical" H 7300 7800 50  0001 C CNN
F 3 "~" H 7300 7800 50  0001 C CNN
	1    7300 7800
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x02_Female J6
U 1 1 5C2FB78F
P 8650 8750
F 0 "J6" H 8677 8726 50  0000 L CNN
F 1 "Conn_01x02_Female" H 8677 8635 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x02_P2.54mm_Vertical" H 8650 8750 50  0001 C CNN
F 3 "~" H 8650 8750 50  0001 C CNN
	1    8650 8750
	1    0    0    -1  
$EndComp
Text GLabel 8300 8950 3    50   Input ~ 0
E3
Wire Wire Line
	8300 8950 8300 8850
Wire Wire Line
	8300 8850 8450 8850
Wire Wire Line
	8300 8850 8300 8750
Wire Wire Line
	8300 8750 8450 8750
Connection ~ 8300 8850
Wire Wire Line
	8700 8050 8850 8050
Wire Wire Line
	8700 8150 8700 8050
Wire Wire Line
	8700 8150 8850 8150
Connection ~ 8700 8150
Wire Wire Line
	8700 8250 8700 8150
Text GLabel 8700 8250 3    50   Input ~ 0
E4
$Comp
L Connector:Conn_01x02_Female J8
U 1 1 5C2FB7A1
P 9050 8050
F 0 "J8" H 9077 8026 50  0000 L CNN
F 1 "Conn_01x02_Female" H 9077 7935 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x02_P2.54mm_Vertical" H 9050 8050 50  0001 C CNN
F 3 "~" H 9050 8050 50  0001 C CNN
	1    9050 8050
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x02_Female J7
U 1 1 5C30BD32
P 8800 7100
F 0 "J7" H 8827 7076 50  0000 L CNN
F 1 "Conn_01x02_Female" H 8827 6985 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x02_P2.54mm_Vertical" H 8800 7100 50  0001 C CNN
F 3 "~" H 8800 7100 50  0001 C CNN
	1    8800 7100
	1    0    0    -1  
$EndComp
Text GLabel 8450 7300 3    50   Input ~ 0
E5
Wire Wire Line
	8450 7300 8450 7200
Wire Wire Line
	8450 7200 8600 7200
Wire Wire Line
	8450 7200 8450 7100
Wire Wire Line
	8450 7100 8600 7100
Connection ~ 8450 7200
Wire Wire Line
	8850 6400 9000 6400
Wire Wire Line
	8850 6500 8850 6400
Wire Wire Line
	8850 6500 9000 6500
Connection ~ 8850 6500
Wire Wire Line
	8850 6600 8850 6500
Text GLabel 8850 6600 3    50   Input ~ 0
E6
$Comp
L Connector:Conn_01x02_Female J9
U 1 1 5C30BD44
P 9200 6400
F 0 "J9" H 9227 6376 50  0000 L CNN
F 1 "Conn_01x02_Female" H 9227 6285 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x02_P2.54mm_Vertical" H 9200 6400 50  0001 C CNN
F 3 "~" H 9200 6400 50  0001 C CNN
	1    9200 6400
	1    0    0    -1  
$EndComp
Wire Wire Line
	5500 4900 5500 4600
Wire Wire Line
	5050 2900 5050 3350
Wire Wire Line
	4900 2900 4900 3350
Wire Wire Line
	5800 2600 5800 3350
Wire Wire Line
	5500 3000 5500 3350
Wire Wire Line
	4600 2650 4600 3350
Wire Wire Line
	4750 4600 4750 5000
Wire Wire Line
	4300 3200 4300 3350
Wire Wire Line
	4450 3200 4450 3350
Wire Wire Line
	5650 3150 5650 3350
Wire Wire Line
	5350 5250 5350 4600
Wire Wire Line
	5350 2900 5350 3350
Wire Wire Line
	5050 4600 5050 4850
$EndSCHEMATC
