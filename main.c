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

int *bubbleSort1(int *vector, int n){
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

        if(fData==NULL)
            exit(1);

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
        aux = quickSort(aux, size, &compNumber[4], &amountSwap[4]);
        clock_t qend = clock();
        clock_t totalQuick = qend - qstart;
        
        fprintf(results, "%d %ld %ld %ld %ld\n", size, totalBubble, totalinsertion, totalSelection, totalMerge, totalQuick);
        fprintf(swapResult, "%d %lu %lu %lu %lu\n", size, amountSwap[0], amountSwap[1], amountSwap[2], amountSwap[3], amountSwap[4]);
        fprintf(comparationResult, "%d %lu %lu %lu %lu\n", size, compNumber[0], compNumber[1], compNumber[2], compNumber[3], compNumber[4]);

        fclose(fData);
    }
    fclose(lData);
    fclose(results);
    fclose(swapResult);
    fclose(comparationResult);
}

int main(){

    //getData("data/ListOrdered.txt", "data/results/ordered_byTime.dat", "data/results/ordered_bySwapNumber.dat", "data/results/ordered_byNumberComparations.dat");
    //getData("data/ListReverse.txt", "data/results/reverse_byTime.dat","data/results/reverse_bySwapNumber.dat", "data/results/reverse_byNumberComparations.dat");
    //getData("data/ListUnordered.txt", "data/results/unordered_byTime.dat", "data/results/unordered_bySwapNumber.dat", "/data/results/unordered_byNumberComparation.dat");
    
    /*unsigned long int a=0 , b=0; 
    int *vector = readFile(vector, 1000000, "data/1000000_reverse.txt");
    quickSort(vector, 1000000, &a, &b);
    print(vector,1000000);
    printf("\n%lu %lu\n", a,b);
    int *vector = generateVector(1000);
    printFile(vector, 1000, "/home/suayder/Desktop/array.txt");
    quickSort(vector, 1000, &a, &b);
    print(vector,1000);*/
    return 0;
}