#include <stdio.h>

#include <stdlib.h>

#include <string.h>





int* get_int_array(int n){

	return(int*)calloc(n, sizeof(int));

} 



void set_value(int*p, int v){

	*p = v;

}



void print_array(int* p, int n){

	for(int i=0;i<n;i++){

		printf(" %d, ", *p+i);

	}

}



char *func(char *str1, char *str2){

	int length = strlen(str1)+strlen(str2)+1;

	char *z = (char*) malloc(sizeof(char)*length);

	strcpy(z, str1);

	strcat(z, str2);

	return z;

}





int main(){

	int n=10;

	int* ip = get_int_array(n);

	

	for(int i=0;i<n;i++) {

		set_value(ip+i, i+1);

	}

	printf("No.1----------------\n");

	printf("[");

	print_array(ip,n);

	printf("]\n");

	printf("No.2----------------\n");

	printf("[");

	print_array(ip,n+10);

	printf("]\n");

	printf("No.3----------------\n");

	char a[]="IU!IU!";

	char b[]="@CGU";

	char *c = func(a,b);

	printf("add_str_func = %s \n", c);

	return 0;

} 
