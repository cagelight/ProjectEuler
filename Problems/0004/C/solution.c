#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

extern uint64_t project_euler_c_solution() {

	volatile uint64_t highlimit = 999;
	volatile uint64_t lowlimit = 100;

	uint64_t highnum = 0;
	uint64_t curnum = 0;

	for (uint64_t A = highlimit; A >= lowlimit; A--) {
		for (uint64_t B = highlimit; B >= lowlimit; B--) {

			curnum = A * B;
			int num = snprintf(NULL, 0, "%lu", curnum);
			char buf[num+1];
			snprintf(buf, num+1, "%lu", curnum);
			uint8_t checknum = (num) / 2;
			bool good = true;
			for (uint8_t c = 0; c < checknum; c++) {
				if (buf[c] != buf[num-1-c]) good = false;
			}
			if (good && curnum > highnum) highnum = curnum;
		}
	}
	return highnum;
}
