#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	FILE* fp;
	FILE* fp_count;
	int n, i, j, k, temp;
	int num[5][7];
	int count[] = {1};

//read for execution times
	if((fp_count = fopen("lotto_count.bin", "rb")) != NULL) {
		fread(count, sizeof(int), 1, fp_count);
		fclose(fp_count);
	} else {
		fp_count = fopen("lotto_count.bin", "wb+");
		fwrite(count, sizeof(int), 1, fp_count);
		fclose(fp_count);
	}

	printf("歡迎光臨長庚樂透彩購買機台\n請問您要買幾組樂透彩 : ");
	scanf("%d", &n);

//change file title
	char buffer_title[32];
	snprintf(buffer_title, sizeof(char) * 32, "lotto[0000%i].txt", count[0]);
	fp = fopen(buffer_title, "wb");
	fprintf(fp, "========= lotto649 =========\n");
	fprintf(fp, "========+ No.%05d +========\n", count[0]);

//time
	time_t curtime;
	struct tm *info;
	char buffer[80];
	time(&curtime);
	info = localtime(&curtime);
	strftime(buffer, 80, "%a %b %d %X %Y", info);
	fprintf(fp, "= %s =\n", buffer);
//random number
	for(i = 0; i < 5; i++) {
		for(j = 0; j < 6; j++) {
			num[i][j] = rand() % 69 + 1;
		}
	//bubble sort
		for(j = 0; j < 6; j++) {
			for(k = 0; k < 5 - j; k++) {
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
		num[i][6] = rand() % 10 + 1;
		for(j = 0; j < 6; j++) {
			if(i >= n) {
				fprintf(fp, "-- ");
			} else if(num[i][j] < 10) {
				fprintf(fp, "0%d ", num[i][j]);
			} else {
				fprintf(fp, "%d ", num[i][j]);
			}
			if(num[i][6] == num[i][j]) {
				num[i][6] = rand() % 10 + 1;
			}
		}
//special number
		if(i >= n) {
			fprintf(fp, "--\n");
		} else if(num[i][6] == 10) {
			fprintf(fp, "%d\n", num[i][6]);
		} else {
			fprintf(fp, "0%d\n", num[i][6]);
		}
	}

	fprintf(fp, "========= csie@CGU =========\n");
	fclose(fp);
	printf("已為您購買的 %d 組樂透彩組合輸出至 lotto.txt\n", n);
	
//finish lotto.txt, so count for execution add 1
	count[0]++;
	fp_count = fopen("lotto_count.bin", "wb+");
	fwrite(count, sizeof(int), 1, fp_count);
	fclose(fp_count);

	return 0;
}
