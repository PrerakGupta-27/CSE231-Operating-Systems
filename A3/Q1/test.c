#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <linux/kernel.h>
#include <omp.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/syscall.h>
#include <time.h>

#define SYS_mod_vruntime 548

int main(){

    int pid = fork();

    if(pid == 0){
        double st = 0.0;
        clock_t begin = clock();

        printf("This is child process :- %d\n", getpid());

        printf("It is running without mod_vruntime system call\n And the time taken to complete its execution is:-");

        clock_t end = clock();
        //fprintf(stdout, "%lu\n" , (unsigned long)time(NULL));
        st += (double)(end - begin) / CLOCKS_PER_SEC;
        printf("%f\n",st);
        
    }else{

        double st = 0.0;
        clock_t begin = clock();

        printf("This is parent process :- %d\n", getpid());

        //long res = 1;
        long res = syscall(548, getpid(), 80000000000);
        
        if(res < 0){
            perror("syscall");
            return 0;
        }

        printf("It is running with mod_vruntime system call\n And the time taken to complete its execution is:-");

        clock_t end = clock();
        //fprintf(stdout, "%lu\n" , (unsigned long)time(NULL));

        st += (double)(end - begin) / CLOCKS_PER_SEC;
        printf("%f\n",st);       

    }

    return 0;
}
