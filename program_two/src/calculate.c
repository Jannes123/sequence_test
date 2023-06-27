/*
 * Assessment
 * calculates collatz up to limit of 10^6 on standard desktop pc
 */
#include "calculate.h"

#define MAX_ARRAY 80000000

typedef struct table_seq_length{
	unsigned long input_limit;
	unsigned long sequence_length;
} calc_unit;

calc_unit allresult[MAX_ARRAY];

unsigned long odd(unsigned long x){
	return x*3 + 1;
}

unsigned long even(unsigned long x){
	return x/2;
}

/*
 *Iterative process until sequence resolves or until 200 000 steps are reached.
 * 
 */

unsigned long calculate(unsigned long u_limit_in) {
	//upper limit iteratively 
	unsigned long xn = u_limit_in;
	unsigned long s_length_counter = 0;
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
     unsigned long in_limit_data;
     char *in_ptr;
     char ns[ 20 ];
     unsigned long xn, raw_calc;

     // process input

     printf("\n");
     if (argc != 2) {
     	printf("Enter the value of the upper limit : ");
     	scanf("%s", in_limit);
		//printf("%s \n", in_limit);
		int dud = atoi(in_limit);
		in_limit_data = (unsigned long)dud;
		fflush(stdin);
	}else{
		// commandline arguments present
		//printf("%15s \n", argv[1]);
		int dud = atoi(argv[1]);
		in_limit_data = (unsigned long)dud;
     }
     fflush(stdin);
     
     unsigned long param1;
     param1 = (unsigned long) in_limit_data;
     // 40% of input value. Used to calculate the test range for longest sequence length.
     float empiric_batch_size;
     empiric_batch_size = param1*0.40;
     unsigned long empiric_batch_size_int = round(empiric_batch_size);
     unsigned long lower_limit = param1 - empiric_batch_size;

	 printf("Calculating Collatz: \n");
	 printf("---");
     printf("\nempirical guess at lowest value : %lu \n", lower_limit);
     unsigned long x = 0;
     // populate array to hold sequence length counter for every possible value lower than input
	 if (param1>0) {
		//just to be safe include integer (<=) on limit of empiric approximation.
     	while (x<=empiric_batch_size_int) {
			unsigned long counter_res = param1 - x;
     		raw_calc = calculate(counter_res);
			calc_unit add_me = { counter_res, raw_calc};
			allresult[x] = add_me;
			x++;
     	}
     }
	 // sort array according to sequence_length
	 unsigned long len_temp = 0;
	 long j, final;
	 for (j=0; j<empiric_batch_size_int; j++) {
		//printf(" j : %d", j);
		//printf(" j : %lu", allresult[j].sequence_length);
		if(len_temp < allresult[j].sequence_length){
			//printf("len_temp: %lu \n", len_temp);
			//printf("sequence length : %lu \n", allresult[j].sequence_length);
			len_temp = allresult[j].sequence_length;
			final = j;
		}
	 }
	 printf("Answer: start value of longest sequence : %lu", allresult[final].input_limit);
	 printf("\nFinished. \nLongest sequence is : %lu steps.\n", len_temp);
     return 0;
}
