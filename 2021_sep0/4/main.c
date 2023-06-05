#include <stdio.h>
#include <stdlib.h>
#include "stabla.h"

int broj_cvorova_na_nivou(Cvor* koren, int nivo){
    if(koren == NULL || nivo < 0){
        return 0;
    }
    if(nivo == 0){
        return 1;
    }
    return broj_cvorova_na_nivou(koren->levo,nivo-1) + broj_cvorova_na_nivou(koren->desno, nivo-1);

}
int max(int a, int b){
    return a > b ? a : b;
}

int dubina(Cvor* koren){
    if(koren == NULL){
        return 0;
    }
    return 1 + max(dubina(koren->levo),dubina(koren->desno));
}

int br_cvorova_od_nivoa(Cvor* koren, int nivo){
    int db = dubina(koren);
    int uk = 0;
    for(int i = nivo; i <= db; i++){
        uk += broj_cvorova_na_nivou(koren,i);
    }
    return uk;
}

int main(int argc, char const *argv[])
{
    Cvor* koren = NULL;
    int k;
    scanf("%d", &k);

    int x;
    while (scanf("%d",&x) == 1)
    {
        if(!koren){
            koren = napravi_cvor(x);
        } else {
            dodaj_u_stablo(&koren,x);
        }
    }
    
    printf("%d\n",br_cvorova_od_nivoa(koren,k));
    

    return 0;
}
