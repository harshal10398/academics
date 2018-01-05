#include "stdio.h"
#include "string.h"
#include "wordsAVL.h"
struct node *head;
void main(int argc,char *argv[])
{
    iLikeNoise=1;
    char str[256]={},str2[256*10]={},foo[256];
    FILE *f=fopen(argv[1],"r");
    int count=0;
    while(feof(f)==0 && count++!=100)
    {
        fscanf(f,"%s %s",str,foo);
        fgets(str2,256*10,f);
        // insertAvlTree(&head,str,&head);
        printf("%s --> %s\n",str,str2);
    }
    int key;
    while(1)
    {
        printf("Enter choice: ");
        scanf("%d",&key);
        switch(key)
        {
            case 1:
                leftRootRight(head);
                break;
            case 2:
                balRec(head);
                break;
            case 3:
                printHeirarchy(head,0);
                //printf("level:");
                for(int i=0;i<height(head);i++)
                    printf("%d\t",i);
                printf("\n");
                break;
            case 4:
                fscanf(stdin,"%s",str);
                display(search(head,str));
                break;
            case 5:
                printf("Enter a word: ");
                scanf("%s",str);
                insertAvlTree(&head,str,&head);
                break;
            default:
                printf("Oops you may have entered something wrong!\n");
        }
    }
}