//Program to implement the linked allocation method
//of file allocation.
#include <stdio.h>
#include<string.h>
#include <stdlib.h>

#define SIZE 100
#define NEWNODE (struct direntry *)malloc(sizeof(struct direntry))
#define NEWBLK (struct blknode *)malloc(sizeof(struct blknode))

struct blknode
{
  int bno;
  struct blknode *next;
} *curr,*prev;

struct direntry
{
 char fname[14];
 int start,end;
 struct blknode *blist;
 struct direntry *next;
}
*dirst=NULL,*dirend=NULL;


int bitvector[SIZE];

void main()
{
int ch1=0,i,j,n;
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
    dirend->blist=NULL;
    i=0;
    while(n>0)
    {
     if(bitvector[i]==1) //found ith block free
     {
       curr=NEWBLK;
       curr->bno=i; curr->next=NULL;
       if(dirend->blist==NULL)
       { dirend->start=i;
	 dirend->blist=curr;
	 prev=curr;
       }
       else
       { prev->next=curr;
	 prev=curr;
       }
       bitvector[i]=0; //mark ith block allocated
       n--;
       if(n==0)
	 break;
     }
     i++;
    }
    dirend->end=i;
    break;
  case 3 :
    printf("\nDirectory : ");
    printf("\n--------------------------");
    printf("\nFilename        Start  End");
    printf("\n--------------------------");
    for(t1=dirst;t1!=NULL;t1=t1->next)
    {
     printf("\n%-14s  %5d  %3d",t1->fname,t1->start,t1->end);
     printf(" (");
     for(curr=t1->blist;curr!=NULL;curr=curr->next)
      printf("%3d",curr->bno);
     printf(")");
    }

    printf("\n--------------------------");
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
    if(t1!=NULL)
    {
      for(curr=t1->blist; curr!=NULL; )
       { bitvector[curr->bno]=1;
	 prev=curr;
	 curr=curr->next;
	 free(prev);
       }

      if(t1==dirst)
	dirst=dirst->next;
      else
	t2->next=t1->next;

      if(dirst==NULL)
	dirend=NULL;
      free(t1);
    }
    else
    printf("File not found..");
    break;
    case 5:
    exit(0);
  }
}
}
