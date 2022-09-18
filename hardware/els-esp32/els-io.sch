EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 2
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text GLabel 1850 1550 0    50   Output ~ 0
L_ENC_A
Text GLabel 1850 2500 0    50   Output ~ 0
L_ENC_B
$Comp
L Connector:Screw_Terminal_01x04 J?
U 1 1 632C145C
P 4350 1500
AR Path="/632C145C" Ref="J?"  Part="1" 
AR Path="/6328F653/632C145C" Ref="J2"  Part="1" 
F 0 "J2" H 4430 1492 50  0000 L CNN
F 1 "Rotary Encoder" H 4430 1401 50  0000 L CNN
F 2 "TerminalBlock_4Ucon:TerminalBlock_4Ucon_1x04_P3.50mm_Horizontal" H 4350 1500 50  0001 C CNN
F 3 "~" H 4350 1500 50  0001 C CNN
	1    4350 1500
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 632C1462
P 4150 1400
AR Path="/632C1462" Ref="#PWR?"  Part="1" 
AR Path="/6328F653/632C1462" Ref="#PWR0109"  Part="1" 
F 0 "#PWR0109" H 4150 1250 50  0001 C CNN
F 1 "+5V" H 4165 1573 50  0000 C CNN
F 2 "" H 4150 1400 50  0001 C CNN
F 3 "" H 4150 1400 50  0001 C CNN
	1    4150 1400
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 632C1468
P 4150 1700
AR Path="/632C1468" Ref="#PWR?"  Part="1" 
AR Path="/6328F653/632C1468" Ref="#PWR0112"  Part="1" 
F 0 "#PWR0112" H 4150 1450 50  0001 C CNN
F 1 "GND" H 4155 1527 50  0000 C CNN
F 2 "" H 4150 1700 50  0001 C CNN
F 3 "" H 4150 1700 50  0001 C CNN
	1    4150 1700
	1    0    0    -1  
$EndComp
Text GLabel 4150 1600 0    50   Output ~ 0
ROT_ENC_B
Text GLabel 4150 1500 0    50   Output ~ 0
ROT_ENC_A
$Comp
L Connector:Screw_Terminal_01x05 J?
U 1 1 632C1471
P 4250 4600
AR Path="/632C1471" Ref="J?"  Part="1" 
AR Path="/6328F653/632C1471" Ref="J3"  Part="1" 
F 0 "J3" H 4330 4642 50  0000 L CNN
F 1 "LED Display" H 4330 4551 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x05_P2.54mm_Vertical" H 4250 4600 50  0001 C CNN
F 3 "~" H 4250 4600 50  0001 C CNN
	1    4250 4600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 632C1477
P 3750 4700
AR Path="/632C1477" Ref="#PWR?"  Part="1" 
AR Path="/6328F653/632C1477" Ref="#PWR0113"  Part="1" 
F 0 "#PWR0113" H 3750 4450 50  0001 C CNN
F 1 "GND" H 3755 4527 50  0000 C CNN
F 2 "" H 3750 4700 50  0001 C CNN
F 3 "" H 3750 4700 50  0001 C CNN
	1    3750 4700
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 632C147D
P 4200 5100
AR Path="/632C147D" Ref="#PWR?"  Part="1" 
AR Path="/6328F653/632C147D" Ref="#PWR0114"  Part="1" 
F 0 "#PWR0114" H 4200 4950 50  0001 C CNN
F 1 "+5V" H 4215 5273 50  0000 C CNN
F 2 "" H 4200 5100 50  0001 C CNN
F 3 "" H 4200 5100 50  0001 C CNN
	1    4200 5100
	1    0    0    -1  
$EndComp
Text GLabel 4050 4400 0    50   BiDi ~ 0
DIO
Text GLabel 4050 4500 0    50   Input ~ 0
CLK
Text GLabel 4050 4600 0    50   Input ~ 0
STB
Wire Wire Line
	3750 4700 4050 4700
$Comp
L Device:R_Small R?
U 1 1 632C1495
P 1950 3900
AR Path="/632C1495" Ref="R?"  Part="1" 
AR Path="/6328F653/632C1495" Ref="R7"  Part="1" 
F 0 "R7" H 2009 3946 50  0000 L CNN
F 1 "10k" H 2009 3855 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 1950 3900 50  0001 C CNN
F 3 "~" H 1950 3900 50  0001 C CNN
F 4 "C25804" H 1950 3900 50  0001 C CNN "LCSC"
	1    1950 3900
	1    0    0    -1  
$EndComp
Text GLabel 2550 4050 2    50   BiDi ~ 0
DIO
Wire Wire Line
	1950 4000 1950 4050
Wire Wire Line
	1950 4050 2050 4050
Text GLabel 1850 4050 0    50   BiDi ~ 0
L_DISP_MOSI
Wire Wire Line
	1850 4050 1950 4050
Connection ~ 1950 4050
$Comp
L power:+3.3V #PWR?
U 1 1 632C14A9
P 1950 3650
AR Path="/632C14A9" Ref="#PWR?"  Part="1" 
AR Path="/6328F653/632C14A9" Ref="#PWR0116"  Part="1" 
F 0 "#PWR0116" H 1950 3500 50  0001 C CNN
F 1 "+3.3V" H 1965 3823 50  0000 C CNN
F 2 "" H 1950 3650 50  0001 C CNN
F 3 "" H 1950 3650 50  0001 C CNN
	1    1950 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	1950 3650 1950 3700
