#include<mpi.h>
#include<stdio.h>
#include<stdlib.h>
void allocate(int a[],int n)
{
int i;

for(i=0;i<n;i++)
a[i]=rand()%50;
}

int main(int argc, char *argv[])
{
int rank,size,n,sum=0,count,*a=NULL,i;
rand();
MPI_Init(&argc,&argv);
MPI_Comm_size(MPI_COMM_WORLD,&size);
MPI_Comm_rank(MPI_COMM_WORLD,&rank);
n=atoi(argv[1]);
printf("\n size= %d,Rank=%d n=%d\n",size,rank,n);
count=n/size;


if(rank==0)
{
a=(int *) malloc(n*sizeof(int));

allocate(a,n);
}
for(i=0;i<count;i++)
{
printf("\t%d",a[i]);
sum=sum+a[i];

}

printf("\nsum=%d",sum);

MPI_Finalize();
}

