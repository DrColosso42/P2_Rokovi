#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

int main(){
    Cvor* lista = NULL;

    int x;
    while(scanf("%d",&x) == 1){
        if(!lista) lista = napravi_cvor(x);
        else dodaj_na_kraj(&lista,x);
    }

    for(Cvor* trenutni = lista; trenutni->sledeci!=NULL;trenutni = trenutni->sledeci){
        if(trenutni->vrednost <= trenutni->sledeci->vrednost){
            printf("%d ", trenutni->sledeci->vrednost);
        }
    }

    printf("\n");



    return 0;
}