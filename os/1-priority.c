#include <stdio.h>
#include <string.h>
int n, burst[10], processid[10], priority[10], sorted_burst[10], sorted_priority[10], waiting[10], turn_around[10];
float avg_waiting = 0, avg_turnaround = 0;
//BubbleSort for sorting array
void BubbleSort(int a[], int b[], int c[], int array_size)
{
  int i, j, temp,s,t;
  for (i = 0; i < (array_size - 1); ++i)
  {
    for (j = 0; j < array_size - 1 - i; ++j )
    {
      if (a[j] > a[j+1])
      {
        temp = a[j+1];
        a[j+1] = a[j];
        a[j] = temp;
        t = b[j+1];
        b[j+1] = b[j];
        b[j] = t;
        s = c[j+1];
        c[j+1] = c[j];
        c[j] = s;
      }
    }
  }

  memcpy(&sorted_burst , a , sizeof sorted_burst );
  memcpy(&sorted_priority , b, sizeof sorted_burst );
  memcpy(&processid , c, sizeof processid );
}

int main(int argc, char const *argv[]) {

  printf("Enter the number of processes (max 10)\n");
  scanf("%d",&n);
  while(n > 10){
    printf("Enter a value less than 10...\n");
    printf("Enter the number of processes (max 10)\n" );
    scanf("%d\n", &n);
  }

  printf("Enter the burst time for each process\n");
  for (int i = 0; i < n; i++) {
    processid[i] = i+1;
    printf("Process %d's burst time\n", i+1 );
    scanf("%d", &burst[i]);
    printf("Process %d's priority\n", i+1 );
    scanf("%d", &priority[i]);
  }
  BubbleSort(burst, priority, processid, n);
  // memcpy(&sorted , BubbleSort(burst,priority,n), sizeof sorted );
  // for (int i = 0; i < n; i++) {
  //   printf("%d\n", sorted[i] );
  //   /* code */
  // }`

  waiting[0] = 0;
  for (size_t i = 1; i < n; i++) {
    /* code */
    waiting[i] = waiting[i-1]+sorted_burst[i-1];
    // printf("%d \t" , waiting[i-1]);
    avg_waiting +=waiting[i]/n;
  }
  // printf("The waiting time for processes are :\n");
  // for (int i = 0; i < number; i++) {
  //   /* code */
  //   printf("process %d : %d\n", i+1, waiting[i] );
  // }

  // printf("\n" );
  turn_around[0] = sorted_burst[0];
  avg_turnaround = sorted_burst[0]/n;
  for (int i = 1; i < n; i++) {
    /* code */
    turn_around[i] = waiting[i] + sorted_burst[i];
    // printf("%d\n", turn_around[i]);
    avg_turnaround += turn_around[i]/n;
  }


  printf("Process ID \t Priority \t Burst Time \t Waiting Time \t Turn Around Time\n" );
  for (int i = 0; i < n; i++) {
    /* code */
    printf("%d \t\t %d \t\t %d \t\t %d \t\t %d \n",processid[i], sorted_priority[i] ,sorted_burst[i], waiting[i] , turn_around[i] );
  }

  printf("Avg waiting time is %f \n", avg_waiting );
  printf("The average turn around time is %f\n", avg_turnaround);


  return 0;
}
