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
        I have used 2 char to store file names. 2 file pointers for the 2 files . I have opened the source file in read mode and destination file in write mode. I have used the f seek to find the no of bytes of data stored in sorce file and copied all the bytes in char array. then wrote the whole char array to destination file

    input: 
        file names with extensions

    output:
        copy the content of source into destinaion file
    


Q2
    code: 
        i have taken the number in the string and wrote a funtion divide by 2 to divide the no and store the remainders to get the corresponding binary code and the add the no bits by bit to get the output
    
    input:
        both decimal numbers

    output:
        sum of both numbers in the binary fomrat 



Q3
    code:
        i have created a helper funtion swap to swap the 2 integers by reference. first it takes 2 integers and swap them then it takes 2 arrays and swap their elements one by one
    
    input:
        array lenghts and theire elements
    
    output:
        it prints the array with after swapping



Q4
    code:
        this programs revese a string. i have used one parsing to swap the characters at index i with n-i-1 . we will run the loop till n/2.

    input: 
        it takes a strng as a input;

    output:
        it prints the reverse string;


Q5 
    code: 
        this program is normal binary search program used to find the existence of an element of an array. 
        insted of using  m =  (r+l)/2    to calculate the mid point
        i have used      m = l+(r-l)/2   to avoid the overflow 
        i have used unsigned int array
    input:
        it takes the size of the array any its elements
        it takes the element you want to find
    
    output:
        print the index of the element if found otherwise print not found message

