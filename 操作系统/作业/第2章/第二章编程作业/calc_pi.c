#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include<ctype.h>
#include<unistd.h>

#define NUM 10000000
#define RANDMAX 32767

int n;
int *circle_cnt;
int *my_seed;
//int circle_cnt[100] = {0};
//int my_seed[100] = {0};

int my_rand(int id)
{
    int rand_num = 0;
    rand_num = my_seed[id] = (my_seed[id] * 3823547829 + 38728) % RANDMAX;
    return rand_num;
}

void * worker_func(void *arg)
{
    double x = 0, y = 0;
    int rand_num = 0;
    int id = (int)arg;
    //my_seed[id] = (int)time(NULL);
    int seed = (int)time(NULL);
    for (int i = 0; i < NUM / n; i++)
    {	
        //rand_num = my_rand(id);
        //rand_num = rand() % RANDMAX;
        //rand_num = rand_r(&my_seed[id]) % RANDMAX;
        rand_num = rand_r(&seed) % RANDMAX;
        x = -1.0 + 2.0 * (double)rand_num / (double)RANDMAX;
        //rand_num = my_rand(id);
        //rand_num = rand() % RANDMAX;
        //rand_num = rand_r(&my_seed[id]) % RANDMAX;
        rand_num = rand_r(&seed) % RANDMAX;
        y = -1.0 + 2.0 * (double)rand_num / (double)RANDMAX;
        if(x * x + y * y <= 1)
            circle_cnt[id]++;
    }
    
    return NULL;
}


int main(int argc, char *argv[])
{
    //srand((unsigned)time(NULL));
    n = atoi(argv[2]);
    circle_cnt = (int *)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++)
    {
        circle_cnt[i] = 0;
    }
    my_seed = (int *)malloc(sizeof(int) * n);
    pthread_t *worker = (pthread_t *)malloc(sizeof(pthread_t) * n);
    void **worker_status = (void **)malloc(sizeof(void *) * n);
    //pthread_t worker[100];
    //void *worker_status[100];

    for(int i = 0; i < n; i++)
    {
        pthread_create(&worker[i], NULL, worker_func, (void*) i);
    }
    for(int i = 0; i < n; i++)
    {
        pthread_join(worker[i], &worker_status[i]);
    }
    
    int circle = 0;
    for(int i = 0; i < n; i++)
    {
        circle += circle_cnt[i];
    }

    double my_pi = 4.0 * (double)circle / (double)NUM;
    printf("PI = %f\n", my_pi);

    return 0;
}
