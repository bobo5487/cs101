#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct lotto_record {
	int lotto_no;
	int lotto_receipt;
	int emp_id;
	char lotto_date[32];
	char lotto_time[32];
} lotto_record_t;

typedef struct emp_record {
	int emp_id;
	char emp_name[20];
	int emp_salary;
} emp_record_t;

int main(void) {
	FILE* fp;
	FILE* fp_count;
	FILE* fp_operator;
	FILE* fp_record;
	int n, i, j, k, temp;
	int num[5][7];
	int count[] = {1};
	int operator_id[1];

	printf("歡迎光臨長庚樂透彩購買機台\n");

	printf("請輸入操作人員ID (0-5): ");
	scanf("%d", &operator_id[0]);
	fp_operator = fopen("operator_id_old.bin", "wb+");
	fwrite(operator_id, sizeof(int), 1, fp_operator);
	fclose(fp_operator);

	if(operator_id[0] != 0) {

		if((fp_count = fopen("lotto_count.bin", "rb")) != NULL) {
			fread(count, sizeof(int), 1, fp_count);
			fclose(fp_count);
		} else {
			fp_count = fopen("lotto_count.bin", "wb+");
			fwrite(count, sizeof(int), 1, fp_count);
			fclose(fp_count);
		}
		printf("請問您要買幾組樂透彩 : ");
		scanf("%d", &n);

		char buffer_title[32];
		snprintf(buffer_title, sizeof(char) * 32, "lotto[0000%i].txt", count[0]);
		fp = fopen(buffer_title, "wb");
		fprintf(fp, "========= lotto649 =========\n");
		fprintf(fp, "========+ No.%05d +========\n", count[0]);

		time_t curtime;
		struct tm *info;
		char buffer[80];
		time(&curtime);
		info = localtime(&curtime);
		strftime(buffer, 80, "%a %b %d %X %Y", info);
		fprintf(fp, "= %s =\n", buffer);

		for(i = 0; i < 5; i++) {
			for(j = 0; j < 6; j++) {
				num[i][j] = rand() % 69 + 1;
			}
		
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

			if(i >= n) {
				fprintf(fp, "--\n");
			} else if(num[i][6] == 10) {
				fprintf(fp, "%d\n", num[i][6]);
			} else {
				fprintf(fp, "0%d\n", num[i][6]);
			}
		}

		fprintf(fp, "========* Op.");
		fp_operator = fopen("operator_id_old.bin", "rb");
		fread(operator_id, sizeof(int), 1, fp_operator);
		fclose(fp_operator);
		fprintf(fp, "%05d", operator_id[0]);
		fprintf(fp, " *========\n");
		fprintf(fp, "========= csie@CGU =========\n");
		fclose(fp);
		printf("已為您購買的 %d 組樂透彩組合輸出至 lotto.txt\n", n);

		count[0]++;
		fp_count = fopen("lotto_count.bin", "wb+");
		fwrite(count, sizeof(int), 1, fp_count);
		fclose(fp_count);

		lotto_record_t record[1];
		record[0].lotto_no = count[0] - 1;
		record[0].lotto_receipt = n * 50 * 1.1;
		record[0].emp_id = operator_id[0];
		
		strftime(record[0].lotto_date, 32, "%b %d %Y", info);
		strftime(record[0].lotto_time, 32, "%X", info);
		fp_record = fopen("records.bin", "ab");
		fwrite(record, sizeof(lotto_record_t), 1, fp_record);
		fclose(fp_record);	
	} else {

		emp_record_t emp_new[1];
		printf("請輸入要新增操作人員 ID (1-99) : ");
		scanf("%d", &emp_new[0].emp_id);
		printf("請輸入要新增操作人員 Name : ");
		scanf("%s", &emp_new[0].emp_name);
		printf("請輸入要新增操作人員 Salary : ");
		scanf("%d", &emp_new[0].emp_salary);
		fp_operator = fopen("operator_id.bin", "ab");
		fwrite(emp_new, sizeof(emp_record_t), 1, fp_operator);
		fclose(fp_operator);
		printf("輸入完成\n");
	}
	
	return 0;
}
