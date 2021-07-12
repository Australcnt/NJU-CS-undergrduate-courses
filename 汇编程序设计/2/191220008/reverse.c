#include <stdio.h> 

void xor_swap(int *x, int *y){
  *y=*x ^ *y; /* 第一步 */
  *x=*x ^ *y; /* 第二步 */
  *y=*x ^ *y; /* 第三步 */
}

void reverse_array(int a[], int len){
  int left, right=len-1;
  for (left=0; left<right; left++, right--)
    xor_swap(&a[left], &a[right]);
}

int main(){
  int a[] = {1,2,3,4,5,6,7};
  reverse_array(a, 7);
  int i;
  for(i = 0; i < 7; ++i)
   printf("%d ", a[i]);
  printf("\n");
}
