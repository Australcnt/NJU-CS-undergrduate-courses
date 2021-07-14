#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdlib.h>

#define P sem_wait
#define V sem_post

sem_t *writeblock;
sem_t *mutex;

int readcount = 0;

void *reader_i()
{
    printf("读者请求读文件\n");
    P(mutex);
    readcount++;
    if(readcount == 1)
        P(writeblock);
    V(mutex);
    printf("读者读文件中，共有%d个读者\n", readcount);
    sleep(1);
    P(mutex);
    readcount--;
    printf("读者停止读文件，共有%d个读者\n", readcount);
    if(readcount == 0)
        V(writeblock);
    V(mutex);
    //sleep(1);
    return NULL;
}

void *writer_j()
{
    while(1)
    {
        printf("写者请求写文件\n");
        P(writeblock); 
        printf("写者写文件中\n");
        sleep(1);
        printf("写者停止写文件\n");
        V(writeblock);
        sleep(2);
    }
    return NULL;
}

int main()
{
    writeblock = (sem_t *)malloc(sizeof(sem_t));
    mutex = (sem_t *)malloc(sizeof(sem_t));
    sem_init(writeblock, 0, 1);
    sem_init(mutex, 0, 1);

    pthread_t tid1[5];
    pthread_t tid2;

    pthread_create(&tid2, NULL, writer_j, NULL);
    for(int i = 0; i < 5; i++)
    {
        pthread_create(&tid1[i], NULL, reader_i, NULL);
    }

    pthread_join(tid2, NULL);
    for(int i = 0; i < 5; i++)
    {
        pthread_join(tid1[i], NULL);
    }

    pthread_exit(NULL);

    sem_destroy(writeblock);
    sem_destroy(mutex);

    return 0;
}
