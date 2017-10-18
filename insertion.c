void SWAP(int *a, int *b){
    int temp = *a;
    *a=*b;
    *b=temp;
}

//O(n²)
int *insertionSort(int *vector, int n, unsigned long int *comparisionNumber, unsigned long int *swap){
    
        int i,j;
        for(i=1;i<n;i++){
            int index = vector[i];
            j=i;
            *comparisionNumber+=1;
            while(j>0 && vector[j-1]>index){
                *comparisionNumber+=1;
                *swap+=1;
                vector[j] = vector[j-1];
                j--;
            }
            if(i!=j){
                *swap+=1;
                vector[j] = index;
            }
        }
        return vector;
    }
    