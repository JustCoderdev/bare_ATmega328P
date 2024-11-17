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

typedef unsigned char byte;  /* assert 8bit */
typedef unsigned short word; /* assert 16bit */

typedef volatile byte reg;
typedef volatile word wreg;


/* IO Pins
 * ------------------------------------------------------------ */

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


/* 
 * ------------------------------------------------------------ */


#endif /* SILICON_H_ */
