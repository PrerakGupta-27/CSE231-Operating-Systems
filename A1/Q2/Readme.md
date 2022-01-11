

# This file explains the working of question 2



First calling the function B using normal call

Then calling the C fucntion by modifying the return address in the stack

i pushed the address of function C into the stack

so when B will try to return then it will get the address of function C  when it will pop
and will go to C insted of A 

ret will pass the control to fucntion C

B.asm store the argument to in var and print it using sys call sys_write

C call the exit(0) which exits the program


# explantion of Makefile


there is only one target file -> run

it dependencies are -> A.o B.o C.o

A.o is the object file of A.c
B.o is the object file of B.asm
C.o is the object file of C.c



in  the final command 
# gcc -no-pie A.o B.o C.o -o run

i have linked / merged all the dependecies of run target in this command
-no-pie is to link nasm file and object file


