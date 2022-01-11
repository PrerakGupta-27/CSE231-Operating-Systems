

all: run

run: A.o B.o C.o 
	gcc -no-pie A.o B.o C.o -o run

A.o: A.c
	gcc -c A.c

B.o: B.asm
	nasm -f elf64 B.asm -o B.o

C.o: C.c
	gcc -c C.c

