#include <stdio.h>
#include <stdlib.h>

static inline int little_endian() {
        int endian = 1;
        return (0 == (*(char *)&endian));
}

void broken_endian_example() {

        union {

                int i;
                char j[sizeof(int)];
              } test = {0xdeadbeef};
        int i = 0;

        for (i=0;i<sizeof(int);i++) {
                printf("test.j[%d] = 0x%x\n",
                i, test.j[i]);

        }

}

int main(int argc, char **argv)
{

        printf("This machine is ");
        little_endian() ? printf("little") : printf("big");
        printf(" endian\n");

        printf("This program was build on a machine that is: ");
#if BYTE_ORDER == BIG_ENDIAN
error        printf("big endian\n");
#else
#if BYTE_ORDER == LITTLE_ENDIAN
        printf("little endian\n");
#else
        printf("something weird\n");

#endif
#endif

       printf("and here's a silly example...\n");
       broken_endian_example();

       exit(0);
}


