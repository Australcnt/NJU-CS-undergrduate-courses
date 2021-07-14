#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

using namespace std;

pthread_mutex_t mutex;
pthread_cond_t full, empty;

class CircleBuffer
{
private:
    int *buffer;
    int in;
    int out;
    int counter;
    int size;
public:
    CircleBuffer();
    CircleBuffer(int k);
    void get(int &x);
    void put(int x);
};

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
}

CircleBuffer::CircleBuffer(int k)
{
    buffer = new int[k];
    in = 0;
    out = 0;
    counter = 0;
    size = k;
}

void CircleBuffer::get(int &x)
{
    pthread_mutex_lock(&mutex);
    if(counter == 0)
    {
        cout << "缓冲区为空，等待添加中" << endl;
        pthread_cond_wait(&empty, &mutex);
    }
    x = buffer[out];
    cout << "从缓冲区buffer[" << out << "]中拿出" << x << endl;
    out = (out + 1) % size;
    counter--;
    pthread_cond_signal(&full);
    pthread_mutex_unlock(&mutex);
}

void CircleBuffer::put(int x)
{
    pthread_mutex_lock(&mutex);
    if(counter == size)
    {
        cout << "缓冲区已满，等待释放中" << endl;
        pthread_cond_wait(&full, &mutex);
    }
    buffer[in] = x;
    cout << "将" << x << "加入缓冲区buffer[" << in << "]" << endl;
    in = (in + 1) % size;
    counter++;
    pthread_cond_signal(&empty);
    pthread_mutex_unlock(&mutex);
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
    pthread_mutex_init(&mutex,0);
    pthread_cond_init(&full,0);
    pthread_cond_init(&empty,0);
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
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&full);
    pthread_cond_destroy(&empty);

    return 0;
}