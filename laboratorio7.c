#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{

    int sz;
    int fd = open("archivo_de_prueba", O_WRONLY | O_APPEND);

    int rc = fork();    

    if (rc < 0) {
        // fork falló, error
        fprintf(stderr, "fork fallo \n");
        exit(1);
    } else if (rc == 0) {            // proceso hijo (nuevo proceso)

        close(STDOUT_FILENO); 

        printf("La respuesta del open() desde el hijo es: %d \n", fd);

    } else {                     // proceso padre
        //printf("La respuesta del open() desde el padre es: %d \n", fd);


    }

    close(fd); 

    return 0;
}