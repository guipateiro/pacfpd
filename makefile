all:
	gcc cpf.c -o saida

run:	all
	./saida

plot:	run
	./plot.sh

clear:
	rm -f *.txt
	rm -f *.dat	
	rm -f *.png

purge:	clear
	rm -f saida