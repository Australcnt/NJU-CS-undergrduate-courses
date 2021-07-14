#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define P sem_wait
#define V sem_post

sem_t *forks[5];

void *philosopher_i(void *arg)
{
    int i = (int)arg;
    while(1)
    {
        printf("哲学家%d思考中\n", i);
        sleep(1);
        P(forks[i]);
        printf("哲学家%d拿起左边的叉子\n", i);
        P(forks[(i + 1) % 5]);
        printf("哲学家%d拿起右边的叉子\n", i);
        printf("哲学家%d进餐中\n", i);
        sleep(1);
        V(forks[i]);
        V(forks[(i + 1) % 5]);
    }
}

int main()
{
    for(int i = 0; i < 5; i++)
        forks[i] = (sem_t *)malloc(sizeof(sem_t));
    for(int i = 0; i < 5; i++)
        sem_init(forks[i], 0, 1);
    pthread_t tid[5];
    for(int i = 0; i < 5; i++)
        pthread_create(&tid[i], NULL, philosopher_i, (void *)i);
    for(int i = 0; i < 5; i++)
        pthread_join(tid[i], NULL);
    pthread_exit(NULL);
    for(int i = 0; i < 5; i++)
        sem_destroy(forks[i]);
    
    return 0;
}