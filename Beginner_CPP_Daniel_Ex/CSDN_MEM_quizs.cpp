#include<iostream>
using namespace std;

// #1  �ڴ�˼����
//���ڴ�(heap)��ջ�ڴ�(stack)
/* Run it what happen?
�����������ΪGetMemory�����ܴ��ݶ�̬�ڴ棬
Test�����е� strһֱ���� NULL��
strcpy(str, "hello world");��ʹ���������*/
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
*���������롣
��ΪGetMemory���ص���ָ��ջ�ڴ桱��ָ�룬��ָ��ĵ�ַ���� NULL��
����ԭ�ֵ������Ѿ�������������ݲ���֪
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
*��1���ܹ����hello
��2���ڴ�й©
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
*�۸Ķ�̬�ڴ��������ݣ��������Ԥ�ϣ��ǳ�Σ�ա�
��Ϊfree(str);֮��str��ΪҰָ�룬
if(str != NULL)��䲻�����á�
*/
void Test(void)
{
	char* str = (char*)malloc(100);
	strcpy(str, ��hello��);
	free(str);
	if (str != NULL)
	{
		strcpy(str, ��world��);
		printf(str);
	}
}
