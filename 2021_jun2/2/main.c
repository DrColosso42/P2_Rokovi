#include <stdio.h>
#include <stdlib.h>
void print_bits(unsigned x){
    for(int i=0; i<(sizeof(x)*8); i++){
        printf("%d", x&(1<<(sizeof(x)*8-i-1)) ? 1 : 0);
    }
    printf("\n");
}

unsigned popuni(unsigned x){
    int size = sizeof(unsigned)*8;
    unsigned tmp = 0;
    int poceli = 0;
    for(int i =0; i<size;i++){
        if(!poceli && x&1 == 1){
            poceli = 1;
        }
        if(poceli){
            tmp+=(1<<i);
        }

        x>>=1;
        if(!x) break;
    }
    return tmp;
}

int main(){
    unsigned int x;
    scanf("%u", &x);

    // print_bits(x);
    // print_bits(popuni(x));

    printf("%u\n", popuni(x));

    return 0;
}