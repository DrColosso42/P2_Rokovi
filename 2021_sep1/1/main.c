#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void greska(){
    printf("-1\n");
    exit(EXIT_FAILURE);
}

typedef struct {
    char ime[21];
    char boja[21];
    int povrsina;
} Figura;


int uporedi_figure(const void * p1, const void* p2){
    Figura* f1 = (Figura*) p1;
    Figura* f2 = (Figura*) p2;

    int rez = strcmp(f1->ime,f2->ime);
    if(rez < 0) return 1;
    if(rez > 0) return -1;

    rez = strcmp(f1->boja, f2->boja);
    if(rez < 0) return -1;
    if(rez > 0) return 1;

    if(f1->povrsina < f2->povrsina){
        return 1;
    } else if(f1->povrsina > f2->povrsina){
        return -1;
    }
    return 0;


}

int main(int argc, char** argv){
    if(argc != 2){
        greska();
    }

    FILE* fp = fopen(argv[1], "r");
    if(!fp) greska();


    int n;
    fscanf(fp,"%d", &n);
    if(n<=0) greska();

    Figura * lista_oblika = malloc(n*sizeof(Figura));

    for(int i = 0; i < n; i++){
        Figura tmp;
        fscanf(fp, "%s %s %d", tmp.ime, tmp.boja, &tmp.povrsina);
        *(lista_oblika+i)=tmp;

    }

    qsort(lista_oblika,n,sizeof(Figura),uporedi_figure);

    for (int i = 0; i < n; i++)
    {
        Figura* tmp = (lista_oblika+i);
        printf("%s %s %d\n", tmp->ime, tmp->boja, tmp->povrsina);
    }
    


    free(lista_oblika);

    fclose(fp);

    

    return 0;
}