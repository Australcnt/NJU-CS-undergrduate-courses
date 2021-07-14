#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Merge(int *array, int left, int median, int right);
void MergeSort(int *array, int left, int right);

int main()
{
    srand((int)time(NULL));
    int n;
    //scanf("%d", &n);
    n = 1000000;
    int *array = (int *)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++)
    //    scanf("%d", &array[i]);
        array[i] = rand();
    MergeSort(array, 0, n - 1);
    //for(int i = 0; i < n; i++)
    //    printf("%d ", array[i]);
    //printf("\n");
    return 0;
}

void Merge(int *array, int left, int median, int right)
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

void MergeSort(int *array, int left, int right)
{
    if(left < right)
    {
        int median = (left + right) / 2;
        MergeSort(array, left, median);
        MergeSort(array, median + 1, right);
        Merge(array, left, median, right);
    }
}
