main:Function.o Function.h main.o
	g++ Function.o Function.h main.o -o main
main.o:main.cpp
	g++ -c main.cpp -o main.o
Function.o:Function.cpp
	g++ -c Function.cpp -o Function.o

clean:
	rm *.o
	rm main
