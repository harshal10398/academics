#include "stdio.h"
#include "GL/glut.h"
#include "GL/gl.h"
#include "time.h"
#include "math.h"
#include "stdlib.h"

#define DATA_TYPE char
#define FORMAT_SPECIFIER "%c"
#include "myBinaryTree.h"

#define MAX_STR_SIZE 256

struct node *head;

void main(int argc,char *argv[])
{
    iLikeNoise=1;
    // printf("I am changed now!\n");
    // setDataType("char");
    // SET_DATA_TYPE("int");
    DATA_TYPE n;
    int key;
    srand(time(NULL));
    while(1)
    {

        printf("Enter choice: ");
        scanf("%d",&key);
        switch(key)
        {
            case 1:
                printf("Enter data: ");
                scanf("%d",&n);
                insertAvlTree(&head,n,&head);
                break;
            case 2:
                leftRootRight(head);
                break;
            case 3:
                balRec(head);
                break;
            case 5:
                printf("How much to enter?: ");
                scanf("%d",&key);
                for(int i=0;i<key;i++)
                    insertAvlTree(&head,rand()%(26)+'a',&head);
                break;
            case 4:
                printHeirarchy(head,0);
                //printf("level:");
                for(int i=0;i<height(head);i++)
                    printf("%d\t",i);
                printf("\n");
                break;
            default:
                printf("Oops you may have entered something wrong!\n");
        }
    }
}