#include "mWayTree.h"
struct node *treeHead;
void main()
{
    int c,x;
    while(1)
    {
        printf("Choice: ");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
                printf("Enter numbeR: ");
                scanf("%d",&x);
                insertMwayTree(&treeHead,x);
                break;
            case 2:
                traverse(treeHead);
                break;
        }
    }
    // insertMwayTree(&treeHead,10);
    // traverse(treeHead);
}