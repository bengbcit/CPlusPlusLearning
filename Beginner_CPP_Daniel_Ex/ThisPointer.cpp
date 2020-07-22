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
	ThisPointer ho(23);
	ho.printCrap();
}
