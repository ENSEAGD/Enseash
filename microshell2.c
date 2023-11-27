#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>

main(){


char commande[100];
ssize_t bytesRead;


while(1){
    
    write(STDOUT_FILENO, "Bienvenue dans le Shell ENSEA.\nPour quitter, tapez 'exit'.\n", 57);

    bytesRead = read(STDIN_FILENO, commande, 1024);
    
    commande[bytesRead] = '\0';

    if (strcmp(commande, "exit") == 0) {
        break;
        
        } 
        pid_t pid = fork();

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
            wait(NULL); //Wait the end of the child process
        } 
    
    
    }
}



