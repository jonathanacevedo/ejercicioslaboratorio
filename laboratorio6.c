#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{

    int  status;
    int rc = fork();    

    if (rc < 0) {
        // fork falló, error
        fprintf(stderr, "fork fallo \n");
        exit(1);
    } else if (rc == 0) {            // proceso hijo (nuevo proceso)
       printf("PID del proceso hijo: %d \n",(int) getpid());

    } else {                         // proceso padre

       int wc = waitpid(rc, &status, WCONTINUED);
       printf("PID del proceso padre: %d \n",(int) getpid());
       printf("Waitpid retorna: %d \n\n", wc);                
       
    }


    return 0;
}