#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{

 FILE *fp;
	fp = fopen("lotto.txt","w+");
	
	printf("歡迎光臨長庚樂透彩機台\n");

	int num, i, n, j, k, o, Y;
	num = 0, k = 1, Y = 1;

	time_t curtime;
	time(&curtime);
	printf("請問你要買幾組樂透彩: ");
	scanf("%d", &num);
	fprintf(fp,"%s", ctime(&curtime));

	printf("已為您購買的%d組樂透組合輸出至lotto.txt");

	srand((unsigned) time(NULL));
	for (o = 1 ; o <= 5 ; o++){
		if (o <= num){
		fprintf(fp,"\n[%d]: ",o);
		for (i = 0 ; i < 6 ; i++ ){
		fprintf(fp,"%2d ", rand() % 70 );
		}
		for (j = 0 ; j < 1 ; j++ ){
		fprintf(fp,"%2d\n ", rand() % 11 );
		}
	}else{
		fprintf(fp,"\n[%d]: ",o);
		fprintf(fp,"-- -- -- -- -- -- --\n");
	}
	}while(1);

   fclose(fp);
   
	return 0;
}
