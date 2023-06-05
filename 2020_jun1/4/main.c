#include <stdio.h>
#include <stdlib.h>
#include "stabla.h"

int zbir_jedno(Cvor* koren){
    if(koren == NULL){
        return 0;
    }
    if((koren->levo && !koren->desno) || (koren->desno && !koren->levo)){
        return koren->vrednost + zbir_jedno(koren->levo) + zbir_jedno(koren->desno);
    }
    return zbir_jedno(koren->levo) + zbir_jedno(koren->desno);

}


void print_vece(Cvor* koren, int k){
    if(!koren) return;

    print_vece(koren->levo, k);
    if(koren->vrednost > k) printf("%d ", koren->vrednost);
    print_vece(koren->desno, k);
}


int main(){
    Cvor* koren = NULL;
    int x;

    while(scanf("%d", &x) == 1){
        if(!koren) koren = napravi_cvor(x);
        else dodaj_u_stablo(&koren,x);
    }
    
    int zb = zbir_jedno(koren);
    printf("%d ",zb);
    print_vece(koren,zb);
    printf("\n");



    return 0;
}