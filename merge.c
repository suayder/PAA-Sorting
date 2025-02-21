int* merge(int* L, int nl, int *R, int nr, unsigned long int *comparisionNumber, unsigned long int *swap){
    int i = 0, j = 0, k = 0;
    int *vector = (int*) malloc((nl+nr)*sizeof(int));
    while(i<nl && j<nr){
        *comparisionNumber+=1;
        *swap+=1;
        if(L[i] < R[j]){
            vector[k++] = L[i++];
        }
        else{
            vector[k++] = R[j++];
        }
    }
    *comparisionNumber+=1;
    while(i<nl){
        *swap+=1;
        vector[k++] = L[i++];
    }
    *comparisionNumber+=1;
    while(j<nr){
        *swap+=1;
        vector[k++] = R[j++];
    }
    return vector;
}
//O(nlogn)
int *mergeSort(int *vector, int n, unsigned long int *comparisionNumber, unsigned long int *swap){

    
    if(n<2) return vector;

    int middle = n/2, *left, *right;
    left = vector;
    right = vector+middle;

    left = mergeSort(left, middle,comparisionNumber,swap);
    right = mergeSort(right, n-middle,comparisionNumber,swap);
    vector = merge(left, middle, right, n-middle,comparisionNumber,swap);

    return vector;
}