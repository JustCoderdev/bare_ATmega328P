/*
 * Justcoderdev Silicon library for ATmega328P microcontroller
 */

#ifndef SILICON_H_
#define SILICON_H_

#define CLOCK_HZ  16000000U
#define CLOCK_KHZ 16000U

#define LED_BUILTIN B5


/* Types
 * ------------------------------------------------------------ */

typedef enum bool {
	true = (1 == 1),
	false = (1 != 1)
} bool;

typedef unsigned int _bm;    /* for bitmasks */
typedef unsigned char byte;  /* assert 8bit  */
typedef unsigned short word; /* assert 16bit */

typedef volatile byte reg;
typedef volatile word wreg;

/* Binary mappings (2, 3, 4 bits)
 * ------------------------------------------------------------ */

/* 2-bit */
#define b00 0x0 /* 0 */
#define b01 0x1 /* 1 */
#define b10 0x2 /* 2 */
#define b11 0x3 /* 3 */

/* 3-bit */
#define b000 0x0 /* 0 */
#define b001 0x1 /* 1 */
#define b010 0x2 /* 2 */
#define b011 0x3 /* 3 */
#define b100 0x4 /* 4 */
#define b101 0x5 /* 5 */
#define b110 0x6 /* 6 */
#define b111 0x7 /* 7 */

/* 4-bit */
#define b0000 0x0 /* 0 */
#define b0001 0x1 /* 1 */
#define b0010 0x2 /* 2 */
#define b0011 0x3 /* 3 */
#define b0100 0x4 /* 4 */
#define b0101 0x5 /* 5 */
#define b0110 0x6 /* 6 */
#define b0111 0x7 /* 7 */
#define b1000 0x8 /* 8 */
#define b1001 0x9 /* 9 */
#define b1010 0xA /* 10 */
#define b1011 0xB /* 11 */
#define b1100 0xC /* 12 */
#define b1101 0xD /* 13 */
#define b1110 0xE /* 14 */
#define b1111 0xF /* 15 */


/* IO Pins
 * ------------------------------------------------------------ */

#if 0
struct {
	_bm D7: 1; _bm D6: 1; _bm D5: 1; _bm D4: 1;
	_bm D3: 1; _bm D2: 1; _bm D1: 1; _bm D0: 1;
}* const PORTD = (void*)0x2B;
#endif

#define PORTD ((reg*)0x2B)
#define DDRD  ((reg*)0x2A)
#define PIND  ((reg*)0x29)

#define PORTC ((reg*)0x28)
#define DDRC  ((reg*)0x27)
#define PINC  ((reg*)0x26)

#define PORTB ((reg*)0x25)
#define DDRB  ((reg*)0x24)
#define PINB  ((reg*)0x23)

typedef enum {

	/*     v port
	 * ---|00|000
	 *        ^ pin */

	/* A = ---|00|000 0x00 */
	/* B = ---|01|000 0x08 */
	/* C = ---|10|000 0x10 */
	/* D = ---|11|000 0x18 */

	B0 = 0x10, B1, B2, B3, B4, B5, B6, B7,
	C0 = 0x08, C1, C2, C3, C4, C5, C6, C7_,
	D0 = 0x18, D1, D2, D3, D4, D5, D6, D7
} IOPin;

/* TODO: Replace pin operations with inline macro replacment */

extern __inline bool reg_read_(reg* address, byte position);
extern __inline void reg_write_1_(reg* address, byte position);
extern __inline void reg_write_0_(reg* address, byte position);


/* PINx */

extern __inline void pinx_write_1_(IOPin pin);
extern __inline bool pinx_read_(IOPin pin);

#define pin_toggle(PIN) pinx_write_1_(PIN)
#define pin_read(PIN) pinx_read_(PIN)

/* PORTx */

extern __inline void portx_write_1_(IOPin pin);
extern __inline void portx_write_0_(IOPin pin);

#define pin_set_HIGH(PIN) portx_write_1_(PIN)       /* output */
#define pin_set_LOW(PIN) portx_write_0_(PIN)        /* output */
#define pin_PULLUP_enable(PIN) portx_write_1_(PIN)  /* input */
#define pin_PULLUP_disable(PIN) portx_write_0_(PIN) /* input */

/* DDRx */

extern __inline void ddrx_write_1_(IOPin pin);
extern __inline void ddrx_write_0_(IOPin pin);

#define pin_as_INPUT(PIN) ddrx_write_1_(PIN)
#define pin_as_OUTPUT(PIN) ddrx_write_0_(PIN)


/* Interrupts
 * ------------------------------------------------------------ */

#define SREG ((reg*)0x5F)

/* #define interrupts_enable() reg_write_1_(SREG, 7) */
/* #define interrupts_disable() reg_write_0_(SREG, 7) */

#define interrupts_enable() __asm("sei")
#define interrupts_disable() __asm("cli")


/* Timers
 * ------------------------------------------------------------ */

/* Timer0 */

#if 0
typedef enum {
	IGN = b00, /* Normal port operation, OC0A disconnected. */
	TGL = b01, /* Toggle OC0A on Compare Match */
	CLR = b10, /* Clear OC0A on Compare Match */
	SET = b11  /* Set OC0A on Compare Match */
} COM0A;

