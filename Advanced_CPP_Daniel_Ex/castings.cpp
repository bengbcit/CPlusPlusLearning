//########### CppNuts cast series Derived#############################
/* All Castings Considered
 * Type Conversion:
 *    1. Implicit Type Conversion
 *    2. Explicit Type Conversion - Casting
 */
#include <iostream> 
#include <string>
using namespace std;

/*  1.const_cast: const_cast<T>(v) can be used to change the const or volatile qualifiers of (pointers or references)
 *		Where T MUST be a pointer, reference, or pointer to member type.
 *		Where v MUST be pointer or reference
 *	USE ONLY WHEN:
 *		a. you have to
 *		b. the actual refered obj/variable is not const.
 *		c. we're dealing with 3rd party library and some API(make sure not changing our var) required data in non-const
 */
// EG1: when the actual referred object/vaiable is not const
void const_cast_eg() {
	int a1 = 10;		// refered value a1 is not const
	const int* b1 = &a1;		
	int* d1 = const_cast<int*>(b1);	
	cout << d1 << " and *di " << *d1 << endl;
	*d1 = 15;
	cout << d1 << " and *di "<<*d1<<endl;
}

// EG2: when we need to call 3rd party library where it's taking var/obj as non-const
void const_cast_thirdPartyLib(int* x) { // non-const fn
	int i = 10;
	cout << i + *x<<endl << endl;
}

/*	2. dynamic_cast: dynamic_cast <new_type>(expression); Casting could be risky.
 *	USE ONLY WHEN:
 *		a. to find out correct down-cast at run time
 *			i.	Need at least one virtual fn in base class(work only on polymorphic)
 *			ii.	If cast successful, dynamic_cast return a value of new_type
 *			iii.If cast fail and new_type is ptr type, return null ptr
 *			iv.	If cast fail and new_type is reference type, throws an exception that matchese handler of bad_cast 
 *		b. we are not sure to cast right or wrong obj
 *		c. has run time overhead, bcuz it checks obj types at run time using RTTI(run time type info)
*/
// EG1: 
class DC_Base { // can have d1 or d2
	virtual void print() { cout << "Dynamic Cast Base " << endl; }
};
class DC_Base_Derived1: public DC_Base {
	void print() { cout << "Dynamic Cast Base Derived1 " << endl; }
};
class DC_Base_Derived2: public DC_Base {
	void print() { cout << "Dynamic Cast Base Derived2" << endl; }
};

void dynamic_cast_print() {
	DC_Base_Derived1 d1;
	DC_Base* bptr = dynamic_cast<DC_Base*>(&d1);							// if cast fails,bptr return null
	if (bptr == nullptr) 
		cout << "NULL Ptr" << endl << endl; 
	else 
		cout << "Not NULL Ptr" << endl << endl;
	DC_Base_Derived2* dptr2 = dynamic_cast<DC_Base_Derived2*>(bptr);		// if fails, dptr2 return null
	if (dptr2 == nullptr) { cout << "NULL Ptr" << endl << endl; }
}

/*	3. static_cast:
 *	USE ONLY WHEN:
 *		a. it performs implicit conversions btw types
 *		b. conversion btw types is provided thru conversion operator or conversion constructor
 *		c. it wants to be more restrictively compare to C-style
 *		d. avoiding cast from derived to private base pointer
 *		e. converting to void* or from void*
*/                 
// EG1: implicit conversion
void static_cast_eg() {
	float f = 3.5;
	int a;

	a = f;
	a = static_cast<int>(f); 
	cout <<"static_cast a value is:"<< a << endl;
}

//EG2: thru conv operator or conv constructor
class static_cast_ConvBtwType {
	int ip;	// private member
public:
	static_cast_ConvBtwType(int i1 = 0) :ip(i1) {}	// conversion constructor
	operator string() { return to_string(ip); }		// conversion operator
};

void static_cast_Conv_Opr_and_ctor() {
	static_cast_ConvBtwType obj;	
	// hacky way
	string str1 = obj;				// using conv operator
	cout << "str1 content is " << str1 << "; Obj content is " << obj.operator::string() << endl;
	obj = 20;						// using conv constructor
	cout << "str1 content is " << str1 << "; Obj content is " << obj.operator::string() << endl;
	// proper way:static_cast
	string str2 = static_cast<string>(obj);			// using conv operator
	cout << "str2 content is " << str2 << "; Obj content is " << obj.operator::string() << endl;
	obj = static_cast<static_cast_ConvBtwType>(30);	// using conv constructor
	cout << "str1 content is " << str1 << "; str2 content is " << str2 << "; Obj content is " << obj.operator::string() << endl;
}

