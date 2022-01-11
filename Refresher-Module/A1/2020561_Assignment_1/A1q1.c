#include <stdio.h>
#include <conio.h>

int main(){

    char source[20];   //enter souce file name
    char destination[20];  // enter destination file name
    printf("enter both file names : ");
    scanf("%s%s",source,destination);

    FILE* fp;
    FILE* fpd;

    long long a;
    fp = fopen(source,"r");
    fpd = fopen(destination,"w");

    fseek(fp,0,SEEK_END);
    a = ftell(fp);
    fseek(fp,0,SEEK_SET);

    char data[a];

    fread(&data,sizeof(data),1,fp);  //read the source file
    fwrite(data,sizeof(data),1,fpd); //write on destination file

    fclose(fp);
    fclose(fpd);

    return 0;

}