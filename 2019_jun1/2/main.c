#include <stdio.h>
#include <stdlib.h>

void print_bits(unsigned x){
    for(int i=0; i<(sizeof(x)*8); i++){
        printf("%d", x&(1<<(sizeof(x)*8-i-1)) ? 1 : 0);
        if(i%8 == 7 && i){
            printf("  ");
        }
    }
    printf("\n");
}

unsigned invertuj(unsigned x){
    size_t size = sizeof(x)*8;
    unsigned tmp = 0;
    for(int i = 0; i<size;i++){
        if(i<16){
            if(i % 2 == 0){
                tmp += ((~x&1))<<i;
            } else {
                tmp += (x&1)<<i;
            }
            
        } else if(i < 32){
            if(i % 2 == 1){
                tmp += ((~x&1))<<i;
            } else {
                tmp += (x&1)<<i;
            }
        }
        x>>=1;
    }
    return tmp;
}



int main(){
    unsigned x;
    scanf("%x",&x);

    print_bits(x);
    print_bits(invertuj(x));
    printf("0x%x\n",invertuj(x));

    return 0;
}