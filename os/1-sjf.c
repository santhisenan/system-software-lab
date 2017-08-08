#include <stdio.h>
#include <string.h>

//BubbleSort for sorting array
int* BubbleSort(int a[], int array_size)
{
int i, j, temp;
for (i = 0; i < (array_size - 1); ++i)
{
     for (j = 0; j < array_size - 1 - i; ++j )
     {
          if (a[j] > a[j+1])
          {
               temp = a[j+1];
               a[j+1] = a[j];
               a[j] = temp;
          }
     }
}

return a;
}

int main(int argc, char const *argv[]) {
  int n, burst[10], sorted[10];
  printf("Enter the number of processes (max 10)\n" );

  scanf("%d \n" , &n);

  while(n > 10){
    printf("Enter a value less than 10...\n");
    printf("Enter the number of processes (max 10)\n" );
    scanf("%d\n", &n);
  }

  printf("Enter the burst time for each process\n");
  for (int i = 0; i < n; i++) {
    printf("Process %d\n", i );
    scanf("%d\n", &burst[i]);
  }

  memcpy(&sorted , BubbleSort(burst,n), sizeof sorted );
  for (int i = 0; i < n; i++) {
    printf("%d\n", sorted[i] );
    /* code */
  }
  return 0;
}
