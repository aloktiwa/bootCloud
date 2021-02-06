
static int mohan = 100;


//extern long mohan;
void printmohan()
{
	printf("now mohan is %d \n",mohan);
	printf("now mohan is %d \n",mohan);
}

int * getinstance()
{
	return &mohan;
}
