#ploting values with a vector ordered
set xlabel "tamanho"
set title "comparações dos métodos por números de troca (Desordenado)"
plot '../data/results/unordered_bySwapNumber.dat' using 1:2 with lines title 'bubble', '../data/results/unordered_bySwapNumber.dat' using 1:3 with lines title 'insertion', '../data/results/unordered_bySwapNumber.dat' using 1:4 with lines title 'selection', '../data/results/unordered_bySwapNumber.dat' using 1:5 with lines title 'Merge', '../data/results/unordered_bySwapNumber.dat' using 1:6 with lines title 'Quick'