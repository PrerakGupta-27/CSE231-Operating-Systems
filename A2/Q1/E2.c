// HARJEET SINGH YADAV
// CSAI - 2020561

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/wait.h>

int s1;
char timestamp[45];

void ST_handler(int sig){
    
    printf("This is ST handler\n");
    unsigned high, low;
    __asm__ volatile("rdtsc":"=a"(low),"=d"(high));

    unsigned long long clock=(((unsigned long long)low)|((unsigned long long)high)<<32);
    unsigned long long t=clock/2400000000;
    
    sprintf(timestamp, "%lld", t);
    printf("the value of CPU stampcounter : %s\n",timestamp);


}


int main(int argc, char **argv)
{   
    s1 = atoi(argv[1]);

    struct itimerval st_timer;
    signal(SIGALRM, ST_handler);

    printf("i'm st\n");

    st_timer.it_value.tv_sec = 0;
    st_timer.it_value.tv_usec = 1;

    st_timer.it_interval.tv_sec = 0;
    st_timer.it_interval.tv_usec = 1;

    int b = setitimer(ITIMER_REAL, &st_timer, NULL);

    union sigval sigv;
    sigv.sival_ptr=timestamp;

    sigqueue(s1,SIGALRM,sigv);
    kill(s1,SIGALRM);

    return 0;
}
