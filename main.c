#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "bubble.c"
#include "quick.c"
#include "merge.c"
#include "insertion.c"
#include "selection.c"
#include "rwFile.c"


void print(int *vector, int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d ",vector[i]);
    }
    printf("\n");
}

int *generateVector(const int size){
    int *vector, i;
    vector = (int*) malloc(size*sizeof(int));
    for(i = 0; i<size; i++){
        vector[i] = i;
    }
    for(i = 0;i<2*size;i++){
        srand((unsigned)clock());
        int a = rand()%size;
        srand((unsigned)clock());
        int b = rand()%size;
        if(a!=b)
            SWAP(&vector[a], &vector[b]);
    }
    //print(vector, size);
    return vector;
}

int *revertVector(int *vector, int n){
    int i, j;
    for(i = 1;i<n;i++){
        for(j = 0;j<n-i;j++){
            if(vector[j]<vector[j+1]){
                SWAP(&vector[j],&vector[(j+1)]);
            }
        }
    }
    return vector;
}

void getData(char listname[], char resultlistname[], char swapR[], char compResult[]){

    FILE *lData, *fData; // List of data, file with data
    lData = fopen(listname, "r");
    FILE *results = fopen(resultlistname, "w");
    FILE *swapResult = fopen(swapR, "w");
    FILE *comparationResult = fopen(compResult, "w");

    if(lData == NULL || results == NULL || swapResult == NULL || comparationResult == NULL)
        exit(1);

    char str[128];
    int size, *vector, *aux, i;
    unsigned long int amountSwap[5] = {0,0,0,0,0}, compNumber[5] = {0,0,0,0,0};

    fprintf(results, "# size | bubble | Insertion | Selection | Merge | Quick\n");
    fprintf(swapResult, "# size | bubble | Insertion | Selection | Merge | Quick\n");
    fprintf(comparationResult, "# size | bubble | Insertion | Selection | Merge | Quick\n");

    while(fscanf(lData, "%s %d\n", str, &size)!=EOF){
        fData = fopen(str, "r");

        if(fData==NULL){
            printf("Error while trying to open file");
            exit(1);
        }

        aux = (int*) malloc(size*sizeof(int));
        vector = readFile(vector, size, str);
        //Bubble sort
        for(i=0; i<size;i++){
            aux[i] = vector[i];
        }

        clock_t bstart = clock();
        aux = bubbleSort(aux, size, &compNumber[0], &amountSwap[0]);
        clock_t bend = clock();
        clock_t totalBubble = bend - bstart;

        //Insertion Sort
        for(i=0; i<size;i++){
            aux[i] = vector[i];
        }
        clock_t istart = clock();
        aux = insertionSort(aux, size, &compNumber[1], &amountSwap[1]);
        clock_t iend = clock();
        clock_t totalinsertion = iend - istart;

        //Selection Sort *
        for(i=0; i<size;i++){
            aux[i] = vector[i];
        }
        clock_t sstart = clock();
        aux = selectionSort(aux, size, &compNumber[2], &amountSwap[2]);
        clock_t send = clock();
        clock_t totalSelection = send - sstart;

        //Merge Sort
        for(i=0; i<size;i++){
            aux[i] = vector[i];
        }
        clock_t mstart = clock();
        aux = mergeSort(aux, size, &compNumber[3], &amountSwap[3]);
        clock_t mend = clock();
        clock_t totalMerge = mend - mstart;

        //Quick Sort *
        for(i=0; i<size;i++){
            aux[i] = vector[i];
        }
        clock_t qstart = clock();
        quickSort(aux, size, &compNumber[4], &amountSwap[4]);
        clock_t qend = clock();
        clock_t totalQuick = qend - qstart;
        
        fprintf(results, "%d %ld %ld %ld %ld %ld\n", size, totalBubble, totalinsertion, totalSelection, totalMerge, totalQuick);
        fprintf(swapResult, "%d %lu %lu %lu %lu %lu\n", size, amountSwap[0], amountSwap[1], amountSwap[2], amountSwap[3], amountSwap[4]);
        fprintf(comparationResult, "%d %lu %lu %lu %lu %lu\n", size, compNumber[0], compNumber[1], compNumber[2], compNumber[3], compNumber[4]);

        fclose(fData);
        free(aux);
    }
    fclose(lData);
    fclose(results);
    fclose(swapResult);
    fclose(comparationResult);
}

long int runBubble(int *vector, int size, unsigned long int* compNumber, unsigned long int* amountSwap ){
    
    clock_t start = clock();
    vector = bubbleSort(vector, size, compNumber, amountSwap);
    clock_t end = clock();
    clock_t total = end - start;
    return total;
}

