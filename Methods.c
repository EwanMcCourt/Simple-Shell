#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include "header.h"
#include "stdlib.h"

//Stage 1
int parse(char input [512]){
    char * tokens[512];
    char * token = strtok(input, " \n\t|<>&;");
    tokens[0] = token; 
    int i = 1;
     while(token != NULL ) {
      token = strtok(NULL, " \n\t|<>&;");
      tokens[i] = token;
      
      i++;
      
      }
      execute(tokens);
      return 0;
}




//Stage 2

int execute(char * tokens[]){
char * token =tokens[0] ;




pid_t pid = fork(); 
if (pid < 0){
    perror("Error!");

}
else if (pid  == 0){

if(execvp(tokens[0], tokens)==-1);{

    char * errormsg = tokens[0];
    perror(errormsg);
    exit(0);
}
}
else{
wait(NULL);

}

return 0;

}

//Stage 3




