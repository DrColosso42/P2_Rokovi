#include <stdio.h>
#include <stdlib.h>

void print_bits(int x){
    size_t size = sizeof(x)*8;
    for(int i = 0; i<size; i++){
        printf("%d", (1<<(size-1))&x ? 1 : 0 );
        x <<= 1;
    }
    printf("\n");
}

int vodecih_nula(int x){
    int br = 0;
    while(!(x & 1<<(sizeof(x)*8-1))){
        // print_bits(x);
        br++;
        x<<=1;
    }
    return br;
}

int krajnjih_nula(int x){
    int br = 0;
    while(!(x&1)){
        br++;
        x>>=1;
    }
    return br;
}

int main(){
    int x;
    scanf("%d", &x);

    printf("%d %d\n",vodecih_nula(x),krajnjih_nula(x));

    return 0;
}