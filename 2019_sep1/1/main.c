#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void greska(){
    printf("-1\n");
    exit(EXIT_FAILURE);
}

typedef struct {
    char ime[21];
    double plata;
} Plata;

int cmpfnc(const void* p1, const void* p2){
    Plata * plata1 = (Plata *) p1;
    Plata * plata2 = (Plata *) p2;

    if(strcmp(plata1->ime,plata2->ime)){
        return(strcmp(plata1->ime,plata2->ime));
    }
    return plata2->plata - plata1->plata;

}

int main(int argc, char ** argv){
    if(argc != 2) greska();
    int k = atoi(argv[1]);

    FILE* fp = fopen("plate.txt","r");
    int size = 10;
    if(!fp) greska();

    Plata* lista_plata = malloc(size*sizeof(Plata));
    

    int n = 0;
    char ime[21];
    double plata;
    
    while(fscanf(fp, "%s %lf", ime, &plata ) == 2){
        
        if((n) >= size){
            
            size+=10;
            lista_plata = realloc(lista_plata,100*sizeof(Plata));
            
        }
        Plata tmp;
        strcpy(tmp.ime, ime);
        tmp.plata = plata;
        *(lista_plata+n)=tmp;
        n++;
    
    }

    qsort(lista_plata,n,sizeof(Plata),cmpfnc);

    int kprim = k;
    char novi_gr[21];
    for(int i = 0; i < n; i++){
        // printf("%d\n", kprim);
        if(kprim == k){
            strcpy(novi_gr,lista_plata[i].ime);
        }
        if(kprim > 0 && !strcmp(novi_gr,lista_plata[i].ime)){
            printf("%s %lf\n",novi_gr,lista_plata[i].plata);
        } else if(strcmp(novi_gr,lista_plata[i].ime)){
            kprim = k;
            printf("%s %lf\n",lista_plata[i].ime,lista_plata[i].plata);
            strcpy(novi_gr,lista_plata[i].ime);
        }
        kprim--;

        
    }


    free(lista_plata);



    fclose(fp);



}