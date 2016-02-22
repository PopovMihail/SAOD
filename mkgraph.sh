#!/usr/bin/gnuplot
set terminal png size 800,480 enhanced font 'Arial, 16'
set output 'sorting.png'

set style line 1 linecolor rgb 'red' linetype 1 linewidth 2
#set style line 2 linecolor rgb 'blue' linetype 1 linewidth 2

set border linewidth 1 #//границы
set key top left #//где подписи
set grid #//сетка
set mytics 0 #//премежуточные деления 
set format y "%.6f" #//формат подписи у
set xlabel "Number of elements" font "Arial, 16" #//подпись х
set format x "%.0f" 
set ylabel "Execution time (sec)" font "Arial, 16"
set xtics 100000 font "Arial, 12"#//деления по оси х
set ytics font "Arial, 12" 
set rmargin 4 #//отступ с права
set tmargin 2 #//отступ сверху
set mxtics

plot "lab.dat" using 1:2 title "MergeSort" with linespoints ls 1
