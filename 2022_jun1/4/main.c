#include <stdio.h>
#include <stdlib.h>
#include "stabla.h"

int max_2(int x, int y){
    if(x > y){
        return x;
    }
    return y;
}

int max_3(int x, int y, int z){
    if(x > y && x > z){
        return x;
    } 
    if(y > x && y > z){
        return y;
    }
    else return z;
}

int abs(int x){
    return x > 0? x : -x;
}

int najveca_razlika(Cvor* koren){
    if(koren == NULL){
        return 0;
    }
    int tr1, tr2;
    if(koren->levo == NULL){
        tr1 = 0;
    } else {
        tr1 = abs(koren->vrednost - koren->levo->vrednost);
    }
    if(koren->desno == NULL){
        tr2 = 0;
    } else {
        tr2 = abs(koren->vrednost - koren->desno->vrednost);
    }

    tr1 = max_2(tr1,tr2);
    
    return max_3(
        najveca_razlika(koren->desno),
        najveca_razlika(koren->levo),
        tr1
    );
    
    
}

int abs_razlika(Cvor* k1, Cvor* k2){
    if(k1 == NULL && k2 == NULL) return 0;
    if(k1 == NULL) return abs(k2->vrednost);
    if(k2 == NULL) return abs(k1->vrednost);
    return abs(k1->vrednost - k2->vrednost);
}

int razlika_dece(Cvor* koren){
    if(koren == NULL){
        return 0;
    }
    if(koren->levo == NULL && koren->desno == NULL){
        return 0;
    }
    if(koren->levo == NULL){
        return abs(koren->vrednost-koren->desno->vrednost);
    } else if (koren->desno == NULL){
        return abs(koren->vrednost - koren->levo->vrednost);
    }
    return max_2(abs(koren->vrednost - koren->desno->vrednost),
    abs(koren->vrednost-koren->levo->vrednost));

}

Cvor* fja(Cvor* k1, Cvor* k2, Cvor* k3){
    int r1 = razlika_dece(k1);
    int r2 = razlika_dece(k2);
    int r3 = razlika_dece(k3);

    // printf("%d: %d | %d: %d | %d: %d\n",
    //     k1 == NULL ? -1 : k1->vrednost, r1,
    //     k2 == NULL ? -1 : k2->vrednost, r2,
    //     k3 == NULL ? -1 : k3->vrednost, r3
    // );

    int rmax = max_3(r1,r2,r3);
    if(rmax == r3) return k3;
    if(rmax == r2) return k2;
    if(rmax == r1) return k1;


}
Cvor* najveca_razlika_v2(Cvor* koren){
    if(koren == NULL){
        return NULL;
    }

    return fja(najveca_razlika_v2(koren->levo),najveca_razlika_v2(koren->desno),
        koren);






    



}

int main(){
    Cvor * koren = NULL;
    
    int x; 
    while (scanf("%d",&x) == 1){
        if (koren == NULL){
            koren = napravi_cvor(x);
        } else {
            dodaj_u_stablo(&koren, x);
        }
    }
    
    printf("%d \n", najveca_razlika_v2(koren)->vrednost);

    return 0;
}