#include <stdio.h>
#include <signal.h>

void nu(int sgn) {
    printf("NU!\n");
    signal(SIGINT, nu);
}

int main() {
    signal(SIGINT, nu);
    while(1);
    return 0;
}
