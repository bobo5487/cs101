#include <stdio.h>

#include <stdlib.h>

#include <time.h>



int main()

{



    time_t curtime;

	time(&curtime);



FILE*fp;



    fp = fopen("report.txt", "w+");



	fprintf(fp, "======== lotto649 Report ========\n");

	

	fprintf(fp, "- Date ------ Num. ------ Receipt -\n");

	

	char szbuff[32];

    time_t now = time(0);

    strftime(szbuff, 100, "%Y%m%d-%H:%M:%S", localtime(&now));

    fprintf("%s\n\t", szbuff);

    

    int num , num_set ;



    fprintf("%d %d\n", num, num_set);

    

	scanf("%2d", num);

	

	fprintf("%2d*25", num);





	fprintf(fp, "= %.*s Printed = ", 24,ctime(&curtime));

	

	fclose(fp);

	

	return 0;

}

