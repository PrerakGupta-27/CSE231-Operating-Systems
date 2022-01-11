#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <string.h>
#include <fcntl.h>
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
	
    char arr[51][10];

    for(int i = 1; i<51 ; i++){
	char s[10] = "string";
	char no[5];
	sprintf(no,"%d",i);
	strcat(s,no);
	strcpy(arr[i],s);
	//printf("%s\n",arr[i]);
    }

    if((key = ftok("common.c",'b'))==-1){
        perror("key");
        exit(1);
    }

    if((msgid = msgget(key, 0644|IPC_CREAT)) == -1){
        perror("msgget");
        exit(1);
    }

    msg.type = 1;
    int curr = 1;

    while (curr<50)
    {	
	strcat(arr[curr],"\n");
        for(int i = curr+1 ; i<= curr+4 ; i++){
		strcat(arr[curr],arr[i]);
		strcat(arr[curr],"\n");	
	}

	strcpy(msg.data, arr[curr]);
	printf("Message has been sent to p2\n");
	if(msgsnd(msgid,&msg,sizeof(msg),0) == -1){
    		perror("msgsnd");
    		exit(1);
	}

        
	
	if(msgrcv(msgid,&msg,sizeof(msg),1,0) == -1){
            perror("msgsnd");
            exit(1);
        }

        curr = atoi(msg.data);

        printf("\nIndex returned by P2 : - %d\n",curr);

    }
    
    return 0;
}