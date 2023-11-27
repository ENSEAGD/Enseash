#include <unistd.h>
#include <stdio.h>
#include <strln.h>
#include <stdio.h>
#include <string.h>

int main () {

char commande[100];
ssize_t bytesRead;

while(1){
    
    write(STDOUT_FILENO, "Bienvenue dans le Shell ENSEA.\nPour quitter, tapez 'exit'.\n", 57);

    bytesRead = read(STDIN_FILENO, commande, sizeof(commande));
    
    commande[bytesRead] = '\0';

    if (strcmp(commande, "exit") == 0) {
        write(STDOUT_FILENO, "Au revoir !\n", 12);
        break;
        
        } else {
        
        write(STDOUT_FILENO, "nous ne connaissons pas la commande que vous avez entrez pour l'instant je ne connais que la commande 'exit' :3 /n", 99)
            
        }
    
    
}

