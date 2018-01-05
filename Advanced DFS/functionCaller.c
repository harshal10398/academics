#include "stdio.h"
void fun1()
{
	printf("Inside fun1\n");
}
void fun2()
{
	printf("Inside fun2\n");
}

void functionChanger(void (*func1)(),void (*func2)())
{
	printf("before func1=%p func2=%p\n",func1,func2);
	func1=func2;
	printf("after func1=%p func2=%p\n",func1,func2);
	
	func1();
	func2();
}
void main()
{
	fun1();
	fun2();
	printf("fun1=%p fun2=%p\n",&fun1,&fun2);
	functionChanger(fun1,fun2);
	printf("fun1=%p fun2=%p\n",&fun1,&fun2);
		
	fun1();
	fun2();
}
