# IMPORTANT NOTE FOR FILE NAME AND MAKEFILE

# this file expalins the code / input / output format for Assignment 2 Questions 

# nameing covention of the .c file and Makefile
# A_ stands for Assingment and no after if represent the assingmet no. eg A2 means Assingmet 2
# q_ stands for question no.  eg q3 represent question no 3 
# a/b represent the part a or part b of the question q2a means question 2 part a

# eg A2q1b means Assignment 2 question no 1 part b
# Target file name in Makefile is same as .c file name

Q1
    code:
        used simple command line arguments to perform the action. used cal mm yyyy command to print the calender of the month . it prints the calender only when the date is valid
    input:
        it takes date as a command line arguments, of the form  dd mm yyyy format
    output:
        it prints the calender of that month 


Q2
    code:
        it only supports integer operations , bc command wasn't working 
        i have definde 5 different function to perform different operations like add sub mul div and exp according to user input. if exponet funtoion i have perform operation form LEFT TO RIGHT 
    input:
        it takes the command line arguments of the form  eg add 3 4 5 .. 
        no of arguments  should be   >=2 and less then 10
    output:
        it prints the result of the operation 

Q3
part a
    code:
        i have implemented binary search tree using struct node. with left and write pointer to strore the address of its chiledren. I have made insert and delete function to insert and delete the elements in the binary tree.
        i have made print function to print the elemets of the BST in incresing order using inorder traversal
    input:
        it ask for elements to insert in the binary tree
    output:
        print the inorder traversal of the tree after each operation

Q3
part b
    code:
        i have impelemeted AVL tree which is self balancing tree to keep the height difference of 1 all the time.
        i have made left rotate and right rotate function to peforem the rotation if there is imbalance in the tree after insetion or deletion
    input:
        it ask or elements to insert in the binary tree 
    output:
        print the inorder traversal ( increasing order ) of the tree after each insert and delete operation


Q4
    code:
        I have wrote 2 different function one for bubble and other for selection sort.
    input:
        it ask array size and elements and option for sorting algorithm
    output:
        performs the sorting and prints the elements of the array