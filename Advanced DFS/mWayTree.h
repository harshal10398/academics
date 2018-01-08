#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#define DATA_TYPE int
#define FORMAT_SPECIFIER "%d"

#define CAST_PTR_node (struct node*)
#define CAST_PTR_key (struct key*)
// #define m 5
struct key{
    int data;
    struct key *next;

    struct node *link;
};

struct node{
    struct key *keys;
    struct node *link;
};
void append(struct key **root,int d)
{
    if(*root==NULL)
    {
        struct key *newKey=malloc(sizeof(struct key));
        newKey->data=d;
        newKey->next=NULL;
        newKey->link=NULL;

        *root=newKey;
    }
    append(&(CAST_PTR_key root)->next,d);
}
void push(struct key **root,int d)
{
    struct key *keyNew=malloc(sizeof(struct key));
    keyNew->data=d;
    keyNew->next=*root;
    *root=keyNew;
}
void insertAfter(struct key **root,int d)
{
    if(*root==NULL)
    {
        append(root,d);
        return;
    }
    struct key *curr=*root;
    if(curr->next==NULL)
    {
        push(root,d);
        return;
    }
    while(curr->next->data < d)
        curr=curr->next;
    struct key *keyNew=malloc(sizeof(struct key));
    keyNew->next=curr->next->next;
    keyNew->link=curr->next->link;
    // keyNew->
    /*
    hu ahiya pochyo to chhele me vicharyu chhe ke,
    next ni link shift karvani ke tya ni tya j rakhvani? 
    when we are inserting new node inbetween two other nodes
    */
}
void insertMwayTree(struct node **root,DATA_TYPE d)
{
    if(*root==NULL)
    {
        struct node *newNode=(struct node *)malloc(sizeof(struct node));
        newNode->keys=malloc(sizeof(struct key));
        newNode->keys->data=d;
        newNode->keys->next=NULL;
        newNode->keys->link=NULL;
        newNode->link=NULL;

        *root=newNode;
        return;
    }
    if(d< (CAST_PTR_node *root)->keys->data)
    {
        insertMwayTree(&(CAST_PTR_node *root)->link,d);
        return;
    }
    struct key *keyList=(CAST_PTR_node *root)->keys;
    while(keyList!=NULL)
    {
        printf("yo!\n");
        if(! keyList->data < d )
        {
            struct key *newKey=malloc(sizeof(struct key));
            newKey->data=d;
            newKey->next=keyList->next;
            newKey->link=keyList->link;

            keyList->next=newKey;
            keyList->link=NULL;
        }
        keyList=keyList->next;
    }
}
void traverse(struct node *root)
{
    if(root==NULL)
        return;
    traverse(root->link);
    struct key *keyList=root->keys;
    while(keyList)
    {
        printf(FORMAT_SPECIFIER" ",root->keys->data);
        traverse(root->keys->link);
        keyList=keyList->next;
    }
}