void SWAPq(int *a, int *b){
    int temp = *a;
    *a=*b;
    *b=temp;
}

void qSort(int *vector, int begin, int end, unsigned long int *comparisionNumber, unsigned long int *swap){

    if(begin >= end)
        return;
    int left,right, pivot;
    
    pivot = vector[begin + (end - begin)/2];
    left = begin-1;
    right = end+1;
    
    while(left<=right)
    {
        while(vector[++left] < pivot);
        while(vector[--right] > pivot);
        if(left >= right)break;
        SWAPq(&vector[left], &vector[right]);
    }

    qSort(vector, begin, right, comparisionNumber, swap);
    qSort(vector, right+1, end, comparisionNumber, swap);
}

void quickSort(int *vector, int size, unsigned long int *comparisionNumber, unsigned long int *swap){
    qSort(vector, 0, size-1, comparisionNumber, swap);
}