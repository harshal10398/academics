#include "dirent.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "mylinkedlist.h"
#include "sys/stat.h"
//struct list *head;
int biggestPrimeLessThan(int num)
{
	if(num<=1)
	{
		if(iLikeNoise)
			printf("No prime ever exist below 1 :(\n");
		return -1;
	}
	int prime,isPrime;
	for(prime=num,isPrime=1;prime>=2;prime--,isPrime=1)
	{
	
		for(int i=2;i<=prime/2;i++)
			if(prime%i==0)
			{
				isPrime=0;
				break;
			}	//notPrime;
		if(isPrime)
			return prime;
	}
}
int hash(int key,int categories)
{
	return key % biggestPrimeLessThan(categories);
}
int length(int num,int base)
{
	/*
	15/2=7	1
	7/2=3	2
	3/2=1	3
	1/2=0	4
	
	16/2=8	1
	8/2=4	2
	4/2=2	3
	2/2=1	4
	1/2=0	5
	
	*/
	if(base==0)
	{
		if(iLikeNoise)
			printf("Base can never be 1 fool :/\n");
		
		return 0;
	}
	int result=0;
	
	while(num!=0)
	{
		num/=base;
		result++;
	}
	return result;
}
void main(int argc,char *argv[])
{
	int cats;
	noiseEnable();
	if(argc!=2)
	{
		printf("Insufficient Arguments!\n");
		return;
	}
	DIR *storageDirectory=opendir(argv[1]);
	if(storageDirectory==NULL)
		if(mkdir(argv[1],0777)==-1)
		{
			printf("Error occured while creating directory: %s\n",argv[1]);
			return;
		}
	struct list **head;
	printf("Number of categories: ");
	scanf("%d",&cats);
	head=malloc(sizeof(struct list **)*cats);
	char fileName[256];	
	int n,c,randomChoice,i,r;
	printf("Want to work on random values?[0/1]: ");
	scanf("%d",&randomChoice);
	printf("\
1)append()\n\
2)display()\n\
3)dumpIntoFile\n\
4)appendFromFile\n\
5)close\n\
6)hashIt\n\
7)biggestPrimeLessThan()\n\
8)dumpIntoFile\n\
9)readFromFile\n\
");

	while(1)
	{
		printf("Choice: ");
		scanf("%d",&c);
		switch(c)
		{
/*			case 1:
				if(randomChoice)
				{
					printf("How many to enter?");
					scanf("%d",&n);
					for(i=0;i<n;i++)
					{
						r=rand()%(n*10);
						printf("Entering %d\n",r);
						append(&head,r);
					}
				}
				else
				{
					printf("Enter value: ");
					scanf("%d",&r);
					append(&head,r);
				}
				break;
			case 2:
				display(head);
				break;
			case 3:
				//dumpIntoFile
				dumpIntoFile(argv[1],head);
				break;
			case 4:
				appendFromFile(argv[1],&head);
				break;
*/			case 5:
				printf("Bye Bye.. See you again!\n");
				return;
			case 6:
				if(randomChoice)
				{
					printf("How many to enter?");
					scanf("%d",&n);
					for(i=0;i<n;i++)
					{
						r=rand()%(n*10);
						printf("%d. Entering %d\n",i,r);
						append(&head[hash(r,cats)],r);
					}
				}
				else
				{
					printf("Enter value: ");
					scanf("%d",&r);
					append(&head[hash(r,cats)],r);
				}
				break;
			case 7:
				printf("Enter value: ");
				scanf("%d",&r);
					
				printf("answer=%d\n",biggestPrimeLessThan(r));
				break;
			case 2:
				for(int i=0;i<cats;i++)
				{
					printf("---------%d--------\n",i);
					display(head[i]);
				}
				break;
			case 8:
				for(int i=0;i<cats;i++)
				{
					snprintf(fileName,256,"%s/%s_%0*d.htab",argv[1],argv[1],length(cats,10),i);
					printf("%s/%s_%0*d\n",argv[1],length(cats,10),i);
					dumpIntoFile(fileName,head[i]);
					
				}
				break;
			case 9:
				for(int i=0;i<cats;i++)
				{
					snprintf(fileName,256,"%s/%s_%0*d.htab",argv[1],argv[1],length(cats,10),i);
					printf("%s/%s_%0*d.htab\n",argv[1],argv[1],length(cats,10),i);
					appendFromFile(fileName,&head[i]);
				}
				break;
			default:
				printf("Wrong choice!\n");
				break;
		}
	}
}

