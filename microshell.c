#include <unistd.h>
#include <stdio.h>
#include <strln.h>

int main () {

write(STDOUT_FILENO, "Bienvenue dans le Shell ENSEA.\nPour quitter, tapez 'exit'.\n", 57);
    
    return 0;
}

