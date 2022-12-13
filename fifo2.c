#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
    FILE *fp;
    int fd1,fd2,l=0,w=1,c=0,i ,fd = 0;
    char *myfifo1="file1",str1[100],str2[100],ch;
    char *myfifo2="file2";

    // Read sentences from first myfifo1 file

    fd1=open(myfifo1,O_RDONLY);
    read(fd1,str1,100);
    printf("\n pipe1 : %s",str1);

    // count number of lines ,words , characters 
    i=0;
    while(str1[i]!='\0'){
        if(str1[i]=='\n') l++;
        else if(str1[i]==' ') w++;
        else c++;
        
        i++;

    }

    // check the result
    printf("\n No of lines %d",l);
    printf("\n No of words %d",w);
    printf("\n No of charcters %d",c);

    // wrire the counted data in text file
    fp = fopen("kp.txt","w");
    fprintf(fp,"\n no of lines:%d ",l);
    fprintf(fp,"\n No of words %d",w);
    fprintf(fp,"\n No of charcters %d",c);
    fclose(fp);

    
    fd = open("kp.txt" , O_RDONLY);
    read(fd,str2,100);

    // Write data of text file on scond fifo pipe

    fd2=open(myfifo2,O_WRONLY);
    
    write(fd2,str2,100);
    close(fd2);



    return 0;
}
