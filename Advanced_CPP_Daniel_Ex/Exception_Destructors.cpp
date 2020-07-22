#include <iostream>
#include <exception>
using namespace std;

/* Prevent Exceptions from Leaving Destructors*/
// sln 1:
class dog {
public:
	string m_name;
	dog(string name) { m_name = name; cout << name << " is born." << endl; }
	~dog() { cout << m_name << " is distroied." << endl; }
	void prepareToDestr() {  throw 20; }
	void bark() { }
};
//sln 2:
class cat : public exception{
public:
	string m_name;
	cat(string name) { m_name = name; cout << name << " is born." << endl; }
	~cat(){// BAD Ideas to do throw exception at destructor; it might cause multiple pending crash
		cout << m_name << " is distroied." << endl; 
	}
	void meow() {};
};
int main() {
	// sln 1
	try {
		dog dog1("Henry");
		dog dog2("Bob");
		dog1.bark();
		dog2.bark();
		dog1.prepareToDestr();
		dog2.prepareToDestr();
	} 
	/*	when reach the end of try block, the stack will unwind and all local variables destroeyed;
		after throw 20; c++ goes pending;
		C++ not allow more than 1 pending at same time; more than 1 will crash
	*/ 
	catch (int e) {
		cout << e << " is caught" << endl<<endl;
	}

	// sln 2
	try {
		cat cat1("Mimi");
		cat cat2("Haya");
		cat1.meow();
		cat2.meow();
		throw exception{ "21" };
	}
	catch (const exception & e2) {
		cout <<e2.what() << " is caught" << endl;
	}
	catch (...) { cout << "Other Errors!"; }

}