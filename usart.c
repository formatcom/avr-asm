/*
 * REF: http://ww1.microchip.com/downloads/en/DeviceDoc/ATmega48A-PA-88A-PA-168A-PA-328-P-DS-DS40002061A.pdf
 *
 * 20. USART0
 *
 * 20.1 Features
 *
 * Full Duplex Operation (Independent Serial Receive and Transmit Registers)
 * Asynchronous or Synchronous Operation
 * Master or Slave Clocked Synchronous Operation
 * High Resolution Baud Rate Generator
 * Supports Serial Frames with 5, 6, 7, 8, or 9 Data Bits and 1 or 2 Stop Bits
 * Odd or Even Parity Generation and Parity Check Supported by Hardware
 * Data OverRun Detection
 * Framing Error Detection
 * Noise Filtering Includes False Start Bit Detection and Digital Low Pass Filter
 * Three Separate Interrupts on TX Complete, TX Data Register Empty and RX Complete
 * Multi-processor Communication Mode
 * Double Speed Asynchronous Communication Mode
 */

/*
 * 20.11.4 UCSRnC - USART Control and Status Register n C
 *
 * bit 7 UMSELn1
 * R/W
 * Initial Value 0
 *
 * bit 6 UMSELn0
 * R/W
 * Initial Value 0
 *
 * bit 5 UPMn1
 * R/W
 * Initial Value 0
 *
 * bit 4 UPMn0
 * R/W
 * Initial Value 0
 *
 * bit 3 USBSn
 * R/W
 * Initial Value 0
 *
 * bit 2 UCSZn1
 * R/W
 * Initial Value 1
 *
 * bit 1 UCSZn0
 * R/W
 * Initial Value 1
 *
 * bit 0 UCPOLn
 * R/W
 * Initial Value 0
 *
 *
 * Bits 7:6 - USART Mode Select
 *
 * Table 20-8. UMSELn Bits Settings
 *
 *  UMSELn1  |  UMSELn0  | Mode
 *  0        |  0        | Asynchronous USART
 *  0        |  1        | Synchronous USART
 *  1        |  0        | Reserved
 *  1        |  1        | Master SPI (MSPIM)
 *
 *
 * Bits 5:4 - Parity Mode
 *
 * Table 20-9. UPMn Bits Settings
 *
 *  UPMn1    |  UPMn0    | Parity Mode
 *  0        |  0        | Disabled
 *  0        |  1        | Reserved
 *  1        |  0        | Enabled, Even Parity
 *  1        |  1        | Enabled, Odd Parity
 *
 *
 * Bit 3 - USBSn: Stop Bit Select
 *
 * Table 20-10. USBS Bit Select
 *
 *  USBSn    | Stop Bit(s)
 *  0        | 1-bit
 *  1        | 2-bit
 *
 * Bits 2:1 - UCSZn1:0: Character Size
 * The UCSZn1:0 bits combined with the UCSZn2 bit in UCSRnB
 *
 * Table 20-11. UCSZn Bits Settings
 *
 *  UCSZn2   | UCSZn1   | UCSZn0   | Character Size
 *  0        | 0        | 0        | 5-bit
 *  0        | 0        | 1        | 6-bit
 *  0        | 1        | 0        | 7-bit
 *  0        | 1        | 1        | 8-bit
 *  1        | 0        | 0        | Reserved
 *  1        | 0        | 1        | Reserved
 *  1        | 1        | 0        | Reserved
 *  1        | 1        | 1        | 9-bit
 *
 *
 * bit 0 - UCPOLn: Clock Polarity
 * This bit is used for synchronous mode only.
 * Write this bit to zero when asynchronous mode is used.
 * REF Figure 20-3. Synchronous Mode XCKn Timing.
 * REF Table 20-12
 *
 *
 *
 * Table 20-1 Operating Mode
 *
 * Asynchronous Normal mode
 * U2Xn = 0
 * UBRRn = ( Fosc / (16 * BAUD) ) - 1
 *
 * Asynchronous Double Speed mode
 * U2Xn = 1
 * UBRRn = ( Fosc / ( 8 * BAUD) ) - 1
 *
 * Synchronous Master mode
 * UBRRn = ( Fosc / ( 2 * BAUD) ) - 1
 */

#define FOSC 16000000
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1

void USART_Init(unsigned int ubrr)
{
	// Set baud rate. REF: 20.11.5 Only usign 11 bits
	UBRR0H = (unsigned char) (ubrr>>8);
	UBRR0L = (unsigned char)ubrr;
}

int main()
{
}

