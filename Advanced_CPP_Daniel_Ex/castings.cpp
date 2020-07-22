//##################Bo Qian Series#################################
/* All Castings Considered
 * Type Conversion:
 *    1. Implicit Type Conversion
 *    2. Explicit Type Conversion - Casting
 */
#include <iostream> 
#include <string>
using namespace std;

/*
 * Casting could be risky.
 *
 * Example with dynamic_cast:
 */


void const_cast_eg() {
	int a1 = 10;
	const int* b1 = &a1;
	int* d1 = const_cast<int*>(b1);
	*d1 = 15;
	cout << d1 << " and *di "<<*d1<<endl;
}
/*  1.const_cast: const_cast<T>(v) can be used to change the const or volatile qualifiers of pointers or references
 *  Where T MUST be a pointer, reference, or pointer to member type.   
 */


/* 2. dynamic_cast */


/* 3. static_cast */                                       

/* 4. reinterpret_cast */


/* C-Style Casting: */

/*
 * Generally C++ style of casts are preferred over the C-style, because:
 * 1. Easier to identify in the code.
 * 2. Less usage error. C++ style provides:
 *    a. Narrowly specified purpose of each cast, and
 *    b. Run-time type check capability.
 */

int main() {
	const_cast_eg();
	return 0;
}


















