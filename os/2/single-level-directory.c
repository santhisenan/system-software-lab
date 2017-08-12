#include<stdio.h>
#include<string.h>
// #include<conio.h>
//A structure to store the directory
struct {
  char dirName[20], fileNames[20][20];
  int fileCount;
} dir = {0};

// dir.fileCount = 0;

void createFile();
void deleteFile();
void listFiles();
void searchFile();

int main(int argc, char const *argv[]) {
  int operation;
  int exit = 1;

  printf("Enter the name of the directory\n");
  scanf("%s", dir.dirName );


  // clrscr();

  do{
    printf("Which operation do you want to perform ?\n 1.Create File \n 2.Delete File \n 3.Display Files \n 4.Search Files \n 5.Exit\n");
    scanf("%d", &operation );

    switch(operation){
      case 1:
        createFile();
        break;
      case 2:
        deleteFile();
        break;
      case 3:
        listFiles();
        break;
      case 4:
        searchFile();
        break;
      case 5:
        printf("Exiting..\n");
        exit = 0;
    }
  } while(exit);
  return 0;
}

void createFile(){
  if(dir.fileCount > 10){
    printf("Maximum number of files reached. Please delete some files\n");
    return;
  }
  printf("Enter the name of file to be created.\n");
  scanf("%s", dir.fileNames[dir.fileCount++]);
  // printf("%d\n" , dir.fileCount);
  //display all files :TODO
  listFiles();
  return;
}

void deleteFile(){
  char file[10];
  int i;
  printf("Enter the name of the file to be deleted.\n");
  scanf("%s", file);

  for(i=0 ; i<dir.fileCount ; i++){
    if(strcmp(file , dir.fileNames[i]) == 0){
      if(dir.fileCount == 1){
        // strcpy(dir.fileNames[0] , &empty);
        memset(dir.fileNames[i] , 0 , sizeof dir.fileNames);
      }
      else if(i == dir.fileCount-1){
        strcpy(dir.fileNames[0] , dir.fileNames[i]);
        dir.fileCount = 0;
        memset(dir.fileNames[i] , 0 , sizeof dir.fileNames);
      }
      else{
        printf("%d %d\n" , i, dir.fileCount);
        strcpy(dir.fileNames[i] , dir.fileNames[--dir.fileCount]);
        memset(dir.fileNames[dir.fileCount] , 0 , sizeof dir.fileNames);
      }
      //:TODO display file list
      listFiles();
    }
    else if(i == dir.fileCount-1){
      printf("File not found\n");
    }
  }
}

void listFiles(){
  int i;
  printf("\n");
  printf("Files in the directory %s are\n", dir.dirName );
  for(i=0; i<dir.fileCount ; i++){
    printf("%s\t",dir.fileNames[i]);
  }
  printf("\n");
  printf("\n");
}

void searchFile() {
  char file[10];
  int i;
  printf("Enter the filename\n");
  scanf("%s", file);
  for(i=0 ; i<dir.fileCount ; i++){
    if(strcmp(file , dir.fileNames[i]) == 0){
      printf("File Found\n");
      return;
    }
  }
  printf("File not found\n");

}
