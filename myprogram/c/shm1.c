#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/mman.h>
#define PAGESIZE 4096
main()
{
  int          fd, i;
  char         *addr, c;

  /* Open physical memory */
  fd = shm_open("Physical", O_RDWR, 0777);
  if (fd == -1) {
    fprintf(stderr, "Open failed:%s\n", strerror(errno));
    exit(1);
  }

  /* Map BIOS ROM */
  addr = mmap(0, PAGESIZE, PROT_READ | PROT_WRITE,
               MAP_SHARED, fd, 0xf0000);
  if (addr == (void *) -1) {
    fprintf(stderr, "mmap failed : %s\n",
     strerror(errno));
    exit(1);
  }
  printf("Map addr is %6.6X\n", addr);

  for (i = 0; i < 3 * 80; ++i) {
     c = *addr++;
     if (c >= ' ' && c <= 0x7f)
       putchar(c);
     else
       putchar('.');
  }

  exit(0);
}


