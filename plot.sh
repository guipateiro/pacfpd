cat resp.txt | cut -d. -f1 >resp.dat
cat resp.dat | uniq -c >dados.dat
gnuplot <<- EOF
	set xlabel "X"
	set ylabel "Y"
	set yrange [0:10000]
	set title "OCORRENCIAS"   
	set term png
	set output "plot.png"
	plot "dados.dat" using 2:1 
EOF