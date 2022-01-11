#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>
#include <pthread.h>

int size,n1,n2;
float sec_A[6],sec_B[6];

void *cal_avg_A(void* args){
    int a = size;
    char *data = (char *)args;
    while(data[--a]!='\n');

    int s = 0;
    while (data[++s]!='\n');

    int sum[6];
    for(int i =0 ; i<6; i++)
    {   sum[i]=0;  }

    int p=0;
    int students = 0;

    for(int i = s ; i<a && i+8<a ; ){

        i+=8;

        if(data[i]!='A'){
            while(data[++i]!='\n');
            continue;
        }

        students++;
        char num[6];
        int j,x,n = 0 , flag =0;
        p=0;
        for( j = i+2 ; data[j]!='\n' ; j++){

            if(data[j]==','){
                sscanf(num,"%d",&x);
                sum[p++] += x;
                n=0;
                num[0]=num[1]=num[2]=num[3]=num[4]='q';

                if(flag==1)break;
               continue;

            }

            num[n++]=data[j];

            if(data[j+1]=='\n'){
                data[j+1]=',';
                flag=1;
            }
        }
        i=j;
    }
    n1 = students;
    char avg[20];
    for(int i = 0 ;i <6 ; i++){
        float f = sum[i]/(students*1.0);
       sec_A[i]=f;
         f+=0.001;
        gcvt(f,10,avg);
        write(1,avg,9);
        write(1,"  ",3);
    }

}

void *cal_avg_B(void* args){
    int a = size;
    char *data = (char *)args;
    while(data[--a]!='\n');

    int s = 0;
    while (data[++s]!='\n');

    int sum[6];
    for(int i =0 ; i<6; i++)
    {   sum[i]=0;  }

    int p=0;
    int students = 0;

    for(int i = s ; i<a && i+8<a ; ){

        i+=8;

        if(data[i]!='B'){
            while(data[++i]!='\n');
            continue;
        }

        students++;
        char num[6];
        int j,x,n = 0 , flag =0;
        p=0;
        for( j = i+2 ; data[j]!='\n' ; j++){

            if(data[j]==','){

                sscanf(num,"%d",&x);
                sum[p++] += x;
                n=0;
                num[0]=num[1]=num[2]=num[3]=num[4]='q';

                if(flag==1)break;
               continue;

            }

            num[n++]=data[j];

            if(data[j+1]=='\n'){
                data[j+1]=',';
                flag=1;
            }
        }
        i=j;
    }
    n2 = students;
    char avg[20];
    for(int i = 0 ;i <6 ; i++){
        float f = sum[i]/(students*1.0);
        sec_B[i]=f;
        f+=0.001;
        gcvt(f,10,avg);
        write(1,avg,9);
        write(1,"  ",3);

    }

}

int main(){

    int fd = open("student_record.csv" ,O_RDONLY);
    if(fd == -1){
        printf("FAIL TO OPEN THE FILE");
        exit(0);
    }

    size = lseek(fd, 0 , SEEK_END);
    char data[size];
    lseek(fd,0,SEEK_SET);

    read(fd,data,size);
    char data1[size];
    for(int i =0; i<size; i++)data1[i]=data[i];

    pthread_t A,B;
    write(1,"Sec_A\n",7);
    pthread_create(&A,NULL,cal_avg_A,(void*)data);
    pthread_join(A,NULL);
    write(1,"\nSec_B\n",8);
    pthread_create(&B,NULL,cal_avg_B,(void*)data1);
    pthread_join(B,NULL);

    printf("\n\nAverages across both sections \n");
    for(int i = 0 ; i< 6 ; i++){

        float f = (n1*sec_A[i] + n2*sec_B[i])/(n1+n2);
       printf("%f ",f);
    }
    write(1,"\n",2);
    return 0;
}