// EG3: char* to int* allowed in C-style but not with static_cast
void static_cast_Restrictive() {
	//char c;				// invalid type conv; *p = 5; will fail @run time bcuz data corrupts at nearest mem location
	int c;
	int* p = (int*)&c;		// typecasted at c address into ptr p
	cout << "ptr p address is " << p << endl;
	*p = 5;					

	 int* ip = static_cast<int*>(&c); 
	 cout << "ptr ip address after static_cast is " << ip << endl;
}

// EG4: avoiding from drived to private base ptr
class SC_Base {};
//class SC_Base_Derived :private Base {};		// if private here, the program not allow at compile time
class SC_Base_Derived :public SC_Base {};
void static_cast_Avoiding() {
	SC_Base_Derived obj;
	SC_Base* ptr1 = (SC_Base*)&obj;
	SC_Base* ptr2 = static_cast<SC_Base*>(&obj);
	cout << "static_cast Base ptr2 " << ptr2 << endl;
	/*BE AWARE!!! NEVER DONE DOWN CAST*/
	// SC_Base_Derived* dptr = static_cast<SC_Base_Derived*>(ptr2);
}

// EG5: preferred when conv to void* or from it
void static_cast_ConvVoid() {
	int i = 10;
	void* ptrV = static_cast<void*>(&i);
	cout << "ptrV Address is " << ptrV<<endl;
	int* ptri = static_cast<int*>(ptrV);
	cout << "ptri Address is " << ptri << endl << endl;
}
/* 4. reinterpret_cast 
 *	USE ONLY WHEN:
 *		a. perform dangerous conversion bcuz it can typecast any pointer to any other pointer
 *		b. work with bits
 *		c. Result of a reinterpret_cast can't safely be used for anything other than being cast back to origin type
*/
// EG1: dangerous conv
class Mango {
public:
	void eatMango() { cout << "eating mango" << endl; }
};
class Banana {
public:
	void eatBanana() { cout << "eating Banana" << endl; }
};

void reinterpret_cast_print() {
	Banana* b = new Banana();
	Mango* m = new Mango();
	Banana* newBanana = reinterpret_cast<Banana*>(m); //m obj to newBanana
	newBanana->eatBanana();	//	reinterpret, so print out eating banana instead of mango
}

// EG2: bits
struct reinterpret_cast_bits {
	int x, y; 
	char c;
	bool b;
};
void reinterpret_cast_bits_fn() {				
	reinterpret_cast_bits s;
	s.x = 5; s.y = 10;
	s.c = 'a';
	s.b = 'true';
	int* p = reinterpret_cast<int*>(&s); // char c and bool b will fil in 4 byte as int x,y
	/* s addr memory like this |x|y|c|b| ---> so print out in a order like |5|10|a|true|*/
	cout << *p << endl;
	p++;
	cout << *p << endl;
	p++;
	char * c = reinterpret_cast<char*>(p);				//	3rd one: type cast back to the char
	cout << *c << endl;									//	print out a 
	cout << *(reinterpret_cast<bool*>(++c)) << endl;	//	increase c to 1 and type cast back to bool gives 1(true); c++ give value 97,dont know why
	/* c++: return value before increment; ++c: return value after increment */
}

/* C-Style Casting: (data_type)Expression eg: (int)2.5 gives you 2*/

/*
 * Generally C++ style of casts are preferred over the C-style, because:
 * 1. Easier to identify in the code.
 * 2. Less usage error. C++ style provides:
 *    a. Narrowly specified purpose of each cast, and
 *    b. Run-time type check capability.
 */

int main() {
	const_cast_eg();				// 1.const_cast: EG1 

	const int i = 20;				// 1.const_cast: EG2
	const int* ptri = &i;			// data is const
	const_cast_thirdPartyLib(const_cast<int*>(ptri));

	dynamic_cast_print();			// 2.dynamic_cast: EG1


	static_cast_eg();				// 3.static_cast: EG1 

	static_cast_Conv_Opr_and_ctor();// 3.static_cast: EG2

	static_cast_Restrictive();		// 3.static_cast: EG3
	
	static_cast_Avoiding();			// 3.static_cast: EG4
	
	static_cast_ConvVoid();			// 3.static_cast: EG5

	reinterpret_cast_print();		// 4. reinterpret_cast: EG1
	
	reinterpret_cast_bits_fn();		// 4. reinterpret_cast: EG2
	return 0;
}


















