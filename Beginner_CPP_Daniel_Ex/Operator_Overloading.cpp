#include <iostream>
using namespace std;

// C++ allow you to specify more than one definition for an operator in the same scope
// which is called Operator Overloading
/* Operators that are not overloaded are:
		- scope operator(::)
		- sizeof
		- member selector(.)
		- member pointer selector(*)
		- ternary operator(?:)
*/

class Sally{
public:
	int num;
	Sally();
	Sally(int a);
	Sally operator + (Sally);
};


Sally::Sally(){}

Sally::Sally(int a) {
	num = a;
}
// Operator Overloading syntax here, operate under class Sally 
Sally Sally::operator+(Sally anotherSallyObj) {
	Sally temp;
	temp.num = anotherSallyObj.num + num ;
	return temp;
}

int main() {
	Sally a(34);
	Sally b(21);
	Sally c;

	c = a + b;	// without operator overloading, user define a +b object wont work
	cout << a.num << endl;
	cout << b.num << endl;
	cout << c.num << endl;
}