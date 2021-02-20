CC = g++

main : main.o dec_class.o 
	$(CC) -std=c++17 -g -Wall main.o dec_class.o -o main

main.o : main.cpp def_class.hpp
	$(CC) -std=c++17 -g -Wall -c main.cpp

dec_class.o : dec_class.cpp def_class.hpp
	$(CC) -std=c++17 -g -Wall -c dec_class.cpp

clean :
	rm *.o 

run : 
	./main
