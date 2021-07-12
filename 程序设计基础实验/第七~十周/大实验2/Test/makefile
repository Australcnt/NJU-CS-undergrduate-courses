main:Func1.o Func2.o Func3.o command.h main.o
	g++ Func1.o Func2.o Func3.o  main.o command.h -o main
main.o:main.cpp
	g++ -c main.cpp	-o main.o
Func1.o:Func1.cpp
	g++ -c Func1.cpp -o Func1.o
Func2.o:Func2.cpp
	g++ -c Func2.cpp -o Func2.o
Func3.o:Func3.cpp
	g++ -c Func3.cpp -o Func3.o

clean:
	rm *.o
	rm main
