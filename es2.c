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
            printf("FIGLIO: mio PID = %d\n", getpid());
            printf("FIGLIO: PID del padre = %d\n", getppid());
            exit(0);
        }

        else {
            printf("PADRE: mio PID = %d\n", getpid());
            printf("Il pid del figlio corrente è: %d\n", pid);

            pid = wait(&status);

            if (WIFEXITED(status))
                printf("Term. volontaria del processo %d con stato %d\n",
                       pid, WEXITSTATUS(status));
            else if (WIFSIGNALED(status))
                printf("Terminazione involontaria per segnale %d\n",
                       WTERMSIG(status));
        }
    }

    return 0;
}
