#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
#include<sys/wait.h>

//In this way zombie process is created by using sleep system call while it is avoided by using wait system call as it sends the signal back.
int main()
{
	pid_t q;
	printf("Before fork\n");
	q =fork();
	
	if(q==0)   //child
	{
		printf("I an child having id: %d \n",getpid());
		printf("My parent id is: %d\n",getppid());
		
	}
	else  //parent
	{
		//wait(NULL);
		sleep(3);
		printf("I am parent having id %d\n",getpid());
		printf("My child id is :%d\n",q);
		
	}
	
	return 0;
}
