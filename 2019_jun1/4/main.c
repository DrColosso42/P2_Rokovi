#include <stdio.h>
#include <stdlib.h>
#include "stabla.h"


void dupliraj_(Cvor* koren, int vrednost);

void dupliraj(Cvor* koren){
    dupliraj_(koren,koren->vrednost);
}

void dupliraj_(Cvor* koren, int moze){
    if(koren == NULL){
        return;
    }

    

    Cvor* novi = NULL;
    if(moze){
        novi = napravi_cvor(koren->vrednost);
        novi->levo = koren->levo;
        koren->levo = novi;
        dupliraj_(koren->levo, 0);
        dupliraj_(koren->desno,1);
    } else {
        dupliraj_(koren->levo,1);
        dupliraj_(koren->desno,1);
    }
}

int main(){
    Cvor * koren = NULL;
    int x;
    while(scanf("%d", &x)==1){
        if(!koren) koren = napravi_cvor(x);
        else dodaj_u_stablo(&koren,x);
    }

    dupliraj(koren);
    ispisi_u_fajl(koren,stdout);
    printf("\n");

    return 0;
}