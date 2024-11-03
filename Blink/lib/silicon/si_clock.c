#include <silicon.h>


__inline void waste_ms(unsigned long millis)
{
	volatile bool t = false;
	unsigned long i, j;

	for(i = 0; i < CLOCK_KHZ; ++i)
		for(j = 0; j < millis; ++j)
			t = !t;
}

__inline void waste_s(unsigned long seconds)
{
	volatile bool t = false;
	unsigned long i, j;

	for(i = 0; i < CLOCK_HZ; ++i)
		for(j = 0; j < seconds; ++j)
			t = !t;
}

