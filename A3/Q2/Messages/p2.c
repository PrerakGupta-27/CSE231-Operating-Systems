#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <string.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <unistd.h>

struct message
{
    long type;
    char data[100];
};

int main(){

    struct message msg;
    int msgid;
    key_t key;

    if((key = ftok("common.c",'b'))==-1){
        perror("key");
        exit(1);
    }

    if((msgid = msgget(key, 0644)) == -1){

        perror("msgget");
        exit(1);
    }

    msg.type = 1;
    int curr = 1;
    while (curr<50)
    {	

	if(msgrcv(msgid,&msg,sizeof(msg),1,0) == -1){
	    perror("msgsnd");
	    exit(1);
	}
	printf("Message sent from P1 :- \n");
	printf("%s\n",msg.data);

	
	curr+=5;
	char ind[5];
	sprintf(ind,"%d",curr);
	strcpy(msg.data,ind);
	printf("Highest index has been sent back to P1\n");
	if(msgsnd(msgid,&msg,sizeof(msg),0) == -1){
            perror("msgsnd");
            exit(1);
        }
	
    }
    
    return 0;
}