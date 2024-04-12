// look disk scheduling

#include<stdio.h>

int main()
{
    int RQ[100],i,j,n,TotalHeadMoment=0,initial,size,move,temp;

    printf("\n Enter the number of Requests : ");
    scanf("%d",&n);

    printf("\n Enter the Requests sequence : ");
    for(i=0;i<n;i++)
	{
	    scanf("%d",&RQ[i]);
	}
	
    printf("\n Enter initial head position : ");
    scanf("%d",&initial);
    
	printf("Enter total disk size\n");
    scanf("%d",&size);
    
	printf("\n Enter the head movement direction for Right 1 and for Left 0 : ");
    scanf("%d",&move);
    
    for(i=1;i<n;i++)
    {
        for(j=0;j<n-i;j++)
        {
            if(RQ[j]>RQ[j+1])
            {
                temp=RQ[j];
                RQ[j]=RQ[j+1];
                RQ[j+1]=temp;
            }
        }
    }

    int index;
    for(i=0;i<n;i++)
    {
        if(initial<RQ[i])
        {
            index=i;
            break;
        }
    }
  
    if(move==1)
    {
        for(i=index;i<n;i++)
        {
            TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
            initial=RQ[i];
        }
        
        for(i=0;i<index;i++)
        {
             TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
             initial=RQ[i];            
        }
    }
    else
    {
        for(i=0;i<index;i++)
		{
            TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
            initial=RQ[i];
        }
        
        for(i=index;i<n;i++)
        {
             TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
             initial=RQ[i];        
        }
    }
    
    printf("\n Total head movement is : %d",TotalHeadMoment);
    
	return 0;
}