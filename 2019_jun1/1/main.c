#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char ime[50];
    char vreme[13];
} Rezultat;

void greska(){
    printf("-1\n");
    exit(EXIT_FAILURE);
}

long int_rez(char* niska){
    char tmp[13];
    strcpy(tmp,niska);
    char* hh = strtok(tmp,":");
    char* mm = strtok(NULL,":");
    char* ost = strtok(NULL,":");
    char* ss = strtok(ost,".");
    char* mss = strtok(NULL,".");

    long rez = atoi(hh)*3600*1000 + atoi(mm)*60*1000 + (int) atof(ost)*1000;
    return rez;

}

int cmpfnc(const void* p1, const void* p2){
    Rezultat* r1 = (Rezultat *) p1;
    Rezultat* r2 = (Rezultat *) p2;

    long vreme1 = int_rez(r1->vreme);
    long vreme2 = int_rez(r2->vreme);

    if(vreme1 > vreme2){
        return 1;
    } else if(vreme1 < vreme2){
        return -1;
    }
    return 0;
}



int main(int argc, char** argv){
    if(argc != 2) greska();
    
    FILE* fp = fopen(argv[1], "r");
    if(!fp) greska();

    size_t size = 10;
    Rezultat * lista_rezulta = malloc(size*sizeof(Rezultat));

    char ime[50], vreme[13];
    int n = 0;
    while(fscanf(fp,"%s %s",ime,vreme) == 2){
        if(n>= size){
            size += 10;
            lista_rezulta = realloc(lista_rezulta,size*sizeof(Rezultat));
        }
        Rezultat tmp;
        strcpy(tmp.ime,ime);
        strcpy(tmp.vreme,vreme);

        *(lista_rezulta+n) = tmp;
        n++;

    }

    qsort(lista_rezulta,n,sizeof(Rezultat),cmpfnc);

    for(int i = 0; i<n;i++){
        Rezultat tmp = *(lista_rezulta+i);
        printf("%s %s\n",tmp.ime,tmp.vreme);
    }

    fclose(fp);

    return 0;
}