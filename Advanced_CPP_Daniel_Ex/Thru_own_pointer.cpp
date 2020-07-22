#include <iostream>
#include <vector>
using namespace std;

// one object(Person ) owns another object (the string) thru its pointer
class Person {
	string* pName_; // private members
	// sln 1:
	Person(const Person& rhs) ;
	Person& operator = (const Person& rhs);
public:
	Person(string name) { pName_ = new string(name); }
	~Person() { delete pName_; }
	// sln 2: Define copy constructor and copy assignment operator for deep copying
	//Person(const Person& rhs) {				// define copy constructor
	//	pName_ = new string(*(rhs.pName()));	// make a deep copying
	//}
	//Person& operator=(const Person& rhs) {}; 	// define copy assignment operator and deep copying
	string* pName() const { return pName_; }	// provide an accessor 		
	void printName() { cout << *pName_; }

	// define a clone fn
	Person* clone() {
		return (new Person(*pName_));			// clone fn return a identical obj itself
	};
};

int main() {
	// working with STL containerwhich need containee to be copy constructible and copy assignable 
	// save obj pointer in the containers class instead of object itself
	// sln 1: Delete copy constructor and copy assignment operator ( put them in the private), define clone()
	vector<Person*> persons;
	persons.push_back(new Person("George")); // push back the a pt of the person
	persons.back()->printName();
	cout << " Goodbye" << endl;

	//sln 2
	//vector<Person> persons;
	//persons.push_back( Person("George")); // push back the a pt of the person
	//persons.back().printName();
	//cout << " Goodbye" << endl;
}