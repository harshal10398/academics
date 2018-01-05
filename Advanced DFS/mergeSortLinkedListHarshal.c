#include "stdio.h"
#include "time.h"
#include "stdlib.h"
//#include "harshal.h"
#define noise 1
struct list {
	int data;
	struct list *next;
}*head[3],*ansHead;//,*harshal;
void printfHarshal(char *str,...)
{
	printf("%s\n",str);
	
}
int timeForSort=0;

void display(struct list *root)
{
	while(root)
	{
		printf("%p\t%d\t%p\n",root,root->data,root->next);
		root=root->next;
	}
}
void displayNode(struct list *node)
{
	if(node==NULL)
	{
		printf("Null\n");
		return;
	}
	printf("%p\t%d\t%p\n",node,node->data,node->next);
}
void append(struct list **root,int d)
{
	struct list *newNode=malloc(sizeof(struct list));
	newNode->data=d;
	newNode->next=NULL;
	if(*root==NULL)
	{
		*root=newNode;
		return;
	}
	struct list *curr=*root;
	while(curr->next)
		curr=curr->next;
	curr->next=newNode;
	
}
struct list * delete(struct list **root)
{
	struct list *prev=*root;
	*root=((struct list*)*root)->next;
	free(prev);
	return *root;
}
void clearList(struct list **root)
{
	while(delete(root));
}
void split(struct list *root,struct list **frontReference,struct list **backReference)
{
	struct list *slow,*fast;
	
	timeForSort++;
	if(root==NULL || root->next==NULL)
	{
		*frontReference=root;
		*backReference=NULL;
	}
	else
	{
		slow=root;
		fast=root->next;
		//slow fast traversal
		while(fast)
		{
			timeForSort++;
			fast=fast->next;
			if(fast!=NULL)
			{
				fast=fast->next;
				slow=slow->next;
			}
			
		}
		*frontReference=root;
		*backReference=slow->next;
		slow->next=NULL;
	}

}
struct list *merge(struct list *a,struct list *b)
{
	struct list *result;
	timeForSort++;
	timeForSort++;
	if(a==NULL)
		return b;
	else if(b==NULL)
		return a;
	timeForSort++;
	if(a->data <= b->data)
	{
		result=a;
		result->next=merge(a->next,b);
	}
	else
	{
		result=b;
		result->next=merge(a,b->next);
	}
	return result;
}
void mergeSortHarshal(struct list **root)
{
	//best case
	struct list *headReference=*root;
	
	timeForSort++;
	if(headReference==NULL || headReference->next==NULL)
		return;

	struct list *a,*b;
	split(headReference,&a,&b);
	
	mergeSortHarshal(&a);
	mergeSortHarshal(&b);
	
	*root=merge(a,b);
}


void main(int argc,char *argv[])
{
	int n,c,r,x;
	printf("\
1)append()\n\
2)display()\n\
3)clearList()\n\
4)mergeSort()\n\
5)display timeForSort\n\
6)reset time\n\
7)autoTest()\n\
");
	while(1)
	{
		printf("Choice: ");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				printf("Which list? [0/1]: ");
				scanf("%d",&x);
				if(argc-1)
				{
					printf("How much to enter?: ");
					scanf("%d",&n);
					for(int i=0;i<n;i++)
					{
						r=rand()%(n*10);
						printf("Entering %d\n",r);
						append(&head[x],r);
					}
				}
				else
				{
					printf("Enter value: ");
					scanf("%d",&n);
					append(&head[x],n);
				}
				break;
			case 2:
				printf("Which list? [0/1]: ");
				scanf("%d",&x);
				display(head[x]);
				break;
			case 3:
				printf("Which list? [0/1]: ");
				scanf("%d",&x);
				clearList(&head[x]);
				break;				
			case 4:
				printf("Which list? [0/1]: ");
				scanf("%d",&x);
				mergeSortHarshal(&head[x]);				
				break;
			case 5:
				printf("This instance has used %d time for sorting\n",timeForSort);
				break;
			case 6:
				timeForSort=0;
				break;
			case 7:
				//autotest
				printf("Nodes\tTime\n");
				for(int m=5;m<1000;m++)
				{
					for(int n=0;n<m;n++)
						append(&head[0],m-n);
					mergeSortHarshal(&head[0]);
					printf("%d\t%d\n",m,timeForSort);
					clearList(&head[0]);
					timeForSort=0;
				}
			case 8:
				printf("Which list? [0/1]: ");
				scanf("%d",&x);
				displayNode(delete(&head[x]));
				break;
			default:
				printf("Wrong choice!\n");
				break;
		}
	}
}
