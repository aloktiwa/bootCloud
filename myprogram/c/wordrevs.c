//gcc 7.4.0

#include  <stdio.h>
#include  <string.h>
int ltobig(int n)
{
    int ret =0;
    // 12 34 56 78
    // 0xff, 
    ret = ((n >> 24) & 0x000000ff ) | ((n << 24) & 0xff000000) | ((n >> 8) & 0x000ff00) | ((n << 8) & 0x00ff0000);
    
    return ret;
}

void strcat1(char *ptr,char *s)
{
	char name[100];
	memset(name,0,100);
	int i=0;

	strcpy(name,ptr);

	i =0;
	while(*s)
	{
		*ptr++ = *s++;
		i++;
	}
	for(;name[i] != '\0';i++)
		ptr[i] = name[i];

}
void reverseword(char name[],int len)
{
    int i=0,j;
    char str[100]="";
    char s[10];
   
    while(i < len) {
        memset(s,0,10);j=0;
        for(;name[i] != ' ' && name[i] != '\0';i++,j++) {
            s[j] = name[i];
        } 
		s[j+1] = '\0';
        strcat1(str,s);i++;
    }
    
    printf("%s \n",str);

}

int main(void)
{
    char name[] = "this alok";
    reverseword(name,strlen(name));
}


