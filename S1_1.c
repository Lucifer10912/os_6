#include<stdio.h>
#include<stdlib.h>

int main()
{
	int allocation[100][100],max[100][100],need[100][100],i,j,pr,rs;
	int available[100];
    int ch;

    do
    {
        printf("\n 1. Accept Available");
        printf("\n 2. Accept Allocation, Max");
        printf("\n 3. Display Need");
        printf("\n 4. Display Available");
        printf("\n 5. Exit");

        printf("\n Enter Choice : ");
        scanf("%d",&ch);

        if(ch==1)
        {
            printf("\n Enter Available Resources : ");
            for(j=0;j<rs;j++)
            {
                printf("\n %c : ",j+65);
                scanf("%d",&available[j]);
            }
        }
        else if(ch==2)
        {
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
        }
        else if(ch==3)
        {
            for(i=0;i<pr;i++)
            {
                for(j=0;j<rs;j++)
                {
                    need[i][j] = max[i][j] - allocation[i][j];
                }
            }            
        
            printf("\n Need Matrix : ");
            for(i=0;i<pr;i++)
            {
                printf("\n");
                for(j=0;j<rs;j++)
                {
                    printf(" %d ",need[i][j]);
                }
            }
        }
        else if(ch==4)
        {
            printf("\n Available Resources : ");
            for(j=0;j<rs;j++)
            {
                printf("\n %c : %d",j+65, available[j]);
            }
        }
        else if(ch==5)
        {
            exit(0);
        }
        else
        {
            printf("\n Invalid Choice");
        }
    }while(1);

	return 0;
}
