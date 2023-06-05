#include <stdio.h>
#include <stdlib.h>
#include "stabla.h"
void ispisi_parne_(Cvor* koren, int br_predaka);

void ispisi_parne(Cvor* koren){
    ispisi_parne_(koren, 0);
}

void ispisi_parne_(Cvor* koren, int br_predaka){
    if(koren!=NULL){
        int uk = br_predaka;
        if(koren->levo != NULL) uk++;
        if(koren->desno != NULL) uk++;
        
        ispisi_parne_(koren->levo,1);
        ispisi_parne_(koren->desno,1);
        if(uk % 2 == 0){
            printf("%d ", koren->vrednost);
        }
    }
}

int main(){
    Cvor* koren = NULL;

    int x;
    while(scanf("%d", &x)){
        if(koren == NULL){
            koren = napravi_cvor(x);
            continue;
        }
        dodaj_u_stablo(&koren,x);
    }

    ispisi_parne(koren);

    return 0;
}