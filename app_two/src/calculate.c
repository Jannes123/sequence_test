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
	colliez *computed_data_ptr = malloc(sizeof(colliez));
	while (xn != 1) {
		if (xn % 2 == 0) {
			xn = even(xn);
		}
        else{
			xn = odd(xn);
			if (xn>=max_nr) {
				max_nr = xn;
			}
		}
		s_length_counter++;
    }
	if (computed_data_ptr==NULL) {
		printf("null ptr");
	}
	computed_data_ptr->start_seq = u_limit_in;
	computed_data_ptr->max_nr = max_nr;
	computed_data_ptr->count_val = s_length_counter;
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
     char ns[ 20 ];
     uint64_t xn;
	 colliez *raw_calc;
	 raw_calc = NULL;

     // first process user input
     if (argc != 2) {
     	printf("\n Enter the value of the upper limit : ");
     	scanf("%s", in_limit);
		printf("\n %s \n", in_limit);
		long dud = atoi(in_limit);
		in_limit_data = (uint64_t)dud;
		fflush(stdin);
		printf("\n");
	}else{
		long dud = atoi(argv[1]);
		in_limit_data = (uint64_t)dud;
     }
     
     uint64_t cmd_user_arg1 = (uint64_t) in_limit_data;
     // 40% of input value. Used to calculate the test range for longest sequence length.
     float empiric_batch_size = cmd_user_arg1*0.40;
     uint64_t empiric_batch_size_int = round(empiric_batch_size);
     uint64_t lower_limit = cmd_user_arg1 - empiric_batch_size;
	 printf("Calculating Collatz: \n");
	 printf("---");
     printf("\nempirical guess of lower limit with longest sequence chain : %lu \n", lower_limit);
     uint64_t x = 0;
     // run through inputs high-low
	 if (cmd_user_arg1>0) {
		colliez *final = malloc(sizeof(colliez));
		uint64_t largest_start_sequence;
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
			new_val = raw_calc->count_val;
			if (new_val>old_val) {
				old_val = new_val;
				largest_start_sequence = raw_calc->start_seq;
				//keep track of ptr to resulting struct
				final = raw_calc;
				raw_calc = NULL;
			}
			x++;
     	}
		printf("largest value in sequence :  %lu \n", final->max_nr);
		printf("start :  %lu \n", final->start_seq);
		printf("steps :  %lu \n", final->count_val);
		printf("\nFinished. \nLongest sequence is : %lu \n \n", final->count_val);
     }	 
     return 0;
}
