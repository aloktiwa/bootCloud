#include <stdio.h>
#include <linux/version.h>


int main()
{
        printf("kernel version(2.6.32) = %d\n",KERNEL_VERSION(2,6,32));
        printf("LINUX_VERSION_CODE = %d\n",LINUX_VERSION_CODE);

        #if LINUX_VERSION_CODE <  KERNEL_VERSION(2,6,32)
                printf("Hello,world.\n");
        #else
                printf("Fine,thank you.\n");
        #endif



        return 0;
}

