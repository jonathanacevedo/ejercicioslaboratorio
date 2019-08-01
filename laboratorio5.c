#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{

    int rc = fork();    

    if (rc < 0) {
        // fork falló, error
        fprintf(stderr, "fork fallo \n");
        exit(1);
    } else if (rc == 0) {            // proceso hijo (nuevo proceso)
       printf("Proceso hijo PID: %d \n",(int) getpid());
        int wc = wait(NULL);
        printf("Wait retorna: %d \n", wc);
    } else {                         // proceso padre
        int wc = wait(NULL);
        printf("Proceso padre PID:%d \n",(int) getpid());
        printf("Wait retorna: %d \n", wc);                  
    }

    return 0;
}