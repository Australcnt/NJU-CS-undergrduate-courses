MyShell:main.o cp.o wc.o cmp.o cat.o man.o sh.o main.h cp.h wc.h cmp.h cat.h man.h sh.h
	g++ main.o cp.o wc.o cmp.o cat.o man.o sh.o main.h cp.h wc.h cmp.h cat.h man.h sh.h -o MyShell
main.o:main.cpp
	g++ -c main.cpp -o main.o
cp.o:cp.cpp
	g++ -c cp.cpp -o cp.o
wc.o:wc.cpp
	g++ -c wc.cpp -o wc.o
cmp.o:cmp.cpp
	g++ -c cmp.cpp -o cmp.o
cat.o:cat.cpp
	g++ -c cat.cpp -o cat.o
man.o:man.cpp
	g++ -c man.cpp -o man.o
sh.o:sh.cpp
	g++ -c sh.cpp -o sh.o

clean:
	rm *.o
	rm MyShell
