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
	void bark() { cout << "Without Virtual: I am a just a dog. " << endl; }				// called
	// with virtual fn: ie dynamic binding
	virtual void bark_virtual() { cout << "With Virtual: I am a just a dog" << endl; }	// not called
	/*	bark(): without virtual
		bark_virtual(): with virtual
	*/ 
	void seeCat() { bark(); bark_virtual(); }
	
};

class yellowDog : public Dog {
public:
	yellowDog() { cout << "Yellow dog born." << endl; }
	// without virtual fn
	void bark() { cout << "Without Virtual: I am a yellow dog " << endl; }				// not called
	// with virtual fn
	virtual void bark_virtual() { cout << "With Virtual:I am a yellow dog " << endl; }	// called
};

int main()
{
	yellowDog d; // dynamic binding will call bark_virtual in yellowDog; ow call bark in Dog
	d.seeCat();

	return 0;
}
