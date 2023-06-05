#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void greska(){
    printf("-1\n");
    exit(EXIT_FAILURE);
}


int main(){
    char ime_fajla[16];
    char sadrzaj[200];
    char linija[201];

    FILE* fajlovi = fopen("fajlovi.txt","r");
    if(!fajlovi) greska();

    while(fgets(linija,sizeof(linija),fajlovi)){
        strcpy(ime_fajla,strtok(linija,":"));
        strcpy(sadrzaj,strtok(NULL,":"));

        size_t slen = strlen(sadrzaj);
        for(int i = slen-1; i>0; i--){
            if(sadrzaj[i] != ' ' && sadrzaj[i] != '\n'){
                sadrzaj[i+1]='\0';
                break;
            }
        }

        FILE* cfp = fopen(ime_fajla,"a+");
        if(!cfp){
            cfp = fopen(ime_fajla,"w");
        }
        fprintf(cfp,"%s",sadrzaj);
        fclose(cfp);
        

    }
    

    




    fclose(fajlovi);

    return 0;
}