#include<stdio.h>

int main()
{
	int allocation[100][100],max[100][100],need[100][100],i,j,k,y,pr,rs,cnt;
	int available[100],safe_state[100];
	
	printf("\n Enter No. of Processes : ");
	scanf("%d",&pr);
	
	printf("\n Enter No. of Resources : ");
	scanf("%d",&rs);
	
	printf("\n Enter Allocation Data : ");
	for(i=0;i<pr;i++)
	{
		for(j=0;j<rs;j++)
		{
			scanf("%d",&allocation[i][j]);
		}
	}	

	printf("\n Enter Max Data : ");
	for(i=0;i<pr;i++)
	{
		for(j=0;j<rs;j++)
		{
			scanf("%d",&max[i][j]);
		}
	}
	
	// for Need 
	for(i=0;i<pr;i++)
	{
		for(j=0;j<rs;j++)
		{
			need[i][j] = max[i][j] - allocation[i][j];
		}
	}
	
	for(i=0;i<pr;i++)
	{
		printf("\n");
		for(j=0;j<rs;j++)
		{
			printf(" %d ",need[i][j]);
		}
	}

	printf("\n Enter Available Resources : ");
	for(j=0;j<rs;j++)
	{
		printf("\n %c : ",j+65);
		scanf("%d",&available[j]);
	}

	y=0;
	for(k=0;k<pr && y!=pr;k++)
	{
		for (i=0;i<pr;i++) 
		{
			cnt=0;
			
			for(j=0;j<rs;j++) 
			{
				if(need[i][j]<=available[j])
				{
				 	cnt++;
				}
			}
			
			if(cnt==rs) 
			{
				safe_state[y++]=i;
				
				for(j=0;j<rs;j++)
				{
					available[j]=available[j] + allocation[i][j];
					need[i][j] = 9999;
				}
			} 
		}
	}
				
	if(y==pr)
	{
		printf("\n System is in Safe State : ");
		for(i=0;i<pr;i++)
		{
			printf(" P%d ",safe_state[i]);
		}
	}
	else
	{
		printf("\n System is not in Safe State");
	}
	
	return 0;
}
