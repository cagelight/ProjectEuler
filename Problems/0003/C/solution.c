#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>

bool is_prime(uint64_t num) {
	bool prime = true;
	for (uint64_t i = 3; i < num / 3 && prime; i++) {
		if (num % i == 0) prime = false;
	}
	return prime;
}

extern uint64_t project_euler_c_solution() {

	uint64_t var = 600851475143;

	for (uint64_t i = var / 3; i > 2; i--) {
		if (var % i != 0) continue;
		if (is_prime(i)) return i;
	}

	return 0;
}
