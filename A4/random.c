#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include <sys/syscall.h>
#include <stdlib.h>
#define WRITER 550
#define READER 549

int main()
{

	int randomData = open("/dev/urandom",O_RDONLY);

    int p= fork();

	if(p==0)
	{
		printf("Unable to open");
	}
	else
	{
		char myRandomData[50];
        while(1){

            ssize_t result = read(randomData,myRandomData, 50);
            printf("\n random data enqued\n");
            if(result < 0)
            {
                printf("Unable to read");
            }
            else
            {
                printf("%s %d\n",myRandomData,sizeof(myRandomData));
                int r = syscall(WRITER,"dfghjsdfghjk");
                printf("%d\n",r);
                printf("\nrandom data dequed\n");
            }
        }
		char buf[50];
		int j = syscall(READER,buf);
		printf("%d %s\n",j,buf);

    }

}