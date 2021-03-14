/* SPDX-License-Identifier: BSD-3-Clause */

#ifndef _HWACHA_SGEMM_H
#define _HWACHA_SGEMM_H
#include <stddef.h>

#define BLIS_MR 16
#define BLIS_NR 16

typedef size_t dim_t;
typedef size_t inc_t;
typedef void auxinfo_t;
typedef void cntx_t;

extern void bli_sgemm_hwacha_16xn(
	dim_t,
	float* restrict,
	float* restrict,
	float* restrict,
	float* restrict,
	float* restrict,
	inc_t,
	inc_t,
	auxinfo_t *,
	cntx_t *);

#endif /* _HWACHA_SGEMM_H */
