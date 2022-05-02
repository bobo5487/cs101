#include<stdio.h>

int my_strlen(char* s){
	int n = 0;
	while(*(s+n) != '\0')n++;
	return n;
} 

int rec_strlen(char* s){
	if (*s == '\0')return 0;
	else return 1+rec_strlen(s+1);
}

char* my_sort(char* s){
	int j, k, temp;
	for(j=0; *(s+j) != '\0'; j++){
		for(k=j; *(s+k) != '\0'; k++){
			if (*(s+j) > *(s+k)){
				temp = *(s+j);
				*(s+j) = *(s+k);
				*(s+k) = temp;
			}
		}
	}
	return s;
}

int main(){
	char s[] = "IU is a girl!";
	printf("len = %d", my_strlen(s));
	printf("len = %d", rec_strlen(s));
	printf("sort = %s", my_sort(s));
	return 0;
}
