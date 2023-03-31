# SoC



## MAX31723
- Temperatuur sensor (-55°C - 125°C)
- Communicatie over SPI (Serial pheripheral interface)
- Pins 
	- 1: SS (moet hoog staan als er communicatie plaats moet vinden)
	- 2: MOSI (serial-data input voor IC)
	- 3: MISO (serial-data output voor IC)
	- 4: SCK (serial clock)
	- 5: GND
	- 6: VCC (3.3V)

## MAX14840E

- RS-486 transmitter
- Communicatie over UART
- Pins j1
	- 1: RE (streepje boven RE) (ingang voor ontvanger inschakelen, deze actief-laag pin maakt de half-duplex-ontvanger mogelijk)
	- 2: DI (Driver Input. Deze pin draagt de zender gegevens van de UART van de het pmod-systeem. Zender naar een aangesloten ontvanger)
	- 3: RO (Ontvanger output. Deze pin draagt de half-duplex ontvangen data over aan de pmod UART ontvanger)
	- 4: DE (Driver output eneble input. Deze actief hoge pin zet de half-duplex zender aan)
	- 5: GND
	- 6: VCC (3.3V)
- pins j2
	- 1: RS485-A (noninverting RS-485 signaal)
	- 2: RS485-B (inverting RS-485 signaal)
- Half duplex -> Communicatie over 1 kanaal. De zender en de ontvanger gebruiken hetzelfde kanaal om de beurt om te zenden en te ontvangen. Bij dit bordje gaat dit maximaal tot 10MBps. 

## Neopixel RGB Matrix (8x8)

- Pins j1
	- 1: V+ (VCC)
	- 2: IN (data pin om elke RGB aan te kunnen spreken
	- 3: V- (GND)

## VL53L5CX

- Kan verschillende objecten op verschillende afstanden detecteren
- Pins 
	- 1: GND
	- 2: VCC (3.3V)
	- 3: SDA
	- 4: SCL
	- 5: INT
	- 6: RST
-	I²C adres -> 0X29
-	RAM-based Sensor

## TFT-shield

- Ambient light sensor 
- Pins 
	- 1: VCC
	- 2: GND
	- 3: ALS_OUT
- Display connector
- Axi GPIO toevoegen
- Pinnen GPIO connecteren met TFT-shield
- segger
