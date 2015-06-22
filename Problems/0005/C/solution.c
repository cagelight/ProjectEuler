#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

extern uint64_t project_euler_c_solution() {
	uint64_t res = 1;
	uint8_t ccur = 2;
	while(true) {
		if (ccur > 20) break;
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