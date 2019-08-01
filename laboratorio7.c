#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{

    int rc = fork();    

    if (rc < 0) {               // fork falló, error
        fprintf(stderr, "fork fallo \n");
        exit(1);
    } else if (rc == 0) {       // proceso hijo (nuevo proceso)
        close(STDOUT_FILENO); 
        printf("Proceso hijo \n"); //esto NO se llega a imprimir
    } else {                    // proceso padre
        printf("Proceso padre\n");
    }

    return 0;
}