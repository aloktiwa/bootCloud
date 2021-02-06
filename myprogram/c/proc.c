#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *prot;
	char addr[14];
	char buf[2048];
	FILE *fp;
	int i = 0; 
	prot = buf;
//	prot = (char *)malloc(sizeof(char *));
	if(prot == NULL || prot >= 0xdeadbeef) {
		printf("%.8x mem error \n",prot);
		exit(0);
	}

	printf("\n enter the protocol for test\n");
	scanf(" %s",prot);
	printf("\n enter the addr::");
	scanf(" %s",addr);

	fp =fopen("/proc/tx_info","w");
	if(fp == NULL)
	{
		printf("\n unable to write on /proc/tx_info \n");
		exit(0);
	}
	fprintf(fp,"%s ",prot);
	while(addr[i] != '\0')
	{
		fprintf(fp,"%c",addr[i]);
		i++;
	}
	fclose(fp);

}
