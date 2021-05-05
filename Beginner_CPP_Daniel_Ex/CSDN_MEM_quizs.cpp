#include<iostream>
using namespace std;

// #1  内存思考题
//堆内存(heap)和栈内存(stack)
/* Run it what happen?
程序崩溃。因为GetMemory并不能传递动态内存，
Test函数中的 str一直都是 NULL。
strcpy(str, "hello world");将使程序崩溃。*/
void GetMemory(char* p)
{
	p = (char*)malloc(100); // dynamic mem
}
void Test(void)
{
	char* str = NULL; // initial pointer as null
	GetMemory(str);
	strcpy(str, "hello world");
	printf(str);
}

/* #2 
*可能是乱码。
因为GetMemory返回的是指向“栈内存”的指针，该指针的地址不是 NULL，
但其原现的内容已经被清除，新内容不可知
*/
char* GetMemory(void)
{
	char p[] = "hello world";
	return p;
}

void Test(void)
{
	char* str = NULL;
	str = GetMemory();
	printf(str);
}

/* #3 
*（1）能够输出hello
（2）内存泄漏
*/
void GetMemory2(char** p, int num)
{
	*p = (char*)malloc(num);
}

void Test(void)
{
	char* str = NULL;
	GetMemory2(&str, 100);
	strcpy(str, "hello");
	printf(str);
}

/* #4 
*篡改动态内存区的内容，后果难以预料，非常危险。
因为free(str);之后，str成为野指针，
if(str != NULL)语句不起作用。
*/
void Test(void)
{
	char* str = (char*)malloc(100);
	strcpy(str, “hello”);
	free(str);
	if (str != NULL)
	{
		strcpy(str, “world”);
		printf(str);
	}
}
