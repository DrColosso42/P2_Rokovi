#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void greska(){
    printf("-1\n");
    exit(EXIT_FAILURE);
}

typedef struct naucnik {
    char ime[101];
    char prezime[101];
    int godina;
    int vek;

} Naucnik;

int uporedi_godine(const void * p1,const void * p2){
    int* n1 = (int*) p1;
    Naucnik * n2 = (Naucnik * ) p2;

    // printf("%d %d\n", *n1, n2->godina);   

    return *(int *)p1 - n2->godina;
}


int main(int argc, char ** argv){
    if(argc != 3){
        greska();
    }

    FILE* fp = fopen(argv[1],"r");
    if(fp == NULL) greska();

    int velicina = 2;
    Naucnik* lista_naucnika = malloc(velicina*sizeof(Naucnik));

    char tr_ime[101];
    char tr_prezime[101];
    int tr_godina;
    int uk_naucnika = 0;
    // fscanf(fp, "%s %s %d", tr_ime, tr_prezime, &tr_godina);

    while(fscanf(fp, "%s %s %d", tr_ime, tr_prezime, &tr_godina) == 3){
        if(uk_naucnika == velicina){
            velicina<<=1;
            lista_naucnika = realloc(lista_naucnika, velicina*sizeof(Naucnik));
        }
        Naucnik temp;
        strcpy(temp.ime,tr_ime);
        strcpy(temp.prezime,tr_prezime);
        temp.godina = tr_godina;
        temp.vek = tr_godina % 100 + 1;

        *(lista_naucnika + uk_naucnika) = temp;


        uk_naucnika++;
    }
    
    

    int trazeni_vek = atoi(argv[2]);

    printf("%d\n",trazeni_vek);

    // int trazeno = 1856;
    // Naucnik * ptr = bsearch(&trazeno, lista_naucnika, uk_naucnika, sizeof(Naucnik), uporedi_godine);

    for(int i = (trazeni_vek-1)*100;i<(trazeni_vek)*100;i++){
        // printf("%d\n", i);
        Naucnik * tr = bsearch(&i,lista_naucnika,uk_naucnika,sizeof(Naucnik),uporedi_godine);
        if(tr != NULL){
            printf("%s %s\n",tr->ime, tr->prezime);
        }
    }




    // for(int j = 0; j<i;j++){
    //     printf("%s\n",(lista_naucnika+j)->ime);
    // }

    fclose(fp);




    return 0;
}