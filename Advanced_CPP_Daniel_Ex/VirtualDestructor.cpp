/*
When we should use virtual destructor:
Any class with virtual functions should have a virtual destructor.

When not to use virtual destructor:
1. Size of the class needs to be small;
2. Size of the class needs to be precise, e.g. passing an object from C++ to C.
*/
#include <iostream>
using namespace std;

/*virtual destructor: used polymorphically*/
class Dog {
public:
	// without virtual, only destroy base dog() destructor and part of yellowdog
	virtual ~Dog() { cout << "Dog is destroyed"<<endl; } 
};

class Yellowdog : public Dog {// Yellowdog derived from Dog
public:
	~Yellowdog() { cout << "Yellow dog destroyed." << endl; }
};

class WhiteDog : public Dog {// WhiteDog derived from Dog
public:
	~WhiteDog() { cout << "White dog destroyed." << endl; }
};

class BlackDog: public Dog {// BlackDog derived from Dog
public:
	~BlackDog() { cout << "Black dog destroyed." << endl; }
};

class DogFactory {
public:
	// static fn createYellowDog, return as Dog pointer
	static Dog* createYellowDog() { return (new Yellowdog()); }
	
	// use shared_ptr as much as possible for classes derived from STL classes
	// no virtual destructor
	static shared_ptr<Dog> createWhiteDog() {
		return shared_ptr<WhiteDog>(new WhiteDog());
	}

	// unique_ptr will only invoke the dogs destructor;
	// eg: uncomment unique ptr gives "interesing" output
	static unique_ptr<Dog> createBlackDog() {
	   return unique_ptr<BlackDog>(new BlackDog());
	}

};

int main() {
	cout << "Virtual Destructor 'YellowDog' Demonstration: \n";
	Dog* pd = DogFactory::createYellowDog();
	delete pd;

	cout << endl<<"Shared Pointer 'WhiteDog'  Demonstration: \n";
	shared_ptr<Dog> pd2 = DogFactory::createWhiteDog();

	/*cout << endl << "Unique Pointer 'BlackDog' Demonstration: \n";
	unique_ptr<Dog> pd3 = DogFactory::createBlackDog();*/
	
	return 0;
}