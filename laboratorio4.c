#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    pid_t pid = fork();    
    if (pid < 0) {               
        fprintf(stderr, "fork fallo \n");
        exit(1);
    } else if (pid == 0) {      
        
        pid = fork(); 
        if (pid == 0) {         

            pid = fork(); 
            if (pid == 0) {       
                
                pid = fork(); 
                if (pid == 0) {

                    pid = fork(); 
                    if (pid == 0) {

                        pid = fork(); 
                        if (pid == 0) {            

                        }else {
                        wait(NULL);  
                        printf("PROCESO 6\n");                  
                        char *const cmd[] = {"ls", "-l", NULL};
                        execvp(cmd[0], cmd);
                        }                           

                    }else {
                    wait(NULL);                    
                    printf("PROCESO 5\n");
                    char* envp[] = { "some", "environment", NULL };
                    char *const argv[] = {"ls", NULL};
                    execvpe(argv[0], argv, envp);
                    }

                }else {
                wait(NULL);                    
                printf("PROCESO 4\n");
                char *const argv[] = {"/bin/ls", NULL};
                execv(argv[0], argv);
                }

            }else {
            wait(NULL);                    
            printf("PROCESO 3\n");
            execlp("ls", "ls", "-l", NULL);
            }

        }else {
        wait(NULL);                    
        printf("PROCESO 2\n");
        char* envp[] = { "some", "environment", NULL };
        execle("/bin/ls", "ls", NULL, envp);
        }
        
    } else {
        wait(NULL);                    
        printf("PROCESO 1\n");
        execl("/bin/ls", "ls", NULL);
    }

    return 0;
}