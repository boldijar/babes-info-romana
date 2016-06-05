#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int a2b, b2a, n;

    n = 5;

    mkfifo("./a2b", 0600);
    mkfifo("./b2a", 0600);
    
    b2a = open("./b2a", O_RDONLY);
    a2b = open("./a2b", O_WRONLY);

    write(a2b, &n, sizeof(int));
    read(b2a, &n, sizeof(int));

    close(a2b);
    close(b2a);

    unlink("./a2b");
    unlink("./b2a");
    
    printf("%d\n", n);
    
    return 0;
}
