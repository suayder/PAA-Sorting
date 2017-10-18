#include <stdio.h>
#include <stdlib.h>

int main(){

    system("gnuplot -p scripts_gnuplot/OrderedByTime.gnu");
    return 0;
}