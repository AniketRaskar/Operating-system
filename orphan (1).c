#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>


int main()
{
	pid_t q;
	printf("Before fork\n");
	q =fork();
	
	if(q==0)   //child
	{
		sleep(2);
		printf("I am child having id: %d \n",getpid());
		printf("My parent id is: %d\n",getppid());
		
	}
	else  //parent
	{
		
		printf("My child id is :%d\n",q);
		printf("I am parent having id %d\n",getpid());
	}
	
	return 0;
}
