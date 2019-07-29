#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{

    int rc = fork();    

    if (rc < 0) {
        // fork falló, error
        fprintf(stderr, "fork fallo \n");
        exit(1);
    } else if (rc == 0) {            // proceso hijo (nuevo proceso)
       printf("Hello \n");

    } else {                     // proceso padre
        sleep (1);
        printf("goodbye \n");

    }


    return 0;
}