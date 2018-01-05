#include "stdio.h"
#include "stdlib.h"
struct list
{
	int data;
	struct list *next;
}*head;
void display(struct list *root)
{

	//printf("head=%p root=%p\n",head,root);
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
struct list* maximum(struct list *root)
{
	struct list *max=root;
	while(root)
	{
		if(root->data > max->data)
			max=root;
		root=root->next;
	}
	return max;
}
struct list* secondMaximumHarshal(struct list *root)
{

	struct list *secondMax=root;
	struct list *max=maximum(root);
	if(max==root)
		secondMax=secondMax->next;
	int count=1;
	while(root)
	{
		if(root!=max)
			if(secondMax->data < root->data)
				secondMax=root;
		printf("%d\n",count++);
		root=root->next;
	}
	return secondMax;
}

struct list* secondMaximumSangita(struct list *root)
{

	struct list *secondMax=root;
	struct list *max=maximum(root);
	if(max==root)
		secondMax=secondMax->next;
	while(root)
	{
		if(root->data > secondMax->data && root->data < max->data)
			secondMax=root;
		root=root->next;
	}
	return secondMax;
}

void main()
{
	int n,c,randomChoice,i,r;
	printf("Want to work on random values?[0/1]: ");
	scanf("%d",&randomChoice);
	printf("\
1)addNodeEnd()\n\
2)display()\n\
3)maximum()\n\
4)secondMaximumHarshal()\n\
5)secondMaximumSangita()\n\
");
	//head=NULL;
	while(1)
	{
		printf("Choice: ");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
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
				displayNode(maximum(head));
				break;
			case 4:
				displayNode(secondMaximumHarshal(head));
				break; 
			case 5:
				displayNode(secondMaximumSangita(head));
				break;
			default:
				printf("Wrong choice!\n");
				break;
		}
	}
}
