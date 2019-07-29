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
        printf("La respuesta del open() desde el hijo es: %d \n", fd);
        sz = write(fd, "Hola desde el proceso hijo \n", strlen("Hola desde el proceso hijo \n")); 
        printf("variable sz desde el proceso hijo: %d \n", sz);

    } else {                     // proceso padre
        printf("La respuesta del open() desde el padre es: %d \n", fd);
        sz = write(fd, "Hola desde el proceso padre \n", strlen("Hola desde el proceso padre \n")); 
        printf("variable sz desde el proceso padre %d \n", sz);

    }

    close(fd); 

    return 0;
}