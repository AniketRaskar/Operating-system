#include<stdio.h>

void SJF(int n,int arrival[],int brust[])
{
	int Rbrust[10];
	for(int i=0;i<n;i++)
	{
		Rbrust[i] = brust[i];
	}
	
	int count =0,end=0,time=0;
	int small =9;
	
	Rbrust[9]=9999;
	float turn=0 ,average_wait=0;
	float wait=0,average_turn=0;
	
	printf("Process No\t wait time \t Trun A time\n");
	
	for(time =0;count != n;time++)
	{
		small =9;
		for(int i=0;i<n;i++)
		{
			if(Rbrust[i]<Rbrust[small] && arrival[i]<=time && Rbrust[i]>0)
				small =i;
		}
		Rbrust[small]--;
		if(Rbrust[small]==0)
		{
			count++;
			end = time+1;
			
			turn += end-arrival[small];
			wait += end - arrival[small]-brust[small];
			
			
			printf("P %d\t\t %d \t\t %d \t\t\n",small+1,end-arrival[small],end-arrival[small]-brust[small]);
		
			
		}
	}
	average_wait = wait/n;
	average_turn = turn /n;
	
	printf("Average waiting time is: %lf \n",average_wait);
	printf("Average turn around time is: %lf \n",average_turn);
}

void RRS(int n,int arrival[],int brust[],int q)
{
	int Rbrust[n];
	for(int i=0;i<n;i++)
	{
		Rbrust[i] = brust[i];
	}
	int y=n,c=0,time=0,i=0;
	float wait =0,average_wait=0;
	float turn =0, average_turn=0;
	
	printf("Process\t\t Wait\t\t Turn\t\t\n");
	
	for(time=0,i=0;y != 0;)
	{
		if(Rbrust[i]<=q && Rbrust[i]>0)
		{
			time += Rbrust[i];
			Rbrust[i] = 0;
			c=1;
		}
		else if(Rbrust[i]>q)
		{
			time +=q;
			Rbrust[i] = Rbrust[i]-q;
		}
		
		if(Rbrust[i]==0 && c==1)
		{
			y--;
			turn += time -arrival[i];
			wait += time - arrival[i]-brust[i];
			printf("P%d\t\t %d\t\t %d\t\t\n",i+1,time-arrival[i],time-arrival[i]-brust[i]);
			c=0;
		}
		
		if(i == n-1) i=0;
		else if(arrival[i+1]<=time) i++;
		else i=0;
			
	}
	average_wait = wait /n;
	average_turn = turn /n;
	printf("Average waiting time is:%lf\n",average_wait);
	printf("Average turn around time is: %lf\n",average_turn);
}
int main()
{
	int n;
	printf("Enter the number of process:\n");
	scanf("%d",&n);
	
	int arrival[n];
	int brust[n];
	for(int i=0;i<n;i++)
	{
		printf("Enter the arrival time:\n");
		scanf("%d",&arrival[i]);
		printf("Enter the brust time:\n");
		scanf("%d",&brust[i]);
	}
	//SJF(n,arrival,brust);
	printf("\n");
	printf("\n");
	int q=0;
	printf("Enter the quntm:\n");
	scanf("%d",&q);
	RRS(n,brust,arrival,q);
	return 0;
}
