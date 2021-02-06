#include <stdio.h>
#include <stdbool.h>

struct Node {
	int val;
	struct Node *next;
}Node;

int findgcd(int n1,int n2)
{
	int i,gcd=1,maxgcd=1;
	bool lcm=false;
	printf("lcm %d %d ==>",n1,n2);
	for(i=2;i<=n1 && i <=n2;i++)
	{
		if( ((n1 % i) == 0)  && ((n2 % i) == 0))
		{	lcm=true;
			gcd=gcd*i;
			maxgcd=i;
			printf("%d \t",i);
		}
	}
	printf("%s and lcm =%d gcd =%d\n",lcm == true ? " ":"no lcm found",(n1*n2)/maxgcd,gcd);
}

int main()
{
	int aa=100;
	int * const ptr=&aa;
	ptr = 0;
	*ptr = 200;
	printf("%d %d\n",aa,*ptr);
	struct Node val;
	val.val=100;
	printf("%d \n",val.val);
	findgcd(12,8);
}
