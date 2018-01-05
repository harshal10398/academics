//#define DATA_TYPE
#define HELPER(X) #X
#define STRINGIFY(X) HELPER(X)
/*
 *  Upar nu logic uthavelu chhe
 *  Mane pan nathi khabar how will it work :(
 *
*/

#include "string.h"
int iLikeNoise=0;


struct node{
    DATA_TYPE data;
    struct node *left;
    struct node *right;
};
#define CAST_DBLPTR (struct node **)
#define CAST_PTR (struct node *)

void insertBinaryTree(struct node **root,DATA_TYPE d,char *pathStr)
{
    if(*root==NULL)
    {
        struct node *newNode=malloc(sizeof(struct node));
        newNode->data=d;
        newNode->left=newNode->right=NULL;
        if(pathStr!=NULL)
           if(iLikeNoise)
               printf("Warning!\tTree is empty now... ignoring whatever path is given!\n");
        *root=newNode;
        return;
    }
    if(*pathStr=='l' || *pathStr=='L')
        insertBinaryTree(&(CAST_PTR *root)->left,d,++pathStr);
    else if(*pathStr=='r'|| *pathStr=='R')
        insertBinaryTree(&(CAST_PTR *root)->right,d,++pathStr);
    else
        if(iLikeNoise)
            printf("Info!\tOverriding of a node is not allowed here bro!\n");
}
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
struct node* insertBinarySearchTree(struct node **root,DATA_TYPE d)
{
    if(*root==NULL)
    {
        struct node *newNode=malloc(sizeof(struct node));
        newNode->data=d;
        newNode->left=newNode->right=NULL;
        *root=newNode;
        return *root;
    }
    if(d > (CAST_PTR *root)->data)
        return insertBinarySearchTree(&(CAST_PTR *root)->right,d);
    else if(d < (CAST_PTR *root)->data)
        return insertBinarySearchTree(&(CAST_PTR *root)->left,d);
    else
    {
        printf(FORMAT_SPECIFIER" already exists!\n",d);
        return NULL;
    }
}
DATA_TYPE max(DATA_TYPE x,DATA_TYPE y)
{
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
        newNode->data=d;
        newNode->left=newNode->right=NULL;
        *root=newNode;
        return *root;
    }
    struct node *curr;
    
    if(d < (CAST_PTR *root)->data)
        curr=insertAvlTree(&(CAST_PTR *root)->left,d,root);
    else if(d > (CAST_PTR *root)->data)
        curr=insertAvlTree(&(CAST_PTR *root)->right,d,root);
    int b=balance(*parent);
    // printf("Balance: %d\tparent=%p --> %d\n",b,*parent,(CAST_PTR *parent)->data);
    if(b<-1 || b>1)
    {
        // printf("THIS NODE IS UNBALANCED!\n");
        if(d < (CAST_PTR *parent)->data) //unbalanced na left
        {
            if(d < (CAST_PTR *parent)->left->data)  //unbalanced na left ni left
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
            if(d < (CAST_PTR *parent)->right->data) //unbalanced na right ni left
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
    if(root->left)
    {
    printIndent(indent);
        printHeirarchy(root->left,indent+1);
    }
    printf("\n");
        printIndent(indent+0);
            printf(FORMAT_SPECIFIER,root->data);
    printf("\n");
    if(root->right)
    {
    printIndent(indent);
        printHeirarchy(root->right,indent+1);
    }
}
