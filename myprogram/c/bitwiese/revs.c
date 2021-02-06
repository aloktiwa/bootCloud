#include <stdio.h>

void reverseword(char name[],int i,int len)
{
	int j;
    char ptr[20];//=;
	memset(ptr,20,0);
    if(i >= len)
        return ;
 
    for(j=0;name[i] != ' ' && i < len;i++) { 
		ptr[j++] = name[i];
    }
    reverseword(&name[i],i,9);
    printf("%s ",ptr);
    
}

int main(void)
{
    char name[] = "I am alok";
    
    reverseword(name,0,9);
    return 0;
}

