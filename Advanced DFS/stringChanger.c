#include "stdio.h"
#include "stdlib.h"
void stringChanger(char *str)
{
	printf("\tBefore: %s\n",str);
	str[5]='h';
	printf("\tAfter: %s\n",str);
}
void main()
{
	char *string=malloc(sizeof(char)*10);
	for(int i='0';i<'9';i++)
		string[i-'0']=i;
	printf("Before calling: %s\n",string);
	stringChanger(string);
	printf("After calling: %s\n",string);
}
