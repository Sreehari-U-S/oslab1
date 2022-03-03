#include<stdio.h>

#define MAX 20
struct BLOCK
{
	int size;
	int isallocated;
	int pallocated;
	int frag;
} block[MAX];

void main()
{
	int np, nb, psize[MAX], i, j, k, best;
	printf("\nEnter the no: of blocks\t");
	scanf("%d",&nb);
	printf("\nEnter the size of the blocks");
	for(i = 0; i < nb; i++)
	{
		printf("\nBlock%d: ",i);
		scanf("%d",&block[i].size);
		block[i].isallocated = 0;
		block[i].pallocated = -1;
		block[i].frag = block[i].size;
	}
	printf("\nEnter the no: of processes\t");
	scanf("%d",&np);
	printf("\nEnter the size of the processes");
	for(j = 0; j < np; j++)
	{ 
		printf("\nProcess%d: ",j);
		scanf("%d",&psize[j]);
	}
	//Best Fit Memory Allocation
	for(j = 0; j < np; j++)
	{
		best = -1;
		for(i = 0; i < nb; i++)
		{
			if(block[i].isallocated==0 && block[i].size >= psize[j])
			{
				if(best == -1)
				best = i;
				else if(block[i].size < block[best].size)
				best = i;	
			}
		}
		if(best!=-1)
		{
			printf("\nProcess%d is allocated to block%d",j,best);
			block[best].frag = block[best].size - psize[j];
			block[best].isallocated = 1;
			block[best].pallocated = j;	
			}
	}
	for(i = 0; i < nb; i++)
	{
		printf("\nBlock\tIsallocated\tProcess_allocated\tBlockSize\tPSize\tFragment");
		printf("\n  %d \t    %d     \t        %d       \t  %d     \t  %d \t   %d   \n",i, block[i].isallocated,  block[i].pallocated, block[i].size, psize[block[i].pallocated], block[i].frag);
	}
} 