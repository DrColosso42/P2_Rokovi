#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

int main(int argc, char** argv){
    Cvor* lista = NULL;

    int x;
    int n = 0;
    while(scanf("%d",&x) == 1){
        if(!lista) lista=napravi_cvor(x);
        else dodaj_na_kraj(&lista,x);
        n++;
    }

    Cvor* p1 = lista;
    Cvor* p2 = lista;
    for(int i = 0; i<(n/2-1);i++){
        p2=p2->sledeci;
    }

    int i = 0;
    for(Cvor* trenutni = lista; i<n/2;trenutni=trenutni->sledeci){
        if(i%2 == 0){
            Cvor* tmp = trenutni->sledeci;
            Cvor* tmp2 = p2->sledeci->sledeci;
            if(!tmp || !tmp2) break;
            trenutni->sledeci = p2->sledeci;
            trenutni->sledeci->sledeci = tmp;
            p2->sledeci = tmp2;
        }
       

        i++;
    }

    ispisi_listu(lista,stdout);

    return 0;
}