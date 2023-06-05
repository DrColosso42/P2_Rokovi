#include <stdio.h>
#include <stdlib.h>

#include "stabla.h"

int jeste_ogledalo(Cvor* koren1, Cvor* koren2){
    if(koren1 == NULL && koren2 == NULL){
        return 1;
    }

    if(koren1 && koren2){
        return jeste_ogledalo(koren1->levo, koren2->desno) &&
            jeste_ogledalo(koren1->desno, koren2->levo);
    }
    return 0;
}

int simetricno(Cvor* koren){
    return jeste_ogledalo(koren,koren);
}

int suma(Cvor* koren){
    if(koren == NULL){
        return 0;
    }
    return koren->vrednost + suma(koren->levo) + suma(koren->desno);
}


int main(int argc, char const *argv[])
{
    Cvor* koren = NULL;
    int x;

    while (scanf("%d", &x) == 1)
    {
        if(koren == NULL){
            koren = napravi_cvor(x);
        } else {
            dodaj_u_stablo(&koren,x);
        }
    }

    if(simetricno(koren)){
        printf("%d\n",suma(koren));
    }
    else {
        printf("-1\n");
    }


    return 0;
}
