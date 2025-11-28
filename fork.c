#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Errore in fork()");
        return 1;
    }

    if (pid == 0) {
        printf("Sono il processo figlio.\n");
        printf("PID del figlio: %d\n", getpid());
        printf("PID del processo padre: %d\n", getppid());
    } else {
        printf("Sono il processo padre.\n");
        printf("PID del padre: %d\n", getpid());
        printf("PID del processo figlio: %d\n", pid);
    }

    return 0;
}
