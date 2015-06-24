#include <stdbool.h>
#include <stdint.h>
#include <math.h>

bool is_prime(uint64_t num) {
	if (num < 2) return false;
	bool prime = true;
	uint64_t start = sqrt(num);
	for (uint64_t i = 2; i <= start && prime; i++) {
		if (num % i == 0) prime = false;
	}
	return prime;
}

extern uint64_t project_euler_c_solution() {
	volatile uint64_t limit = 10001;
	uint64_t cur = 0;
	for (uint64_t i = 0;;i++) {
		if (is_prime(i)) cur++;
		if (cur == limit) return i;
	}
}
