#include <stdint.h>

extern char const * project_euler_problem_description() {
	return "Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be: \n1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ... \nBy considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.";
}

extern uint64_t project_euler_loop_test_count() {
	return 5000000;
}