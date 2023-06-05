#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

int ost(int x, int k){
    if(x > 0){
        return x%k;
    }
    return k+x%k;
}

int main(){
    int k, p;
    scanf("%d %d", &k, &p);

    if(p<0 || p>=k){
        greska();
    }

    Cvor* lista = NULL;

    int x;
    while(scanf("%d", &x) == 1){
        if(lista == NULL){
            lista = napravi_cvor(x);
            continue;
        }

        dodaj_na_kraj(&lista,x);
    }

    for(Cvor* trenutni = lista; trenutni->sledeci != NULL; trenutni=trenutni->sledeci){
        if(ost(trenutni->vrednost + trenutni->sledeci->vrednost,k) == p){

            Cvor* tmp1 = napravi_cvor(0);
            Cvor* tmp2 = napravi_cvor(0);
            tmp1->sledeci = tmp2;
            tmp2->sledeci = trenutni->sledeci;
            trenutni->sledeci = tmp1;
            trenutni = tmp2;
            continue;
        }
    }
    printf("\n");

    ispisi_listu(lista,stdout);
    printf("\n");

    return 0;
}