#include <stdint.h>

extern uint64_t project_euler_c_solution() {

	volatile uint64_t limit = 20;

	uint64_t res = 1;
	uint8_t ccur = 2;

	for(;;) {
		if (ccur > limit) break;
		if (res % ccur == 0) {
			ccur++;
			continue;
		} else {
			ccur = 2;
			res++;
		}
	}
	return res;
}
