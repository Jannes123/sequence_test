/*
 * Assessment 8/06  Linschoten 65ft
 * calculates collatz up to limit of 10^6 on standard desktop pc
 * 
 * optionally increase stack size on linux
 * ulimit -t 300 -l 4086688 -s 81920
 */
#include "calculate.h"

uint64_t odd(uint64_t x){
	return x*3 + 1;
}

uint64_t even(uint64_t x){
	return x/2;
}

/*
 * Iterative process until sequence converges to 1.
 */
colliez* calculate(uint64_t u_limit_in) {
	//keep track of biggest number and sequence counter
	uint64_t xn = u_limit_in;
	uint64_t s_length_counter = 0;
	uint64_t max_nr = 0;
	colliez *computed_data_ptr = malloc(sizeof(colliez)+1);
	while (xn != 1) {
		if (xn % 2 == 0) {
			//printf("%lu \t \t even ", xn);
			xn = even(xn);
		}
        else{
			//printf("%lu \t \t odd \n ", xn);
			xn = odd(xn);
			if (xn>=max_nr) {
				max_nr = xn;
			}
		}
		s_length_counter++;
    }
	//printf("%lu --- end \n \n", xn);
	printf("%lu  max \n", max_nr);
	
	if (computed_data_ptr!=NULL) {
		printf("oops");
	}
	printf("OK");
	colliez s_computed_data = {u_limit_in, max_nr, s_length_counter};
	computed_data_ptr = &s_computed_data;
	return computed_data_ptr;
}


/*
 * Commandline application called with one argument
 * eg ./Colliez 3
 */
int main(int argc, char *argv[])
{
     int a, n;
     char in_limit[ 20 ];
     uint64_t in_limit_data;
     char *in_ptr;
     char ns[ 20 ];
     uint64_t xn;
	 colliez * raw_calc;
     // first process input

     printf("\n");
     if (argc != 2) {
     	printf("Enter the value of the upper limit : ");
     	scanf("%s", in_limit);
		printf("%s \n", in_limit);
		long dud = atoi(in_limit);
		in_limit_data = (uint64_t)dud;
		printf("Enter the max iteration limit : ");
		fflush(stdin);
		scanf("%s \n", ns);
		printf("%s \n", ns);
		printf("\n");
		dud = atoi(ns);
		uint64_t max_iterations = (uint64_t) dud;
		scanf("%s \n", ns);
	}else{
		// commandline arguments present
		printf("%15s", argv[1]);
		long dud = atoi(argv[1]);
		in_limit_data = (uint64_t)dud;
     }
     fflush(stdin);
     
     uint64_t cmd_user_arg1;
     cmd_user_arg1 = (uint64_t) in_limit_data;
     // 40% of input value. Used to calculate the test range for longest sequence length.
     float empiric_batch_size;
     empiric_batch_size = cmd_user_arg1*0.40;
     uint64_t empiric_batch_size_int = round(empiric_batch_size);
     uint64_t lower_limit = cmd_user_arg1 - empiric_batch_size;
     printf("empirical guess of lower limit with longest seqence chain : %lu \n", lower_limit);
     uint64_t x = 0;
     // populate array to hold sequence length counter for every possible value lower than input
	 if (cmd_user_arg1>0) {
		printf("if");
		uint64_t new_val = 0;
		uint64_t old_val = 0;
		//just to be safe include one more integer on limit of empiric approximation.
		uint64_t counter_res;
     	while (x<=empiric_batch_size_int) {
			counter_res = cmd_user_arg1 - x;
			if (raw_calc!=NULL) {
				free(raw_calc);
				}
     		raw_calc = calculate(counter_res);
			// compare results and keep longest
			new_val = raw_calc->count_val;
			uint64_t largest_start_sequence;
			if (new_val>old_val){
				old_val = new_val;
				largest_start_sequence = raw_calc->start_seq;
				//keep track of ptr to resulting struct
			}
			x++;
     	}
		printf("x:  %lu ", new_val);
		printf("x:  %lu ", x);
     }
     printf("---");
	 // sort array according to sequence_length
	 printf("Finished. Longest sequence is : %lu", raw_calc->start_seq);
     
     return 0;
// <----->
}
