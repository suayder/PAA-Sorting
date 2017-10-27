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
    
        fprintf(results, "# size | bubble | Insertion | Selection | Merge | Quick");
        fprintf(swapResult, "# size | bubble | Insertion | Selection | Merge | Quick");
        fprintf(comparationResult, "# size | bubble | Insertion | Selection | Merge | Quick");
    
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
            clock_t totalBubble = runBubble(aux, size, &compNumber[0], &amountSwap[0]);
    
            //Insertion Sort
            for(i=0; i<size;i++){
                aux[i] = vector[i];
            }
            clock_t totalinsertion = runInsertion(aux, size, &compNumber[1], &amountSwap[1]);
    
            //Selection Sort
            for(i=0; i<size;i++){
                aux[i] = vector[i];
            }
            clock_t totalSelection = runSelection(aux, size, &compNumber[2], &amountSwap[2]);
    
            //Merge Sort
            for(i=0; i<size;i++){
                aux[i] = vector[i];
            }
            clock_t totalMerge = runMerge(aux, size, &compNumber[3], &amountSwap[3]);
    
            //Quick Sort
            for(i=0; i<size;i++){
                aux[i] = vector[i];
            }
            clock_t totalQuick = runQuick(aux, size, &compNumber[4], &amountSwap[4]);
            
            fprintf(results, "\n%d %ld %ld %ld %ld %ld", size, totalBubble, totalinsertion, totalSelection, totalMerge, totalQuick);
            fprintf(swapResult, "\n%d %lu %lu %lu %lu %lu", size, amountSwap[0], amountSwap[1], amountSwap[2], amountSwap[3], amountSwap[4]);
            fprintf(comparationResult, "\n%d %lu %lu %lu %lu %lu", size, compNumber[0], compNumber[1], compNumber[2], compNumber[3], compNumber[4]);
    
            fclose(fData);
            free(aux);
        }
        fclose(lData);
        fclose(results);
        fclose(swapResult);
        fclose(comparationResult);
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
    fprintf(comparationResult, "# size | comparacoes");

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
        

        fprintf(results, "\n%d %ld", size, timevalue);
        fprintf(swapResult, "\n%d %lu", size, amountSwap);
        fprintf(comparationResult, "\n%d %lu", size, compNumber);

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
        system("gnuplot -p scripts_gnuplot/ordered_bySwapNumber.gnu");
        system("gnuplot -p scripts_gnuplot/ordered_byNumberComparations.gnu");
        system("gnuplot -p scripts_gnuplot/ordered_byTime.gnu");
        system("gnuplot -p scripts_gnuplot/reverse_byNumberComparations.gnu");
        system("gnuplot -p scripts_gnuplot/reverse_bySwapNumber.gnu");
        system("gnuplot -p scripts_gnuplot/reverse_byTime.gnu");
        system("gnuplot -p scripts_gnuplot/unordered_byNumberComparation.gnu");
        system("gnuplot -p scripts_gnuplot/unordered_bySwapNumber.gnu");
        system("gnuplot -p scripts_gnuplot/unordered_byTime.gnu");
    }
    else{
        runmethod("data/ListOrdered.txt", "data/results/O_individualsorting_byTime.dat", "data/results/O_individualsorting_bySwapNumber.dat", "data/results/O_individualsorting_byNumberComparation.dat", op);
        runmethod("data/ListReverse.txt", "data/results/R_individualsorting_byTime.dat", "data/results/R_individualsorting_bySwapNumber.dat", "data/results/R_individualsorting_byNumberComparation.dat", op);
        runmethod("data/ListUnordered.txt", "data/results/U_individualsorting_byTime.dat", "data/results/U_individualsorting_bySwapNumber.dat", "data/results/U_individualsorting_byNumberComparation.dat", op);
        system("gnuplot -p scripts_gnuplot/individualsorting.gnu");
        /*int *i = readFile(i, 500000, "/home/suayder/Documents/PAA/PAA-Sorting/data/500000_reverse.txt");
        unsigned long int c, a;
        long int t = runBubble(i, 500000, &c, &a);
        print(i,500000);
        printf("time: %ld - comp: %lu - swap: %lu\n", t, c, a);*/
    }
    

    return 0;
}