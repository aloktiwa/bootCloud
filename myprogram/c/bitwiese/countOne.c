int countOne(int n)
{
	int count =0;
	while(n) {
		count++;
		n = n & ( n-1);
	}
	return count;
}

int main()
{
	int n = 23;
	printf("%x %d \n",n,countOne(n));
}
