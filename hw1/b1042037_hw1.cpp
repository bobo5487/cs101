#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{

 FILE *fp;
	fp = fopen("lotto.txt","w+");
	
	printf("�w����{�����ֳz�m���x\n");

	int num, i, n, j, k, o, Y;
	num = 0, k = 1, Y = 1;

	time_t curtime;
	time(&curtime);
	printf("�аݧA�n�R�X�ռֳz�m: ");
	scanf("%d", &num);
	fprintf(fp,"%s", ctime(&curtime));

	printf("�w���z�ʶR��%d�ռֳz�զX��X��lotto.txt");

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
