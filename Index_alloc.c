//Program to implement the index allocation method
//of file allocation.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100
#define NEWNODE (struct direntry *)malloc(sizeof(struct direntry))

struct direntry
{
char fname[14];
int ibno,blist[20],k;
struct direntry *next;
}*dirst=NULL,*dirend=NULL;

int bitvector[SIZE];

void main()
{
int ch1=0,i,j,n,flag;
char fname[14];
struct direntry *t1,*t2;


for(i=0;i<SIZE;i++)
	bitvector[i]=rand()%2;
 
while(ch1!=5)
{
  printf("\n\n1. Print Bit Vector");
  printf("\n2. Create File");
  printf("\n3. Print Directory");
  printf("\n4. Delete File");
  printf("\n5. Exit");
  printf("\nEnter Your Choice : ");
  scanf("%d",&ch1);
  switch(ch1)
  {
   case 1 :
    for(i=0;i<SIZE;i++)
     printf("%4d",bitvector[i]);
    break;
   case 2 :
    if(dirst==NULL)
     dirst=dirend=NEWNODE;
    else
     {
      dirend->next=NEWNODE;
      dirend=dirend->next;
     }
    dirend->next=NULL;
    printf("\nEnter A Filename : ");
    scanf("%s",dirend->fname);
    printf("\nEnter The Number of Blocks To Allocate : ");
    scanf("%d",&n);
    dirend->k=n;
    i=j=flag=0;
    while(n>0)
    {
     if(bitvector[i]==1)//block i is free
      {
       if(flag==0)//index block not allocated
       {
	dirend->ibno=i;
	flag=1;
       }
       else//allocate data blck
       {
	dirend->blist[j++]=i;  //store block i in blist[j]
	n--;
       }
       bitvector[i]=0;//mark ith block allocated
       if(n==0)
	break;
      }//if
      i++;
     }//while
    break;
    case 3 :
     printf("\nDirectory : ");
     printf("\n---------------------------------------------");
     printf("\nFilename  IndexBlockNo      Block List");
     printf("\n--------------------------------------------");
     for(t1=dirst;t1!=NULL;t1=t1->next)
     { printf("\n%-10s %5d\t",t1->fname,t1->ibno);
       for(j=0;j<t1->k;j++)
	 printf("  %5d",t1->blist[j]);
     }
     printf("\n-------------------------------------------");
     break;
    case 4 :
     printf("\nEnter a Filename : ");
     scanf("%s",fname);
     t1=dirst;
     while(t1!=NULL)
     {
      if(strcmp(t1->fname,fname)==0)
	break;
      t2=t1;
      t1=t1->next;
     }
     if(t1!=NULL)  //file found
     {
      for(j=0;j<t1->k;j++) //mark data blocks as free
       bitvector[t1->blist[j]]=1;

      bitvector[t1->ibno]=1;//mark index block as free
      if(t1==dirst)
       dirst=dirst->next;
      else
       t2->next=t1->next;

       if(dirst==NULL)
	dirend=NULL;
       free(t1);
      }
     else
       printf("\nFile not found..");
      break;
      case 5: exit(0);
    }
}
}
