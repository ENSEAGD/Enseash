#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <stdio.h>

void displayPrompt(int status) {//we create a fonction to display the return code
    if (WIFEXITED(status)) {
        //If the process ended normally
        write(STDOUT_FILENO, "[exit:", 6);
        dprintf(STDOUT_FILENO, "%d", WEXITSTATUS(status));
        write(STDOUT_FILENO, "] ", 4);
    } else if (WIFSIGNALED(status)) {
        //If the process have been interrupted by a signal
        write(STDOUT_FILENO, "[sign:", 6);
        dprintf(STDOUT_FILENO, "%d", WTERMSIG(status));
        write(STDOUT_FILENO, "] % ", 4);
    }
}


int main(){


char input[100];
ssize_t bytesRead;


while(1){
    
    write(STDOUT_FILENO, "Bienvenue dans le Shell ENSEA.\nPour quitter, tapez 'exit'.\n", 57);

    bytesRead = read(STDIN_FILENO, input, 1024);
    
    input[bytesRead] = '\0';

    if (strcmp(input, "exit") == 0 || bytesRead == 0) {
        
        write(STDOUT_FILENO, "Bye bye...\n", 12);
        break;
        // If the user enter 'exit' or use CTRL+D we exit the program
         
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
            waitpid(pid, &status, 0) < 0); //Wait the end of the child process
        } 
    
    
    }
}
