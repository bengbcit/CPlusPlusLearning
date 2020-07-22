#include <iostream>
using namespace std;
/********** clone(): to make identical copy ************/
class Dog {
public:
	virtual Dog* clone() { return (new Dog(*this)); } // return a dog which copy constructed from itself
};

class YellowDog : public Dog {
public:
	virtual YellowDog* clone() { return (new YellowDog(*this)); } // return a dog which copy constructed from itself
};

void foo(Dog* d) {// fn foo take Dog pointer d
	// Dog* c = new Dog(*d); // c is a Dog; Issue here: not a identical copy constuctor
	Dog* c = d->clone();	// c is a YellowDog; clone() here act like virtual constructor
}

int main() {
	YellowDog d;
	foo(&d);
}