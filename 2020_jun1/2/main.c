#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char ime[25];
    char prezime[25];
    char index[10];
} Student;

int cmpfnc(const Student s1, const Student s2){
    char s1_br_in[5];
    char s1_g_in[5];
    char s2_br_in[5];
    char s2_g_in[5];
    
    char c;
    int posle = 0;
    int i = 0, j = 0;
    while((c = s1.index[j++]) != '\0'){
        if(c == '/') {posle = 1; s1_br_in[i] = '\0'; i = 0;}
        if(!posle){
            s1_br_in[i++] = c;
        } else {
            s1_g_in[i++] = c;
        }
    }
    s1_g_in[i] = '\0';
    posle = 0;
    i = 0;
    j = 0;
    while((c = s2.index[j++]) != '\0'){
        if(c == '/') {posle = 1; s2_br_in[i] = '\0'; i = 0;}
        if(!posle){
            s2_br_in[i++] = c;
        } else {
            s2_g_in[i++] = c;
        }
    }
    s2_g_in[i] = '\0';


    if(strcmp(s1_br_in,s2_br_in)){
        return atoi(s1_br_in) - atoi(s2_br_in);
    } 
    return atoi(s2_g_in) - atoi(s1_g_in); 


}

void instertion_sort(Student* lista, int n, int (*cmp)(const Student, const Student)){
    for(int i = 0; i<n; i++){
        Student tr = lista[i];
        for(int j = i; j>0; j--){
            // if (j-1) ide posle tebe -> zameni
            // u suprotnom nista
            if(cmp(lista[j-1],lista[j]) >= 0){
                
                Student tmp = lista[j];
                lista[j] = lista[j-1];
                lista[j-1] = tmp;
            } else{
                break;
            }
        }
    }
}

int main(){
    char index[10];
    char ime[25];
    char prezime[25];

    Student lista_studenata[128];
    int n = 0;
    while(scanf("%s %s %s", index, ime, prezime) == 3){
        Student tmp;
        strcpy(tmp.ime,ime);
        strcpy(tmp.index,index);
        strcpy(tmp.prezime,prezime);
        lista_studenata[n++] = tmp;
    }

    instertion_sort(lista_studenata,n,cmpfnc);

    for(int i = 0; i<n; i++){
        Student tmp = lista_studenata[i];
        printf("%s %s %s\n",tmp.index,tmp.ime,tmp.prezime);
    }


    return 0;
}