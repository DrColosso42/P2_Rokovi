#include <stdio.h>
#include <stdlib.h>

void print_bits(unsigned x);

unsigned invertovanje(unsigned x){
    unsigned temp = 0;
    for(int i = 0; i<sizeof(x)*8; i++){
        unsigned l = x&1;
        if((i % 4 >= 2) && i!=0){
            l = ~l&1;
        }
        // print_bits(x);
        // print_bits(l);
        

        l<<=i;
        temp+=l;
        // print_bits(temp);
        // printf("-----\n");
        x>>=1;
    }
    return temp;
}

void greska(){
    fprintf(stderr,"-1");
    exit(EXIT_FAILURE);
}

void print_bits(unsigned x){
    for(int i=0; i<(sizeof(x)*8); i++){
        printf("%d", x&(1<<(sizeof(x)*8-i-1)) ? 1 : 0);
    }
    printf("\n");
}

int main(){
    int x;

    scanf("%x", &x);

    // print_bits(x);

    x = invertovanje(x);
    // print_bits(x);
    printf("0x%x\n", x);


    return 0;
}