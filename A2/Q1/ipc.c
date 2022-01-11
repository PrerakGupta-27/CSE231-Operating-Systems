// HARJEET SINGH YADAV
// CSAI - 2020561


#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/wait.h>


void S1_handler(int sig, siginfo_t *info, void *ucontext){

    printf("THIS IS S1 hanler %d %d %s\n",sig, info->si_value.sival_int,(char *) info->si_value.sival_ptr);

}

int main(){

    pid_t s1 = fork();
    pid_t sr,st;

    char str_s1[10];
    sprintf(str_s1, "%d", s1);

    if(s1==0){                                               //S1 body
    
        struct sigaction s1_action;
        s1_action.sa_flags = SA_SIGINFO;
        sigemptyset(&s1_action.sa_mask);

        s1_action.sa_sigaction = S1_handler;

        sigaction(SIGALRM, &s1_action, NULL);

        printf("I'm s1\n");

        for( ; ; );

        
    }else{

        sr = fork();
        if(sr==0){                                              //SR body E1

            char *args[] = {"./E1", str_s1, NULL};
            execv(args[0], args);


        }else{

            st = fork();
            if(st==0){                                           //ST body E2

               // waitpid();
                char *args[] = {"./E2", str_s1, NULL};
                execv(args[0], args);


            }else{                                               //Parent body

                printf("i'm parent %d\n",getpid());
                
            }
        }        
    }
    
    return 0;
}