Wire Wire Line
	2250 3750 2250 3700
Wire Wire Line
	2250 3700 1950 3700
Connection ~ 1950 3700
Wire Wire Line
	1950 3700 1950 3800
Wire Wire Line
	2450 4050 2550 4050
Text GLabel 2550 5000 2    50   Output ~ 0
CLK
Text GLabel 2550 5950 2    50   Output ~ 0
STB
Text GLabel 7450 4550 0    50   Output ~ 0
L_DRV_ALARM
Text GLabel 8150 1550 2    50   Output ~ 0
STEP
Text GLabel 8150 2550 2    50   Output ~ 0
DIR
Text GLabel 8150 3550 2    50   Output ~ 0
ENABLE
$Comp
L power:GND #PWR?
U 1 1 63307977
P 9200 1500
AR Path="/63307977" Ref="#PWR?"  Part="1" 
AR Path="/6328F653/63307977" Ref="#PWR0127"  Part="1" 
F 0 "#PWR0127" H 9200 1250 50  0001 C CNN
F 1 "GND" H 9205 1327 50  0000 C CNN
F 2 "" H 9200 1500 50  0001 C CNN
F 3 "" H 9200 1500 50  0001 C CNN
	1    9200 1500
	1    0    0    -1  
$EndComp
Text GLabel 9700 1900 0    50   Input ~ 0
STEP
Text GLabel 9700 1800 0    50   Input ~ 0
DIR
Text GLabel 9700 1700 0    50   Input ~ 0
ENABLE
$Comp
L Connector:Screw_Terminal_01x06 J?
U 1 1 6330A3A3
P 9900 1700
AR Path="/6330A3A3" Ref="J?"  Part="1" 
AR Path="/6328F653/6330A3A3" Ref="J4"  Part="1" 
F 0 "J4" H 9980 1692 50  0000 L CNN
F 1 "Stepper Driver/Servo" H 9980 1601 50  0000 L CNN
F 2 "TerminalBlock_4Ucon:TerminalBlock_4Ucon_1x06_P3.50mm_Horizontal" H 9900 1700 50  0001 C CNN
F 3 "~" H 9900 1700 50  0001 C CNN
	1    9900 1700
	1    0    0    -1  
$EndComp
Text GLabel 9700 1600 0    50   Output ~ 0
ALARM
Text GLabel 8150 4550 2    50   Input ~ 0
ALARM
Text GLabel 2550 2500 2    50   Input ~ 0
ROT_ENC_B
Text GLabel 2550 1550 2    50   Input ~ 0
ROT_ENC_A
Wire Wire Line
	9200 1500 9700 1500
$Comp
L power:+5V #PWR?
U 1 1 635FF197
P 9200 2000
AR Path="/635FF197" Ref="#PWR?"  Part="1" 
AR Path="/6328F653/635FF197" Ref="#PWR0121"  Part="1" 
F 0 "#PWR0121" H 9200 1850 50  0001 C CNN
F 1 "+5V" H 9215 2173 50  0000 C CNN
F 2 "" H 9200 2000 50  0001 C CNN
F 3 "" H 9200 2000 50  0001 C CNN
	1    9200 2000
	1    0    0    -1  
$EndComp
Wire Wire Line
	9200 2000 9700 2000
Text GLabel 1850 5000 0    50   Input ~ 0
L_DISP_CLK
Text GLabel 1850 5950 0    50   Input ~ 0
L_DISP_CS
Text GLabel 7450 3550 0    50   Input ~ 0
L_DRV_EN
Text GLabel 7450 2550 0    50   Input ~ 0
L_DRV_DIR
Text GLabel 7450 1550 0    50   Input ~ 0
L_DRV_STEP
Connection ~ 2450 4050
$Comp
L Device:R_Small R?
U 1 1 632C1489
P 2450 3750
AR Path="/632C1489" Ref="R?"  Part="1" 
AR Path="/6328F653/632C1489" Ref="R8"  Part="1" 
F 0 "R8" H 2509 3796 50  0000 L CNN
F 1 "10k" H 2509 3705 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 2450 3750 50  0001 C CNN
F 3 "~" H 2450 3750 50  0001 C CNN
F 4 "C25804" H 2450 3750 50  0001 C CNN "LCSC"
	1    2450 3750
	1    0    0    -1  