struct {
	COM0A com0a: 2;
} *const TCCR0A = (void*)0x44;
#endif

#define TCCR0A ((reg*)0x44)
#define TCCR0B ((reg*)0x45)

#define TCNT0  ((reg*)0x46) /* Timer counter */
#define OCR0A  ((reg*)0x47) /* Output compare rA */
#define OCR0B  ((reg*)0x48) /* Output compare rB */

#define TIMSK0 ((reg*)0x6E) /* Timer 0 Interrupt Mask */

extern void timer0_counter_set(byte value);

extern void timer0_compareA_set(byte value);
extern void timer0_compareA_enable(void);
extern void timer0_compareA_disable(void);

extern void timer0_compareB_set(byte value);
extern void timer0_compareB_enable(void);
extern void timer0_compareB_disable(void);

extern void timer0_overflow_enable(void);
extern void timer0_overflow_disable(void);

/* Timer1 */

#define TCCR1A ((reg*)0x80)
#define TCCR1B ((reg*)0x81)
#define TCCR1C ((reg*)0x82)

#define TIMSK1 ((reg*)0x6F) /* Timer 1 Interrupt Mask */

#define TCNT1  ((wreg*)0x84)
#define TCNT1H ((reg*)0x85)
#define TCNT1L ((reg*)0x84)




/* Clock
 * ------------------------------------------------------------ */

/* Waste cpu cycles */
extern __inline void waste_ms(unsigned long millis);
extern __inline void waste_s(unsigned long seconds);



/* UART
 * ------------------------------------------------------------ */


/* Binary mapping (inc)
 * ------------------------------------------------------------ */

/* 8-bit */
#define b00000000 0x00 /* 0 */
#define b00000001 0x01 /* 1 */
#define b00000010 0x02 /* 2 */
#define b00000011 0x03 /* 3 */
#define b00000100 0x04 /* 4 */
#define b00000101 0x05 /* 5 */
#define b00000110 0x06 /* 6 */
#define b00000111 0x07 /* 7 */
#define b00001000 0x08 /* 8 */
#define b00001001 0x09 /* 9 */
#define b00001010 0x0A /* 10 */
#define b00001011 0x0B /* 11 */
#define b00001100 0x0C /* 12 */
#define b00001101 0x0D /* 13 */
#define b00001110 0x0E /* 14 */
#define b00001111 0x0F /* 15 */

#define b00010000 0x10 /* 16*/
#define b00010001 0x11 /* 17 */
#define b00010010 0x12 /* 18 */
#define b00010011 0x13 /* 19 */
#define b00010100 0x14 /* 20 */
#define b00010101 0x15 /* 21 */
#define b00010110 0x16 /* 22 */
#define b00010111 0x17 /* 23 */
#define b00011000 0x18 /* 24 */
#define b00011001 0x19 /* 25 */
#define b00011010 0x1A /* 26 */
#define b00011011 0x1B /* 27 */
#define b00011100 0x1C /* 28 */
#define b00011101 0x1D /* 29 */
#define b00011110 0x1E /* 30 */
#define b00011111 0x1F /* 31 */

#define b00100000 0x20 /* 32 */
#define b00100001 0x21 /* 33 */
#define b00100010 0x22 /* 34 */
#define b00100011 0x23 /* 35 */
#define b00100100 0x24 /* 36 */
#define b00100101 0x25 /* 37 */
#define b00100110 0x26 /* 38 */
#define b00100111 0x27 /* 39 */
#define b00101000 0x28 /* 40 */
#define b00101001 0x29 /* 41 */
#define b00101010 0x2A /* 42 */
#define b00101011 0x2B /* 43 */
#define b00101100 0x2C /* 44 */
#define b00101101 0x2D /* 45 */
#define b00101110 0x2E /* 46 */
#define b00101111 0x2F /* 47 */

#define b00110000 0x30 /* 48 */
#define b00110001 0x31 /* 49 */
#define b00110010 0x32 /* 50 */
#define b00110011 0x33 /* 51 */
#define b00110100 0x34 /* 52 */
#define b00110101 0x35 /* 53 */
#define b00110110 0x36 /* 54 */
#define b00110111 0x37 /* 55 */
#define b00111000 0x38 /* 56 */
#define b00111001 0x39 /* 57 */
#define b00111010 0x3A /* 58 */
#define b00111011 0x3B /* 59 */
#define b00111100 0x3C /* 60 */
#define b00111101 0x3D /* 61 */
#define b00111110 0x3E /* 62 */
#define b00111111 0x3F /* 63 */

#define b01000000 0x40 /* 64 */
#define b01000001 0x41 /* 65 */
#define b01000010 0x42 /* 66 */
#define b01000011 0x43 /* 67 */
#define b01000100 0x44 /* 68 */
#define b01000101 0x45 /* 69 */
#define b01000110 0x46 /* 70 */
#define b01000111 0x47 /* 71 */
#define b01001000 0x48 /* 72 */
#define b01001001 0x49 /* 73 */
#define b01001010 0x4A /* 74 */
#define b01001011 0x4B /* 75 */
#define b01001100 0x4C /* 76 */
#define b01001101 0x4D /* 77 */
#define b01001110 0x4E /* 78 */
#define b01001111 0x4F /* 79 */

#endif /* SILICON_H_ */
