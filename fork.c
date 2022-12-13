#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>

int main()
{
	pid_t q;
	printf("Before fork\n");
	q =fork();
	
	if(q==0)
	{
		printf("I an child having id: %d \n",getpid());
		printf("My parent id is: %d\n",getppid());
		
		pid_t p;
		printf("natu \n");
		p = fork();
		if(p==0)
		{
			printf("I am natu having id %d \n",getpid());
			printf("My pappa id is %d \n",getppid());
		}
		else
		{
			printf("My child id is %d\n",p);
			printf("I am pappa my id is: %d \n",getpid());
		}
	}
	else
	{
		printf("My child id is :%d\n",q);
		printf("I am parent having id %d\n",getpid());
	}
	
	return 0;
}
