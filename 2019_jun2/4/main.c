#include <stdio.h>
#include <stdlib.h>
#include "stabla.h"

int levo_desno(Cvor* koren, int k);

int desno_suma(Cvor* koren){
    if(koren == NULL) return 0;
    return koren->vrednost + desno_suma(koren->desno);
}

int k_suma(Cvor* koren, int k){
    if(koren == NULL) return 0;

    int rez = levo_desno(koren,k);

    return rez+k_suma(koren->desno,k);

}

int levo_desno(Cvor* koren, int k){
    if(koren == NULL) return 0;
    if(k > 1){
        levo_desno(koren->levo,k-1);
    } else{
        // printf("%d\n",koren != NULL ? koren->vrednost : -1);
        return desno_suma(koren);
    }
}

int main(int argc, char const *argv[])
{
    int x,k;
    scanf("%d",&k);
    Cvor* koren = NULL;

    while (scanf("%d",&x) == 1){
        if(!koren) koren = napravi_cvor(x);
        else dodaj_u_stablo(&koren,x);
    }

    
    printf("%d\n",k_suma(koren,k));

    return 0;
}
