#include <stdint.h>

extern uint64_t project_euler_c_solution() {
	uint64_t num = 100;

	volatile uint64_t susq = 0;
	volatile uint64_t sqsu = 0;

	for (uint64_t i = 0; i <= num; i++) {
		susq += i * i;
		sqsu += i;
	}
	sqsu *= sqsu;

	return sqsu - susq;
}
