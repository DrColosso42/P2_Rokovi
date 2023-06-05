#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void greska(){
    printf("-1\n");
    exit(EXIT_FAILURE);
}


typedef struct {
    char ime[11];
    float x;
    float y;
} Tacka;


int cmpfnc(const void* p1, const void* p2){
    Tacka* tacka1 = (Tacka *) p1;
    Tacka* tacka2 = (Tacka *) p2;

    if(tacka1->x < tacka2->x){
        return -1;
    } else if (tacka1->x > tacka2->x) {
        return 1;
    }
    if(tacka1->y > tacka2->y){
        return -1;
    } else if(tacka1->y < tacka2->y){
        return 1;
    }
    return strcmp(tacka1->ime,tacka2->ime);
    

}

int main(){
    FILE* fp = fopen("tacke.txt","r");
    if(!fp) greska();

    int n;
    if(fscanf(fp, "%d", &n) != 1) greska();
    if(n<1) greska();

    Tacka * lista_tacaka = malloc(n*sizeof(Tacka));
    for(int i = 0; i<n; i++){
        Tacka tmp;
        fscanf(fp, "%f %f %s", &tmp.x, &tmp.y, tmp.ime);
        *(lista_tacaka+i)=tmp;
    }

    qsort(lista_tacaka,n,sizeof(Tacka),cmpfnc);

    for(int i = 0; i<n; i++){
        Tacka tck = *(lista_tacaka+i);
        printf("%g %g %s\n", tck.x, tck.y, tck.ime);
    }

    free(lista_tacaka);


    fclose(fp);

    return 0;
}