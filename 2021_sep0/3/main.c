#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cvor{
    struct cvor* sledeci;
    char ime[21];
    int grami;
} Cvor;

Cvor* napravi_cvor(char* ime, int grami){
    Cvor* cvor = malloc(sizeof(Cvor));
    cvor->sledeci = NULL;
    strcpy(cvor->ime, ime);
    cvor->grami = grami;
    return cvor;
}

void dodajNaKraj(Cvor**glava, char* ime, int grami){
    Cvor* novi = napravi_cvor(ime,grami);

    Cvor* trenutni = *glava;
    while(trenutni->sledeci != NULL){
        trenutni = trenutni->sledeci;
    }
    trenutni->sledeci = novi;
}

Cvor* izbrisi(Cvor* glava, char* ime, int grami){

    for(Cvor* trenutni = glava; trenutni->sledeci != NULL; ){
        // printf("%s\n", trenutni->ime);
        if(trenutni == NULL) break;
        
        // printf("%s: %d, %s: %d\n",trenutni->sledeci->ime, trenutni->sledeci->grami, ime, grami);
        if(!(strcmp(trenutni->sledeci->ime,ime)) || trenutni->sledeci->grami <= grami){
            
            Cvor* tmp = trenutni->sledeci;

            trenutni->sledeci = trenutni->sledeci->sledeci;
            free(tmp);
            continue;
        }
        trenutni=trenutni->sledeci;
    }
    if(!(strcmp(glava->ime,ime)) || glava->grami <= grami){
        Cvor* tmp = glava;
        glava = glava->sledeci;
        free(tmp);
        
    }
    return glava;
}

void greska(){
    printf("-1\n");
    exit(EXIT_FAILURE);
}



int main(int argc, char ** argv){
    if(argc != 3) greska();

    Cvor* glava = napravi_cvor(argv[1],atoi(argv[2]));


    char ime[21];
    int grami;
    while(scanf("%s %d", ime, &grami) == 2){
        dodajNaKraj(&glava,ime,grami);
    }

    glava = izbrisi(glava,argv[1],atoi(argv[2]));

    for(Cvor* trenutni = glava; trenutni!=NULL; trenutni = trenutni->sledeci){
        printf("%s %d\n", trenutni->ime, trenutni->grami);
    }

}