#include <stdio.h>
#include <pthread.h>

extern int volatile ab;
void *mythread(void *arg)
{
	int i=0;
	for(i=0;i<6;i++){
		printf("this is my thread \n");
		sleep(1);
		ab=0;
	}
	return;
}

int create_main()
{
	pthread_t thread_id;
	pthread_create(&thread_id,NULL,mythread,NULL);
	pthread_join(thread_id,NULL);
	printf("thred done \n");

}
