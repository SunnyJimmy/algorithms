#include<stdio.h>

void quicksort(int A[], int lo, int hi) {
  int i, j, pivot, temp;

  if(lo == hi) return;
  i=lo;
  j=hi;
  pivot= A[(lo+hi)/2];

  /* Split the array into two parts, make sure all a[i] < a[j], 只要没有交集都可以 */
  do {
    while (A[i] < pivot) i++;
    while (A[j] > pivot) j--;
    //不符合要求的,交换
    if (i<=j) {
      temp= A[i];
      A[i]= A[j];
      A[j]=temp;
      i++;
      j--;
    }
  } while (i<=j);
  printf("i %d j %d\n", i, j);

  if (lo < j) quicksort(A, lo, j);
  if (i < hi) quicksort(A, i, hi);
}
int main()
{
    int i;
    int a[11]={1,3,4,8,2,9,7,5,0,6,10};
    quicksort(a,0, 10); //快速排序调用

    //输出排序后的结果
    for(i=0;i<11;i++)
        printf("%d ",a[i]);
    return 0;
}
