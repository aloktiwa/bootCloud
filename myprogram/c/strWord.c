#include <stdio.h>
#include <string.h>

int palimdo(int n)
{
	int x=0,n1=n,base=10;

	while(n) {
		x = n%10 + x*base;
		n = n/10;
	}

	printf("%d %d \n",x,n1);
	if(x == n1)
		return 1;
	else 
		return 0;
}
int main()
{	int i,j,k,len,p,g;
	char str1[]= "this is a word which need a reverse";
	char *str2;

	str2 = (char *)malloc(sizeof(strlen(str1)));

	printf("%d %s\n",1221,palimdo(10)?"yes it is pal":"no it is not pali");
	printf("%d \n",len = strlen(str1));
	printf("%c \n",str1[strlen(str1) -1]);

	for(i=0,j=len-1,k=0;j >=0;j--){
		if(str1[j] == ' ' || str1[j] == str1[0]) {
			if(str1[j] == str1[0] ) { 
				k++;
				str2[i++] = str1[0];
			}
			printf(" k=%d \t",k);
			for(g=0,p=j+1;g<k;i++,g++,p++) {
				str2[i] = str1[p];
			}
			k=0;
			if(str1[j] == str1[0] ) {
			//	str2[i++] = str1[0];
			} else  {
				str2[i++] = ' ';
			}
		}
		else {
			k++;
		}
	}
	printf("%s == \n%s \n",str1,str2);
}
