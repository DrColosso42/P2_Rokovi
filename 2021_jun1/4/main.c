#include <stdio.h>
#include <stdlib.h>
#include "stabla.h"

int neparnih_listova(Cvor* koren){
    if(koren == NULL){
        return 0;
    }
    if(koren->levo == NULL && koren->desno == NULL){
        return (koren->vrednost % 2 == 1);
    }
    return neparnih_listova(koren->levo) + neparnih_listova(koren->desno);
}

int main(int argc, char** argv){

    Cvor* koren = NULL;
    int x;
    while(scanf("%d", &x) == 1){
        if(!koren) koren = napravi_cvor(x);
        else dodaj_u_stablo(&koren,x);
    }

    printf("%d\n",neparnih_listova(koren));



}