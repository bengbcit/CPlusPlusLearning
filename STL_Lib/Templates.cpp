#include <iostream>
using std::cout;
using std::endl;

/************** Function Template *****************/
//template <class T>
//T Comparison(T a, T b) {
//	return (a > b) ? a : b;
//}
//
//int main() {
//
//	cout << "Compare two integers." << endl;
//	int ia = 9, ib = 12;
//	cout << "The larger integer is " << Comparison(ia, ib) << endl;
//	
//	cout << "Compare two float numbers." << endl;
//	float fa = 19.02, fb = 12.22;
//	cout << "The larger float number is " << Comparison(fa, fb) << endl;
//
//	cout << "Compare two chars." << endl;
//	char ca = 'a', cb = 'y';
//	cout << "The larger char is " << Comparison(ca, cb) << endl;
//
//	return 0;
//}

/************** Class Template *****************/
template <class T>
class Calculator
{
private:
	T num1, num2;

public:
	Calculator(T n1, T n2)
	{
		num1 = n1;
		num2 = n2;
	}

	void displayResult()
	{
		cout << "Numbers are: " << num1 << " and " << num2 << "." << endl;
		cout << "Addition is: " << add() << endl;
		cout << "Subtraction is: " << subtract() << endl;
		cout << "Product is: " << multiply() << endl;
		cout << "Division is: " << divide() << endl;
	}

	T add() { return num1 + num2; }

	T subtract() { return num1 - num2; }

	T multiply() { return num1 * num2; }

	T divide() { return num1 / num2; }
};

int main()
{
	Calculator<int> intCalc(2, 1);
	Calculator<float> floatCalc(2.4, 1.2);

	cout << "Int results:" << endl;
	intCalc.displayResult();

	cout << endl << "Float results:" << endl;
	floatCalc.displayResult();

	return 0;
}