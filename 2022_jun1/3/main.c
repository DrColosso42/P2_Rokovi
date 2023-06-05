#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

int main(int argc, char const *argv[])
{
    Cvor* lista = NULL;
    int x;
    while(scanf("%d", &x) == 1){
        if(lista == NULL){
            lista = napravi_cvor(x);
        } else {
            dodaj_na_kraj(&lista,x);
        }

    }
// zameni prvi
    Cvor* cv1 = lista;
    Cvor* cv2 = lista->sledeci;
    Cvor* cv3 = lista->sledeci->sledeci;

    lista = cv2;
    cv2->sledeci = cv1;
    cv1 ->sledeci = cv3;

    
    
    int i = 1;
    for(Cvor* trenutni = lista->sledeci; trenutni->sledeci != NULL; trenutni=trenutni->sledeci){
        if(i % 2 == 1){
            if(trenutni->sledeci != NULL &&
                trenutni->sledeci->sledeci != NULL){
                    Cvor* tri = trenutni->sledeci->sledeci->sledeci;
                    Cvor* nula = trenutni;
                    Cvor* jedan = trenutni->sledeci;
                    Cvor* dva = trenutni->sledeci->sledeci;
                    // trenutni 0; trenutni->sl 1 trenutni->sl->sl 2
                    
                    nula->sledeci = dva;
                    dva->sledeci = jedan;
                    jedan->sledeci = tri;

                }
        }


        i++;
    }

    ispisi_listu(lista,stdout);


    /* code */
    return 0;
}
