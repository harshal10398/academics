#include "stdio.h"
#include "time.h"
#include "stdlib.h"
struct list {
	int data;
	struct list *next;
}*head[3],*ansHead;//,*harshal;
void display(struct list *root)
{
	while(root)
	{
		printf("%p\t%d\t%p\n",root,root->data,root->next);
		root=root->next;
	}
}
void displayAlternate(struct list *root)
{
	while(root)
	{
		printf("%p\t%d\t%p\n",root,root->data,root->next);
		if(root->next)
			root=root->next->next;
		else
			break;
	}
}
void push(struct list *root,int d)
{
	printf("Haju baki chhe\n");
}
void appendAscending(struct list **root,int d)
{
	struct list *newNode=malloc(sizeof(struct list));
	struct list *curr=*root;
	newNode->data=d;
	while(curr)
	{
		if(curr->data == newNode->data)
			return;
		if(curr->data > newNode->data)
		{
			newNode->next=curr;
			*root=newNode;
//			display(*root);
			return;
		}
		if(curr->next)
		{
			if(curr->next->data > newNode->data && curr->data < newNode->data )
			{
				newNode->next=curr->next;
				curr->next=newNode;
//				display(*root);
				return;
			}
		}
		else
		{
			curr->next=newNode;
//			display(*root);
			return;
		}
		curr=curr->next;
	}
	*root=newNode;
//	display(*root);
	return;
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
struct list* getNthElement(struct list *root,int n)
{

	int c=0;
	while(root!=NULL && c!=n)
	{
		c++;
		root=root->next;
	}
	return root;
}
void merge(struct list *root,int low,int mid,int high)
{
	while((low < mid) && (getNthElement(root,low)!=NULL && getNthElement(root,mid)!=NULL) )
	{

		if(getNthElement(root,low)->data < getNthElement(root,mid)->data)
			append(&ansHead,getNthElement(root,low++)->data);
		else
			append(&ansHead,getNthElement(root,mid++)->data);
	}
	while(low<mid)
		append(&ansHead,getNthElement(root,low++)->data);
	while(mid<high)
		append(&ansHead,getNthElement(root,mid++)->data);
}
void mergeSortHarshal(struct list *root,int low,int high)
{
	printf("called mergeSortHarshal low=%d high=%d\n",low,high);
	if(low>=high)
		return;
	int mid=(low+high)/2;
	mergeSortHarshal(root,low,mid);
	mergeSortHarshal(root,mid+1,high);
	merge(root,low,mid,high);
	display(ansHead);
}
struct list* mergeSortSangita(struct list *root1,struct list *root2)
{
	struct list *ans;
	struct timespec t1,t2;
	t1.tv_sec=0;
	t1.tv_nsec=0.5e9;
	while(root1 && root2)
	{
		if(root1->data < root2->data)
		{
			append(&ans,root1->data);
			root1=root1->next;
		}
		else
		{
			append(&ans,root2->data);
			root2=root2->next;
		}
		nanosleep(&t1,&t2);;
	}
	while(root1)
		append(&ans,root1->data),root1=root1->next;
	while(root2)
		append(&ans,root2->data),root2=root2->next;
//	display(ans);
 	return ans;
}
int getNumberOfElements(struct list *root)
{
	int c=0;
	while(root)
		root=root->next,c++;
	return c;
}
void main(int argc,char *argv[])
{
	int n,c,r,x;
	printf("\
1)append()\n\
2)display()\n\
3)getNthElement()\n\
4)mergeSort()\n\
5)mergeSortSangita()\n\
6)displayAlternate()\n\
7)appendAscending()\n\
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
				printf("Serial number of element to get?: ");
				scanf("%d",&n);
				displayNode(getNthElement(head[x],n));
				break;
			case 4:
				mergeSortHarshal(head[2],0,getNumberOfElements(head[2]));
				break;
			case 5:
				display(mergeSortSangita(head[0],head[1]));
				break;
			case 6:
				printf("Which list?: ");
				scanf("%d",&x);
				displayAlternate(head[x]);
				break;
			case 7:
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
						appendAscending(&head[x],r);
					}
				}
				else
				{
					printf("Enter value: ");
					scanf("%d",&n);
					appendAscending(&head[x],n);
				}
				break;
			default:
				printf("Wrong choice!\n");
				break;
		}
	}
}
