#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

bool is_prime(uint64_t num) {
	bool prime = true;
	uint64_t start = sqrt(num);
	for (uint64_t i = 3; i < start && prime; i++) {
		if (num % i == 0) prime = false;
	}
	return prime;
}

extern uint64_t project_euler_c_solution() {

	uint64_t var = 600851475143;
	uint64_t start = sqrt(var);
	for (uint64_t i = start; i > 2; i--) {
		if (var % i != 0) continue;
		if (is_prime(i)) return i;
	}

	return 0;
}
