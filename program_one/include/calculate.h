/*
 *
 * Assessment
 */

#ifndef _CALCULATE_H
#define _CALCULATE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

typedef struct colli{
	unsigned long start_seq;
	unsigned long max_nr;
	unsigned long count_val;
	} colliez;

unsigned long odd(unsigned long x);
unsigned long even(unsigned long x);
colliez calculate(unsigned long u_limit_in);
void colliez_processor(unsigned long cua, unsigned long lower_limit);

#ifdef __cplusplus
}
#endif

#endif
