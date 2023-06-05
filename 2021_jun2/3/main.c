#include <stdio.h>
#include <stdlib.h>

#include "liste.h"

Cvor* izbaci(Cvor* glava){
    for(Cvor* trenutni = glava; trenutni->sledeci != NULL;){
        if(trenutni->sledeci->vrednost < trenutni->vrednost){
            Cvor* tmp = trenutni->sledeci;
            trenutni->sledeci = trenutni->sledeci->sledeci;
            free(tmp);
            continue;
        }
        
        trenutni=trenutni->sledeci;
    }

    return glava;

    

}

int main(int argc, char const *argv[])
{
    Cvor* glava = NULL;

    int x;
    while(scanf("%d", &x) == 1){
        if(!glava) glava = napravi_cvor(x);
        else dodaj_na_kraj(&glava,x);
    }

    glava = izbaci(glava);

    ispisi_listu(glava,stdout);


    return 0;
}

