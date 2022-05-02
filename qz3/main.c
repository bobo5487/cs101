#include <stdio.h>

void rec_dec(char *s) {
	if(*s == '\0') {
		printf("\n");
		return;}
	printf("%c,", *s);
	rec_dec(++s);
}

FILE* fp;
void count(int n, char A, char B, char C) {
	if (n == 1) {
		fprintf(fp, "Move disk %d form %c to %c\n", n, A, C);
	} else {
		count(n - 1, A, C, B);
		fprintf(fp, "Move disk %d form %c to %c\n", n, A, C);
		count(n - 1, B, A, C);
	}
}
void hanoi_tower(int n) {
	fp = fopen("hanoi.txt", "w+");
	count(n, 'A', 'B', 'C');
	fclose(fp);
}

int multiplication(int i, int j) {
	if(i == 10) {
		return 0;
	} else if(j == 9) {
		printf("%d*%d=%d \n", i, j, i*j);
		multiplication(i+1, 1);
	} else {
		printf("%d*%d=%d ", i, j, i*j);
		multiplication(i, j+1);
	}
}

int main(void) {
	char s[] = "1234567890";
	rec_dec(s);
	printf("func#1-----------------------\n");
	hanoi_tower(16);
	printf("func#2-----------------------\n");
	multiplication(1, 1);
	printf("func#3-----------------------\n");
	return 0;
}
