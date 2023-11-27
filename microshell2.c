#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>


while(1){
    
    write(STDOUT_FILENO, "Bienvenue dans le Shell ENSEA.\nPour quitter, tapez 'exit'.\n", 57);

    bytesRead = read(STDIN_FILENO, commande, sizeof(commande));
    
    commande[bytesRead] = '\0';

    if (strcmp(commande, "exit") == 0) {
        write(STDOUT_FILENO, "Au revoir !\n", 12);
        break;
        
        } 
        pid_t pid = fork();

        if (pid == 0) {
            // Processus enfant
            execlp(input, input, NULL);
            perror("Erreur lors de l'exécution de la commande"); // En cas d'échec de l'exécution
            exit(EXIT_FAILURE);
        } else if (pid > 0) {
            // Processus parent
            wait(NULL); // Attends la fin du processus enfant
        } else {
            perror("Erreur lors de la création du processus");
        }
    
    
}



