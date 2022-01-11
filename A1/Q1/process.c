#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>

void calc_avg(int a, char data[], char sec){

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

        if(data[i]!=sec){
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
    char avg[20];
    for(int i = 0 ;i <6 ; i++){
        float f = sum[i]/(students*1.0);
        f+=.0001;
        gcvt(f,10,avg);
        write(1,avg,9);
        write(1,"  ",3);
    }

}


int main() {

    int fd = open("student_record.csv" ,O_RDONLY);
    if(fd == -1){
        printf("FAIL TO OPEN THE FILE");
        exit(0);
    }

    int size = lseek(fd, 0 , SEEK_END);
    char data[size];
    lseek(fd,0,SEEK_SET);

    read(fd,data,size);

    int pid = fork();

    if(pid == 0){
        
        write(1,"This is child prcess\nThis will print the Averages of sec A\n",60);
        calc_avg(size,data,'A');
        write(1,"\nChild process finished execution\n\n\n",37);
        exit(0);
    }


    waitpid(pid,NULL,0);

    write(1,"This is the parent process\nThis will print Averages of sec B\n",62);
    calc_avg(size,data,'B');
    write(1,"\nParent process finished execution\n",36);

    return 0;
}
