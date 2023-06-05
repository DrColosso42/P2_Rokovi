#include <stdio.h>
#include <stdlib.h>
#include "stabla.h"
#include <math.h>
#include <limits.h>

int iz_koren(int x){
    return (int) round(sqrt((double) x));
}

void izmeni_stablo(Cvor* koren){
    if(koren == NULL){
        return;
    }

    

    if(koren->desno && koren->desno->vrednost > 0){
        int rez = iz_koren(koren->desno->vrednost);
        
        
        if(koren->levo){
            if(koren->levo->vrednost < rez){
                printf("%d -> %d\n",koren->vrednost, rez);
                koren->vrednost = rez;
                
            } 
        }
    }

    izmeni_stablo(koren->levo);
    izmeni_stablo(koren->desno);

    
}



int main(int argc, char const *argv[])
{
    Cvor* koren = NULL;
    int x;
    while(scanf("%d", &x) == 1){
        if(!koren) koren = napravi_cvor(x);
        else dodaj_u_stablo(&koren,x);
    }

    izmeni_stablo(koren);

    ispisi_u_fajl(koren,stdout);
    printf("\n");

       

    return 0;
}