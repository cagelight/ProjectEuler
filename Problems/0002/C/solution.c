#include <stdio.h>
#include <stdint.h>

extern uint64_t project_euler_c_solution() {

	volatile uint64_t limit = 4000000;

	uint64_t sum = 0;
	uint32_t A = 1;
	uint32_t B = 1;

	while (1) {
		A = A + B;
		if (A > limit) break;
		if (!(A & 0x00000001)) sum += A;
		B = A + B;
		if (B > limit) break;
		if (!(B & 0x00000001)) sum += B;
	}

	return sum;
}
