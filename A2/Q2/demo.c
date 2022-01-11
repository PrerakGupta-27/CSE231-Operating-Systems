// Name - Harjeet
// Roll Number - 2020561

#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#define SYS_kernel_2d_memcpy 548


int main(int argc, char **argv)
{
  
    int matrix1[2][2] = { {1,2 },{3,4 }};
    int matrix2[2][2];
 
    printf("Making system call with matrix1 and matrix 2\n");

    long res = syscall(SYS_kernel_2d_memcpy, (float *)matrix1, (float *)matrix2, 2,2);

    printf("System call returned %ld.\n", res);
    perror("Console Output");

    printf("Matrix 2 : - After system call");

    for(int i = 0 ; i< 2 ; i++){

        for(int j =0 ; j<2 ; j++){

            printf("%d ",matrix2[i][j]);
        }
        printf("\n");
    }

  return res;
}
