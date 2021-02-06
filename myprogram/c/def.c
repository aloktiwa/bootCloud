
#define addp(y) #y
#define ALS(x,y) (x##y)

int main()
{
//	printf("%s \n",ALS("12","3"));
	printf("%s \n",ALS(addp(123),addp(234)));
}
