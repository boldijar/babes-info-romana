#include <stdio.h>

int main() {
    int*** m;
    int i, j, k;

    m = (int***) malloc(3*sizeof(int**));
    for(i=0; i<3; i++) {
        m[i] = (int**)malloc(4*sizeof(int*));
        for(j=0; j<4; j++) {
            m[i][j] = (int*)malloc(5*sizeof(int));
            for(k=0; k<5; k++) {
                m[i][j][k] = 8;
            }
        }
    }

    for(i=0; i<3; i++) {
        for(j=0; j<4; j++) {
            free(m[i][j]);
        }
        free(m[i]);
    }
    free(m);
}
