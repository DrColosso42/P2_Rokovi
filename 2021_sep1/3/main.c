#include <stdio.h>
#include <stdlib.h>

#include "liste.h"

int main(int argc, char const *argv[])
{
    Cvor* lista = NULL;

    int x; 
    while (scanf("%d",&x) == 1)
    {
        if(lista==NULL){
            lista = napravi_cvor(x);
        } else{
            dodaj_na_kraj(&lista,x);
        }
    }
    

    int zbir_levo = 0;

    for(Cvor* trenutni = lista; trenutni!=NULL; trenutni = trenutni->sledeci){
        int zbir_desno = 0;
        for(Cvor* trenutni1 = trenutni->sledeci; trenutni1!=NULL; trenutni1 = trenutni1->sledeci){
            zbir_desno+=trenutni1->vrednost;
        }
        if(zbir_levo > zbir_desno){
            zbir_levo += trenutni->vrednost;
            trenutni->vrednost = 0;
            continue;
        }



        zbir_levo += trenutni->vrednost;
    }

    ispisi_listu(lista,stdout);

    return 0;
}
