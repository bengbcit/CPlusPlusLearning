#include <iostream>
using namespace std;

class ThisPointer
{
public:
	ThisPointer(int a);
	void printCrap();
private:
	int h;
};
// define outside constructor with private member
ThisPointer::ThisPointer(int num) :h(num) {}

void ThisPointer::printCrap() {
	cout << "h=" << h << endl;
	// -> work with pointer, so this is a pointer
	cout << "this->" << this->h << endl;
	cout << "(*this).h" << (*this).h << endl;
}

int main() {
	/*ThisPointer ho(23);
	ho.printCrap();*/

	/* Note:
	* Pointers and arrays support the same set of operations, with the same meaning
	* for both. The main difference being that pointers can be assigned new addresses,
	* while arrays cannot.
	*/
	int numbers[5];
	int* p;
	p = numbers;  *p = 10;
	p++;  *p = 20;
	p = &numbers[2];  *p = 30;
	p = numbers + 3;  *p = 40;
	p = numbers;  *(p + 4) = 50;
	for (int n = 0; n < 5; n++)
		cout << numbers[n] << ", ";
	return 0;
}


