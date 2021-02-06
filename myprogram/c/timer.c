#include <stdio.h>
#include <time.h>
#include <fcntl.h>
#include <stdlib.h>

#define FILENAME "/tmp/dafd.status"

int getdadstatus()
{
	int i;
	FILE *fp = fopen(FILENAME,"r");
	if(fp == NULL) {
			perror("open fail");
			return -1;
	}
	fscanf(fp,"%d",&i);
	printf("i = %d\n",i);
	fclose(fp);

	return i;
}
void * funct(void*arg)
{
	int n =0;
	while(1) {
	printf("inside the thread \n");

	n = getdadstatus();
	switch (n) {
	case 128:
		printf(" do some setting for QOS \n");
			  break;
	default:
		printf("revert some setting for QOS \n");
			  return ;
	}
		
	sleep(5);
	}

}

int main()
{
	pthread_t ptid;
	system("cat file.txt > /tmp/dafd.status");

	pthread_create(&ptid, NULL, funct, NULL);
	
	
	pthread_join(ptid,NULL);

}
