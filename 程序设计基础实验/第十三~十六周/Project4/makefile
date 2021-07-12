calculator:function.o function.h main.o main.h
	g++ function.o function.h main.o main.h -o calculator
main.o:main.cpp
	g++ -c main.cpp -o main.o
function.o:function.cpp
	g++ -c function.cpp -o function.o

clean:
	rm *.o
	rm calculator
