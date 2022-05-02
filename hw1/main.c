#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	FILE* fp;
	int n, i, j, k, temp;
	int num[5][6];
		
	printf("歡迎光臨長庚樂透彩購買機台\n請問您要買幾組樂透彩 : ");
	scanf("%d", &n);

	fp = fopen("lotto.txt", "w+");3
	time_t curtime;
	struct tm *info;
	char buffer[80];
	time(&curtime);
	info = localtime(&curtime);
	fprintf(fp, "========= lotto649 =========\n");
	strftime(buffer, 80, "%a %b %d %X %Y", info);
	fprintf(fp, "= %s =\n", buffer);
	for(i = 0; i < 5; i++) {
		for(j = 0; j < 5; j++) {
			num[i][j] = rand() % 69 + 1;
		}
		for(j = 0; j < 5; j++) {
			for(k = 0; k < 4 - j; k++) {
				if(num[i][k] > num[i][k + 1]) {
					temp = num[i][k];
					num[i][k] = num[i][k + 1];
					num[i][k + 1] = temp;
				}
			}
		}
	}
	for(i = 0; i < 5; i++) {
		fprintf(fp, "[%d]: ", i + 1);
		num[i][5] = rand() % 10 + 1;
		for(j = 0; j < 5; j++) {
			if(i >= n) {
				fprintf(fp, "-- ");
			} else if(num[i][j] < 10) {
				fprintf(fp, "0%d ", num[i][j]);
			} else {
				fprintf(fp, "%d ", num[i][j]);
			}
			if(num[i][5] == num[i][j]) {
				num[i][5] = rand() % 10 + 1;
			}
		}
		if(i >= n) {
			fprintf(fp, "--\n");
		} else if(num[i][5] == 10) {
			fprintf(fp, "%d\n", num[i][5]);
		} else {
			fprintf(fp, "0%d\n", num[i][5]);
		}
	}

	fprintf(fp, "========= csie@CGU =========\n");
	fclose(fp);
	printf("已為您購買的 %d 組樂透彩組合輸出至 lotto.txt", n);

	return 0;
}
