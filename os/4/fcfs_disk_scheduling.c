#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int diskLimit, requests, diskQueue[100], headMovement, currentPosition, clone[100];
// requests[0] = 0;

void FCFS();
void SCAN();
void CSCAN();
void sort();
void scanForward();
void scanBackward();

int main(int argc, char const *argv[]) {
  printf("Enter the disk limit: (max 100)\n");
  scanf("%d",&diskLimit);
  printf("Enter the number of requests (Total number of requests should be less than the disk limit.)\n");
  scanf("%d", &requests);

  get_disk_queue:
  printf("Enter the disk queue (The requests should be within disk limit)\n");
  for (int i = 0; i < requests; i++) {
    scanf("%d", &diskQueue[i]);
    if(diskQueue[i] > diskLimit){
      printf("Disk limit exceeded\n");
      goto get_disk_queue;

    }
  }

  //FCFS
  FCFS();

  //SCAN
  SCAN();

  //CSCAN
  CSCAN();

  return 0;
}

void FCFS(){
  printf("FCFS...\n");
  headMovement = 0;

  for (int i = 0; i < requests; i++) {

    if(i == 0){
      headMovement = diskQueue[0];
      continue;
    }

    headMovement = headMovement + abs(diskQueue[i] - diskQueue[i-1]);
  }
  printf("The head movement for FCFS Scheduling is %d\n", headMovement);
return;
}

void sort(){
  int swap;
  for (int c = 0 ; c < ( requests - 1 ); c++)
  {
    for (int d = 0 ; d < requests - c - 1; d++)
    {
      if (diskQueue[d] > diskQueue[d+1])
      {
        swap       = diskQueue[d];
        diskQueue[d]   = diskQueue[d+1];
        diskQueue[d+1] = swap;
      }
    }
  }
}

void cloneRequests(){
  for (int i = 0; i < requests; i++) {
    clone[i] = diskQueue[i];
  }
}

int scanComplete(){
  for (int i = 0; i < requests; i++) {
    if(clone[i] != -1)
      return 0;
  }

  return 1;
}

int Search(int pos){
  for (int i = 0; i < requests; i++) {
    if(diskQueue[i] == pos){
      return 1;
    }
  }
  return 0;
}

void CSCAN(){
  printf("CSCAN...\n");
  printf("Enter the current position\n");
  scanf("%d",&currentPosition);
  int done = 0;
  // sort();
  int headMovement = 0;
  do{
    if(Search(currentPosition))
      clone[currentPosition] = -1;
    if(currentPosition == diskLimit)
      currentPosition = 0;
    else
      currentPosition++;
    headMovement++;
  }
  while(scanComplete());

  // for (int i = 0; i < requests; i++) {
  //   if(i == 0){
  //     headMovement = diskQueue[0];
  //     continue;
  //   }
  //   headMovement = headMovement + abs(diskQueue[i] - diskQueue[i-1]);
  // }

  printf("The total head movement for SCAN in %d\n", headMovement);
  return;
}


void scanForward(int done){
  do{
    if(Search(currentPosition))
      done++;
    if(currentPosition == diskLimit)
      scanBackward(done);
    else
      currentPosition++;
      headMovement++;
  }
  while(done != requests);
  if(done == requests)
    return;
}

void scanBackward(int done){
  do{
    if(Search(currentPosition))
      done++;
    if(currentPosition == 0)
      scanForward(done);
    else
      currentPosition--;
      headMovement++;
  }
  while(done != requests);
  if(done == requests)
    return;
}
void SCAN(){
  int done = 0;
  printf("SCAN...\n");
  printf("Enter the current position\n");
  scanf("%d",&currentPosition);
  scanForward(done);
  printf("The total head movement in CSAN is %d\n",headMovement);
  return;

}
