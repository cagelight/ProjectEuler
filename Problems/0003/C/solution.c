#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

bool is_prime(uint64_t num) {
	bool prime = true;
	uint64_t start = sqrt(num);
	for (uint64_t i = 2; i < start && prime; i++) {
		if (num % i == 0) prime = false;
	}
	return prime;
}

extern uint64_t project_euler_c_solution() {

	volatile uint64_t var = 600851475143;

	uint64_t start = sqrt(var);
	uint64_t lpf = 0;

	for (uint64_t i = 2; i <= start; i++) {
		if (var % i != 0) continue;
		uint64_t test = var / i;
		if (is_prime(test)) return test;
		if (is_prime(i)) lpf = i;
	}

	return lpf;
}
