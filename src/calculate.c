/*
 * Assessment 8/06  Linschoten 65ft
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>


typedef struct colli{
	struct colli *previous;
	struct colli *next;
	uint64_t val;
	} colliez;

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
	
	while (xn != 1)
	{
		if (xn % 2 == 0){
			printf("%lu \t \t even ", xn);
			xn = even(xn);
		}
          	else{
			printf("%lu \t \t odd \n ", xn);
			xn = odd(xn);
		}
     	}
	printf("%lu /t end", xn);
	return xn;
}


/*
 * Commandline application called with one argument
 *Colliez 3
 */
int main(int argc, char *argv[])
{
     int a, n;
     char in_limit[ 20 ];
     uint64_t in_limit_data;
     char *in_ptr;
     char ns[ 20 ];
     uint64_t xn, raw_calc;
     colliez work_list;

     // first process input
     printf("len of input %d \n", argc);
     printf("sizeof input 0 %lu \n", sizeof(argv[0]));

     printf("sizeof input 1 %lu \n", sizeof(argv[1]));
     
     printf("argv[0] : %12s \n", argv[0]);
     printf("argv[1] : %12s \n", argv[1]);
     printf("argv[2] : %12s \n", argv[2]);

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

     }else if (argc == 1) {
	printf("No arguments specified. Enter the value of the upper limit : ");
	scanf("*%15d", &a);
	printf("%15d", a);
     }else{
	printf("%15s", argv[1]);
	int dud = atoi(argv[1]);
	in_limit_data = (uint64_t)dud;
     }
     fflush(stdin);
     // do calc and print result
     uint64_t param1;
     param1 = (uint64_t) in_limit_data;
     if (param1!=0 && param1!=NULL) {
     	raw_calc = calculate(param1);
     }
     printf("Result for longest sequence: ");
     
     return 0;
}
