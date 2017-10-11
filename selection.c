
void SWAPs(int *a, int *b){
    int temp = *a;
    *a=*b;
    *b=temp;
}

int *selectionSort(int *vector, int n, unsigned long int *comparisionNumber, unsigned long int *swap){
    
    int i,j, smallest;
    *comparisionNumber = 0;
    for(i=0;i<n-1;i++){
        smallest = i;
        for(j=i+1;j<n;j++){
            *comparisionNumber+=1;
            if(vector[j]<vector[smallest])
                smallest = j;
        }
        if(i!=smallest){
            SWAPs(&vector[i],&vector[smallest]);
            *swap+=1;
        }
    }
    return vector;
}