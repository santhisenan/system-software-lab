#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//structure for representing a node in the tree
typedef struct node {
  char name[10];
  int type; // Assume that type = 1 for directories and type=2 for files.
  struct node* subTree[10];//assume that a max of 5 subtrees are possible
  int children;

}node;

// //structure for representing a tree
// typedef struct tree{
//   node N;
// }tree;

void createDirectory();
void createFile();
void deleteFile();
void searchFile();
void list();
void createRoot();

void search();


node* root;

int main(int argc, char const *argv[]) {

  int choice;
  int cont = 1;
  system("clear");

  //creating the root directory
  root = (node*) malloc(sizeof (node));
  createRoot();

  do{
    printf("Enter the operation:\n1.Create a directory \n2.Create File \n3.Delete File \n4.Search \n5.List directory tree\n6.Exit\n");
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

void createRoot(){
  root->type = 1;

  printf("Enter the name of root directory\n");
  scanf("%s",root->name);

  root->children = 0;

  for (int i = 0; i < 10; i++) {
    root->subTree[i] = NULL;
  }
}

int found;
node* current_search;
void search(char item[10] , node* root){
  found = 0;
  current_search = root;
  for (int i = 0; i < 10; i++) {
    // printf("%d\n", found );
    if(strcmp(current_search->name, item) == 0){
      // printf("%s\n", current_search->name);

      found = 1;
      return;
      // node* res = (node*) malloc(sizeof (node))
      // res = current;
    }
    else{
      if(current_search->subTree[i]){
        search(item , current_search->subTree[i]);
      }
    }
  }
};


void createDirectory(){
  // node newDir;
  node* newDir = (node*)malloc(sizeof (node));
  newDir->type = 1;
  char parentName[10];

  printf("Enter the name of parent directory\n");
  scanf("%s",parentName);

  printf("Enter the name of directory to be created\n");
  scanf("%s",newDir->name);

  newDir->children = 0;

  for (int i = 0; i < 10; i++) {
    newDir->subTree[i] = NULL;
  }

  //search for the parent node and add the new directory as a child
  search(parentName , root);
  if(found){
    if(current_search->children < 10){
      current_search->subTree[++current_search->children] = newDir;
      // printf("%s , %d\n", current_search->subTree[current_search->children]->name , found);
      printf("Directory %s created under directory %s\n", newDir->name , parentName);
    }
  }
  else{
    printf("Enter a valid parent node's name\n");
  }


  //:TODO display the tree


  return;
};
void createFile(){
  char pName[10] , fName[10];
  printf("Enter the name of parent\n");
  scanf("%s", pName);
  search(pName , root);
  if(found){
    node * newFile = (node *)malloc(sizeof (node));
    printf("Enter the name of file\n");
    scanf("%s", fName);
    strcpy(newFile->name, fName);
    newFile->children = 0;
    newFile->type = 0;
    for (int i = 0; i < 10; i++) {
      newFile->subTree[i] = NULL;
    }
    printf("File %s created under directory %s\n", fName , pName);
  }
  else{
    printf("Enter a valid parent node's name\n");
  }
};


void searchFile(){
  char item[10];
  printf("Enter the name of file/directory to be searched\n");
  scanf("%s", item );

  // node* result;
  // result = search(item , root);
  if(found){
    printf("Item found\n");
  }
  else{
    printf("Item not found\n");
  }

};

void deleteFile(){};


void list(){

};
