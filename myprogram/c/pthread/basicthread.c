#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 
#include <unistd.h>  //Header file for sleep(). man 3 sleep for details. 
#include <pthread.h> 
  
// A normal C function that is executed as a thread  
// when its name is specified in pthread_create() 

pthread_mutex_t mpl = PTHREAD_MUTEX_INITIALIZER;


_atomic unsigned long i=0;
//bool done = false;
void *myThreadFun(void *vargp) 
{ 
	int j;
    printf("Printing GeeksQuiz from Thread \n"); 
	for(j=0;j<10000;j++) {
//	pthread_mutex_lock(&mpl);
		i++;
//	 __atomic_fetch_add(&i, 1, __ATOMIC_SEQ_CST);
//	pthread_mutex_unlock(&mpl);
	}
} 
   
int main() 
{ 
//	pthread_mutex_init(&mpl,NULL);
    pthread_t thread_id1; 
    pthread_t thread_id2; 
    pthread_t thread_id3; 
    pthread_t thread_id4; 
    pthread_t thread_id5; 
    pthread_t thread_id6; 
    pthread_t thread_id7; 
    printf("Before Thread\n"); 
    pthread_create(&thread_id1, NULL, myThreadFun, NULL); 
    pthread_create(&thread_id2, NULL, myThreadFun, NULL); 
    pthread_create(&thread_id3, NULL, myThreadFun, NULL); 
    pthread_create(&thread_id4, NULL, myThreadFun, NULL); 
    pthread_create(&thread_id5, NULL, myThreadFun, NULL); 
  //  pthread_create(&thread_id6, NULL, myThreadFun, NULL); 
    pthread_create(&thread_id7, NULL, myThreadFun, NULL); 

    pthread_join(thread_id1, NULL); 
    pthread_join(thread_id2, NULL); 
    pthread_join(thread_id3, NULL); 
    pthread_join(thread_id4, NULL); 
    pthread_join(thread_id5, NULL); 
//    pthread_join(thread_id6, NULL); 
    pthread_join(thread_id7, NULL); 
    printf("After Thread %ld \n",i); 
    exit(0); 
}
