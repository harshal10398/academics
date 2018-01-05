#include "stdio.h"
#include "stdlib.h"
int iLikeNoise=0;
void noiseEnable(){
iLikeNoise=1;
}
void noiseDisable(){
iLikeNoise=0;
}

struct list
{
	int data;
	struct list *next;
};
void display(struct list *root)
{

	//printf("head=%p root=%p\n",head,root);
	while(root)
	{
		printf("%p\t%d\thex(data)=%02x\t%p\n",root,root->data,root->data,root->next);
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
	printf("%p\t%d\thex(data)=%02x\t%p\n",node,node->data,node->data,node->next);
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
/*
void append(struct list **root,struct list **newNode)
{
	if(*root==NULL)
	{
		*root=*newNode;
		return;
	}
	struct list *curr=*root;
	while(curr->next)
		curr=curr->next;
	curr->next=*newNode;
}
*/

void appendFromFile(char *fileName,struct list **root)
{
	FILE *stream=fopen(fileName,"r");
	if(stream==NULL)
	{
		printf("Error while opening file: %s\n",fileName);
		return;
	}
	struct list *curr=malloc(sizeof(struct list *));
	int count=0;
	while(fread(curr,sizeof(struct list),1,stream)!=0)
	{	
		append(root,curr->data);
		if(iLikeNoise)
			printf("Iteration: %d\n",count++);
	}
	fclose(stream);
}
void dumpIntoFile(char *fileName,struct list *root)
{
	FILE *stream=fopen(fileName,"a+");
	if(stream==NULL)
	{
		//if(iLikeNoise)
		printf("Error while writing/appending file: %s\n",fileName);
		return;
	}
	int count=1;
	while(root)
	{
		if(iLikeNoise)
			printf("Iteration: %d\n",count++);
		fwrite(root,sizeof(struct list),1,stream);
		root=root->next;
	}
	fclose(stream);
}
void push(struct list **root,int d)
{
	struct list *newNode=malloc(sizeof(struct list));
	newNode->data=d;
	newNode->next=*root;
	*root=newNode;
}
void pushFromFile(char *fileName,struct list **root)
{
	FILE *stream=fopen(fileName,"r");
	if(stream==NULL)
	{
		printf("Error while opening file: %s\n",fileName);
		return;
	}
	struct list *curr=malloc(sizeof(struct list *));
	int count=0;
	while(fread(curr,sizeof(struct list),1,stream)!=0)
	{	
		push(root,curr->data);
		if(iLikeNoise)
			printf("Iteration: %d\n",count++);
	}
	fclose(stream);
}
void deleteIntoFile(char *fileName,struct list **root)
{
	FILE *stream=fopen(fileName,"a+");
	if(stream==NULL)
	{
		//if(iLikeNoise)
		printf("Error while writing/appending file: %s\n",fileName);
		return;
	}
	int count=1;
	while(root)
	{
		if(iLikeNoise)
			printf("Iteration: %d\n",count++);
		fwrite(root,sizeof(struct list),1,stream);
		root=root->next;
	}
	fclose(stream);
	
}
