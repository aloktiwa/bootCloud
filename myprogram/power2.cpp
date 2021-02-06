#include <bits/stdc++.h>
using namespace std;
#define bool int

/* Function to check if x is power of 2*/
bool isPowerOfTwo (int x)
{
	/* First x in the below expression is for the case when x is 0 */
	return (x && (!(x&(x-1))));
}

/*Driver code*/
int main()
{
	int num =1,i;
	for(i=2;i<1024;i+=2)
	{
		num *= (2*i);
		cout << "num = " << num;
		isPowerOfTwo(num)? cout<<" Yes\n": cout<<" No\n";
	}
	return 0;
}

