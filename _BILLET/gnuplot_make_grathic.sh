set terminal png size 1000, 600 enhanced font 'Arial, 16'


set style line 1 linecolor rgb 'red' linetype 1 linewidth 2
set style line 2 linecolor rgb 'blue' linetype 1 linewidth 2
set style line 3 linecolor rgb 'green' linetype 1 linewidth 2
set style line 4 linecolor rgb 'black' linetype 0 linewidth 2



set title ""


set border linewidth 1
set key top left
set grid
set mytics 1


# set yrange [0:10]
# set xrange [0:8]




set logscale x
# set logscale y
set format y "%.9f"
# set format y "10^{%L}"
# set format y "%.2f"
set xlabel "Номер испытания" font "Arial, 16"
# set format x "%.f" 
set format x "10^{%L}"
set ylabel "Время одной функции" font "Arial, 16"


set xtics font "Arial, 12"
set ytics font "Arial, 12"


set rmargin 4
set tmargin 2
set mxtics




set output 'grathics.png'

plot [*:*] [*:*] "report.txt" using 1:2 title "tiki" with linespoints ls 1,\
	"report.txt" using 1:3 title "gettimeofday" with linespoints ls 2



set output 'grathics_error.png'

plot [*:*] [*:*] "report_error.txt" using 1:2 title "tiki" with linespoints ls 1,\
	"report_error.txt" using 1:3 title "gettimeofday" with linespoints ls 2


