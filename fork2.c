#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid_figlio, pid_nipote;

    // Primo fork: Nonno crea Figlio
    pid_figlio = fork();

    if (pid_figlio < 0) {
        perror("Errore fork Figlio");
        exit(1);
    }

    if (pid_figlio == 0) {
        // Siamo nel Figlio
        printf("FIGLIO: PID=%d, PPID=%d\n", getpid(), getppid());

        // Secondo fork: Figlio crea Nipote
        pid_nipote = fork();

        if (pid_nipote < 0) {
            perror("Errore fork Nipote");
            exit(1);
        }

        if (pid_nipote == 0) {
            // Siamo nel Nipote
            printf("NIPOTE: PID=%d, PPID=%d\n", getpid(), getppid());
        }

    } else {
        // Siamo nel Nonno
        printf("NONNO: PID=%d, PPID=%d\n", getpid(), getppid());
    }

    return 0;
}
