/*
 * Assessment 14/06  
 * calculates collatz up to limit of 10^6 on standard desktop pc
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include "calculate.h"

#define MAX_ARRAY 80000000

typedef struct table_seq_length{
	uint64_t input_limit;
	uint64_t sequence_length;
} calc_unit;

calc_unit allresult[MAX_ARRAY];

uint64_t odd(uint64_t x){
	return x*3 + 1;
}

uint64_t even(uint64_t x){
	return x/2;
}

/*
 *Iterative process until sequence resolves or until 200 000 steps are reached.
 * 
 */

uint64_t calculate(uint64_t u_limit_in) {
	//upper limit iteratively 
	uint64_t xn = u_limit_in;
	uint64_t s_length_counter = 0;
	while (xn != 1)
	{
		if (xn % 2 == 0){
			xn = even(xn);
		}
          	else{
			xn = odd(xn);
		}
		s_length_counter++;
    }

	return s_length_counter;
}

int main(int argc, char *argv[])
{
     int a, n;
     char in_limit[ 20 ];
     uint64_t in_limit_data;
     char *in_ptr;
     char ns[ 20 ];
     uint64_t xn, raw_calc;

     // process input

     printf("\n");
     if (argc != 2) {
     	printf("Enter the value of the upper limit : ");
     	scanf("%s", in_limit);
		printf("%s \n", in_limit);
		int dud = atoi(in_limit);
		in_limit_data = (uint64_t)dud;
		fflush(stdin);
	}else{
		// commandline arguments present
		printf("%15s", argv[1]);
		int dud = atoi(argv[1]);
		in_limit_data = (uint64_t)dud;
     }
     fflush(stdin);
     
     uint64_t param1;
     param1 = (uint64_t) in_limit_data;
     // 40% of input value. Used to calculate the test range for longest sequence length.
     float empiric_batch_size;
     empiric_batch_size = param1*0.40;
     uint64_t empiric_batch_size_int = round(empiric_batch_size);
     uint64_t lower_limit = param1 - empiric_batch_size;
     printf("empirical guess at lowest value : %lu \n", lower_limit);
     uint64_t x = 0;
     // populate array to hold sequence length counter for every possible value lower than input
	 if (param1>0) {
		printf("if");
		//just to be safe include integer (<=) on limit of empiric approximation.
     	while (x<=empiric_batch_size_int) {
			uint64_t counter_res = param1 - x;
     		raw_calc = calculate(counter_res);
			calc_unit add_me = { counter_res, raw_calc};
			allresult[x] = add_me;
			x++;
     	}
		printf("x:  %lu ", x);
     }
     printf("---");
	 // sort array according to sequence_length
	 uint64_t len_temp = 0;
	 int j;
	 for (j=0; j<empiric_batch_size_int; j++) {
		//printf(" j : %d", j);
		//printf(" j : %lu", allresult[j].sequence_length);
		if(len_temp < allresult[j].sequence_length){
			//printf("len_temp: %lu \n", len_temp);
			printf("sequence length : %lu \n", allresult[j].sequence_length);
			len_temp = allresult[j].sequence_length;
		}
	 }
	 printf("Finished. Longest sequence is : %lu", len_temp);
     
     return 0;
}
