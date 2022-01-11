

# This file explains the working of question 1
# q1 part A

1st part create 2 process through fork child computes the averages of sec A and parent computes the averages of sec B

then print the ans on the screen using write system call

# Makefile Explanation

this first generates the assembly file using gcc -S process.c command
then compile the generated assebly file to create the extecutable file


# q2 part B
This crates two threads one computes the avg of section A and other computes the average of sec B
then using those averages im computing the total average of all assignments accross both sections

# Makefile explaination of part b

command of both files is in same Makefile

i have used multiple targets in make file 

process target for part a 

thread target for part b

their dependencies is on object file  and dependency of object file is on assembly file 
assembly file is genetated  using 
# gcc -S thread.c  

this gives the coresponding Assembly file



