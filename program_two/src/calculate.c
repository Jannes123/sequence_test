/*
 *
 * calculates collatz up to limit of 10^6 on standard desktop pc
 * ./Collles 1000
 */
#include "calculate.h"
#include <limits.h>

#define JMAX_ARRAY 30000


bigtype max_array = JMAX_ARRAY;

struct Point{
	bigtype step_count;
	bigtype input_val;
	struct Point *nexty;
};

typedef struct Point my_point;

bigtype odd(bigtype x)
{
	return x * 3ULL + 1ULL;
}

bigtype even(bigtype x)
{
	return x / 2ULL;
}

/*
 *Iterative process until sequence resolves.
 */

bigtype calculate(bigtype u_limit_in, bigtype a_r[])
{
	// upper limit iteratively
	bigtype xn = u_limit_in;
	bigtype s_length_counter = 0ULL;
	while (xn != 1)
	{
		// save all series values and  steps calculated
		// check if previous calculated data matches
		// every xn has unique remaining series associated with it, stored in a_r .
		bigtype arxn = a_r[xn];
		printf("%lu . ", arxn);
		if (a_r[xn] != 0ULL)
		{
			bigtype z = a_r[xn] + s_length_counter;
			printf("\n--\n%lu \n", xn);
			printf("optimal \n");
			return z;
		}
		else
		{
			a_r[xn] = s_length_counter;
		}
		if (xn % 2 == 0)
		{
			xn = even(xn);
		}
		else
		{
			xn = odd(xn);
		}
		s_length_counter++;
	}
	return s_length_counter;
}

int main(int argc, char *argv[]) {
	char in_limit[20];
	long in_limit_data;
	long raw_calc;
	// process input
	printf("---%lu ---\n", max_array);
	printf("size of struct Point with two bigtype fields : %lu", sizeof(my_point));
	

	printf("\n");
	if (argc != 2) {
		printf("Enter the value of the upper limit : ");
		scanf("%s ", in_limit);
		long dud = atoi(in_limit);
		in_limit_data = (long)dud;
		fflush(stdin);
	}
	else {
		long dud = atoi(argv[1]);
		in_limit_data = (long)dud;
		fflush(stdin);
	}

	bigtype param1;
	param1 = (bigtype)in_limit_data;

	// 40% of input value. Used to calculate the test range for longest sequence.
	float empiric_batch_size;
	empiric_batch_size = param1 * 0.40;
	bigtype empiric_batch_size_int = (bigtype)round(empiric_batch_size);
	bigtype lower_limit = param1 - empiric_batch_size_int;

	printf("Calculating Collatz: \n");
	printf("---");
	printf("\nempirical guess at lowest value : %lu \n", lower_limit);

	bigtype allresult[max_array];
	//my_point *arr = (bigtype*)malloc(sizeof(my_point)*100000000ULL);
	my_point *starti = malloc(sizeof(my_point));
	my_point *endi = starti;
	if (param1 >= 1) {
		long ie;
		printf("\n---------------");
		printf("\n--Calculating--");

		bigtype x = 0ULL;
		bigtype counter_res = 0ULL;
		// calc and save to array
		while (x < empiric_batch_size_int) {
			printf("%lu ", x);
			counter_res = param1 - x;
			//do pointer thingy
			my_point *answer = malloc(sizeof(my_point));
			raw_calc = calculate(counter_res, allresult);
			allresult[x] = raw_calc;
			x++;
		}
		// results_pointer = NULL;
		// free(results_pointer);
	}
	bigtype len_temp = 0ULL;
	bigtype final;
	bigtype j;
	for (j = 0ULL; j < empiric_batch_size_int; j++) {
		if (len_temp < allresult[j]) {
			printf("sequence length : %lu \n", allresult[j]);
			len_temp = allresult[j];
			final = j;
		}
	}
	printf("Answer: start value of longest sequence : %lu", allresult[final]);
	printf("\nFinished. \nLongest sequence is : %lu steps.\n", len_temp);
	printf("\nMore info: \nMaksimum values of different base types: %lu\n", len_temp);
	
	printf("CHAR_BIT    :   %d\n", CHAR_BIT);
    printf("CHAR_MAX    :   %d\n", CHAR_MAX);
    printf("CHAR_MIN    :   %d\n", CHAR_MIN);
    printf("INT_MAX     :   %d\n", INT_MAX);
    printf("INT_MIN     :   %d\n", INT_MIN);
    printf("LONG_MAX    :   %ld\n", (long) LONG_MAX);
    printf("LONG_MIN    :   %ld\n", (long) LONG_MIN);
    printf("SCHAR_MAX   :   %d\n", SCHAR_MAX);
    printf("SCHAR_MIN   :   %d\n", SCHAR_MIN);
    printf("SHRT_MAX    :   %d\n", SHRT_MAX);
    printf("SHRT_MIN    :   %d\n", SHRT_MIN);
    printf("UCHAR_MAX   :   %d\n", UCHAR_MAX);
    printf("UINT_MAX    :   %u\n", (unsigned int) UINT_MAX);
    printf("ULONG_MAX   :   %lu\n", (long) ULONG_MAX);
    printf("USHRT_MAX   :   %d\n", (unsigned short) USHRT_MAX);

	return 0;
}
