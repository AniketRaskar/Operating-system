#include<stdio.h>
int max[10][10],allocation[10][10],need[10][10];
int avia[10];
int np,nr;

void getInput(int matrix[10][10])
{
	for(int i=0;i<np;i++)
	{
		for(int j=0;j<nr;j++)
		{
			scanf("%d",&matrix[i][j]);
		}
	}
}
void findNeed(int matrix[10][10])
{
	for(int i=0;i<np;i++)
	{
		for(int j=0;j<nr;j++)
		{
			need[i][j] = max[i][j]-allocation[i][j];
		}
	}
}
void Display(int matrix[10][10])
{
	for(int i=0;i<np;i++)
	{
		for(int j=0;j<nr;j++)
		{
			printf(" %d ",matrix[i][j]);
		}
		printf("\n");
	}
}

void Bankers()
{
	int l=0,i=0,j=0,k=0,f=0;
	int com[10],safe[10];
	for(j=0;j<10;j++)
	{
		com[j] = 0;
	}
	
	for(i=0;i<np;i++)
	{
		if(com[i]==0)
		{
			f=0;
			
			for(j=0;j<nr;j++)
			{
				if(need[i][j]>avia[j])
				{
					f =1;
					break;
				}
			}
			if(f==0)
			{
				com[i] =1;
				safe[k]= i;
				k++;
				for(l=0;l<nr;l++)
				{
					avia[l] += allocation[i][l];
				}
				i=-1;
			}
		}
	}
	
	f=0;
	for(i=0;i<np;i++)
	{
		if(com[i]==0)
		{
			printf("Process deadlock occurs...");
			f=1;
			break;
			
	}
	}
	printf("Safe path is:\n");
	if(f==0)
	{
	
	for(j=0;j<np;j++)
	{
		printf(" %d ",safe[j]);
	}
	}

}
int main()
{
	printf("Enter the number of Process:");
	scanf("%d",&np);
	printf("Enter the no of recources:");
	scanf("%d",&nr);
	
	printf("Enter the allocation matrix:\n");
	getInput(allocation);
	
	printf("enter the maximum matrix:\n");
	getInput(max);
	
	
	printf("Enter the resources:\n");
	for(int j=0;j<nr;j++)
	{
		scanf("%d",&avia[j]);
	}
	findNeed(need);
	
	Display(allocation);
	Display(max);
	printf("===============\n");
	printf("===============\n");
	printf("Result\n");
	Bankers();
	return 0;
}
