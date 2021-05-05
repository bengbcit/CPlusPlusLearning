#include <iostream>
using namespace std;
/*	void pointer:
		1. could hold address of float, int, ch, bool etc
		2. but cannot dereference directly void pointer
	why void pointer?
		if you want to create a fn of pass by reference, using void ptr to avoid repeatness for each data type 
*/
/* normal pointer: 
		int pointer holds only addr of int, ch pointer holds only addr of ch
*/
  
void print(void* ptr, char type) {
	/* Step:
	*	1. you cast desired ptr type
		2. dereference it
	*/
	switch (type) {
	case 'i': cout << *((int*)ptr) << endl; break;
	case 'l': cout << *((long*)ptr) << endl;break;
	case 'f': cout << *((float*)ptr) << endl;break;
	case 'c': cout << *((char*)ptr) << endl;break;
	case 's': cout << *((string*)ptr) << endl;break;
	}
}
int main()
{
	int number = 5;
	char letter = 'a';
	long numLong = 100000;
	float numFloat = 3.14;
	string stringRandom = "ptrrrrr";
	print(&number, 'i');
	print(&letter, 'c');
	print(&numFloat, 'f');
	print(&stringRandom, 's');



	system("pause>0");
	return 0;
}