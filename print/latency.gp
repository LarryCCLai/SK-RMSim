reset
set ytics 
set xtics
set key under
set ylabel 'Total latency(ns)' 
set xlabel 'Track capacity(bits)'

set term png enhanced font 'arial,12'
set terminal pngcairo size 720,400

set grid
set style data histogram
set style fill solid
set style histogram clustered gap 3 title offset character 0,0,0
set boxwidth 1 relative

set output './outputFile/graphs/latency.png'

plot [:][:1500000000]'./outputFile/information/latency(ns).txt' \
using 2:xtic(1) with histogram fs p 1 lt rgb "black" title 'Naive', \
'' using 3:xtic(1) with histogram fs p 2 lt rgb "black" title 'DCW'  , \
'' using 4:xtic(1) with histogram fs p 4 lt rgb "black" title 'FNW'  , \
'' using 5:xtic(1) with histogram fs p 6 lt rgb "black" title 'M-out-of-N-Write, d = 8'  , \
'' using 6:xtic(1) with histogram fs p 7 lt rgb "black" title 'M-out-of-N-Write, d = 16'  , \
