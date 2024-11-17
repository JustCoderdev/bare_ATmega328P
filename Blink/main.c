#include <silicon.h>

int main(void)
{
	/* int cycles, i; */

	pin_as_OUTPUT(LED_BUILTIN);
	/* pin_set_HIGH(LED_BUILTIN); */

	/* *TCCR1A = 0; */
	/* *TCCR1B = 0; */

	/* reg_write_1_(TCCR1B, 0); /1* disable prescaler *1/ */
	/* reg_write_1_(TIMSK1, 0); /1* Enable Overflow Interrupt *1/ */

	/* *TCNT1H = 0; */
	/* *TCNT1L = 0; */

	/* /1* Compare *1/ */
	/* { */

	/* } */

	/* cycles = (*TCNT1H << 8) | *TCNT1L; */

	/* for(i = 0; i < cycles; ++i) */
	/* { */
		/* pin_set_LOW(LED_BUILTIN); */
		/* waste_ms(800); */
		/* pin_set_HIGH(LED_BUILTIN); */
		/* waste_ms(800); */
	/* } */

	while(true)
	{
		pin_set_HIGH(LED_BUILTIN);
		waste_ms(800);

		pin_set_LOW(LED_BUILTIN);
		waste_s(2);
	}

	return 0;
}
