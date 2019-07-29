#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	char *args[] = {"/bin/ls", NULL};
    char *env[] = {"PATH=C:\\TEST", NULL};

    char *const envp[2] = {"STEPLIB=SASC.V6.LINKLIB", NULL};

    int rc = fork();    

    char *argument[] = { "ls", 0 };

    if (rc < 0) {
        // fork falló, error
        fprintf(stderr, "fork fallo \n");
        exit(1);
    } else if (rc == 0) {            // proceso hijo (nuevo proceso)

       int rc2 = fork();
       if (rc2 < 0) {
       		// fork falló, error
        	fprintf(stderr, "fork fallo \n");
        	exit(1);
      	} else if (rc == 0) {
    		printf("Proceso nieto \n");
    		execle("/bin/ls", "ls", NULL, envp);
      	}  else {                     // proceso padre
	        printf("Proceso padre \n");
            execv("/bin/ls", argument);
    	}

    } else {                     // proceso padre

      	int rc3 = fork();
		if (rc3 < 0) {
	        // fork falló, error
	        fprintf(stderr, "fork fallo \n");
	        exit(1);
	    } else if (rc == 0) {            // proceso hijo (nuevo proceso)

	       int rc4 = fork();
	       if (rc4 < 0) {
	       		// fork falló, error
	        	fprintf(stderr, "fork fallo \n");
	        	exit(1);
	      	} else if (rc4 == 0) {
	    		printf("Proceso nieto \n");
	    		execle("/bin/ls", "ls", NULL, envp);
	      	}  else {                     // proceso padre
		        printf("Proceso padre \n");
	            execv("/bin/ls", argument);
	    	}

       if (rc3 < 0) {
       		// fork falló, error
        	fprintf(stderr, "fork fallo \n");
        	exit(1);
      	} else if (rc == 0) {
    		printf("Proceso segundo hijo \n");
    		execvpe("/bin/ls", args, env);
      	}  else {                     // proceso padre
	        printf("Proceso padre \n");
            execlp(input,"",(char*) 0)
    	}


        printf("Proceso hijo \n");
        

    }

    int execl("/bin/ls", (char *)0);

    execvp(argument[0], argument);

    




    return 0;
}