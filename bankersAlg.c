#include<stdio.h>

#define MAX 20

void main()
{
	int Curr_alloc[MAX][MAX], Need[MAX][MAX], Max[MAX][MAX], Avail[MAX], Exist[MAX], Possess[MAX], Ans[MAX], completed[MAX], np, nr, i, j, k, t, p = 0, safe, change_comp ;
	
	printf("\nEnter the no: of processes\t");
	scanf("%d",&np);
	
	
	printf("\nEnter the no: of types of resources\t");
	scanf("%d",&nr);
	
	
	printf("\nEnter the total no: of instances of each type of resources\t");
	for(j = 0; j < nr; j++)
	{
		printf("\nNo: of instances of Resource%d: ",j);
		scanf("%d",&Exist[j]);
	}
	
	
	printf("\nEnter the maximum no: of resources required by each process\t");
	for(i = 0; i < np; i++)
	for(j = 0; j < nr; j++)
	{
		printf("\nEnter the maximum no: of R%d resources required by process%d\t",j,i);
		scanf("%d", &Max[i][j]);
	}
	
	
	for(j = 0; j < nr; j++)
	Possess[j] = 0;

	
	for(i = 0; i < np; i++)
	completed[i] = 0;
	
	
	printf("\nEnter the current allocation of resources required by each process\t");
	for(i = 0; i < np; i++)
	for(j = 0; j < nr; j++)
	{
		printf("\nEnter the current allocation: of R%d resources to the process%d\t",j,i);
		scanf("%d", &Curr_alloc[i][j]);
		Possess[j]=Possess[j]+Curr_alloc[i][j];
	}
	
	
	for(j = 0; j < nr; j++)
	Avail[j] = Exist[j] - Possess[j];
	
	
	for(i = 0; i < np; i++)
	for(j = 0; j < nr; j++)
	{
		Need[i][j] = Max[i][j] - Curr_alloc[i][j];
	}	

	
	printf("\nMax Matrix\n");
	for(i = 0; i < np; i++)
	{
		for(j = 0; j < nr; j++)
		{
			printf("%d\t",Max[i][j]);
		}
		printf("\n");
	}
	
	
	printf("\nCurr_alloc matrix\n");
	for(i = 0; i < np; i++)
	{
		for(j = 0; j < nr; j++)
		{
			printf("%d\t",Curr_alloc[i][j]);
		}
		printf("\n");
	}
	
	
	printf("\nNeed matrix\n");
	for(i = 0; i < np; i++)
	{
		for(j = 0; j < nr; j++)
		{
			printf("%d\t",Need[i][j]);
		}
		printf("\n");
	}
	
	
	printf("\nExist Vector\n");
	for(j = 0; j < nr; j++)
	printf("%d\t",Exist[j]);	

	
	printf("\nPossess Vector\n");
	for(j = 0; j < nr; j++)
	printf("%d\t",Possess[j]);	
	
	
	printf("\nAvail Vector\n");
	for(j = 0; j < nr; j++)
	printf("%d\t",Avail[j]);	

	for(k = 0; k < np; k++)
	{
		printf("\n k Iteration %d", k+1);
		change_comp = 0;
		for(i = 0;i < np; i++)
		{
			printf("\n i Iteration %d", i+1);
			if(completed[i] == 0)
			{
				int flag = 1;
				for(j = 0;j < nr; j++)
				{
					if(Need[i][j] > Avail[j])
					{
						//printf("\nProcess%d cannot complete now. Go for Process%d",i, i+1);
						flag = 0;
						break;
					}
				}
				
				if(flag == 1)
				{
					printf("\nProcess%d can complete execution with available resources", i);
					completed[i] = 1;
					change_comp = 1;
					Ans[p++] = i;
					for(j = 0;j < nr; j++)
					{
						Avail[j] += Curr_alloc[i][j];
					}
					
					printf("\nAvail Vector\n");
					for(j = 0; j < nr; j++)
					printf("%d\t",Avail[j]);
				}
				
			}
		}
		if(change_comp == 0)
		{
			safe = 0;
			break;
		}
		else
		{
			safe = 1;
			for(int t = 0; t < np; t++)
			{	
				if(completed[t]==0)
				{
					safe = 0;
					break;
					
				}
			}
		}
		if(safe)
		break;
	}
	
	
	if(safe == 1)
	{
		printf("\n The state is Safe and the sequence of process completion is\t");
		for(i = 0; i < np; i++)
		printf("P%d\t",Ans[i]);
	}
	else
	printf("\nThe state is Unsafe");
	printf("\n");
}