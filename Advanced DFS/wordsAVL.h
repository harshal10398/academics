#include "string.h"
#include "stdlib.h"
int iLikeNoise=0;
#define DATA_TYPE char*
#define FORMAT_SPECIFIER "%s"
struct node{
    DATA_TYPE data;
    struct node *left;
    struct node *right;
};
#define CAST_DBLPTR (struct node **)
#define CAST_PTR (struct node *)
void leftRootRight(struct node *root)
{
    if(root==NULL)
        return;
    leftRootRight(root->left);
    printf(" "FORMAT_SPECIFIER" ",root->data);
    leftRootRight(root->right);
}
void rootLeftRight(struct node *root)
{
    if(root==NULL)
        return;
    printf(" "FORMAT_SPECIFIER" ",root->data);
    rootLeftRight(root->left);
    rootLeftRight(root->right);
}
void leftRightRoot(struct node *root)
{
    if(root==NULL)
        return;
    leftRightRoot(root->left);
    leftRightRoot(root->right);
    printf(" "FORMAT_SPECIFIER" ",root->data);
}
int max(int x,int y)
{
    // if(strcmp(x,y)>0)
    if(x>y)
        return x;
    return y;
}
int height(struct node *root)
{
    if(root==NULL)
        return 0;
    return max(1+height(root->left),1+height(root->right));
}
int balance(struct node *root)
{
    return height(root->left)-height(root->right);
}
struct node* insertAvlTree(struct node **root,DATA_TYPE d,struct node **parent)
{
    if(*root==NULL)
    {
        struct node *newNode=malloc(sizeof(struct node));
        // newNode->data=d;
        newNode->data=malloc(sizeof(char)*sizeof(d));
        memcpy(newNode->data,d,sizeof(char)*sizeof(d));
        newNode->left=newNode->right=NULL;
        *root=newNode;
        return *root;
    }
    struct node *curr;
    if(strcmp(d,(CAST_PTR *root)->data)<0)
        curr=insertAvlTree(&(CAST_PTR *root)->left,d,root);
    else if(strcmp(d,(CAST_PTR *root)->data)>0)
        curr=insertAvlTree(&(CAST_PTR *root)->right,d,root);
    int b=balance(*parent);
    
    if(b<-1 || b>1)
    {
        if(strcmp(d,(CAST_PTR *parent)->data)<0)
        {
            if(strcmp(d , (CAST_PTR *parent)->left->data)<0)  //unbalanced na left ni left
            {
                if(iLikeNoise)
                    printf("Will perform LL roation!\n");
                struct node 
                    *p=*parent,
                    *pl=(CAST_PTR *parent)->left,
                    *plr=pl->right;

                *parent=pl;
                (CAST_PTR *parent)->right=p;
                (CAST_PTR *parent)->right->left=plr;
            }
            else                                   //unbalanced na left ni right
            {
                if(iLikeNoise)
                    printf("Will perform LR rotaion!\n");
                struct node
                    *p=*parent,
                    *pl=p->left,
                    *pr=p->right,
                    *plr=pl->right,
                    *plrr=plr->right,
                    *plrl=plr->left;

                *parent=plr;
                (CAST_PTR *parent)->left=pl;
                (CAST_PTR *parent)->right=p;
                (CAST_PTR *parent)->right->right=pr;
                (CAST_PTR *parent)->right->left=plrr;
                (CAST_PTR *parent)->left->right=plrl;

            }
        }
        else                            //unbalanced na right
        {
            if(strcmp(d , (CAST_PTR *parent)->right->data)<0)
            {
                if(iLikeNoise)
                    printf("Will perform RL rotaion!\n");
                struct node
                    *p=*parent,
                    *pl=p->left,
                    *pr=p->right,
                    *prl=pr->left,
                    *prlr=prl->right,
                    *prll=prl->left;
                *parent=prl;
                (CAST_PTR *parent)->left=p;
                (CAST_PTR *parent)->right=pr;
                (CAST_PTR *parent)->left->left=pl;
                (CAST_PTR *parent)->left->right=prll;
                (CAST_PTR *parent)->right->left=prlr;
            }
            else                                    //unbalanced na right ni right
            {
                if(iLikeNoise)
                    printf("Will perform RR rotaion!\n");
                struct node
                    *p=*parent,
                    *pl=p->left,
                    *pr=p->right,
                    *prr=pr->right,
                    *prl=pr->left;
                *parent=pr;
                (CAST_PTR *parent)->left=p;
                (CAST_PTR *parent)->left->left=pl;
                (CAST_PTR *parent)->left->right=prl;
                (CAST_PTR *parent)->right=prr;
            }
        }
    }
    return curr;
}
void balRec(struct node *root)
{
    if(root==NULL)
        return;
    // if(iLikeNoise)
    printf(FORMAT_SPECIFIER" --> balance=%d\n",root->data,balance(root));
    balRec(root->left);
    balRec(root->right);
}
void printIndent(int indent)
{
    for(int i=0;i<indent;i++)
        printf("\t|");
}
void printHeirarchy(struct node *root,int indent)
{
    if(root==NULL)
        return;
    if(root->right)
    {
        printIndent(indent);
            printHeirarchy(root->right,indent+1);
    }
    printf("\n");
        printIndent(indent+0);
            printf(FORMAT_SPECIFIER,root->data);
    printf("\n");
    if(root->left)
    {
        printIndent(indent);
            printHeirarchy(root->left,indent+1);
    }
}
struct node* search(struct node *root,DATA_TYPE d)
{
    if(root==NULL)
        return NULL;
    if(strcmp(d,root->data)==0)
        return root;
    else if(strcmp(d,root->data)<0)
        return search(root->left,d);
    else if(strcmp(d,root->data)>0)
        return search(root->right,d);
}
void display(struct node* curr)
{
    if(curr==NULL)
    {
        if(iLikeNoise)
            printf("Node is null!\n");
        return;
    }
    printf("%p --> "FORMAT_SPECIFIER"\n",curr,curr->data);
}