$EndComp
$Comp
L Transistor_FET:2N7002 Q?
U 1 1 632C148F
P 2250 3950
AR Path="/632C148F" Ref="Q?"  Part="1" 
AR Path="/6328F653/632C148F" Ref="Q1"  Part="1" 
F 0 "Q1" V 2499 3950 50  0000 C CNN
F 1 "2N7002" V 2590 3950 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 2450 3875 50  0001 L CIN
F 3 "https://www.onsemi.com/pub/Collateral/NDS7002A-D.PDF" H 2250 3950 50  0001 L CNN
F 4 "C8545" V 2250 3950 50  0001 C CNN "LCSC"
	1    2250 3950
	0    1    1    0   
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 632C149B
P 2450 3650
AR Path="/632C149B" Ref="#PWR?"  Part="1" 
AR Path="/6328F653/632C149B" Ref="#PWR0115"  Part="1" 
F 0 "#PWR0115" H 2450 3500 50  0001 C CNN
F 1 "+5V" H 2465 3823 50  0000 C CNN
F 2 "" H 2450 3650 50  0001 C CNN
F 3 "" H 2450 3650 50  0001 C CNN
	1    2450 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	2450 3850 2450 4050
$Comp
L Device:R_Small R?
U 1 1 636A412C
P 1950 1400
AR Path="/636A412C" Ref="R?"  Part="1" 
AR Path="/6328F653/636A412C" Ref="R1"  Part="1" 
F 0 "R1" H 2009 1446 50  0000 L CNN
F 1 "10k" H 2009 1355 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 1950 1400 50  0001 C CNN
F 3 "~" H 1950 1400 50  0001 C CNN
F 4 "C25804" H 1950 1400 50  0001 C CNN "LCSC"
	1    1950 1400
	1    0    0    -1  
$EndComp
Wire Wire Line
	1950 1500 1950 1550
Wire Wire Line
	1950 1550 2050 1550
Wire Wire Line
	1850 1550 1950 1550
Connection ~ 1950 1550
$Comp
L power:+3.3V #PWR?
U 1 1 636A4138
P 1950 1150
AR Path="/636A4138" Ref="#PWR?"  Part="1" 
AR Path="/6328F653/636A4138" Ref="#PWR0105"  Part="1" 
F 0 "#PWR0105" H 1950 1000 50  0001 C CNN
F 1 "+3.3V" H 1965 1323 50  0000 C CNN
F 2 "" H 1950 1150 50  0001 C CNN
F 3 "" H 1950 1150 50  0001 C CNN
	1    1950 1150
	1    0    0    -1  
$EndComp
Wire Wire Line
	1950 1150 1950 1200
Wire Wire Line
	2250 1250 2250 1200
Wire Wire Line
	2250 1200 1950 1200
Connection ~ 1950 1200
Wire Wire Line
	1950 1200 1950 1300
Wire Wire Line
	2450 1550 2550 1550
Connection ~ 2450 1550
$Comp
L Device:R_Small R?
U 1 1 636A4145
P 2450 1250
AR Path="/636A4145" Ref="R?"  Part="1" 
AR Path="/6328F653/636A4145" Ref="R5"  Part="1" 
F 0 "R5" H 2509 1296 50  0000 L CNN
F 1 "10k" H 2509 1205 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 2450 1250 50  0001 C CNN
F 3 "~" H 2450 1250 50  0001 C CNN
F 4 "C25804" H 2450 1250 50  0001 C CNN "LCSC"
	1    2450 1250
	1    0    0    -1  
$EndComp
$Comp
L Transistor_FET:2N7002 Q?
U 1 1 636A414B
P 2250 1450
AR Path="/636A414B" Ref="Q?"  Part="1" 
AR Path="/6328F653/636A414B" Ref="Q2"  Part="1" 
F 0 "Q2" V 2499 1450 50  0000 C CNN
F 1 "2N7002" V 2590 1450 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 2450 1375 50  0001 L CIN
F 3 "https://www.onsemi.com/pub/Collateral/NDS7002A-D.PDF" H 2250 1450 50  0001 L CNN
F 4 "C8545" V 2250 1450 50  0001 C CNN "LCSC"
	1    2250 1450
	0    1    1    0   
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 636A4151
P 2450 1150
AR Path="/636A4151" Ref="#PWR?"  Part="1" 
AR Path="/6328F653/636A4151" Ref="#PWR0106"  Part="1" 
F 0 "#PWR0106" H 2450 1000 50  0001 C CNN
F 1 "+5V" H 2465 1323 50  0000 C CNN
F 2 "" H 2450 1150 50  0001 C CNN
F 3 "" H 2450 1150 50  0001 C CNN
	1    2450 1150
	1    0    0    -1  
$EndComp
Wire Wire Line
	2450 1350 2450 1550
$Comp
L Device:R_Small R?
U 1 1 636C8041
P 1950 2350
AR Path="/636C8041" Ref="R?"  Part="1" 
AR Path="/6328F653/636C8041" Ref="R2"  Part="1" 
F 0 "R2" H 2009 2396 50  0000 L CNN
F 1 "10k" H 2009 2305 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 1950 2350 50  0001 C CNN
F 3 "~" H 1950 2350 50  0001 C CNN
F 4 "C25804" H 1950 2350 50  0001 C CNN "LCSC"
	1    1950 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	1950 2450 1950 2500
Wire Wire Line
	1950 2500 2050 2500
Wire Wire Line
	1850 2500 1950 2500
