#include <pthread.h> 
#include <stdio.h> 
#include <unistd.h> 
#include <sys/types.h>
#include <sys/syscall.h>

pthread_cond_t cond1 = PTHREAD_COND_INITIALIZER;


pthread_mutex_t lock1 = PTHREAD_MUTEX_INITIALIZER;

int done = 1;
void * foo_hanlder(void *argv)
{
	int a = *(int*)argv;

	printf(" >> %d ,...\n",a);

	while(a < 1000) 
	{
		pthread_mutex_lock(&lock1);
		if(done == 1) {
		printf("%d ,...\n",a);
			done = 2;
//			printf("set done =2 %d\n",pthread_self());
//			printf("The id of %d is %u\n",a,syscall( __NR_gettid ));
			pthread_cond_wait(&cond1,&lock1);
		} else {
			a +=1;
//			printf("	signal %d \n",pthread_self());
//			printf("The id of %d is %u\n",a,syscall( __NR_gettid ));
			pthread_cond_signal(&cond1);
		}
	//	printf(">>%d ,...\n",a);

		pthread_mutex_unlock(&lock1);
	}

}
#define NUM_TH 2
int main()
{
	pthread_t tid[NUM_TH];
	int i , n,ptr=100;


	for (i=0; i < NUM_TH ;i++) {
		ptr = ptr + i;
		pthread_create(&tid[i],NULL,foo_hanlder,&ptr);

		sleep(1);
	}

		pthread_join(tid[0],NULL);
		pthread_join(tid[1],NULL);
}
