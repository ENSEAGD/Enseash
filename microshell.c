#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <stdio.h>

int main () {

char input[100];
ssize_t bytesRead;

while(1){
    
    write(STDOUT_FILENO, "Bienvenue dans le Shell ENSEA.\nPour quitter, tapez 'exit'.\n", 59);

    bytesRead = read(STDIN_FILENO, input, sizeof(input));
    
    input[bytesRead] = '\0';

    if (strcmp(input, "exit\n") == 0) {
        
        write(STDOUT_FILENO, "\n", 0); //If the user enter 'exit' we exit the program

        break;
        
        } else {
        
        write(STDOUT_FILENO, "nous ne connaissons pas la commande que vous avez entrez pour l'instant je ne connais que la commande 'exit' :3 /n", 99);
            
        }
    
    
}
}

