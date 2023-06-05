#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char ime[51];
    int pb;
} Grad;

void greska(){
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int cmp(const void* pivot, const void* grad){
    int * pv = (int *) pivot;
    Grad * gr = (Grad *) grad;

    if(*pv < gr->pb){
        return -1;
    } else if(*pv > gr->pb){
        return 1;
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    if(argc != 3) greska();

    int n = atoi(argv[2]);

    FILE* fp = fopen(argv[1],"r");
    if(!fp) greska();

    Grad* lista_gradova = malloc(n*sizeof(Grad));

    for(int i = 0; i<n; i++){
        char ime[51];
        int pb;
        fscanf(fp,"%s %d", ime, &pb);

        Grad gradtmp;

        strcpy(gradtmp.ime,ime);
        gradtmp.pb = pb;

        *(lista_gradova+i) = gradtmp;

    }

    int zadato;
    scanf("%d",&zadato);

    Grad* trazeni_grad = bsearch(&zadato,lista_gradova,n,sizeof(Grad),cmp);

    if(trazeni_grad){
        printf("%s\n",trazeni_grad->ime);
    } else {
        printf("\n");
    }



    fclose(fp);



    return 0;
}
