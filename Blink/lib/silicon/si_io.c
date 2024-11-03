#include <silicon.h>

/* IO Pins
 * -------------------------------- */

__inline bool reg_read_(reg address, byte position)
{
	return ((*address & (1 << position)) >> position);
}

__inline void reg_write_1_(reg address, byte position)
{
	*address |= (1 << position);
}

__inline void reg_write_0_(reg address, byte position)
{
	*address &= ~(1 << position);
}

/* PINx */

__inline void pinx_write_1_(IOPin pin)
{
	/* TODO: assert */
	if(pin > D7 || pin == C7_ || pin < B0) return;

	if(pin >= D0) reg_write_1_(PIND, pin - D0);
	else if(pin >= C0) reg_write_1_(PINC, pin - C0);
	else if(pin >= B0) reg_write_1_(PINB, pin - B0);
}

__inline bool pinx_read_(IOPin pin)
{
	/* TODO: assert */
	if(pin > D7 || pin == C7_ || pin < B0) return false;

	if(pin >= D0) return reg_read_(PIND, pin - D0);
	else if(pin >= C0) return reg_read_(PINC, pin - C0);
	else if(pin >= B0) return reg_read_(PINB, pin - B0);
	return false;
}

/* PORTx */

__inline void portx_write_1_(IOPin pin)
{
	/* TODO: assert */
	if(pin > D7 || pin == C7_ || pin < B0) return;

	if(pin >= D0) reg_write_1_(DDRD, pin - D0);
	else if(pin >= C0) reg_write_1_(DDRC, pin - C0);
	else if(pin >= B0) reg_write_1_(DDRB, pin - B0);
}

__inline void portx_write_0_(IOPin pin)
{
	/* TODO: assert */
	if(pin > D7 || pin == C7_ || pin < B0) return;

	if(pin >= D0) reg_write_0_(PORTD, pin - D0);
	else if(pin >= C0) reg_write_0_(PORTC, pin - C0);
	else if(pin >= B0) reg_write_0_(PORTB, pin - B0);
}

/* DDRx */

__inline void ddrx_write_1_(IOPin pin)
{
	/* TODO: assert */
	if(pin > D7 || pin == C7_ || pin < B0) return;

	if(pin >= D0) reg_write_1_(DDRD, pin - D0);
	else if(pin >= C0) reg_write_1_(DDRC, pin - C0);
	else if(pin >= B0) reg_write_1_(DDRB, pin - B0);
}

__inline void ddrx_write_0_(IOPin pin)
{
	/* TODO: assert */ if(pin > D7 || pin == C7_ || pin < B0) return;

	if(pin >= D0) reg_write_0_(DDRD, pin - D0);
	else if(pin >= C0) reg_write_0_(DDRC, pin - C0);
	else if(pin >= B0) reg_write_0_(DDRB, pin - B0);
}
