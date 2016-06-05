//Calculati suma elementelor unei matrici bi-dimensionale, folosind cate un thread pentru a calcula suma fiecarei linii, iar apoi thread-ul 
//main sa calculeze rezultatul final ca si suma a acestor sume.

#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>

int* mat;
int* vec;
#define rows 3
#define cols 3

void* calculate(void* line){
        int l = *(int*)line;
        int sum = 0;
        int j;
        for( j = 0; j < cols; j++){
                int offset = l * cols + j;
                sum += mat[offset];

        }
        vec[l] = sum;
        return NULL;
}
int main()
{
        int finalsum = 0;
        vec = (int*)malloc(rows * sizeof(int));
        mat = (int*)malloc(rows * cols * sizeof(int));
        int i,j;
        for( i = 0; i < rows; i++){
                for( j = 0; j < cols; j++){
                        int offset = i * rows + j;
                        mat[offset] = 10;
                }
        }

        pthread_t t1[rows];
        for( i = 0; i < rows; i++){
                pthread_create(&t1[i], NULL, calculate, &i);
                pthread_join(t1[i], NULL);
        }

        for( i = 0; i < rows; i++){
                finalsum += vec[i];
		}
        
		printf("%d", finalsum);
        free(vec);
        free(mat);
}
                       