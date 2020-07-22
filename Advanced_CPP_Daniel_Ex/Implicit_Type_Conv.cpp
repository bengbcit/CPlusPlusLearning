//####################Bo Qian Series####################################
/* User Defined Implicit Type Conversion
*  General guideline:
 *    1. Avoid defining seemingly unexpected conversion.
 *    2. Avoid defining two-way implicit conversion.
 * Categories of Type Conversion:
 *                                  Implicit      Explicit
 * Standard Type Conversion            A            B
 * User Defined Type Conversion        C            D
 *                                              (casting)			
 */
#include <iostream>
#include <string>
using namespace std;

void f(int i) { cout << i << endl; };
void simp_print() {
	/*Category A : Implicit Standard Type Conversion*/
	// Eg1: Integral promotion
	char c = 'A';
	int i = c;
	cout <<"i is "<< i << endl;

	// Eg2: int -> Null pointer
	char* pc = 0;
	cout << "* pc is " << &pc << endl;

	// Eg3: char -> integer (implicityly)
	f(c);

	// Eg4: pointer type conversion
	//dog* pd = new yellowdog();  
}

/* Category C: Implicit User Defined Type Conversion
 * Defined inside class (user defined type)
 *
 * There are 2 methods to define implicit user defined type conversion:
 * Method 1: Use constructor that can accept a single parameter.
 *    - convert other types of object into your class
 * Method 2: Use the type conversion function
 *    - convert an object of your class into other types
 */
class dog {
public:
	 /*If you only want to define a constructor, and no implicit type conversion, always put "explicit" 
	 before the constructor to avoid inadvertent type conversion.*/
	// method 1
	dog(string name) { m_name = name; }  
	string getName() { return m_name; }
	// method 2
	operator string() const { return m_name; }
private:
	string m_name;
};

/* Implicit type conversion is useful when creating numerical types of class, such as a rational class.*/
class Rational {
public:
	// constructor + implicit + explicit type 
	Rational(int numerator = 0, int denominator = 2) : num(numerator), den(denominator) {}
	int num;  // Demo only, public data members are not recommended
	int den;

	/* // uncomment this: "Rational r2 = r1 * 2; " not work bcuz two way implicit conversion.

	const Rational operator*(const Rational& rhs) {
		return Rational(num * rhs.num, den * rhs.den);
	}
	// make r3 Rational: integer * r1 work ; 
	operator int() const { return num / den; }

	*/
};

// better approach make Rational r2 & r3 below works. 
// use non-member operator multiply two rational together
const Rational operator*(const Rational& lhs, const Rational& rhs) { // operator can choose + or - or /
	return Rational(lhs.num * rhs.num, lhs.den * rhs.den);
}

int main() {
	
	//simp_print();

	string dogname = "Bob";
	// method 1
	dog dog1 = dogname;
	cout << "My name is " << dog1.getName()<<endl;
	// method 2
	const dog dog2 = dogname;
	cout << "My name is " << dog2.operator::string()  << endl;
	
	// Implicit Type Conversion Useful eg
	Rational r1 = 23;		// convert 23 into a Rational and assign it to r1
	Rational r2 = r1 * 2;	// convert 2 into a Rational and multipled r1 before assign it to r2

	/*	Because the constructor is not marked 'explicit', it means it can be invoked implicitly 
		to convert integers to Rational objects. */
	 // Rational r3 = 3 * r1; // not compile, but " r3 = Rational(3) * r1 " works;  <------ way 1
	Rational r3 = 3 * r1;

	cout << "denominator " << r1.den << "," << "numerator " << r1.num << endl;
	cout << "denominator " << r2.den << "," << "numerator " << r2.num << endl;
	cout << "denominator(pass by ref from r2.den) become " << r3.den << "," << "numerator " << r3.num << endl;



	return 0;

}