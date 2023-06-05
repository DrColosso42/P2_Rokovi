#include <stdio.h>
#include <stdlib.h>

void greska(){
    printf("-1\n");
    exit(EXIT_FAILURE);
}

void print_bits(unsigned x){
    for(int i=0; i<(sizeof(x)*8); i++){
        printf("%d", x&(1<<(sizeof(x)*8-i-1)) ? 1 : 0);
    }
    printf("\n");
}

int invertuj_kti(unsigned b, int k){
    unsigned x = 0;
    for(int i = 0; i< sizeof(b)*8-1; i++ ){
        unsigned l = b&1;
        // printf(" b: ");
        // print_bits(b);
        // printf(" l: ");
        // print_bits(l);
        

        if(i%k == 0){
            l = (~l)&1;
            // printf("~l: ");
            // print_bits(l);
            
        }
        

        
        
        b>>=1;
        x+=(l<<i);
        // printf(" x: ");
        // print_bits(x);
        

        // printf("---\n");
        
        
    }

    return x;
}

int main(int argc, char const *argv[])
{
    int i;
    unsigned b;
    scanf("%d %u", &i, &b);

    if(i<1) greska();

    // print_bits(5);

    print_bits(b);
    b=invertuj_kti(b,i);
    print_bits(b);

    print_bits(16805887);

    printf("%d",b);

    return 0;
}