long int runInsertion(int *vector, int size, unsigned long int* compNumber, unsigned long int* amountSwap ){
    //Insertion Sort
    clock_t start = clock();
    vector = insertionSort(vector, size, compNumber, amountSwap);
    clock_t end = clock();
    clock_t total = end - start;
    return total;
}

long int runSelection(int *vector, int size, unsigned long int* compNumber, unsigned long int* amountSwap ){
    
    clock_t start = clock();
    vector = selectionSort(vector, size, compNumber, amountSwap);
    clock_t end = clock();
    clock_t total = end - start;
    return total;
}

long int runMerge(int *vector, int size, unsigned long int* compNumber, unsigned long int* amountSwap ){
    
    clock_t start = clock();
    vector = mergeSort(vector, size, compNumber, amountSwap);
    clock_t end = clock();
    clock_t total = end - start;
    return total;
}

long int runQuick(int *vector, int size, unsigned long int* compNumber, unsigned long int* amountSwap ){
    
    clock_t start = clock();
    quickSort(vector, size, compNumber, amountSwap);
    clock_t end = clock();
    clock_t total = end - start;
    return total;
}

void runmethod(char listname[], char resultlistname[], char swapR[], char compResult[], int op){

    FILE *lData, *fData; // List of data, file with data
    lData = fopen(listname, "r");
    FILE *results = fopen(resultlistname, "w");
    FILE *swapResult = fopen(swapR, "w");
    FILE *comparationResult = fopen(compResult, "w");

    if(lData == NULL || results == NULL || swapResult == NULL || comparationResult == NULL)
        exit(1);

    char str[128];
    int size, *vector, *aux, i;
    unsigned long int amountSwap = 0, compNumber = 0;
    long int timevalue;

    fprintf(results, "# size | time\n");
    fprintf(swapResult, "# size | swap\n");
    fprintf(comparationResult, "# size | comparacoes\n");

    while(fscanf(lData, "%s %d\n", str, &size)!=EOF){
        fData = fopen(str, "r");

        if(fData==NULL){
            printf("Error while trying to open file");
            exit(1);
        }

        aux = (int*) malloc(size*sizeof(int));
        vector = readFile(vector, size, str);

        //Sorting method
        switch(op){
            case 1:
                timevalue = runBubble(vector, size, &compNumber, &amountSwap);
                break;
            case 2:
                timevalue = runInsertion(vector, size, &compNumber, &amountSwap);
                break;
            case 3:
                timevalue = runSelection(vector, size, &compNumber, &amountSwap);
                break;
            case 4:
                timevalue = runMerge(vector, size, &compNumber, &amountSwap);
                break;
            case 5:
                timevalue = runQuick(vector, size, &compNumber, &amountSwap);
                break;
            default:
                exit(1);
        }
        

        fprintf(results, "%d %ld\n", size, timevalue);
        fprintf(swapResult, "%d %lu\n", size, amountSwap);
        fprintf(comparationResult, "%d %lu\n", size, compNumber);

        fclose(fData);
        free(aux);
    }
    fclose(lData);
    fclose(results);
    fclose(swapResult);
    fclose(comparationResult);

}

int main(){

    int op;
    puts("digite:\n\t1-Bubble\n\t2-Insertion\n\t3-Selection\n\t4-Merge\n\t5-Quick\n\t6-Todos de uma vez (Demora bastante)\n\t Outro valor para sair");
    scanf("%d", &op);
    if(op<0 && op>7);
    else if(op==6){
        getData("data/ListOrdered.txt", "data/results/ordered_byTime.dat", "data/results/ordered_bySwapNumber.dat", "data/results/ordered_byNumberComparation.dat");
        getData("data/ListReverse.txt", "data/results/reverse_byTime.dat","data/results/reverse_bySwapNumber.dat", "data/results/reverse_byNumberComparation.dat");
        getData("data/ListUnordered.txt", "data/results/unordered_byTime.dat", "data/results/unordered_bySwapNumber.dat", "data/results/unordered_byNumberComparation.dat");
    }
    else{
        runmethod("data/ListOrdered.txt", "data/results/O_individualsorting_byTime.dat", "data/results/O_individualsorting_bySwapNumber.dat", "data/results/O_individualsorting_byNumberComparation.dat", op);
        runmethod("data/ListReverse.txt", "data/results/R_individualsorting_byTime.dat", "data/results/R_individualsorting_bySwapNumber.dat", "data/results/R_individualsorting_byNumberComparation.dat", op);
        runmethod("data/ListUnordered.txt", "data/results/U_individualsorting_byTime.dat", "data/results/U_individualsorting_bySwapNumber.dat", "data/results/U_individualsorting_byNumberComparation.dat", op);
    }
    

    return 0;
}