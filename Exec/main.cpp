/*
================================================================
======================== PROJECT EULER =========================
================================================================

	- Each problem is located in a numbered file associated
	with the problem number. Inside each solution file is four
	different implementations for the solution:

		NASM Assembly
		Standard C
		Standard C++11
		Standard C++11 With Multithreading

	- Not all solutions will implement all 4 methods.

	- Running a solution file will cause this program to link
	with the file and run each method sequentially (if present).

	- Each call will be timed and the results will be printed.

	Function signatures for each method:

		uint64_t project_euler_nasm_solution(void)
		uint64_t project_euler_c_solution(void)
		uint64_t project_euler_cxx_solution(void)
		uint64_t project_euler_cxxmulti_solution(void)

	Function signature for problem description:

		char const * project_euler_problem_description(void)

		project_euler_loop_test_count


================================================================
*/
#include <dlfcn.h>

#include <cstdint>

#include <chrono>
#include <iostream>

typedef std::chrono::duration<double, std::milli> pe_timeunit;

typedef uint64_t(*pe_sig)(void);
typedef char const *(*pe_desc)(void);
typedef uint64_t(*pe_loopc)(void);

#define RUN_SOLUTION( NAME, VAR ) \
	if (solution_##VAR) { \
		printf("Running "#NAME" Solution...\n"); \
		uint64_t sol{0}; \
		start = std::chrono::high_resolution_clock::now(); \
		for (uint64_t i = 0; i < loop_count; i++) sol = solution_##VAR(); \
		printf("Solution: %li\n", sol); \
		completion_##VAR = std::chrono::duration_cast<pe_timeunit>(std::chrono::high_resolution_clock::now() - start).count(); \
		printf("================\n"); \
	} \

#define PRINT_TIMES( NAME, VAR ) \
	if (completion_##VAR) { \
		printf("%li "#NAME" Solution completed in %lf milliseconds.\n", loop_count, completion_##VAR); \
	} \

int main(int argc, char * * argv) {

	pe_desc prob_desc {nullptr};
	uint64_t loop_count {1};
	pe_sig solution_nasm {nullptr};
	pe_sig solution_c {nullptr};
	pe_sig solution_cxx {nullptr};
	pe_sig solution_cxxmulti {nullptr};
	double completion_nasm {0};
	double completion_c {0};
	double completion_cxx {0};
	double completion_cxxmulti {0};

	std::string pe_id;
	if (argc == 1) {
		printf("Enter problem ID: ");
		std::getline(std::cin, pe_id);
	} else {
		pe_id = argv[1];
	}
	if (pe_id.length() < 4 && strtol(pe_id.c_str(), nullptr, 10) != 0L) {
		pe_id.insert(0, 4 - pe_id.length(), '0');
	}
	printf("Loading problem %s...\n", pe_id.c_str());
	void * dl = dlopen(("./" + pe_id).c_str(), RTLD_NOW);
	if (!dl) {
		printf("Problem %s not found.\n", pe_id.c_str());
		return 1;
	}
	prob_desc = reinterpret_cast<pe_desc>(dlsym(dl, "project_euler_problem_description"));
	pe_loopc loopc = reinterpret_cast<pe_loopc>(dlsym(dl, "project_euler_loop_test_count"));
	if (loopc) loop_count = loopc();
	solution_nasm = reinterpret_cast<pe_sig>(dlsym(dl, "project_euler_nasm_solution"));
	solution_c = reinterpret_cast<pe_sig>(dlsym(dl, "project_euler_c_solution"));
	solution_cxx = reinterpret_cast<pe_sig>(dlsym(dl, "project_euler_cxx_solution"));
	solution_cxxmulti = reinterpret_cast<pe_sig>(dlsym(dl, "project_euler_cxxmulti_solution"));

	if (!solution_nasm && !solution_c && !solution_cxx && !solution_cxxmulti) {
		printf("Problem %s contains no solutions!\n", pe_id.c_str());
		return 1;
	}

	std::chrono::high_resolution_clock::time_point start;
	pe_timeunit dur;

	if (prob_desc) {
		printf("\n================================\n%s\nRunning %li time(s)...\n", prob_desc(), loop_count);
	}
	printf("================================\n");
	RUN_SOLUTION( NASM, nasm )
	RUN_SOLUTION( C, c )
	RUN_SOLUTION( C++, cxx )
	RUN_SOLUTION( Multithreaded C++, cxxmulti )

	printf("\n================================\nRESULTS\n================\n\n");
	PRINT_TIMES( NASM, nasm )
	PRINT_TIMES( C, c )
	PRINT_TIMES( C++, cxx )
	PRINT_TIMES( Multithreaded C++, cxxmulti )
	printf("\n================================\n");

	dlclose(dl);

	return 0;
}

/*
================================================================
*/
