#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

int main(int argc, char const *argv[])
{
    Cvor* lista = NULL;
    int x;
    while(scanf("%d",&x) == 1){
        if(!lista) lista =napravi_cvor(x);
        else dodaj_na_kraj(&lista,x);
    }

    Cvor* poz_lista = NULL;
    Cvor* neg_lista = NULL;

    for(Cvor* trenutni = lista; trenutni!=NULL; ){
        if(trenutni->vrednost >= 0){
            if(!poz_lista) poz_lista = trenutni;
            else {
                for(Cvor* tmp = poz_lista; tmp != NULL; tmp=tmp->sledeci){
                    if(tmp->sledeci == NULL){
                        tmp->sledeci = trenutni;
                        break;
                    }
                }
            }
        } else {
            if(!neg_lista) neg_lista = trenutni;
            else {
                for(Cvor* tmp = neg_lista; tmp!= NULL; tmp=tmp->sledeci){
                    if(tmp->sledeci == NULL){
                        tmp->sledeci = trenutni;
                        break;
                    }
                }
            }
        }

        Cvor* tmp = trenutni->sledeci;
        trenutni->sledeci = NULL;

        trenutni = tmp;


    }

    ispisi_listu(poz_lista,stdout);
    ispisi_listu(neg_lista,stdout);


    return 0;
}
