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

int grupa_jedinica(unsigned b, int k){
    unsigned check = (1<<k)-1;
    int broj = 0;
    for(int i = 0; i < sizeof(b)*8-1; i++){
        if((b & check) == check) {
            broj++;
            
            }
        b>>=1;
    }
    return broj;

}

int main(int argc, char const *argv[])
{
    int x;
    unsigned b;

    scanf("%u %d", &b, &x);

    printf("%d\n",grupa_jedinica(b,x));



    return 0;
}
