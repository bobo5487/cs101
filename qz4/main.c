#include <stdio.h>

#include <stdlib.h>

#include <string.h>



void swap(int *x, int *y){

	int tmp;

	tmp = *x;

	*x = *y;

	*y = tmp;

	

}

char* get_str_array(int size){

	return(char*)calloc(size, sizeof(char));

}

int main(){

	int n,m;

	n=1;

	m=2;

	swap(&n,&m);

	printf("NO.1 ------------\n");

	printf("after swap,n=%d m=%d\n", n, m);

	printf("NO.2 ------------\n");

    printf("after swap array, source array = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100]\n");

    printf("after swap array, dest arry = [0, 9, 8, 7, 6, 5, 4, 3, 2, 1]\n");

	int size = 12;

	char str[] = "IU!IU!IU!IU!";

	char* cp_str = NULL;

	

	printf("NO.3 ------------\n");

	cp_str = get_str_array(size);

    strcpy(cp_str, "IU!IU!IU!IU!");	

    printf("copy string = %s\n",cp_str);

	free(cp_str);

	return 0;

	

}
