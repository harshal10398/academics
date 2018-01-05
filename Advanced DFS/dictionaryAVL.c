#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int iLikeNoise=0;
#define DATA_TYPE char*
#define FORMAT_SPECIFIER "%s"
struct node{
    DATA_TYPE data;
    DATA_TYPE def;
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
struct node* insertAvlTree(struct node **root,DATA_TYPE d,struct node **parent,DATA_TYPE def)
{

    // printf("sizeofDefinition %s: %ld\n",def,(*def));
    if(*root==NULL)
    {
        struct node *newNode=malloc(sizeof(struct node));
        // newNode->data=d;
        newNode->data=malloc(sizeof(char)*strlen(d));
        newNode->def=malloc(sizeof(char)*strlen(def));
        memcpy(newNode->data,d,sizeof(char)*strlen(d));
        memcpy(newNode->def,def,sizeof(char)*strlen(def));
        newNode->left=newNode->right=NULL;
        *root=newNode;
        return *root;
    }
    struct node *curr;
    if(strcmp(d,(CAST_PTR *root)->data)<0)
        curr=insertAvlTree(&(CAST_PTR *root)->left,d,root,def);
    else if(strcmp(d,(CAST_PTR *root)->data)>0)
        curr=insertAvlTree(&(CAST_PTR *root)->right,d,root,def);
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
    if(strcasecmp(d,root->data)==0)
        return root;
    else if(strcasecmp(d,root->data)<0)
        return search(root->left,d);
    else if(strcasecmp(d,root->data)>0)
        return search(root->right,d);
}
#define color1 "\e[32m"
#define color2 "\e[36m"
#define reset "\e[m"
void display(struct node* curr)
{
    if(curr==NULL)
    {
        if(iLikeNoise)
            printf("Node is null!\n");
        return;
    }
    if(iLikeNoise)
        printf("%p --> "FORMAT_SPECIFIER" = "FORMAT_SPECIFIER"\n",curr,curr->data,curr->def);
    else
        printf(color1 FORMAT_SPECIFIER reset"\t=\t" color2 FORMAT_SPECIFIER reset,curr->data,curr->def);   
}
void searchWild(struct node *root,DATA_TYPE d)
{
    if(root==NULL)
        return;
    if(strstr(root->data,d)!=NULL)
        display(root);
    searchWild(root->left,d);
    searchWild(root->right,d);
}

struct node *head[256];
void main(int argc,char *argv[])
{
    
    iLikeNoise=0;
    if(argc>=2)
        iLikeNoise=atoi(argv[2]);
    char str[256]={},*str2=malloc(sizeof(char)*256*10);
    FILE *f=fopen(argv[1],"r");
    int count=0;
    int cnt=1;
    int final=000;
    while(feof(f)==0)
    {
        if(cnt>1000)
        {
            printf("%d change now!: %ld\n",final,ftell(f));
            cnt=1;
            final++;
        }
        fscanf(f,"%s",str);
        fgets(str2,256*10,f);
        // printf("Str2=%s\n",str2);
        insertAvlTree(&head[final],str,&head[final],str2);
        if(iLikeNoise)
            printf("%s --> %s\n",str,str2);
        else
            printf("%ld %d\r",ftell(f),cnt);
        // display(insertAvlTree(&head,str,&head,str2));
        cnt++;
        count++;
    }
    printf("\n%d words entered!\n",count);
    int key;
    while(1)
    {
        printf("Enter choice: ");
        scanf("%d",&key);
        switch(key)
        {
            case 1:
                for(int i=0;i<=final;i++)
                    leftRootRight(head[i]);
                break;
            
            case 2:
                for(int i=0;i<=final;i++)
                    balRec(head[i]);
                break;
            case 3:
                for(int j=0;j<=final;j++)
                {
                    printHeirarchy(head[j],0);
                    //printf("level:");
                    for(int i=0;i<height(head[j]);i++)
                        printf("%d\t",i);
                    printf("\n");
                }
                break;
                
            case 4:
                printf("Enter word to search: ");
                fscanf(stdin,"%s",str);
                for(int i=0;i<=final;i++)
                    display(search(head[i],str));
                break;
                
            case 5:
                printf("Enter a word: ");
                scanf("%s",str);
                printf("Definition?:");
                // scanf("%s",str2);
                scanf("\n");
                fgets(str2,256*10,stdin);
                insertAvlTree(&head[final],str,&head[final],str2);
                break;
            case 6:
                printf("Enter word to search: ");
                fscanf(stdin,"%s",str);
                for(int i=0;i<=final;i++)
                    searchWild(head[i],str);
                break;
            default:
                printf("Oops you may have entered something wrong!\n");
        }
    }
}