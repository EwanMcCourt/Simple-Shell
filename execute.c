#include <stdio.h>
#include <string.h>
#include <unistd.h>

int execute(char * token){
char *argv[3];
argv[0] = token;
argv[1] = "-la";
argv[2] = NULL;
pid_t pid = fork(); 
if (pid < 0){
    perror("Error!");

}
else if (pid  == 0){
execvp(token, argv);
}
else{
wait(NULL);
printf("the child has completed");
}

return 0;

}