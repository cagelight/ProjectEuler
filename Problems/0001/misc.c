#include <stdint.h>

extern char const * project_euler_problem_description() {
	return "If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23. Find the sum of all the multiples of 3 or 5 below 1000.\n";
}

extern uint64_t project_euler_loop_test_count() {
	return 50000;
}
