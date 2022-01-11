
#-*- Makefile -*-

all: process thread

process: process.o
	gcc process.o -o process

process.o: process.s
	gcc -c process.s

process.s:
	gcc -S process.c




thread: thread.o
	gcc thread.o -o thread -lpthread

thread.o: thread.s
	gcc -c thread.s

thread.s: 
	gcc -S thread.c


