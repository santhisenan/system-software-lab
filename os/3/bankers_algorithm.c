#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isSafe();
int requestResource();

int available[3] , max[5][3] , allocation[5][3] , need[5][3];

int main(int argc, char const *argv[]) {
  int safe;;
  //clear the console
  system("clear");
  printf("Assume that the total number of resources are 3 , number of processes are 5\n" );

  printf("Enter available resources\n");
  for (int i = 0; i < 3; i++) {
    printf("Enter the total number of available resources of type %d\n\n", i );
    scanf("%d", &available[i]);
  }

  printf("\nEnter the number of resources of each type currently allocated to processes\n");
  for (int i = 0; i < 5; i++) {
    printf("Enter the number of allocated resources for process %d\n\n", i );
    for (int j = 0; j < 3; j++) {
      printf("Enter the number of allocated resources of type %d\n", j );
      scanf("%d", &allocation[i][j]);
    }
  }

  printf("\nEnter the maximum demand of resources of each type for each process\n");
  for (int i = 0; i < 5; i++) {
    printf("Enter the maximum demand for process %d\n\n", i );
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

  //call isSafe function
  safe = isSafe();
  if(safe)
    printf("The system is safe!\n");
  else
    printf("The system is not safe\n");

    //call resource request function
    printf("Resource request algorithm\n");
    safe = requestResource();
    if(safe)
      printf("The system will be safe after allocaitng the resources!\n");
    else
      printf("The system will not be safe after allocaitng the resources!\n");

return 0;
}

int isSafe(){
  int safe = 1;
  int work[3] , finish[5];
  //Safety Algorothm

  //intialising work = available
  for (int i = 0; i < 3; i++) {
    work[i] = available[i];
  }

  //intialising all processes as not completed
  for (int i = 0; i < 5; i++) {
    finish[i] = 0;
  }

  int safeSequence[5];
  int count = 0;
  for (int j = 0; j < 3; j++) {
    for (int i = 0; i < 5; i++) {
      if((finish[i] == 0) && need[i][j] <= work[j]){
        work[j] = work[j] + allocation[i][j];
        finish[i] = 1;
        printf("%d\n",i );
      }
    }
  }

  for (int i = 0; i < 5; i++) {
    if(finish[i] != 1){
      safe = 0;
    }
  }

  if (safe == 1) {
    printf("Safe sequence ..\n");
    for (int i = 0; i < 5; i++) {
      printf("%d\t", safeSequence[i]);
    }
    return 1;
  }
  else{
    // printf("The system is not in safe state\n");
    return 0;
  }

}

int requestResource(){

    //Resource request algorithm
    int processNumber;
    int request[3];
    printf("Enter the process number (0-4)\n");
    scanf("%d", &processNumber);

    int hasExceededMax = 0;
    printf("Enter the number of instances of each resource to be requested\n");
    for (int i = 0; i < 3; i++) {
      printf("Number of instances of resource %d\n" , i);
      scanf("%d", &request[i]);
      if(request[i] > need[processNumber][i]){
        printf("Exceeded the maximum number of resource instances that can be requested \n");
        hasExceededMax = 1;
        break;
      }
    }

    if(!hasExceededMax){
      int hasToWait = 0; //If the request is less than available the process must wait
      for (int i = 0; i < 3; i++) {
        if(request[i] < available[i]){
          hasToWait = 1;
        }
      }
      if(!hasToWait){
        // int isNotAvailable = 0;
        for (int i = 0; i < 3; i++) {
          available[i] = available[i] - request[i];
          allocation[processNumber][i] = allocation[processNumber][i] + request[i];
          need[processNumber][i] = need[processNumber][i] - request[i];
        }
        if(isSafe())
          return 1;
        else
          return 0;
      }
    }
}
