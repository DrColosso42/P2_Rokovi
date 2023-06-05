#include <stdio.h>
#include <stdlib.h>

int cmp(const void *p1,const void *p2){
    int * n1 = (int * )p1;
    int * n2 = (int * )p2;
    
    printf("%d %d\n", *n1, *n2);

    return *n1 - *n2;
}

int main(){
    int lista[] = {1, 3, 7, 12, 15, 24, 38};
    
    int trazeno = 24;

    int * ptr = bsearch(&trazeno, lista, 7, sizeof(int),cmp);


}