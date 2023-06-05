#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char ime[21];
    char prezime[21];
    char index[10];
    int poeni;
} Student;

void greska(){
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int cmpfnc(const void* p1, const void* p2){
    Student * s1 = (Student *) p1;
    Student * s2 = (Student *) p2;

    if(s2->poeni != s1->poeni){
        return s2->poeni - s1->poeni;
    }
    return strcmp(s1->prezime,s2->prezime);
}

int main(int argc, char ** argv){
    
    if(argc != 2) greska();

    FILE* fp = fopen(argv[1], "r");
    if(!fp) greska();

    size_t size = 2;
    Student * lista_studenata = malloc(size*sizeof(Student));

    char ime[21], prezime[21], index[10];
    int poeni;
    
    int n = 0;
    while(fscanf(fp, "%s %s %s %d", ime,prezime,index,&poeni) == 4){
        if(n >= size){
            size<<=1;
            lista_studenata = realloc(lista_studenata,size*sizeof(Student));
        }

        Student tmp;
        strcpy(tmp.ime,ime);
        strcpy(tmp.prezime,prezime);
        strcpy(tmp.index,index);
        tmp.poeni = poeni;

        *(lista_studenata + n) = tmp;
        n++;
    }

    qsort(lista_studenata,n,sizeof(Student),cmpfnc);


    for(int i = 0; i<n; i++){
        Student tmp = *(lista_studenata+i); 
        printf("%s %s %s %d\n",tmp.ime,tmp.prezime,tmp.index,tmp.poeni);
    }



    fclose(fp);
    

    return 0;
}