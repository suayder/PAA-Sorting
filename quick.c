void SWAPq(int *a, int *b){
    int temp = *a;
    *a=*b;
    *b=temp;
}

void qSort(int *vector, int begin, int end, unsigned long int *comparisionNumber, unsigned long int *swap){
    
    int left,right, pivot;

    if(begin >= end)
        return;

    left = begin;
    right = begin;
    pivot = vector[end];

    for(left;left<=end;left++){
        (*comparisionNumber)+=1;
        if(vector[left]<pivot){
            if(right!=left){
                (*swap)+=1;
                SWAPq(&vector[left], &vector[right]);
            }
            right++;
        }
    }
    SWAPq(&vector[end], &vector[right]);

    qSort(vector, begin, right-1, comparisionNumber, swap);
    qSort(vector, right+1, end, comparisionNumber, swap);
}

void quickSort(int *vector, int size, unsigned long int *comparisionNumber, unsigned long int *swap){
    qSort(vector, 0, size-1, comparisionNumber, swap);
}