#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//structure fot the directory
struct {
  char dirName[10], fileName[10][10];
  int fileCount;
} dir[10];

int dirCount=0;

void createDirectory();
void createFile();
void deleteFile();
void searchFile();
void list();

int main(){

  int choice;
  int cont = 1;
  system("clear");

  do{
  printf("Enter the operation:\n1.Create a directory \n2.Create File \n3.Delete File \n4.Search for a File\n5.List directory tree\n6.Exit\n");
  scanf("%d", &choice);

  switch(choice){
    case 1:
      // printf("Choice 1\n");
      createDirectory();
      break;

    case 2:
      createFile();
      break;

    case 3:
      deleteFile();
      break;

    case 4:
      searchFile();
      break;

    case 5:
      list();
      break;

    case 6:
      cont = 0;
      break;

    default:
      printf("Enter a valid choice\n");
  }

} while(cont);


  return 0;
}

void createDirectory(){
  printf("Enter the name of the directory\n");
  scanf("%s",dir[dirCount].dirName);
  dir[dirCount].fileCount = 0;
  dirCount++;
  printf("directory '%s' created\n", dir[dirCount-1].dirName);
  return;
};
void createFile(){
  char dName[10] , fName[10];
  int done = 0;
  printf("Enter the name of the directory\n");
  scanf("%s", dName);
  printf("Enter the name of the new file\n");
  scanf("%s", fName);
  for (int i = 0; i < dirCount; i++) {
    if(strcmp(dName , dir[i].dirName) == 0){
      done = 1;
      if(dir[i].fileCount < 10){
        dir[i].fileCount++;
        strcpy(dir[i].fileName[dir[i].fileCount],fName);
        printf("File %s added to directory %s\n\n", fName, dName );
      }
      else{
        printf("Please choose another directory\n\n");
      }
      break;
    }
  }
  if (!done) {
    printf("Directory not found\n\n");
  }

  return;
};
void deleteFile(){
  int found = 0;
  char fName[10];
  printf("Enter the name of file to be deleted\n");
  scanf("%s", fName);
  for (int i = 0; i < dirCount; i++) {
    for(int j = 0; j<=dir[i].fileCount; j++){
      if(strcmp(fName , dir[i].fileName[j]) == 0){
        found = 1;
        if(dir[i].fileCount == 1){
          dir[i].fileCount = 0;
        }
        else if(j == dir[i].fileCount){
          dir[i].fileCount--;
        }
        else{
          strcpy(dir[i].fileName[j] , dir[i].fileName[dir[i].fileCount]);
          dir[i].fileCount--;
        }
        printf("File deleted. Listing the directory tree\n");
        list();
      }
    }
  }
  if(!found){
    printf("File not found\n");
  }
};
void searchFile(){
  int found = 0;
  char fName[10];
  printf("Enter the name of file to be searched..\n");
  scanf("%s", fName);
  for (int i = 0; i < dirCount; i++) {
    for(int j = 0; j<=dir[i].fileCount; j++){
      if(strcmp(fName , dir[i].fileName[j]) == 0){
        found = 1;
        printf("File found in directory %s\n", dir[i].dirName );
      }
    }
  }
  if(!found)
    printf("File not found\n");
  return;
};


void list(){
  for (int i = 0; i < dirCount; i++) {
    printf("Directory %s\n" , dir[i].dirName);
    for(int j = 0; j<=dir[i].fileCount; j++){
      printf("%s\t", dir[i].fileName[j]);
    }
    printf("\n");
  }
  return;

};

//:TODO prevent adding files with same name