Connection ~ 1950 2500
$Comp
L power:+3.3V #PWR?
U 1 1 636C804D
P 1950 2100
AR Path="/636C804D" Ref="#PWR?"  Part="1" 
AR Path="/6328F653/636C804D" Ref="#PWR0107"  Part="1" 
F 0 "#PWR0107" H 1950 1950 50  0001 C CNN
F 1 "+3.3V" H 1965 2273 50  0000 C CNN
F 2 "" H 1950 2100 50  0001 C CNN
F 3 "" H 1950 2100 50  0001 C CNN
	1    1950 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	1950 2100 1950 2150
Wire Wire Line
	2250 2200 2250 2150
Wire Wire Line
	2250 2150 1950 2150
Connection ~ 1950 2150
Wire Wire Line
	1950 2150 1950 2250
Wire Wire Line
	2450 2500 2550 2500
$Comp
L Device:R_Small R?
U 1 1 636C805A
P 2450 2200
AR Path="/636C805A" Ref="R?"  Part="1" 
AR Path="/6328F653/636C805A" Ref="R6"  Part="1" 
F 0 "R6" H 2509 2246 50  0000 L CNN
F 1 "10k" H 2509 2155 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 2450 2200 50  0001 C CNN
F 3 "~" H 2450 2200 50  0001 C CNN
F 4 "C25804" H 2450 2200 50  0001 C CNN "LCSC"
	1    2450 2200
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 636C8066
P 2450 2100
AR Path="/636C8066" Ref="#PWR?"  Part="1" 
AR Path="/6328F653/636C8066" Ref="#PWR0108"  Part="1" 
F 0 "#PWR0108" H 2450 1950 50  0001 C CNN
F 1 "+5V" H 2465 2273 50  0000 C CNN
F 2 "" H 2450 2100 50  0001 C CNN
F 3 "" H 2450 2100 50  0001 C CNN
	1    2450 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	2450 2300 2450 2500
$Comp
L Device:R_Small R?
U 1 1 6372194F
P 1950 4850
AR Path="/6372194F" Ref="R?"  Part="1" 
AR Path="/6328F653/6372194F" Ref="R3"  Part="1" 
F 0 "R3" H 2009 4896 50  0000 L CNN
F 1 "10k" H 2009 4805 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 1950 4850 50  0001 C CNN
F 3 "~" H 1950 4850 50  0001 C CNN
F 4 "C25804" H 1950 4850 50  0001 C CNN "LCSC"
	1    1950 4850
	1    0    0    -1  
$EndComp
Wire Wire Line
	1950 4950 1950 5000
Wire Wire Line
	1950 5000 2050 5000
Wire Wire Line
	1850 5000 1950 5000
Connection ~ 1950 5000
$Comp
L power:+3.3V #PWR?
U 1 1 6372195B
P 1950 4600
AR Path="/6372195B" Ref="#PWR?"  Part="1" 
AR Path="/6328F653/6372195B" Ref="#PWR0117"  Part="1" 
F 0 "#PWR0117" H 1950 4450 50  0001 C CNN
F 1 "+3.3V" H 1965 4773 50  0000 C CNN
F 2 "" H 1950 4600 50  0001 C CNN
F 3 "" H 1950 4600 50  0001 C CNN
	1    1950 4600
	1    0    0    -1  
$EndComp
Wire Wire Line
	1950 4600 1950 4650
Wire Wire Line
	2250 4700 2250 4650
Wire Wire Line
	2250 4650 1950 4650
Connection ~ 1950 4650
Wire Wire Line
	1950 4650 1950 4750
Wire Wire Line
	2450 5000 2550 5000
Connection ~ 2450 5000
$Comp
L Device:R_Small R?
U 1 1 63721968
P 2450 4700
AR Path="/63721968" Ref="R?"  Part="1" 
AR Path="/6328F653/63721968" Ref="R9"  Part="1" 
F 0 "R9" H 2509 4746 50  0000 L CNN
F 1 "10k" H 2509 4655 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 2450 4700 50  0001 C CNN
F 3 "~" H 2450 4700 50  0001 C CNN
F 4 "C25804" H 2450 4700 50  0001 C CNN "LCSC"
	1    2450 4700
	1    0    0    -1  
$EndComp
$Comp
L Transistor_FET:2N7002 Q?
U 1 1 6372196E
P 2250 4900
AR Path="/6372196E" Ref="Q?"  Part="1" 
AR Path="/6328F653/6372196E" Ref="Q4"  Part="1" 
F 0 "Q4" V 2499 4900 50  0000 C CNN
F 1 "2N7002" V 2590 4900 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 2450 4825 50  0001 L CIN
F 3 "https://www.onsemi.com/pub/Collateral/NDS7002A-D.PDF" H 2250 4900 50  0001 L CNN
F 4 "C8545" V 2250 4900 50  0001 C CNN "LCSC"
	1    2250 4900
	0    1    1    0   
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 63721974
P 2450 4600
AR Path="/63721974" Ref="#PWR?"  Part="1" 
AR Path="/6328F653/63721974" Ref="#PWR0118"  Part="1" 
F 0 "#PWR0118" H 2450 4450 50  0001 C CNN
F 1 "+5V" H 2465 4773 50  0000 C CNN
F 2 "" H 2450 4600 50  0001 C CNN
F 3 "" H 2450 4600 50  0001 C CNN
	1    2450 4600
	1    0    0    -1  
