#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define NFigli 4

int main() {

    int status, pid, x;

    for (x = 0; x < NFigli; x++) {

        pid = fork();

        if (pid == 0) {
            // CODICE FIGLIO
            printf("FIGLIO: mio PID = %d\n", getpid());
            printf("FIGLIO: PID del padre = %d\n", getppid());
            exit(0);   // il figlio termina con stato 0
        }

        else {
            // CODICE PADRE
            printf("PADRE: mio PID = %d\n", getpid());
            printf("Il pid del figlio corrente è: %d\n", pid);

            // attende la terminazione del figlio
            pid = wait(&status);

            printf("PADRE: terminato figlio %d con status = %d\n",
                   pid, status);
        }
    }

    return 0;
}
