#include <stdio.h>

void g() {
    int x[3];
    x[0] = 2;
    x[1] = 20;
    x[2] = 200;
}

int* f() {
    int x[3];
    x[0] = 1;
    x[1] = 10;
    x[2] = 100;
    return x; // EROARE!!!
}

int main() {
    int* a = f();
    g();
    printf("%d  %d  %d\n", a[0], a[1], a[2]);
    return 0;
}