$EndComp
Wire Wire Line
	2450 4800 2450 5000
$Comp
L Device:R_Small R?
U 1 1 63726D6F
P 1950 5800
AR Path="/63726D6F" Ref="R?"  Part="1" 
AR Path="/6328F653/63726D6F" Ref="R4"  Part="1" 
F 0 "R4" H 2009 5846 50  0000 L CNN
F 1 "10k" H 2009 5755 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 1950 5800 50  0001 C CNN
F 3 "~" H 1950 5800 50  0001 C CNN
F 4 "C25804" H 1950 5800 50  0001 C CNN "LCSC"
	1    1950 5800
	1    0    0    -1  
$EndComp
Wire Wire Line
	1950 5900 1950 5950
Wire Wire Line
	1950 5950 2050 5950
Wire Wire Line
	1850 5950 1950 5950
Connection ~ 1950 5950
$Comp
L power:+3.3V #PWR?
U 1 1 63726D7B
P 1950 5550
AR Path="/63726D7B" Ref="#PWR?"  Part="1" 
AR Path="/6328F653/63726D7B" Ref="#PWR0119"  Part="1" 
F 0 "#PWR0119" H 1950 5400 50  0001 C CNN
F 1 "+3.3V" H 1965 5723 50  0000 C CNN
F 2 "" H 1950 5550 50  0001 C CNN
F 3 "" H 1950 5550 50  0001 C CNN
	1    1950 5550
	1    0    0    -1  
$EndComp
Wire Wire Line
	1950 5550 1950 5600
Wire Wire Line
	2250 5650 2250 5600
Wire Wire Line
	2250 5600 1950 5600
Connection ~ 1950 5600
Wire Wire Line
	1950 5600 1950 5700
Wire Wire Line
	2450 5950 2550 5950
Connection ~ 2450 5950
$Comp
L Device:R_Small R?
U 1 1 63726D88
P 2450 5650
AR Path="/63726D88" Ref="R?"  Part="1" 
AR Path="/6328F653/63726D88" Ref="R10"  Part="1" 
F 0 "R10" H 2509 5696 50  0000 L CNN
F 1 "10k" H 2509 5605 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 2450 5650 50  0001 C CNN
F 3 "~" H 2450 5650 50  0001 C CNN
F 4 "C25804" H 2450 5650 50  0001 C CNN "LCSC"
	1    2450 5650
	1    0    0    -1  
$EndComp
$Comp
L Transistor_FET:2N7002 Q?
U 1 1 63726D8E
P 2250 5850
AR Path="/63726D8E" Ref="Q?"  Part="1" 
AR Path="/6328F653/63726D8E" Ref="Q5"  Part="1" 
F 0 "Q5" V 2499 5850 50  0000 C CNN
F 1 "2N7002" V 2590 5850 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 2450 5775 50  0001 L CIN
F 3 "https://www.onsemi.com/pub/Collateral/NDS7002A-D.PDF" H 2250 5850 50  0001 L CNN
F 4 "C8545" V 2250 5850 50  0001 C CNN "LCSC"
	1    2250 5850
	0    1    1    0   
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 63726D94
P 2450 5550
AR Path="/63726D94" Ref="#PWR?"  Part="1" 
AR Path="/6328F653/63726D94" Ref="#PWR0120"  Part="1" 
F 0 "#PWR0120" H 2450 5400 50  0001 C CNN
F 1 "+5V" H 2465 5723 50  0000 C CNN
F 2 "" H 2450 5550 50  0001 C CNN
F 3 "" H 2450 5550 50  0001 C CNN
	1    2450 5550
	1    0    0    -1  
$EndComp
Wire Wire Line
	2450 5750 2450 5950
$Comp
L Device:R_Small R?
U 1 1 637BCF58
P 7550 1400
AR Path="/637BCF58" Ref="R?"  Part="1" 
AR Path="/6328F653/637BCF58" Ref="R11"  Part="1" 
F 0 "R11" H 7609 1446 50  0000 L CNN
F 1 "10k" H 7609 1355 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 7550 1400 50  0001 C CNN
F 3 "~" H 7550 1400 50  0001 C CNN
F 4 "C25804" H 7550 1400 50  0001 C CNN "LCSC"
	1    7550 1400
	1    0    0    -1  
$EndComp
Wire Wire Line
	7550 1500 7550 1550
Wire Wire Line
	7550 1550 7650 1550
Wire Wire Line
	7450 1550 7550 1550
Connection ~ 7550 1550
$Comp
L power:+3.3V #PWR?
U 1 1 637BCF64
P 7550 1150
AR Path="/637BCF64" Ref="#PWR?"  Part="1" 
AR Path="/6328F653/637BCF64" Ref="#PWR0122"  Part="1" 
F 0 "#PWR0122" H 7550 1000 50  0001 C CNN
F 1 "+3.3V" H 7565 1323 50  0000 C CNN
F 2 "" H 7550 1150 50  0001 C CNN
F 3 "" H 7550 1150 50  0001 C CNN
	1    7550 1150
	1    0    0    -1  
$EndComp
Wire Wire Line
	7550 1150 7550 1200
