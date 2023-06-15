/*
 *
 * Assessment
 */

#ifndef _CALCULATE_H
#define _CALCULATE_H



#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

typedef struct colli{
	uint64_t start_seq;
	uint64_t max_nr;
	uint64_t count_val;
	} colliez;

uint64_t odd(uint64_t x);
uint64_t even(uint64_t x);
colliez * calculate(uint64_t u_limit_in);


#endif
