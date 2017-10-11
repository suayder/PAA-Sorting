void printFile(int *vector, int n, char str[]){
    FILE *text;
    int i;
    text  = fopen(str, "w");
    if(text==NULL)
        exit(1);

    for(i=0;i<n;i++){
        fprintf(text, "%d ",vector[i]);
    }
    fclose(text);
}

int *readFile(int *vector, const int size, char str[]){

    FILE *text;
    text  = fopen(str, "r");

    vector = (int*) malloc(size*sizeof(int));
    int i=0;
    //for(i = 0; i<size; i++){
    while(fscanf(text, "%d ", &vector[i])!=EOF){
        i++;
    }
    //print(vector, size);
    fclose(text);
    return vector;
}