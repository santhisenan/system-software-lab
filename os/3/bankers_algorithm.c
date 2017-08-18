#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {

  //clear the console
  system("clear");
  printf("Assume that the total number of resources are 3 , number of processes are 5\n" );

  int work[3] , available[3] , max[5][3] , allocation[5][3] , need[5][3] , request[3];
  int finish[5];
  int safe = 1;
  printf("Enter available resources\n");
  for (int i = 0; i < 3; i++) {
    printf("Enter the total number of available resources of type %d\n", i );
    scanf("%d", &available[i]);
  }

  printf("\nEnter the number of resources of each type currently allocated to processes\n");
  for (int i = 0; i < 5; i++) {
    printf("Enter the number of allocated resources for process %d\n\t", i );
    for (int j = 0; j < 3; j++) {
      printf("Enter the number of allocated resources of type %d\n", j );
      scanf("%d", &allocation[i][j]);
    }
  }

  printf("\nEnter the maximum demand of resources of each type for each process\n");
  for (int i = 0; i < 5; i++) {
    printf("Enter the maximum demand for process %d\n\t", i );
    for (int j = 0; j < 3; j++) {
      printf("Enter the max demand of resources of type %d\n", j );
      scanf("%d", &max[i][j]);
    }
  }

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 3; j++) {
      need[i][j] = max[i][j] - allocation[i][j];
    }
  }

  //Safety Algorothm

  //intialising work = available
  for (int i = 0; i < 3; i++) {
    work[i] = available[i];
  }

  //intialising all processes as not completed
  for (int i = 0; i < 5; i++) {
    finish[i] = 0;
  }

  for (int j = 0; j < 3; j++) {
    for (int i = 0; i < 5; i++) {
      if((finish[i] == 0) && need[i][j] < work[j]){
        work[j] = work[j] + allocation[i][j];
        finish[i] = 1;
      }
    }
  }

  for (int i = 0; i < 5; i++) {
    if(finish[i] != 1){
      safe = 0;
    }
  }

  if (safe == 1) {
    printf("The system is in safe state.\n");
  }
  else{
    printf("The system is not in safe state\n");
  }

  //Resource request algorithm
  int processNumber;

  printf("Enter the process number (0-4)\n");
  scanf("%d\n", &processNumber);

  int hasExceededMax = 0;
  printf("Enter the number of instances of each resource to be requested\n");
  for (int i = 0; i < 3; i++) {
    printf("Number of instances of resource %d\n");
    scanf("%d\n", &request[i]);
    if(request[i] > need[processNumber][i]){
      printf("Exceeded the maximum number of resource instances that can be requested \n");
      hasExceededMax = 1;
      break;
    }
  }

  if(!hasExceededMax){
  int hasToWait = 0; //If the request is less than available the process must wait
  for (int i = 0; i < 3; i++) {
    if(request[i] < available[processNumber][i]){
      hasToWait = 1;
    }
  }
  if(!hasToWait){
    int isNotAvailable = 0;
    for (int i = 0; i < 3; i++) {
      available[processNumber][i] = available[processNumber][i] - request[i];
      allocation[processNumber][i] = allocation[processNumber][i] + request[i];
      need[processNumber][i] = need[processNumber][i] - request[i];
      }
    }
  }

}



  return 0;
}
