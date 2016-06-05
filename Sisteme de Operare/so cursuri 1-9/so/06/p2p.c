#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    printf("BEGIN Parinte %d\n", getpid());
    execl("./p2f", "./p2f", NULL);
    printf("END Parinte %d\n", getpid());
    return 0;
}
