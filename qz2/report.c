#include<stdio.h>
#include<stdlib.h> 
#include<time.h>
#include <string.h>

FILE* reportFile;
FILE* openRecords;
static char date[32];


typedef struct lottoRecord{
	int lotto_no;//= currentCount
	int lotto_receipt;//= i *55
	int emp_id;//= id
	char lotto_date[32];//= date
	char lotto_time[32];//= Time
}lotto_record_t; 

void cutTheTime(){ //cut the time to date&time
	time_t now = time(0);
	strftime(date, 100, "%Y%m%d", localtime(&now));
	//strftime(Time, 100, "%H:%M:%S", localtime(&now));
}


int main(){
	
	reportFile = fopen("reportFile.txt", "w+");
	openRecords = fopen("salesRecordFile.bin", "r");
	
	lotto_record_t tmp[256];
	int i = 0;
	while(fread(&tmp[i], sizeof(lotto_record_t), 1, openRecords)){
		//printf("%d\t%d\t%d\t%s\n", tmp[i].lotto_no, tmp[i].lotto_receipt, tmp[i].emp_id, tmp[i].lotto_date);
		i++;
	}	
	i--;

	int no = 0; // = lotto_no = currentCount = i
	int dateSum = 0, noSum, setsSum = 0, receiptSum = 0;
	int j = 0;
	
	fprintf(reportFile,"========= lotto649 Report =========\n");
	fprintf(reportFile,"- Date ------- Num. ------ Receipt -\n");
	
	while(j<=i){
		int sets = 0; // lotto_receipt/55
		int receipt = 0; // =lotto_receipt
		while(strcmp(tmp[j].lotto_date,tmp[j+1].lotto_date) == 0){
			sets = sets + (tmp[j].lotto_receipt/55);
			receipt = receipt + tmp[j].lotto_receipt;
			j++;
		}
		sets = sets + (tmp[j].lotto_receipt/55);
		receipt = receipt + tmp[j].lotto_receipt;
		no = tmp[j].lotto_no - no;
		dateSum ++;
		printf("%d",no);
		setsSum = setsSum + sets;
		receiptSum = receiptSum + receipt;
		fprintf(reportFile, "%s\t%d/%d\t\t%d\n", tmp[j].lotto_date, no, sets, receipt);
		no = tmp[j].lotto_no;
		j++;
	}
	
	fprintf(reportFile,"-----------------------------------\n");
	fprintf(reportFile,"\t%d\t%d/%d\t\t%d\n", dateSum, tmp[i].lotto_no, setsSum, receiptSum);
	cutTheTime();
	fprintf(reportFile,"======== %s Printed =========", date);
	
	
	fclose(reportFile);
	fclose(openRecords);		
}
