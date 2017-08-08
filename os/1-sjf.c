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
  int n, burst[10], sorted[10], waiting[10], turn_around[10];
  float avg_waiting = 0, avg_turnaround = 0;
  printf("Enter the number of processes (max 10)\n");
  scanf("%d",&n);
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

  waiting[0] = 0;
  for (size_t i = 1; i < n; i++) {
    /* code */
    waiting[i] = waiting[i-1]+sorted[i-1];
    // printf("%d \t" , waiting[i-1]);
    avg_waiting +=waiting[i]/n;
  }
  // printf("The waiting time for processes are :\n");
  // for (int i = 0; i < number; i++) {
  //   /* code */
  //   printf("process %d : %d\n", i+1, waiting[i] );
  // }

  // printf("\n" );
  turn_around[0] = sorted[0];
  avg_turnaround = sorted[0]/n;
  for (int i = 1; i < n; i++) {
    /* code */
    turn_around[i] = waiting[i] + sorted[i];
    // printf("%d\n", turn_around[i]);
    avg_turnaround += turn_around[i]/n;
  }


  printf("Process \t Burst Time \t Waiting Time \t Turn Around Time\n" );
  for (int i = 0; i < n; i++) {
    /* code */
    printf("%d \t\t %d \t\t %d \t\t %d \n", i+1, sorted[i], waiting[i] , turn_around[i] );
  }

  printf("Avg waiting time is %f \n", avg_waiting );
  printf("The average turn around time is %f\n", avg_turnaround);


  return 0;
}
