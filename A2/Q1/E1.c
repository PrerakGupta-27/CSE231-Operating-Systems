// HARJEET SINGH YADAV
// CSAI - 2020561


#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/wait.h>

int value;

void SR_handler(int sig){

    printf("This is S1 handler\n");
    char s;
    
    __asm__ volatile("rdrand %0 ; setc %1" : "=r"(value),"=qm"(s));
    printf("The randon no is :%d\n",value);

    
}

int main(int argc, char **argv)
{   
    int s1 = atoi(argv[1]);

    struct itimerval sr_timer;

    signal(SIGALRM,SR_handler);

    printf("i'm st\n");

    sr_timer.it_value.tv_sec = 0;
    sr_timer.it_value.tv_usec = 1;

    sr_timer.it_interval.tv_sec = 1;
    sr_timer.it_interval.tv_usec = 1;
    
    int b = setitimer(ITIMER_REAL, &sr_timer, NULL);

    union sigval sigv;
    sigv.sival_int=value;
    sigqueue(s1,SIGALRM,sigv);
    kill(s1,SIGALRM);

    return 0;

}