Wire Wire Line
	7850 1250 7850 1200
Wire Wire Line
	7850 1200 7550 1200
Connection ~ 7550 1200
Wire Wire Line
	7550 1200 7550 1300
Wire Wire Line
	8050 1550 8150 1550
Connection ~ 8050 1550
$Comp
L Device:R_Small R?
U 1 1 637BCF71
P 8050 1250
AR Path="/637BCF71" Ref="R?"  Part="1" 
AR Path="/6328F653/637BCF71" Ref="R15"  Part="1" 
F 0 "R15" H 8109 1296 50  0000 L CNN
F 1 "10k" H 8109 1205 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 8050 1250 50  0001 C CNN
F 3 "~" H 8050 1250 50  0001 C CNN
F 4 "C25804" H 8050 1250 50  0001 C CNN "LCSC"
	1    8050 1250
	1    0    0    -1  
$EndComp
$Comp
L Transistor_FET:2N7002 Q?
U 1 1 637BCF77
P 7850 1450
AR Path="/637BCF77" Ref="Q?"  Part="1" 
AR Path="/6328F653/637BCF77" Ref="Q6"  Part="1" 
F 0 "Q6" V 8099 1450 50  0000 C CNN
F 1 "2N7002" V 8190 1450 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 8050 1375 50  0001 L CIN
F 3 "https://www.onsemi.com/pub/Collateral/NDS7002A-D.PDF" H 7850 1450 50  0001 L CNN
F 4 "C8545" V 7850 1450 50  0001 C CNN "LCSC"
	1    7850 1450
	0    1    1    0   
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 637BCF7D
P 8050 1150
AR Path="/637BCF7D" Ref="#PWR?"  Part="1" 
AR Path="/6328F653/637BCF7D" Ref="#PWR0123"  Part="1" 
F 0 "#PWR0123" H 8050 1000 50  0001 C CNN
F 1 "+5V" H 8065 1323 50  0000 C CNN
F 2 "" H 8050 1150 50  0001 C CNN
F 3 "" H 8050 1150 50  0001 C CNN
	1    8050 1150
	1    0    0    -1  
$EndComp
Wire Wire Line
	8050 1350 8050 1550
$Comp
L Device:R_Small R?
U 1 1 637C6092
P 7550 2400
AR Path="/637C6092" Ref="R?"  Part="1" 
AR Path="/6328F653/637C6092" Ref="R12"  Part="1" 
F 0 "R12" H 7609 2446 50  0000 L CNN
F 1 "10k" H 7609 2355 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 7550 2400 50  0001 C CNN
F 3 "~" H 7550 2400 50  0001 C CNN
F 4 "C25804" H 7550 2400 50  0001 C CNN "LCSC"
	1    7550 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	7550 2500 7550 2550
Wire Wire Line
	7550 2550 7650 2550
Wire Wire Line
	7450 2550 7550 2550
Connection ~ 7550 2550
$Comp
L power:+3.3V #PWR?
U 1 1 637C609C
P 7550 2150
AR Path="/637C609C" Ref="#PWR?"  Part="1" 
AR Path="/6328F653/637C609C" Ref="#PWR0124"  Part="1" 
F 0 "#PWR0124" H 7550 2000 50  0001 C CNN
F 1 "+3.3V" H 7565 2323 50  0000 C CNN
F 2 "" H 7550 2150 50  0001 C CNN
F 3 "" H 7550 2150 50  0001 C CNN
	1    7550 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	7550 2150 7550 2200
Wire Wire Line
	7850 2250 7850 2200
Wire Wire Line
	7850 2200 7550 2200
Connection ~ 7550 2200
Wire Wire Line
	7550 2200 7550 2300
Wire Wire Line
	8050 2550 8150 2550
Connection ~ 8050 2550
$Comp
L Device:R_Small R?
U 1 1 637C60A9
P 8050 2250
AR Path="/637C60A9" Ref="R?"  Part="1" 
AR Path="/6328F653/637C60A9" Ref="R16"  Part="1" 
F 0 "R16" H 8109 2296 50  0000 L CNN
F 1 "10k" H 8109 2205 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 8050 2250 50  0001 C CNN
F 3 "~" H 8050 2250 50  0001 C CNN
F 4 "C25804" H 8050 2250 50  0001 C CNN "LCSC"
	1    8050 2250
	1    0    0    -1  
$EndComp
$Comp
L Transistor_FET:2N7002 Q?
U 1 1 637C60AF
P 7850 2450
AR Path="/637C60AF" Ref="Q?"  Part="1" 
AR Path="/6328F653/637C60AF" Ref="Q9"  Part="1" 
F 0 "Q9" V 8099 2450 50  0000 C CNN
F 1 "2N7002" V 8190 2450 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 8050 2375 50  0001 L CIN
F 3 "https://www.onsemi.com/pub/Collateral/NDS7002A-D.PDF" H 7850 2450 50  0001 L CNN
F 4 "C8545" V 7850 2450 50  0001 C CNN "LCSC"
	1    7850 2450
	0    1    1    0   
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 637C60B5
P 8050 2150
AR Path="/637C60B5" Ref="#PWR?"  Part="1" 
AR Path="/6328F653/637C60B5" Ref="#PWR0125"  Part="1" 
F 0 "#PWR0125" H 8050 2000 50  0001 C CNN
F 1 "+5V" H 8065 2323 50  0000 C CNN
F 2 "" H 8050 2150 50  0001 C CNN
F 3 "" H 8050 2150 50  0001 C CNN
	1    8050 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	8050 2350 8050 2550
