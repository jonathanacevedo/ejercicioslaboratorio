#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    printf("hello world (pid:%d)\n", (int) getpid());

    int x = 100;

    printf("El valor de la variable es: %d \n", x);

    int rc = fork();    

    if (rc < 0) {
        // fork falló, error
        fprintf(stderr, "fork fallo \n");
        exit(1);
    } else if (rc == 0) {            // proceso hijo (nuevo proceso)

        printf("El valor de la variable en el proceso hijo es: %d \n", x);

        x = 110;

        printf("El valor de la variable luego de modificar en el proceso hijo es: %d \n", x);

    } else {                     // proceso padre
        
        x = 120;

        printf("El valor de la variable en el proceso padre es: %d \n", x);

    }
    return 0;
}