all: cpp javaci c

c: 
	gcc luhnTest.c -o  luhnTest

cpp: cppmain
	g++ -g -Wall -std=c++11 luhncpp.o -o luhncpp

cppmain:
	g++ -c luhncpp.cpp

javaci:
	javac luhnjava.java

clean: 
	rm -f *.o luhncpp luhnjava.class luhnTest

javaRun:
	java luhnjava

tests:
