#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void greska(){
    printf("-1\n");
    exit(EXIT_FAILURE);
}

typedef struct cvor {
    char ime[25];
    char prezime[25];
    double prosek;
    struct cvor* sledeci;
} Cvor;

Cvor* napravi_cvor(char* ime, char* prezime, double prosek){
    Cvor* novi = malloc(sizeof(Cvor));
    strcpy(novi->ime,ime);
    strcpy(novi->prezime,prezime);
    novi->prosek = prosek;
    return novi;
}

void dodaj_na_kraj(Cvor** glava, char* ime, char* prezime, double prosek){
    Cvor* novi = napravi_cvor(ime,prezime,prosek);
    Cvor* trenutni = NULL;
    for(trenutni = *glava; trenutni->sledeci != NULL; trenutni = trenutni->sledeci){
    }
    trenutni->sledeci = novi;
}

double suma(Cvor* glava, double k){
    double suma = 0;
    for(Cvor* trenutni = glava; trenutni!=NULL;trenutni = trenutni->sledeci){
        if(trenutni->prosek >= k) suma+= trenutni->prosek;
    }
    return suma;
}

int main(){
    float k;
    char ime_fajla[20];
    scanf("%f %s", &k, ime_fajla);

    FILE* fp = fopen(ime_fajla,"r");
    if(!fp) greska();

    Cvor* glava =NULL;

    char prezime[25], ime[25];
    double prosek;
    while(fscanf(fp, "%s %s %lf", ime,prezime,&prosek) == 3){
        if(!glava) glava = napravi_cvor(ime,prezime,prosek);
        else dodaj_na_kraj(&glava,ime,prezime,prosek);
    }


    fclose(fp);

    printf("%.2lf\n",suma(glava,k));

    return 0;
}