/*
 * Assessment 8/06  Linschoten 65ft
 * calculates collatz up to limit of 10^6 on standard desktop pc
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define MAX_ARRAY 1000000
/// @brief basically a  optimized version using linked list as opposed to the array calc_unit.


typedef struct table_seq_length{
	uint64_t input_limit;
	uint64_t sequence_length;
} calc_unit;

typedef struct colli{
	struct colli *previous;
	struct colli *next;
	uint64_t val;
	} colliez;

calc_unit allresult[MAX_ARRAY];

uint64_t odd(uint64_t x){
	return x*3 + 1;
}

uint64_t even(uint64_t x){
	return x/2;
}

/*
 *Iterative process until sequence converges to 1 .
 *
 */

uint64_t calculate(uint64_t u_limit_in) {
	//upper limit iteratively 
	uint64_t xn = u_limit_in;
	uint64_t s_length_counter = 0;
	uint64_t max_nr = 0;
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
	return s_length_counter;
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
     uint64_t xn, raw_calc;
     colliez *work_list_head;

     // first process input

     printf("\n");
     if (argc != 2) {
     	printf("Enter the value of the upper limit : ");
     	scanf("%s", in_limit);
		printf("%s \n", in_limit);
		int dud = atoi(in_limit);
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
		int dud = atoi(argv[1]);
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
     printf("empirically guessed lower limit : %lu \n", lower_limit);
     uint64_t x = 0;
     // populate array to hold sequence length counter for every possible value lower than input
	 if (cmd_user_arg1>0) {
		printf("if");
		//just to be safe include integer on limit of empiric approximation.
     	while (x<=empiric_batch_size_int) {
			uint64_t counter_res = cmd_user_arg1 - x;
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
		if(len_temp < allresult[j].sequence_length){
			printf("sequence length : %lu \n", allresult[j].sequence_length);
			len_temp = allresult[j].sequence_length;
		}
	 }
	 printf("Finished. Longest sequence is : %lu", len_temp);
     
     return 0;
// <----->
}
