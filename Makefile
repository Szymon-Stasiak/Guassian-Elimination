all:
	gcc -Wall --pedantic src/*.c -o bin/gauss
test: all
	bin/gauss dane/A.txt dane/B.txt