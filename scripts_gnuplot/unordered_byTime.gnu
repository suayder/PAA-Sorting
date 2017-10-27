#ploting values with a vector unordered
set grid
set xlabel "tamanho"
set title "comparações dos métodos por tempo (Desordenado)"
plot 'data/results/unordered_byTime.dat' using 1:2 with linespoint title 'bubble', 'data/results/unordered_byTime.dat' using 1:3 with linespoint title 'insertion', 'data/results/unordered_byTime.dat' using 1:4 with linespoint title 'selection', 'data/results/unordered_byTime.dat' using 1:5 with linespoint title 'Merge', 'data/results/unordered_byTime.dat' using 1:6 with linespoint title 'Quick'

#savar
set term postscript eps enhanced color
set output "data/results/graficos/unordered_byTime.eps"
replot