#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/syscall.h>

#define MAX_NO 4

pthread_cond_t val_cond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t v_mutex = PTHREAD_MUTEX_INITIALIZER;

pid_t getTid() {
	pid_t tid1;
	tid1 = syscall(SYS_gettid);
	return tid1;
}

struct node {
	unsigned long val;
	char name[20];
};

int done =0;
struct node N1;
void *thread_func(void *arg)
{
	unsigned long ll;
	printf(" >> self %d tid %d arg %ld \n",pthread_self(),getTid(),*(unsigned long *)arg);

	ll = *(unsigned long *)arg;
	for(int i=0;i<2000;i++) {
		pthread_mutex_lock(&v_mutex);
		if(done == 0) {
			done =1;
			pthread_cond_wait(&val_cond,&v_mutex);
				N1.val = ll;
				sprintf(N1.name,"thread%ld",ll);
			} else {
				done =0;
				printf("%ld %s \n",N1.val,N1.name);
				pthread_cond_signal(&val_cond);
			}
			pthread_mutex_unlock(&v_mutex);
		}

	return NULL;
}

int main()
{
	int *retval;
	pthread_t tid[MAX_NO];
	unsigned long arg =0;
	for(int i =0;i<MAX_NO;i++,arg++) {
		if(pthread_create(&tid[i],NULL,thread_func,(void *)&arg)) {
			perror("pthrad create error \n");
			exit(0);
		}
		sleep(1);
	}
	for(int i =0;i<MAX_NO;i++) {
		pthread_join(tid[i],&retval);
	}

}
