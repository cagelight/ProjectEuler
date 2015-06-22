#include <stdio.h>
#include <stdint.h>

extern uint64_t project_euler_c_solution() {

	volatile uint64_t sum = 0;

	for (uint64_t i = 0; i < 1000; i++) {
		if (i % 3 == 0 || i % 5 == 0) sum += i;
	}

	return sum;

}
