#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

int thread_num_max;
int thread_num = 0;
int *array;

void Merge(int left, int median, int right);
void *MergeSort(void *arg);

int main(int argc, char *argv[])
{
    srand((int)time(NULL));
    thread_num_max = atoi(argv[2]);
    int n;
    //scanf("%d", &n);
    n = 1000000;
    array = (int *)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++)
    //    scanf("%d", &array[i]);
        array[i] = rand();
    int arg[2] = {0, n - 1};
    pthread_t tid;
    pthread_create(&tid, NULL, MergeSort, arg);
    pthread_join(tid, NULL);
    //for(int i = 0; i < n; i++)
    //    printf("%d ", array[i]);
    //printf("\n");
    return 0;
}

void Merge(int left, int median, int right)
{
    int n1 = median - left + 1;
    int n2 = right - median;
    int *array_left = (int *)malloc(n1 * sizeof(int));
    int *array_right = (int *)malloc(n2 * sizeof(int));
    for(int i = 0; i < n1; i++)
        array_left[i] = array[left + i];
    for(int j = 0; j < n2; j++)
        array_right[j] = array[median + 1 + j];
    int i = 0, j = 0;
    for(int k = left; k <= right; k++)
    {
        if(i == n1)
        {
            array[k] = array_right[j];
            j++;
        }
        else if(j == n2)
        {
            array[k] = array_left[i];
            i++;
        }
        else if(array_left[i] < array_right[j])
        {
            array[k] = array_left[i];
            i++;
        }
        else
        {
            array[k] = array_right[j];
            j++;
        }
    }
}

void *MergeSort(void *arg)
{
    int left = ((int*)arg)[0];
    int right = ((int*)arg)[1];
    if(left < right)
    {
        int median = (left + right) / 2;
        int arg1[2] = {left, median};
        int arg2[2] = {median + 1, right};
        pthread_t t1;
        pthread_t t2;
        if(thread_num < thread_num_max)
        {
            thread_num++; 
            pthread_create(&t1, NULL, MergeSort, arg1);
            pthread_join(t1, NULL); 
            pthread_exit(NULL);
            thread_num--;
        }
        else
            MergeSort(arg1);
        if(thread_num < thread_num_max)
        {
            thread_num++;
            pthread_create(&t2, NULL, MergeSort, arg2); 
            pthread_join(t2, NULL);
            pthread_exit(NULL);
            thread_num--;
        }
        else
            MergeSort(arg2);
        Merge(left, median, right);
    }
    return NULL;
}
