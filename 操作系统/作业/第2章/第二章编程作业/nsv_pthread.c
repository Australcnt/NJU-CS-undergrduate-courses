#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define NUM 50000

int gi[2];

void * worker_func(void *arg)
{
    int id = (int)arg;
    for (int i = 0; i < NUM; i++) {	
        gi[id]++;
    }

    return NULL;
}


int main(void)
{
    pthread_t worker1, worker2;
    void *worker1_status;
    void *worker2_status;

    gi[0] = 0;
    gi[1] = 0;

    pthread_create(&worker1, NULL, worker_func, (void*) 0);
    pthread_create(&worker2, NULL, worker_func, (void*) 1);
    
    pthread_join(worker1, &worker1_status);
    pthread_join(worker2, &worker2_status);
    
    printf("%d-%d\n", gi[0] + gi[1], 2*NUM);

    return 0;
}
