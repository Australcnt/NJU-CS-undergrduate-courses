#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_rwlock_t lock;

int readcount = 0;

void *reader_i()
{
    printf("读者请求读文件\n");
    pthread_rwlock_rdlock(&lock);
    readcount++;
    printf("读者读文件中，共有%d个读者\n", readcount);
    sleep(1);
    readcount--;
    printf("读者停止读文件，共有%d个读者\n", readcount);
    pthread_rwlock_unlock(&lock);
    //sleep(1);
    return NULL;
}

void *writer_j()
{
    while(1)
    {
        printf("写者请求写文件\n");
        pthread_rwlock_wrlock(&lock);
        printf("写者写文件中\n");
        sleep(1);
        printf("写者停止写文件\n");
        pthread_rwlock_unlock(&lock);
        sleep(2);
    }
    return NULL;
}

int main()
{
    pthread_rwlock_init(&lock, NULL);

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

    pthread_rwlock_destroy(&lock);

    return 0;
}
