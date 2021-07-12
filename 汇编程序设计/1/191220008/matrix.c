#include <stdio.h>
#include <time.h>

void copyij(int src[2048][2048], int dst[2048][2048])
{
  int i, j;
  for (i = 0; i < 2048; i++)
  {
    for (j = 0; j < 2048; j++)
    {
      dst[i][j] = src[i][j];
    }
  }
}

void copyji(int src[2048][2048], int dst[2048][2048])
{
  int i, j;
  for (j = 0; j < 2048; j++)
  {
    for (i = 0; i < 2048; i++)
    {
      dst[i][j] = src[i][j];
    }
  }
}

int src[2048][2048];
int dstij[2048][2048]; 
int dstji[2048][2048];

int main()
{
  int t, m;
  for (t = 0; t < 2048; t++)
  {
    for (m = 0; m < 2048; m++)
    {
      src[t][m] = t + m;
    }
  }
  clock_t startij, finishij, startji, finishji; 
  startij = clock();
  copyij(src, dstij);
  finishij = clock();
  double durationij = (double)(finishij - startij) / CLOCKS_PER_SEC;
  printf("copyij %f s\n", durationij); 
  startji = clock();
  copyji(src, dstji);
  finishji = clock();
  double durationji = (double)(finishji - startji) / CLOCKS_PER_SEC;
  printf("copyji %f s\n", durationji);
  return 0;
} 
