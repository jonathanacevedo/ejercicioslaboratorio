## Ejercicios en el laboratorio ## 

1. Escriba un programa que llame un ```fork()```. Antes del llamado del ```fork()```, declare una variable de acceso (por ejemplo, ```x```) y asígnele un valor (por ejemplo, ```100```). Responda las siguientes preguntas:
  * ¿Cuál es el valor de la variable en el proceso hijo?
  Apenas se realiza el fork, el valor de la variable en el proceso hijo es el mismo que el de la variable del proceso padre.
  * ¿Qué sucede con la variable cuando el proceso hijo y el padre cambian el valor de ```x```?
  Las variables en cada proceso no se encuentran relacionas ya que pertenecen a imagenes de procesos diferentes y por lo tanto son diferentes a pesar de estar identificadas con un mismo nombre.
2. Escriba un programa que abra un archivo (con la llamada ```open()```) y entonces llame a ```fork()```. **Nota**: El siguiente [enlace](https://www.geeksforgeeks.org/input-output-system-calls-c-create-open-close-read-write/) puede ser de utilidad para entender la llamada ```open()```.
  * ¿Pueden el padre y el hijo acceder al file descriptor retornado por ```open()```? 
  Sí
  * ¿Qué pasa si ellos empiezan a escribir el archivo de manera concurrente, es decir, a la misma vez?
  Ambas modificaciones o escrituras quedan grabadas en el archivo.
3. Escriba un programa usando ```fork()```. El proceso hijo imprimirá ```"Hello"```; el proceso padre imprimirá ```"goodbye"```. Usted deberá asegurar que el proceso hijo imprima en primer lugar; ¿usted podría hacer esto sin llamar ```wait()``` en el padre? 
Sí, usando el comando sleep()
4. Escriba un programa que llame ```fork()``` y entonces llame alguna forma de ```exec()``` para correr el programa ```/bin/ls```. Intente probar todas las variaciones de la familia de funciones ```exec()``` incluyendo (en linux) ```execl()```, ```execle()```, ```execlp()```, ```execv()```, ```execvp()``` y ```execvpe()```. ¿Por qué piensa usted que existen tantas variaciones para la misma llamada básica?
5. Escriba ahora un programa que use ```wait()``` para esperar que el proceso hijo finalice su ejecución. 
¿Cuál es el valor de retorno de la función ```wait()```?
El PID del hijo.
¿Qué pasa si usted usa la función ```wait``` en el hijo?
Retorna un -1 (falla), ya que el proceso hijo no tiene más hijos en este caso.
6. Haga un programa, como el del ejercicio anterior, con una breve modificación, la cual consiste en usar ```waitpid()``` en lugar de ```wait()```. ¿Cuándo podría ser ```waitpid()``` útil?
waitpid es útil cuando el proceso padre tiene más de un proceso hijo, pero sólo necesita esperar a un hijo o a un grupo en específico de ellos. 
7. Escriba un programa que cree un proceso hijo y entonces en el proceso hijo cierre la salida estandar (```STDOUT FILENO```). ¿Qué pasa si el hijo llama ```printf()``` para imprimir alguna salida después de cerrar el descriptor?
