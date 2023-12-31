#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

int main(){

int status;
char input[100];
ssize_t bytesRead;


while(1){
    
    write(STDOUT_FILENO, "Bienvenue dans le Shell ENSEA.\nPour quitter, tapez 'exit'.\n", 59);

    bytesRead = read(STDIN_FILENO, input, 1024);
    
    input[bytesRead] = '\0';

    if (strcmp(input, "exit\n") == 0 || bytesRead == 0) {
        
        write(STDOUT_FILENO, "Bye bye...\n", 12);
        break;
        // If the user entered 'exit' or use CTRL+D we exit the program
         
        } 
    
        pid_t pid = fork();//We give birth to a new copy process
    
            if (pid == 0) {
                // Child process
                if (strlen(input) == 0) {
                    char *args[] = {"date", "-l", NULL};
                    // User entered nothing so the code prints the date
                    execvp(args[0], args);
                } else {
                    char *args[] = {input, "-l", NULL};
                    execvp(args[0], args);
                }
                
        } else if (pid > 0) {
            //Parent process
            
            waitpid(pid, &status, 0); //Wait the end of the child process
        } 
    
    
    }
}
