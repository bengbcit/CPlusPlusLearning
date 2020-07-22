#include <iostream>
using namespace std;

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

Sally Sally::operator+(Sally anotherSallyObj) {
	Sally newS;
	newS.num = num + anotherSallyObj.num;
	return newS;
}

int main() {
	Sally a(34);
	Sally b(21);
	Sally c;

	c = a + b;
	cout << a.num << endl;
	cout << b.num << endl;
	cout << c.num << endl;
}