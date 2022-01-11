# IMPORTANT NOTE FOR FILE NAME AND MAKEFILE

# this file expalins the code / input / output format for Assignment 2 Questions 

# nameing covention of the .c file and Makefile
# A_ stands for Assingment and no after if represent the assingmet no. eg A2 means Assingmet 2
# q_ stands for question no.  eg q3 represent question no 3 
# a/b represent the part a or part b of the question q2a means question 2 part a

# eg A2q1b means Assignment 2 question no 1 part b
# Target file name in Makefile is same as .c file name


Q1
part a:

    code:
        i have used array of struct node with a pointer variable to store the pointer of each row. pointer of each row will be stored in pointers of each node. Then i have assigned the no of columns to each row pointer
        i have used malloc and colloc for memeory allocation

    input: 
        no user input in this question  i have made the same matrix given the question
    
    output:
        pirnt the matrix with different columns


Q1
part b:

    code: 
        i have used the similar logic for this question as first question.i have used array of struct node with a pointer variable to store the pointer of each row. pointer of each row will be stored in pointers of each node. Then i have assigned the no of columns to each row pointer. i have used malloc and calloc for memory allocation and realloc for modifiying the no of columns
    
    input:
        it asks for no of rows the no of columns for each row. then ask for no of column for modification of matrix
    
    output:
        it prints the matrix with different columns and matrix after reallocation

Q2
part a

    code: 
        i have used a struct node with multiple data fields to store the all the requried information of the student and one next pointer to store the address of the next node
        then i have wrote insert fucntion to insert at any postion  then a delete function delete the node at any positon
        and print function to print the information of students

    input:
        it ask for the all the fields in the node and the positon at which you want to insert
    
    output:
          
Q2
part b
    code:
        similar approach as a part plus one more previous pointer to store the address of the previous node, rest everything remains same
    
    input:
        it ask for the all the fields in the node and the positon at which you want to insert

    output:
        it pirnt the all the data after each insertion

Q2
part c
    code: 
        i have implemented stack and queue using singly linked list. stack has push and pop funtion to insert and delete. insertion and deletion in stack is always at head of the singly linked list. queue has enqueue and dequeue funtion to insert at rear and delete from fornt end 
    input:
        ask for elemets to insert in the stack and queue
    output:
        prints the state of stack and queue after each operation

Q3
    code:
        I have declared an array of 5 void function pointers to points to 5 diffrent function. each element of array points to a particylar function 
    input:
        it ask to input 2 integers
    output:
        it prints their sum, sub, mul , division and exponent


Q5
    code:
        I have wrote 2 different function one for bubble and other for selection sort.
    input:
        it ask array size and elements and option for sorting algorithm
    output:
        performs the sorting and prints the elements of the array