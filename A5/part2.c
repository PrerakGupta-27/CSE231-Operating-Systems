#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

sem_t forks[5];
sem_t bowl;

void eat(int n){
    printf("Thread %d is eating now\n",n);

}

void * fork_bowl(void * n){

    while(1){

        int thread=*(int *)n;
        int val;

        sem_wait(&forks[thread]);
        printf("Thread %d has picked the left fork\n",thread);

        sem_getvalue(&bowl,&val);
        printf("Value of bowl semaphore :- %d\n",val);

        sem_wait(&bowl);
        printf("Thread %d has picked bowl\n",thread);
        
        eat(thread);
       // sleep(1);

        sem_getvalue(&bowl,&val);
        printf("Value of bowl semaphore :- %d\n",val);

        sem_post(&forks[thread]);
        printf("Thread %d has left the fork\n", thread);

        sem_post(&bowl);
        printf("Thread %d has left the bowl\n",thread);

        sem_getvalue(&bowl,&val);
        printf("Value of bowl semaphore :- %d\n",val);

        for(int i = 0 ; i<1e6 ;i++);
        
    }

}

int main(){

    pthread_t thread[5];
    int thread_no[5];

    for(int i = 0 ; i<5 ; i++)
        sem_init(&forks[i],0,1);

    sem_init(&bowl,0,4);

    for(int i = 0 ; i<5 ; i++){

        thread_no[i]=i;
        pthread_create(&thread[i],NULL,fork_bowl,(void *)&thread_no[i]);

    }

    for(int i=0;i<5;i++)
        pthread_join(thread[i],NULL);

    return 0; 

}