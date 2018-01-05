#include "stdio.h"
#include "stdlib.h"
#define SIZE 3
#define Z 0
#define C 1
#define RED "\e[32m"
#define BLUE "\e[34m"
#define RESET "\e[0m"
int table[SIZE][SIZE];
void resetTable()
{
	for(int i=0;i<SIZE;i++)
		for(int j=0;j<SIZE;j++)
			table[i][j]=-SIZE;
}
int win()
{
	int result[2]={0,0};
	for(int i=0;i<SIZE;i++,result[0]=0,result[1]=0)
	{
		for(int j=0;j<SIZE;j++)
			result[0]+=table[i][j],result[1]+=table[j][i];
		if(result[0]==3||result[1]==3)
			return 1;
		if(result[0]==0||result[1]==0)
			return 0;
	}
	for(int i=0;i<SIZE;i++)
		result[0]+=table[i][i],result[1]+=table[SIZE-i-1][i];
	if(result[0]==3 || result[1]==3)
		return 1;
	if(result[0]==0 || result[1]==0)
		return 0;
	return -1;
}
void printTable()
{
	for(int i=0;i<SIZE;i++,printf("\n"))
		for(int j=0;j<SIZE;j++)
			if(table[i][j]==0)
				printf(RED"o\t"RESET);
			else if(table[i][j]==1)
				printf(BLUE"x\t"RESET);	
			else
				printf("_\t");
}
void main(int argc,char *argv[])
{
	int winStatus;
	int chance=0,x,y;
	if(argc!=1+SIZE*SIZE)
	{
		resetTable();
		winStatus=win();
		while(winStatus!=0 && winStatus!=1)
		{
			printTable();
			printf("Player %d's chance!\n",chance%2);
			printf("Enter position: ");
			scanf("%d",&x);
			table[x/SIZE][x%SIZE]=chance%2;
			chance++;
			winStatus=win();
		}
		printf("\n\n-------------------\n");
				printf("Player %d won: (See how brilliant he/she is ;)\n",winStatus);
		printTable();
		return;
	}
	for(int i=0;i<SIZE;i++)
		for(int j=0;j<SIZE;j++)
			table[i][j]=atoi(argv[j+i*SIZE+1]);
	printTable();
	printf("\n\n\n");
	winStatus=win();
	if(winStatus==1)
		printf("Player 1 won!\n");
	else if(winStatus==0)
		printf("Player 0 won!\n");
	else
		printf("Draw!\n");
	return;
}
