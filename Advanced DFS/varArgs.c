#include "stdio.h"
#include "stdarg.h"
void normalFunction(int a,...)
{
	va_list args;
	va_start(args,a);
//	for(int i=0;i<a;i++)

	printf("I am a normal function! %d\n",va_arg(args,int));
	printf("I am a normal function! %d\n",va_arg(args,int));
	printf("I am a normal function! %d\n",va_arg(args,int));
	printf("i got string: %s\n",va_arg(args,char*));
	printf("I am a normal function! %d\n",va_arg(args,int));
	
	va_end(args);
}
void main()
{
	normalFunction(5,10,20,30,"le bol",50);
}

