# HARJEET SINGH YADAV

# CSAI - 2020561

# This is readme file for q1 of the assignment

In the ipc.c file i'm creating three process S1, SR AND ST using fork()

S1 define a sigaction struct and set flag to SA_SIGINFO to receive more arguments or more information about the signal

# SR EXPLANATION

SR process replces the entire process with E1.c uisng execv system call and sending the s1 pid as argument to the file

E1.c setitimer() which sends SIGALRM signal after an defined interval

then SR handler is handling the signal and generating the random no using rdrand and queue using sigqueue system call
and union sigval sigval has 2 fields one integer and other one void pointer we are setting the interger to store the
randon no and sending the signal to the S1 handler using kill( ) system call the receving the random using siginfo_t *
info structure and accessing the

integer using si_value field of the siginfo structure and printing the

# ST EXPLANATION

ST process replces the entire process with E2.c using execv system call and sending the s1 pid as argument to the file

E2.c setitimer() which sends SIGALRM signal after an defined interval

then ST handler is handling the signal and generating the CPU timestamp string using rdrand and queue using sigqueue
system call and union sigval sigval has 2 fields one integer and other one void pointer we are setting the void pointer
to store the string and sending the signal to the S1 handler using kill( ) system call the receving the random using
siginfo_t *info structure and accessing the

integer using si_value field of the siginfo structure and printing the sting

# Makefile explanation

all: ipc E1 E2 run

ipc: ipc.c gcc ipc.c -o ipc

E1: E1.c gcc E1.c -o E1

E2: E2.c gcc E2.c -o E2

first generating the object file of all the files and then using ipc executable file to run all the files ./ipc


