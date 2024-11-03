#include <silicon.h>

int main(void)
{
	pin_as_OUTPUT(LED_BUILTIN);

	while(true)
	{
		pin_set_HIGH(LED_BUILTIN);
		waste_ms(800);

		pin_set_LOW(LED_BUILTIN);
		waste_s(2);
	}

	return 0;
}
