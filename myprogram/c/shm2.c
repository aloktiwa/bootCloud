#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>

#define PAGESIZE 4096

main(int argc, char *argv[])
{
  int          fd;
  char         *addr;

  /*
   * In case the unlink code is
   * not executed at the end
   */
  if (argc != 1) {
     shm_unlink("bolts");
     exit(0);
  }

  /* Create a new memory object */
  fd = shm_open("bolts", O_RDWR | O_CREAT, 0777);
  if (fd == -1) {
     fprintf(stderr, "Open failed:%s\n",
       strerror(errno));
     exit(1);
  }

  /* Set memory objects size */
  if (ltrunc(fd, PAGESIZE, SEEK_SET) == -1) {
    fprintf(stderr, "ltrunc : %s\n", strerror(errno));
    exit(1);
  }

  /* Map memory object */
  addr = mmap(0, PAGESIZE, PROT_READ | PROT_WRITE,
               MAP_SHARED, fd, 0);
  if (addr == (void *) -1) {
     fprintf(stderr, "mmap failed : %s\n",
     strerror(errno));
     exit(1);
  }
  printf("Map addr is %6.6X\n", addr);

  /* Write to shared memory */
  *addr = 1;

  /*
   * The memory object remains in
   * the system after the close
   */
  close(fd);

  /*
   * To remove a memory object
   * you must unlink it like a file.
   */
  /*
   * This may be done by another process.
   */
  shm_unlink("bolts");

  exit(0);
}


