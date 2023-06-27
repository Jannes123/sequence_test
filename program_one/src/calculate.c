/*
 * Assessment  Linschoten 65ft
 * calculates collatz up to limit of 10^6 on standard desktop pc
 * 
 * optionally increase stack size on linux
 * ulimit -t 300 -l 4086688 -s 81920
 */
#include "calculate.h"

unsigned long odd(unsigned long x){
	return x*3 + 1;
}

unsigned long even(unsigned long x){
	return x/2;
}

/*
 * Iterative process until sequence converges to 1.
 */
colliez calculate(unsigned long u_limit_in) {
	// keep track of biggest number and sequence counter
	unsigned long xn = u_limit_in;
	unsigned long s_length_counter = 0;
	unsigned long max_nr = 0;
	colliez computed_data = {0, 0, 0};
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
	computed_data.start_seq = u_limit_in;
	computed_data.max_nr = max_nr;
	computed_data.count_val = s_length_counter;
	return computed_data;
}

void colliez_processor(unsigned long cua, unsigned long lower_limit){
	colliez raw_calc = {0, 0, 0};
	unsigned long x = 0;
	// run through inputs high-low
	if (cua>0) {
		colliez final = {0, 0, 0};
		unsigned long largest_start_sequence;
		unsigned long new_val = 0;
		unsigned long old_val = 0;
		//just to be safe include one more integer on limit of empiric approximation.
		unsigned long counter_res;
		int x = 0;
     		while (x<=lower_limit) {
			counter_res = cua - x;
     		raw_calc = calculate(counter_res);
			new_val = raw_calc.count_val;
			if (new_val>old_val) {
				old_val = new_val;
				largest_start_sequence = raw_calc.start_seq;
				//keep track of ptr to resulting struct
				final = raw_calc;
				//raw_calc= NULL;
				//raw_calc = {0, 0, 0};
			}
			x++;
     		}
		printf("largest value in sequence :  %lu \n", final.max_nr);
		printf("start :  %lu \n", final.start_seq);
		printf("steps :  %lu \n", final.count_val);
		printf("\nFinished. \nLongest sequence is : %lu \n \n", final.count_val);
     	} else {
		printf("\nZero input does not compute any steps\n");
	}

}

/*
 * Commandline application called with one argument
 * eg ./Colliez 3
 */

int main(int argc, char *argv[])
{
	char in_limit[ 20 ];
	unsigned long in_limit_data;
	colliez *raw_calc;
	raw_calc = NULL;
	// first process user input
	if (argc != 2) {
		printf("\n Enter the value of the upper limit : ");
		scanf("%s", in_limit);
		printf("\n %s \n", in_limit);
		long dud = atoi(in_limit);
		in_limit_data = (unsigned long)dud;
		fflush(stdin);
		printf("\n");
	}else{
		long dud = atoi(argv[1]);
		in_limit_data = (unsigned long)dud;
	}
	unsigned long cmd_user_arg1 = (unsigned long) in_limit_data;
	// 40% of input value. Used to calculate the test range for longest sequence length.
	float empiric_batch_size = cmd_user_arg1*0.40;
	unsigned long empiric_batch_size_int = round(empiric_batch_size);
	unsigned long lower_limit = cmd_user_arg1 - empiric_batch_size;
	printf("Calculating Collatz: \n");
	printf("---");
	printf("\n empirical guess of lower limit with longest sequence chain : %lu \n", lower_limit);
	// run through inputs high-low
	if (cmd_user_arg1>0) {
		colliez_processor(cmd_user_arg1, empiric_batch_size_int);
    	} else {
		printf("\nZero input does not compute any steps\n");
	}
	return 0;
}
