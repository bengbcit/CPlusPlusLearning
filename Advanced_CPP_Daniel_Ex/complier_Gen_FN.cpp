//############################################################################
/*
Compiler silently writes 4 functions if they are not explicitly declared:
1. Copy constructor.
2. Copy Assignment Operator.
3. Destructor.
4. Default constructor (only if there is no constructor declared).
*/

#include <iostream>
using namespace std;
/*	base default constructor
	member default constructor
	base destructor
	member destructor
	
	Order of destruction
	1.	The class's destructor is called, and the body of the destructor function is executed.
	2.	Destructors for nonstatic member objects are called in the REVERSE order in which 
		they appear in the class declaration.
	3.	Destructors for non-virtual base classes are called in the reverse order of declaration.
	4.	Destructors for virtual base classes are called in the reverse order of declaration.
*/

//Eg1:
//class dog {
//public:
//	/* string& m_name; no work for dog2 = dog1;
//	 std lib required containee to be sign&copy-able when copy constructible*/
//	string m_name;
//
//	dog(string name = "bob") { m_name = name; cout << name << " is born." << endl; }
//	~dog() { cout << m_name << " is destroyed.\n" ; }
//};
//
//int main() {
//	dog dog1("henry");
//	dog dog2;
//	dog2 = dog1;
//};

//Eg2:
//class collar {
//public:
//	/*	if there's no defualt constructor for collar, so the compiler create one (base);
//		but here is a default constructor created, the fn will run, ow not*/
//	collar() { std::cout << " collar is born.\n"; }
//};
//class dog {
//	/*	there's no default constructor for dog, so the compiler create one default constructor (base); 
//		then base constructor will call data members('collar' in this case) default constructor; 
//		then dog data memeber default constructor call collar default constructor; 
//	*/
//	collar m_collar; 
//public:
//	const string& m_name = "Daniel"; // name need to initialize
//};
//
//
//int main() {
//	dog dog1;
//	std::cout << dog1.m_name;
//}

//Eg3£º
class dog {
public:
	dog() = default;
	dog(string name)  { cout << name << endl; }
};
int main() {
	dog dog1("Pang");
}