/*
 * Justcoderdev Silicon library for arduino microcontroller
 */

#ifndef SILICON_H_
#define SILICON_H_

#include <stdint.h>

#ifndef F_CPU
#error F_CPU not defined
#else
#undef F_CPU
#endif

#define CLOCK_HZ  16000000U
#define CLOCK_KHZ 16000U

#define LED_BUILTIN B5


/* Types
 * -------------------------------- */

typedef enum bool {
	true = (1 == 1),
	false = (1 != 1)
} bool;

typedef unsigned char byte;  /* assert 8bit */
typedef unsigned short word; /* assert 16bit */
typedef volatile byte* reg;


/* IO Pins
 * -------------------------------- */

#define PORTD ((reg)0x2B)
#define DDRD  ((reg)0x2A)
#define PIND  ((reg)0x29)

#define PORTC ((reg)0x28)
#define DDRC  ((reg)0x27)
#define PINC  ((reg)0x26)

#define PORTB ((reg)0x25)
#define DDRB  ((reg)0x24)
#define PINB  ((reg)0x23)

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


/* Time
 * -------------------------------- */

/* Waste cpu cycles */
extern __inline void waste_ms(unsigned long millis);
extern __inline void waste_s(unsigned long seconds);


#endif /* SILICON_H_ */
