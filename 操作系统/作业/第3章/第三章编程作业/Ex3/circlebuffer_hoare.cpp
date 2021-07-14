#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <time.h>

using namespace std;

#define P sem_wait
#define V sem_post

struct InterfaceModule
{
    sem_t *mutex;
    sem_t *next;
    int next_count;
};

class CircleBuffer
{
private:
    int *buffer;
    int in;
    int out;
    int counter;
    int size;
    sem_t *full;
    sem_t *empty;
    int full_count;
    int empty_count;
    InterfaceModule IM;
public:
    CircleBuffer();
    CircleBuffer(int k);
    void get(int &x);
    void put(int x);
    friend void enter(InterfaceModule &IM);
    friend void leave(InterfaceModule &IM);
    friend void wait(sem_t *x_sem, int &x_count, InterfaceModule &IM);
    friend void signal(sem_t *x_sem, int &x_count, InterfaceModule &IM);
};

void enter(InterfaceModule &IM)
{
    P(IM.mutex);
}

void leave(InterfaceModule &IM)
{
    if(IM.next_count > 0)
    {
        IM.next_count--;
        V(IM.next);
    }
    else
        V(IM.mutex);
}

void wait(sem_t *x_sem, int &x_count, InterfaceModule &IM)
{
    x_count++;
    if(IM.next_count > 0)
    {
        IM.next_count--;
        V(IM.next);
    }
    else
        V(IM.mutex);
    P(x_sem);
}

void signal(sem_t *x_sem, int &x_count, InterfaceModule &IM)
{
    if(x_count > 0)
    {
        x_count--;
        IM.next_count++;
        V(x_sem);
        P(IM.next);
    }
}

CircleBuffer *circlebuffer;
clock_t clk;
int k;

CircleBuffer::CircleBuffer()
{
    buffer = NULL;
    in = 0;
    out = 0;
    counter = 0;
    size = 0;
    sem_init(full, 0, 0);
    sem_init(empty, 0, 0);
    full_count = 0;
    empty_count = 0;
    sem_init(IM.mutex, 0, 1);
    sem_init(IM.next, 0 ,0);
    IM.next_count = 0;
}

CircleBuffer::CircleBuffer(int k)
{
    buffer = new int[k];
    in = 0;
    out = 0;
    counter = 0;
    size = k;
    full = new sem_t;
    empty = new sem_t;
    sem_init(full, 0, 0);
    sem_init(empty, 0, 0);
    full_count = 0;
    empty_count = 0;
    IM.mutex = new sem_t;
    IM.next = new sem_t;
    sem_init(IM.mutex, 0, 1);
    sem_init(IM.next, 0 ,0);
    IM.next_count = 0;
}

void CircleBuffer::get(int &x)
{
    enter(IM);
    if(counter == 0)
    {
        cout << "缓冲区为空，等待添加中" << endl;
        wait(empty, empty_count, IM);
    }
    x = buffer[out];
    cout << "从缓冲区buffer[" << out << "]中拿出" << x << endl;
    out = (out + 1) % size;
    counter--;
    signal(full, full_count, IM);
    leave(IM);
}

void CircleBuffer::put(int x)
{
    enter(IM);
    if(counter == size)
    {
        cout << "缓冲区已满，等待释放中" << endl;
        wait(full, full_count, IM);
    }
    buffer[in] = x;
    cout << "将" << x << "加入缓冲区buffer[" << in << "]" << endl;
    in = (in + 1) % size;
    counter++;
    signal(empty, empty_count, IM);
    leave(IM);
}

void* producer(void* arg)
{
    while(1)
    {
        int x = rand() % k;
        //cout << "生产产品" << endl;
        sleep(1);
        circlebuffer->put(x);
    }
}
void* consumer(void* arg)
{
    while(1)
    {
        int x;
        circlebuffer->get(x);
        //cout << "消费产品" << endl;
        sleep(1);
    }
}

int main()
{
    srand((int)time(NULL));
    cin >> k;
    circlebuffer = new CircleBuffer(k);
    pthread_t id1;
    pthread_t id2;
    clk = clock();
    pthread_create(&id1, NULL, producer, NULL);
    pthread_create(&id2, NULL, consumer, NULL);
    pthread_join(id1, NULL);
    pthread_join(id2, NULL);
    pthread_exit(NULL);

    return 0;
}