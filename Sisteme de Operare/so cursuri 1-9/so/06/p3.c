#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int i, p;
    char* ex[] = {"./p2f", "/bin/ls", "/bin/ps"};

    printf("BEGIN Parinte %d\n", getpid());
    for(i=0; i<3; i++) {
        p = fork();
        if(p == 0) {
            execl(ex[i], ex[i], NULL);
            exit(0);
        }
    }

    printf("Hop si eu %d\n", getpid());

    for(i=0; i<3; i++) {
        wait(0);
    }

    printf("END Parinte %d\n", getpid());
    return 0;
}
