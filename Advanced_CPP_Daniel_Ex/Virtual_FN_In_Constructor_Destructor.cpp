#include <iostream>
using namespace std;
/* Calling Virtual Fn in constructor and Destructor */

class Dog {
public:
	/*	dynamic binding not working when complex constructor/destructor like:
			Dog() { cout << "Dog born." << endl; bark(); }
			~Dog() {bark();}
		it's a non-virtual fn;  make constructor/ destructor as simple as possible
	*/ 
	Dog() { cout << "Dog born." << endl; }
	
	// without virtual fn
	void bark() { cout << "Without Virtual: I am a just a dog. " << endl; }
	// with virtual fn: ie dynamic binding
	virtual void bark_virtual() { cout << "With Virtual: I am a just a dog" << endl; }
	/*	bark(): without virtual
		bark_virtual(): with virtual
	*/ 
	void seeCat() { bark(); bark_virtual(); }
	
};

class yellowDog : public Dog {
public:
	yellowDog() { cout << "Yellow dog born." << endl; }
	// without virtual fn
	void bark() { cout << "Without Virtual: I am a yellow dog " << endl; }
	// with virtual fn
	virtual void bark_virtual() { cout << "With Virtual:I am a yellow dog " << endl; }
};

int main()
{
	yellowDog d; // dynamic binding, it will call bark() in yellowDog
	d.seeCat();

	return 0;
}
