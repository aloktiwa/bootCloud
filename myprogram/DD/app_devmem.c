#include <stdio.h>
#include <stdint.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>

#define SEG_ADD 0x43c00000
#define SEG_SIZE 0x1000
int main()
{
	int i;
	int fid = open("/dev/mem",O_RDWR);
	if(fid < 0)  {
		perror("open failed \n");
		fprintf(stderr,"open failed printf\n");
		return -1;
	}
	printf("page size %d %d \n",getpagesize(),sizeof(SEG_ADD));
	uint32_t *base_add = mmap(0,getpagesize(),PROT_READ| PROT_WRITE,MAP_SHARED,fid,SEG_ADD);
	if(base_add == MAP_FAILED) {
		perror("Map failed\n");
		exit(0);
	}

	for(i=0;i<4;i++) {
		printf("%d - %8x\n",i,base_add[i]);
	}
	char buff[100];
	printf(" enter a register and value \n");
	fflush(stdout);
	
}

