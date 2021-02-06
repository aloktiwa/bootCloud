#include <sys/mman.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int fd = open("/dev/null", O_RDWR);
	int *pte = (int *)mmap(0, 20*sizeof(int), PROT_READ|PROT_WRITE, MAP_PRIVATE, fd, 0);
	close(fd);
	if(pte == NULL) { perror("mem failed \n");return -1; }
	for(int i=0;i<20;i++) {
//		pte[i] = i+ 10;
		printf("%d \t",pte[i]);
	}

}
