#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 10000

void greska(){
    printf("-1\n");
    exit(EXIT_FAILURE);
}

typedef struct movie {
    char ime[50];
    double ocena_g;
    int broj_gledalaca;
    double ocena_k;
    double procenjena_vrednost;
} Movie;


int uporedi(const void* m1, const void* m2){
    Movie* M1 = (Movie*) m1;
    Movie* M2 = (Movie*) m2;

    int rez = strcmp((*M1).ime, (*M2).ime);

    if(rez < 0){
        return -1;
    } else if (rez > 0){
        return 1;
    }

    if(M1->procenjena_vrednost>M2->procenjena_vrednost){
        return -1;
    }
    return 1;


}



int main(int argc, char const *argv[])
{
    if(argc != 2) greska();

    FILE* fp = fopen(argv[1],"r");
    if(fp == NULL) greska();

    int n;
    fscanf(fp,"%d", &n);
    if(n <= 0) greska();

    Movie* filmovi = malloc(n*sizeof(Movie));


    for(int i = 0; i<n;i++){
        Movie curr_movie;

        double ocena_g,ocena_k;
        int broj_gledalaca;
        fscanf(fp, "%s %lf %d %lf", curr_movie.ime, &ocena_g,&broj_gledalaca,&ocena_k);
        if(broj_gledalaca < 0) greska();
        if(ocena_g < 1 || ocena_g > 10) greska();
        if(ocena_k < 1 || ocena_k > 10) greska();

        curr_movie.ocena_g = ocena_g;
        curr_movie.ocena_k = ocena_k;
        curr_movie.broj_gledalaca = broj_gledalaca;

        curr_movie.procenjena_vrednost = (ocena_g * broj_gledalaca + M * ocena_k)/(M +1);

        *(filmovi+i) = curr_movie;
    }

    qsort(filmovi, n,sizeof(Movie),&uporedi);

    FILE* fizlaz = fopen("vrednosti.txt", "w");
     
    for (int i = 0; i < n; i++)
    {
        fprintf(fizlaz,"%s %.2lf\n", (filmovi+i)->ime, (filmovi+i)->procenjena_vrednost);
    }
    

    fclose(fizlaz);
    
    free(filmovi);



    fclose(fp);

    return 0;
}