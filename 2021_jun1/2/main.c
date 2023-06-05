#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Zahteva se koriscenje matrica.c i matrica.h
// S ozbirom da nigde nisam pronasao te biblioteke
// Uradjeno je bez njih

void greska(){
    printf("-1\n");
    exit(EXIT_FAILURE);
}

int main(int argc, char** argv){
    int m,n;

    scanf("%d %d", &m, &n);

    if(m < 1 || n < 1) greska();

    int** a = malloc(m*sizeof(int*));
    for(int i = 0; i < m; i++){
        *(a+i) = malloc(n*sizeof(int));
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j<n; j++){
            scanf("%d", (*(a+i)+j));
        }
    }

    int max = INT_MIN;
    for(int j =0; j < n; j++){
        int min = INT_MAX;
        for(int i = 0; i < m; i++){
            int el = *(*(a+i)+j);
            if(el < min){
                min = el;
            }

        }
        if(min > max){
            max = min;
        }
    }

    // a[i][j] = *(*(a+i)+j)
    
    printf("%d\n",max);

    return 0;
}