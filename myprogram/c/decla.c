#include <stdio.h>
#include <pthread.h>

int volatile ab=1;
pthread_t thread_id;
void *mythread(void *arg)
{
	int i=0;
	for(i=0;i<6;i++){
		printf("this is my thread \n");
		ab=0;
	}
	return;
}

int create_main()
{
	pthread_create(&thread_id,NULL,mythread,NULL);

}

int main()
{
	create_main();
	do {
		printf("lop \n ");
	}while(ab);
	pthread_join(thread_id,NULL);
	printf("thred done \n");
}
