#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int LOCCTR = 0;
int tokenCount = 0;
char LABEL[20];
char OPERAND[20];
char ARG[20];
FILE *symtab;



char** splitArray(const char*);
void updateLocationCounterNormal();
void updateLocationCounter(char*, int);

int main(int argc, char const *argv[]) {


  FILE *inputFile;
  inputFile = fopen("input.txt" , "r");
  if(!inputFile) {
    printf("inputFile file not found\n");
    return 0;
  }

  FILE *intermediateFile;
  intermediateFile = fopen("inter.txt", "w");
  if(!intermediateFile){
    printf("intermediateFile file not found\n");
    return 0;
  }

  symtab = fopen("symtab.txt", "w");
  if(!symtab){
    printf("SYMTAB file not found\n");
    return 0;
  }

  char* line;
  size_t len = 0;
  ssize_t read;

  //THE OPTAB
  char OPTAB[6][6] = {
    "LDA",
    "STA",
    "LDCH",
    "STCH"
  };


  // Read till the end of file
  while ((read = getline(&line, &len, inputFile)) != -1) {

    //tokenize the read line using splitArray function
    char** tokens = splitArray(line);
    char** it;
    int c = 0;
    for(it=tokens; it && *it; ++it) {

      //copy the first word into label
      if(c == 0)
      strcpy(LABEL, *it);

      //copy the second word to operand
      else if(c == 1)
      strcpy(OPERAND, *it);

      //copy the third word as argument
      else if(c == 2)
      strcpy(ARG, *it);

      c++;
      free(*it);
    }

    //check if the read word is START and initialize the location counter
    if(!strcmp(OPERAND, "START")) {
      LOCCTR = strtol(ARG, NULL, 10);
    }

    else {
      int found = 0;
      //search OPTAB for current OPERAND
      for (int i = 0; i < 6 && !found; i++) {
        if(!strcmp(OPERAND , OPTAB[i])){
          //increment to location counter by 3
          updateLocationCounterNormal();
          //the line contains an OPERAND and thus we dont want to update the symbol table
          found = 1;
        }
      }

      if(!found) {
        //update location counter by passing OPERAND and argument
        int arg = strtol(ARG, NULL, 10);
        updateLocationCounter(OPERAND, arg);

        //add a new entry to the SYMTAB
        char* newEntryOnSymtab = malloc(snprintf(NULL, 0, "%s %d", LABEL, LOCCTR) + 1);
        sprintf(newEntryOnSymtab, "%s %d \n", LABEL, LOCCTR);
        fputs(newEntryOnSymtab, symtab);
      }

      //add the new line containing the LOCCTR to intermediateFile
      char* newLine = malloc(snprintf(NULL, 0, "%d %s", LOCCTR, line) + 1);
      sprintf(newLine, "%d %s", LOCCTR, line);
      fputs(newLine, intermediateFile);
    }
  }
  free(line);
  return 0;
}

void updateLocationCounterNormal(){
  LOCCTR += 3;
}

void updateLocationCounter(char* word, int arg){
  if(!strcmp(word, "WORD")){
    LOCCTR += 3;
  }
  else if(!strcmp(word, "BYTE")){
    LOCCTR += 1;
  }

  else if(!strcmp(word, "RESW")){
    LOCCTR += 3*arg;
  }

  else if(!strcmp(word, "RESB")){
    LOCCTR += 1;
  }
}

//function to split the read line using space delimiter
char** splitArray(const char* line){
  char* str = strdup(line);
  int count = 0;
  int capacity = 10;
  char** result = malloc(capacity*sizeof(*result));
  char* tok = strtok(str, " ");

  while( tok != NULL )
  {
    result[count++] = tok ? strdup(tok) : tok;
    tok = strtok(NULL, " ");
  }

  free(str);
  tokenCount = count;
  return result;
}
