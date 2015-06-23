#include <stdint.h>

extern char const * project_euler_problem_description() {
	return \
	"The sum of the squares of the first ten natural numbers is,\n" \
	"1^2 + 2^2 + ... + 10^2 = 385\n" \
	"The square of the sum of the first ten natural numbers is,\n" \
	"(1 + 2 + ... + 10)^2 = 55^2 = 3025\n" \
	"Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.\n" \
	"Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.\n";
}

extern uint64_t project_euler_loop_test_count() {
	return 5000000;
}