$Comp
L Device:R_Small R?
U 1 1 637C9CB3
P 7550 3400
AR Path="/637C9CB3" Ref="R?"  Part="1" 
AR Path="/6328F653/637C9CB3" Ref="R13"  Part="1" 
F 0 "R13" H 7609 3446 50  0000 L CNN
F 1 "10k" H 7609 3355 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 7550 3400 50  0001 C CNN
F 3 "~" H 7550 3400 50  0001 C CNN
F 4 "C25804" H 7550 3400 50  0001 C CNN "LCSC"
	1    7550 3400
	1    0    0    -1  
$EndComp
Wire Wire Line
	7550 3500 7550 3550
Wire Wire Line
	7550 3550 7650 3550
Wire Wire Line
	7450 3550 7550 3550
Connection ~ 7550 3550
$Comp
L power:+3.3V #PWR?
U 1 1 637C9CBD
P 7550 3150
AR Path="/637C9CBD" Ref="#PWR?"  Part="1" 
AR Path="/6328F653/637C9CBD" Ref="#PWR0126"  Part="1" 
F 0 "#PWR0126" H 7550 3000 50  0001 C CNN
F 1 "+3.3V" H 7565 3323 50  0000 C CNN
F 2 "" H 7550 3150 50  0001 C CNN
F 3 "" H 7550 3150 50  0001 C CNN
	1    7550 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	7550 3150 7550 3200
Wire Wire Line
	7850 3250 7850 3200
Wire Wire Line
	7850 3200 7550 3200
Connection ~ 7550 3200
Wire Wire Line
	7550 3200 7550 3300
Wire Wire Line
	8050 3550 8150 3550
Connection ~ 8050 3550
$Comp
L Device:R_Small R?
U 1 1 637C9CCA
P 8050 3250
AR Path="/637C9CCA" Ref="R?"  Part="1" 
AR Path="/6328F653/637C9CCA" Ref="R22"  Part="1" 
F 0 "R22" H 8109 3296 50  0000 L CNN
F 1 "10k" H 8109 3205 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 8050 3250 50  0001 C CNN
F 3 "~" H 8050 3250 50  0001 C CNN
F 4 "C25804" H 8050 3250 50  0001 C CNN "LCSC"
	1    8050 3250
	1    0    0    -1  
$EndComp
$Comp
L Transistor_FET:2N7002 Q?
U 1 1 637C9CD0
P 7850 3450
AR Path="/637C9CD0" Ref="Q?"  Part="1" 
AR Path="/6328F653/637C9CD0" Ref="Q10"  Part="1" 
F 0 "Q10" V 8099 3450 50  0000 C CNN
F 1 "2N7002" V 8190 3450 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 8050 3375 50  0001 L CIN
F 3 "https://www.onsemi.com/pub/Collateral/NDS7002A-D.PDF" H 7850 3450 50  0001 L CNN
F 4 "C8545" V 7850 3450 50  0001 C CNN "LCSC"
	1    7850 3450
	0    1    1    0   
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 637C9CD6
P 8050 3150
AR Path="/637C9CD6" Ref="#PWR?"  Part="1" 
AR Path="/6328F653/637C9CD6" Ref="#PWR0128"  Part="1" 
F 0 "#PWR0128" H 8050 3000 50  0001 C CNN
F 1 "+5V" H 8065 3323 50  0000 C CNN
F 2 "" H 8050 3150 50  0001 C CNN
F 3 "" H 8050 3150 50  0001 C CNN
	1    8050 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	8050 3350 8050 3550
$Comp
L Device:R_Small R?
U 1 1 637CD3F1
P 7550 4400
AR Path="/637CD3F1" Ref="R?"  Part="1" 
AR Path="/6328F653/637CD3F1" Ref="R14"  Part="1" 
F 0 "R14" H 7609 4446 50  0000 L CNN
F 1 "10k" H 7609 4355 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 7550 4400 50  0001 C CNN
F 3 "~" H 7550 4400 50  0001 C CNN
F 4 "C25804" H 7550 4400 50  0001 C CNN "LCSC"
	1    7550 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	7550 4500 7550 4550
Wire Wire Line
	7550 4550 7650 4550
Wire Wire Line
	7450 4550 7550 4550
Connection ~ 7550 4550
$Comp
L power:+3.3V #PWR?
U 1 1 637CD3FB
P 7550 4150
AR Path="/637CD3FB" Ref="#PWR?"  Part="1" 
AR Path="/6328F653/637CD3FB" Ref="#PWR0129"  Part="1" 
F 0 "#PWR0129" H 7550 4000 50  0001 C CNN
F 1 "+3.3V" H 7565 4323 50  0000 C CNN
F 2 "" H 7550 4150 50  0001 C CNN
F 3 "" H 7550 4150 50  0001 C CNN
	1    7550 4150
	1    0    0    -1  
