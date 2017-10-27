void SWAPb(int *a, int *b){
    int temp = *a;
    *a=*b;
    *b=temp;
}
//O(n²)
int *bubbleSort(int *vector, int n, unsigned long int *comparisionNumber, unsigned long int *swap){
    int i, j;
    for(i = 1;i<n;i++){
        for(j = 0;j<n-i;j++){
            (*comparisionNumber)+=1;
            if(vector[j]>vector[j+1]){
                (*swap)+=1;
                SWAPb(&(vector[j]),&(vector[(j+1)]));
            }
        }
    }
    return vector;
}