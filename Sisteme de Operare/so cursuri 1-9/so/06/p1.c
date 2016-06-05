#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int i;
    int p;

    for(i=0; i<5; i++) {
        p = fork();
        if(p == 0) {
            exit(0);
        }
    }

    sleep(5);

    for(i=0; i<5; i++) {
        wait(0);
    }
    return 0;
}
