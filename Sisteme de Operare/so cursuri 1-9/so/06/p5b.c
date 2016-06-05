#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int a2b, b2a, n;

    a2b = open("./a2b", O_RDONLY);
    b2a = open("./b2a", O_WRONLY);

    read(a2b, &n, sizeof(int));
    n *= 2;
    write(b2a, &n, sizeof(int));

    close(a2b);
    close(b2a);

    return 0;
}
