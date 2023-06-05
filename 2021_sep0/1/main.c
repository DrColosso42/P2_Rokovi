#include <stdlib.h>
#include <stdio.h>

void greska(){
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int rastuce_cmp(const void* p1, const void* p2){
    return *((int *) p1) - *((int *) p2);
}

int opadajuce_cmp(const void* p1, const void* p2){
    return *((int *) p2) - *((int *) p1);
}



int main(int argc, char ** argv){
    if(argc != 3) greska();
    
    FILE* fp = fopen(argv[1],"r");
    if(!fp) greska();

    int pivot = atoi(argv[2]);

    int n;
    fscanf(fp, "%d", &n);
    if(n < 0) greska();

    int n1 = 0;
    int n2 = 0;

    int* veci = malloc(n*sizeof(int));
    int* manji = malloc(n*sizeof(int));

    for(int i = 0; i < n; i++){
        int tmp;
        fscanf(fp,"%d", &tmp);
        if(tmp > pivot){
            *(veci+n1) = tmp;
            n1++;
        } else {
            *(manji+n2) = tmp;
            n2++;
        }
    }
    qsort(veci,n1,sizeof(int),rastuce_cmp);
    qsort(manji,n2,sizeof(int),opadajuce_cmp);

    for(int i = 0; i<n1; i++){
        printf("%d ", *(manji+i));
    }
    for(int i = 0; i<n2; i++){
        printf("%d ", *(veci+i));
    }

    

    
    
    printf("\n");

    

    fclose(fp);

}