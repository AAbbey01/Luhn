all: cpp javac 
	javaci
	cpp

cpp: cppmain
	g++ -g -Wall -std=c++11 luhncpp.o -o luhncpp

cppmain:
	g++ -c luhncpp.cpp

javaci:
	javac luhnjava.java

clean: 
	rm -f *.o luhncpp luhnjava.class

javaRun:
	java luhnjava

cppRun:
	./luhncpp 6211478804654556
