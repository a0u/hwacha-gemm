/* SPDX-License-Identifier: BSD-3-Clause */

#include <stdio.h>
#include "sgemm.h"
#include "dataset.h"

static inline unsigned long rdcycle(void)
{
	unsigned long cycles;
	__asm__ __volatile__ ("rdcycle %0" : "=r" (cycles));
	return cycles;
}

static float output_data[BLIS_MR * BLIS_NR];

int main(void)
{
	float alpha, beta;
	size_t i;
	unsigned long cycles;

	alpha = ALPHA;
	beta = 0.0f;

/*
#define MSTATUS_FS          0x00006000
#define MSTATUS_XS          0x00018000

	__asm__ __volatile__ (
		"csrs mstatus, %0"
		:
		: "r" (MSTATUS_FS | MSTATUS_XS));
*/

	cycles = rdcycle();
	bli_sgemm_hwacha_16xn(
		DIM_K,
		&alpha,
		input_data_A,
		input_data_B,
		&beta,
		output_data,
		BLIS_NR,
		BLIS_MR,
		NULL,
		NULL);
	cycles = rdcycle() - cycles;
	printf("cycles: %lu\n", cycles);

	for (i = 0; i < (BLIS_MR * BLIS_NR); i++) {
		if (output_data[i] != verify_data[i]) {
			printf("%zu %f %f\n", i, output_data[i], verify_data[i]);
			return -1;
		}
	}
	return 0;
}
