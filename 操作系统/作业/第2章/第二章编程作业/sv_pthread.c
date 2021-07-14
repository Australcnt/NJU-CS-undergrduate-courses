#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define NUM 50000

int gi = 0;

void * worker_func(void *arg)
{
    for (int i = 0; i < NUM; i++) {	
        gi++;
    }

    return NULL;
}


int main(void)
{
    pthread_t worker1, worker2;
    void *worker1_status;
    void *worker2_status;

    pthread_create(&worker1, NULL, worker_func, NULL);
    pthread_create(&worker2, NULL, worker_func, NULL);
    
    pthread_join(worker1, &worker1_status);
    pthread_join(worker2, &worker2_status);
    
    printf("%d-%d\n", gi, 2*NUM);

    return 0;
}