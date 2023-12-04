#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>

int main(){


char input[100];
ssize_t bytesRead;


while(1){
    
    write(STDOUT_FILENO, "Bienvenue dans le Shell ENSEA.\nPour quitter, tapez 'exit'.\n", 59);

    bytesRead = read(STDIN_FILENO, input, 1024);
    
    input[bytesRead] = '\0';

    if (strcmp(input, "exit\n") == 0) {
        
        write(STDOUT_FILENO, "\n", 2);//if the user enter 'exit we exit the program
        
        break;
         
        } 
        pid_t pid = fork();//We give birth to a new copy process

        if (pid == 0) {
            //Child process
            if (strlen(input) == 0) {
                //User entered nothing so the code print the date
                execlp("date", "date", NULL);
            }
            else{
            execlp(input, input, NULL);
            }
            exit(EXIT_FAILURE);
        } else if (pid > 0) {
            //Parent process
            waitpid(pid, &status, 0) < 0);
        } 
    
    
    }
}



