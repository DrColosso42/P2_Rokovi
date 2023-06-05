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

void greska(){
    printf("-1\n");
    exit(EXIT_FAILURE);
}

unsigned ukloni(unsigned x, unsigned k){
    unsigned l = 1;
    unsigned tmp = 0;
    size_t size = sizeof(x)*8;
    unsigned test = 1<<(size-1);
    
    for(int i = 0; i<size; i++){
        if(!k){
            x>>=i;
            break;
        }
        if(k && (test & x)){
            k--;
        }
        x<<=1;
        // print_bits(x);
        // printf("k: %d\n---\n",k);
    }
    return x;
}


int main(int argc, char ** argv){
    if(argc != 3) greska();

    unsigned x = atoi(argv[1]);
    unsigned k = atoi(argv[2]);

    // print_bits(x);

    x = ukloni(x,k);

    
    printf("%u\n", x);

    return 0;
}