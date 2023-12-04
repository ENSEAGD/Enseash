#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <stdio.h>
void displayPrompt(int status, struct timespec start_time) {
    struct timespec end_time;
    clock_gettime(CLOCK_MONOTONIC, &end_time);

    long process_time = (end_time.tv_sec - start_time.tv_sec) * 1000 + 
      (end_time.tv_nsec - start_time.tv_nsec) / 1000000;//The struct given at the output of the function clock_gettime give us 2 variables that we put in ms and add to give the elapsed time 

    if (WIFEXITED(status)) {
        // Si le processus s'est terminé normalement
        write(STDOUT_FILENO, "[exit:", 6);
        dprintf(STDOUT_FILENO, "%d|%ldms", WEXITSTATUS(status), elapsed_time);
        write(STDOUT_FILENO, "] % ", 4);
    } else if (WIFSIGNALED(status)) {
        // Si le processus a été interrompu par un signal
        write(STDOUT_FILENO, "[sign:", 6);
        dprintf(STDOUT_FILENO, "%d|%ldms", WTERMSIG(status), elapsed_time);
        write(STDOUT_FILENO, "] % ", 4);
    }
}

main(){


char commande[100];
ssize_t bytesRead;


while(1){
    
    write(STDOUT_FILENO, "Bienvenue dans le Shell ENSEA.\nPour quitter, tapez 'exit'.\n", 57);

    bytesRead = read(STDIN_FILENO, input, 1024);
    
    commande[bytesRead] = '\0';

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
            wait(NULL); //Wait the end of the child process
        } 
    
    
    }
}