$EndComp
Wire Wire Line
	7550 4150 7550 4200
Wire Wire Line
	7850 4250 7850 4200
Wire Wire Line
	7850 4200 7550 4200
Connection ~ 7550 4200
Wire Wire Line
	7550 4200 7550 4300
Wire Wire Line
	8050 4550 8150 4550
Connection ~ 8050 4550
$Comp
L Device:R_Small R?
U 1 1 637CD408
P 8050 4250
AR Path="/637CD408" Ref="R?"  Part="1" 
AR Path="/6328F653/637CD408" Ref="R23"  Part="1" 
F 0 "R23" H 8109 4296 50  0000 L CNN
F 1 "10k" H 8109 4205 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 8050 4250 50  0001 C CNN
F 3 "~" H 8050 4250 50  0001 C CNN
F 4 "C25804" H 8050 4250 50  0001 C CNN "LCSC"
	1    8050 4250
	1    0    0    -1  
$EndComp
$Comp
L Transistor_FET:2N7002 Q?
U 1 1 637CD40E
P 7850 4450
AR Path="/637CD40E" Ref="Q?"  Part="1" 
AR Path="/6328F653/637CD40E" Ref="Q11"  Part="1" 
F 0 "Q11" V 8099 4450 50  0000 C CNN
F 1 "2N7002" V 8190 4450 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 8050 4375 50  0001 L CIN
F 3 "https://www.onsemi.com/pub/Collateral/NDS7002A-D.PDF" H 7850 4450 50  0001 L CNN
F 4 "C8545" V 7850 4450 50  0001 C CNN "LCSC"
	1    7850 4450
	0    1    1    0   
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 637CD414
P 8050 4150
AR Path="/637CD414" Ref="#PWR?"  Part="1" 
AR Path="/6328F653/637CD414" Ref="#PWR0134"  Part="1" 
F 0 "#PWR0134" H 8050 4000 50  0001 C CNN
F 1 "+5V" H 8065 4323 50  0000 C CNN
F 2 "" H 8050 4150 50  0001 C CNN
F 3 "" H 8050 4150 50  0001 C CNN
	1    8050 4150
	1    0    0    -1  
$EndComp
Wire Wire Line
	8050 4350 8050 4550
Wire Wire Line
	4050 4800 4050 5100
Wire Wire Line
	4050 5100 4200 5100
$Comp
L Transistor_FET:2N7002 Q?
U 1 1 6395F350
P 2250 2400
AR Path="/6395F350" Ref="Q?"  Part="1" 
AR Path="/6328F653/6395F350" Ref="Q3"  Part="1" 
F 0 "Q3" V 2499 2400 50  0000 C CNN
F 1 "2N7002" V 2590 2400 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 2450 2325 50  0001 L CIN
F 3 "https://www.onsemi.com/pub/Collateral/NDS7002A-D.PDF" H 2250 2400 50  0001 L CNN
F 4 "C8545" V 2250 2400 50  0001 C CNN "LCSC"
	1    2250 2400
	0    1    1    0   
$EndComp
Connection ~ 2450 2500
$Comp
L Connector_Generic:Conn_02x09_Odd_Even J6
U 1 1 63A7D579
P 5150 6700
AR Path="/6328F653/63A7D579" Ref="J6"  Part="1" 
AR Path="/63A7D579" Ref="J?"  Part="1" 
F 0 "J6" H 5200 7317 50  0000 C CNN
F 1 "Expansion" H 5200 7226 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x09_P2.54mm_Vertical" H 5150 6700 50  0001 C CNN
F 3 "~" H 5150 6700 50  0001 C CNN
	1    5150 6700
	1    0    0    -1  
$EndComp
Text GLabel 4950 6300 0    50   BiDi ~ 0
IO36
Text GLabel 5450 6300 2    50   BiDi ~ 0
IO39
Text GLabel 4950 6400 0    50   BiDi ~ 0
IO34
Text GLabel 5450 6400 2    50   BiDi ~ 0
IO35
Text GLabel 4950 6500 0    50   BiDi ~ 0
IO32
Text GLabel 5450 6500 2    50   BiDi ~ 0
IO33
Text GLabel 4950 6900 0    50   BiDi ~ 0
IO9
Text GLabel 5450 6800 2    50   BiDi ~ 0
IO10
Text GLabel 4950 6600 0    50   BiDi ~ 0
IO8
Text GLabel 5450 6600 2    50   BiDi ~ 0
IO7
Text GLabel 5450 6700 2    50   BiDi ~ 0
IO6
Text GLabel 4950 6800 0    50   BiDi ~ 0
IO11
Text GLabel 5450 6900 2    50   BiDi ~ 0
IO2
Text GLabel 4950 7000 0    50   BiDi ~ 0
IO5
Text GLabel 5450 7000 2    50   BiDi ~ 0
IO17
Text GLabel 4950 6700 0    50   BiDi ~ 0
IO12
Text GLabel 4950 7100 0    50   BiDi ~ 0
IO16
Text GLabel 5450 7100 2    50   BiDi ~ 0
IO4
$EndSCHEMATC
