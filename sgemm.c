/* SPDX-License-Identifier: BSD-3-Clause */
#include "sgemm.h"

#define __vsetcfg(nvd, nvp) \
	__asm__ __volatile__ ("vsetcfg " #nvd ", " #nvp)
#define vsetcfg(nvd, nvp) __vsetcfg(nvd, nvp)

#define vsetvl(vl) \
	__asm__ __volatile__ ("vsetvl zero, %0" : : "r" (vl))

#define vmca(va, x) \
	__asm__ __volatile__ ("vmca " #va ", %0" : : "r" (x))

#define vmcs(vs, x) \
	__asm__ __volatile__ ("vmcs " #vs ", %0" : : "r" (x))

#define vf(p) \
	__asm__ __volatile__ ("vf %0" : : "A" (p))


extern void bli_sgemm_hwacha_16xn_vf_init(void) __attribute__((visibility("protected")));
extern void bli_sgemm_hwacha_16xn_vf_init_beta(void)__attribute__((visibility("protected")));
extern void bli_sgemm_hwacha_16xn_vf_tail(void)__attribute__((visibility("protected")));
extern void bli_sgemm_hwacha_16xn_vf_inner_0(void)__attribute__((visibility("protected")));
extern void bli_sgemm_hwacha_16xn_vf_inner_1(void)__attribute__((visibility("protected")));
extern void bli_sgemm_hwacha_16xn_vf_end(void)__attribute__((visibility("protected")));

void bli_sgemm_hwacha_16xn
     (
       dim_t               k0,
       float*     restrict alpha,
       float*     restrict a,
       float*     restrict b,
       float*     restrict beta,
       float*     restrict c, inc_t rs_c0, inc_t cs_c0,
       auxinfo_t* restrict data,
       cntx_t*    restrict cntx
     )
{
	vsetcfg(BLIS_MR+2, 1);
	vsetvl(BLIS_NR);

	vmca(va0, c);
	vmca(va1, c += rs_c0);
	vmca(va2, c += rs_c0);
	vmca(va3, c += rs_c0);
	vmca(va4, c += rs_c0);
	vmca(va5, c += rs_c0);
	vmca(va6, c += rs_c0);
	vmca(va7, c += rs_c0);
	vmca(va8, c += rs_c0);
	vmca(va9, c += rs_c0);
	vmca(va10, c += rs_c0);
	vmca(va11, c += rs_c0);
	vmca(va12, c += rs_c0);
	vmca(va13, c += rs_c0);
	vmca(va14, c += rs_c0);
	vmca(va15, c += rs_c0);
	vmca(va16, b);
	b += rs_c0;

	if (*beta) {
		vmcs(vs63, *beta);
		vf(bli_sgemm_hwacha_16xn_vf_init_beta);
	} else {
		vf(bli_sgemm_hwacha_16xn_vf_init);
	}

	vmcs(vs63, *alpha);
	for (; k0 > 1; k0 -= 2) {
		vmcs(vs1, a[0]);
		vmcs(vs2, a[1]);
		vmcs(vs3, a[2]);
		vmcs(vs4, a[3]);
		vmcs(vs5, a[4]);
		vmcs(vs6, a[5]);
		vmcs(vs7, a[6]);
		vmcs(vs8, a[7]);
		vmcs(vs9, a[8]);
		vmcs(vs10, a[9]);
		vmcs(vs11, a[10]);
		vmcs(vs12, a[11]);
		vmcs(vs13, a[12]);
		vmcs(vs14, a[13]);
		vmcs(vs15, a[14]);
		vmcs(vs16, a[15]);
		vmca(va16, b);
		vf(bli_sgemm_hwacha_16xn_vf_inner_0);
		b += rs_c0;

		vmcs(vs1, a[16]);
		vmcs(vs2, a[17]);
		vmcs(vs3, a[18]);
		vmcs(vs4, a[19]);
		vmcs(vs5, a[20]);
		vmcs(vs6, a[21]);
		vmcs(vs7, a[22]);
		vmcs(vs8, a[23]);
		vmcs(vs9, a[24]);
		vmcs(vs10, a[25]);
		vmcs(vs11, a[26]);
		vmcs(vs12, a[27]);
		vmcs(vs13, a[28]);
		vmcs(vs14, a[29]);
		vmcs(vs15, a[30]);
		vmcs(vs16, a[31]);
		vmca(va16, b);
		vf(bli_sgemm_hwacha_16xn_vf_inner_1);
		b += rs_c0;
		a += 2 * BLIS_MR;
	}
	if (k0 > 0) {
		vmcs(vs1, a[0]);
		vmcs(vs2, a[1]);
		vmcs(vs3, a[2]);
		vmcs(vs4, a[3]);
		vmcs(vs5, a[4]);
		vmcs(vs6, a[5]);
		vmcs(vs7, a[6]);
		vmcs(vs8, a[7]);
		vmcs(vs9, a[8]);
		vmcs(vs10, a[9]);
		vmcs(vs11, a[10]);
		vmcs(vs12, a[11]);
		vmcs(vs13, a[12]);
		vmcs(vs14, a[13]);
		vmcs(vs15, a[14]);
		vmcs(vs16, a[15]);
		vf(bli_sgemm_hwacha_16xn_vf_tail);
	}

	vf(bli_sgemm_hwacha_16xn_vf_end);
	__asm__ __volatile__ ("fence" ::: "memory");
}
