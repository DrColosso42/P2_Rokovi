#include <stdio.h>
#include <stdlib.h>

void print_bits(unsigned x){
    for(int i=0; i<(sizeof(x)*8); i++){
        printf("%d", x&(1<<(sizeof(x)*8-i-1)) ? 1 : 0);
    }
    printf("\n");
}

unsigned izmeni(unsigned x){
    size_t size = sizeof(x)*2;
    unsigned helper =0xF;
    unsigned tmp = 0;
    for(int i = 0; i<size;i++){
        if(i%2 == 0){
            tmp += helper<<i*4;
        } else {
            tmp += (((x)>>4*i)&0xF)<<4*i;
        }
    }
    return tmp;
}

int main(){
    unsigned x;
    scanf("%x", &x);

    printf("0x%x\n", izmeni(x));

    return 0;
}
