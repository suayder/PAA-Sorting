#ploting values with a vector ordered
set xlabel "tamanho"
set ylabel "tempo"
set grid
set term wxt 1
plot '../data/results/O_individualsorting_byTime.dat' using 1:2 with linespoint title 'Ordenado', '../data/results/U_individualsorting_byTime.dat' using 1:2 with linespoint title 'desordenado', '../data/results/R_individualsorting_byTime.dat' using 1:2 with linespoint title 'Reverso';

#salvar
set term postscript eps enhanced color
set output "../data/results/graficos/individualsorting_byTime.eps"
replot

set term wxt 2
set ylabel "numero de trocas"
plot '../data/results/O_individualsorting_bySwapNumber.dat' using 1:2 with linespoint title 'Ordenado' lt rgb "red", '../data/results/U_individualsorting_bySwapNumber.dat' using 1:2 with linespoint title 'Desordenado' lt rgb "green", '../data/results/R_individualsorting_bySwapNumber.dat' using 1:2 with linespoint title 'Reverso' lt rgb "blue";

#salvar
set term postscript eps enhanced color
set output "../data/results/graficos/individualsorting_bySwapNumber.eps"
replot

set term wxt 3
set ylabel "numero de comparacoes"
plot '../data/results/O_individualsorting_byNumberComparation.dat' using 1:2 with linespoint title 'Ordenado' lt rgb "red", '../data/results/U_individualsorting_byNumberComparation.dat' using 1:2 with linespoint title 'Desordenado' lt rgb "green", '../data/results/R_individualsorting_byNumberComparation.dat' using 1:2 with linespoint title 'Reverso' lt rgb "blue";

#savar
set term postscript eps enhanced color
set output "../data/results/graficos/individualsorting_byNumberComparation.eps"
replot