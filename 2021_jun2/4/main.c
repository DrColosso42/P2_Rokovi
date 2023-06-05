#include <stdio.h>
#include <stdlib.h>
#include "stabla.h"



int suma_(Cvor* koren, int nivo){
    if(koren == NULL){
        return 0;
    }

    if(nivo % 2 == 0){
        return koren->vrednost + suma_(koren->levo,nivo+1) + suma_(koren->desno, nivo+1);
    } else {
        return -koren->vrednost + suma_(koren->levo,nivo+1) + suma_(koren->desno, nivo+1);
    }
}

int suma(Cvor* koren){
    return suma_(koren,0);
}

int main(){
    Cvor* koren = NULL;

    int x;
    while(scanf("%d",&x) == 1){
        if(!koren) koren = napravi_cvor(x);
        else dodaj_u_stablo(&koren,x);
    }

    printf("%d\n",suma(koren));


    return 0;
}