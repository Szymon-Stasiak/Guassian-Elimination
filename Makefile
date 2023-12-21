all:
	gcc -Wall --pedantic src/*.c -o bin/gauss
test: all
	bin/gauss data/A.txt data/B.txt
