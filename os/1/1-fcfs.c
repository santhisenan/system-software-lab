#include<stdio.h>

int main(int argc, char const *argv[]) {
  /* code */
  int number, burst[10] , waiting[10], turn_around[10];
  float avg_waiting=0, avg_turnaround=0;
  printf("Enter the total number of processes (maximum 10)\n");
  scanf("%d", &number );
  if(number>10){
    printf("Enter a number less than 10.. exiting\n" );
    return 0;
  }
  // printf("%d\n" , number);
  printf("Enter the burst time for each process\n" );
  for (int i = 1; i < number+1; i++) {
    /* code */
    printf("process %d\n", i );
    scanf("%d", &burst[i-1]);
  }
  // printf("%d", burst[0]);

waiting[0] = 0;
for (size_t i = 1; i < number; i++) {
  /* code */
  waiting[i] = waiting[i-1]+burst[i-1];
  // printf("%d \t" , waiting[i-1]);
  avg_waiting +=waiting[i]/number;
}
// printf("The waiting time for processes are :\n");
// for (int i = 0; i < number; i++) {
//   /* code */
//   printf("process %d : %d\n", i+1, waiting[i] );
// }

// printf("\n" );
turn_around[0] = burst[0];
avg_turnaround = burst[0]/number;
for (int i = 1; i < number; i++) {
  /* code */
  turn_around[i] = waiting[i] + burst[i];
  // printf("%d\n", turn_around[i]);
  avg_turnaround += turn_around[i]/number;
}


printf("Process \t Burst Time \t Waiting Time \t Turn Around Time\n" );
for (int i = 0; i < number; i++) {
  /* code */
  printf("%d \t\t %d \t\t %d \t\t %d \n", i+1, burst[i], waiting[i] , turn_around[i] );
}

printf("Avg waiting time is %f \n", avg_waiting );
printf("The average turn around time is %f\n", avg_turnaround);


  return 0;
}
