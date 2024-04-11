#include<mpi.h>
#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
	int rank=0,size=2,n=10,max=0,min=51,count,*a=NULL,i;
	
	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	
	n = atoi(argv[1]);
	
	printf("\n Rank=%d n=%d\n",rank,n);
	count=n/size;
	
	if(rank==0)
	{
		a=(int *) malloc(n*sizeof(int));
		
		for(i=0;i<n;i++)
		{
			a[i]=rand()%50;
		}
	}
	
	for(i=0;i<count;i++)
	{
		printf("\n %d",a[i]);
		
		if(a[i]>max)
		{
			max=a[i];
		}
		if(a[i]<min)
		{
			min=a[i];
		}
	}
	
	printf("\n Max = %d \t Min = %d",max,min);
	
	MPI_Finalize();
	
	return 0;
}

