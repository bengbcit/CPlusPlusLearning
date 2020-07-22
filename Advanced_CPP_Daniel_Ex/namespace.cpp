#include <cstdio>
#include <string>
#include <iostream>
/*********************   C++ Keyword: Using    ***************************/
/* case 1. using directive: to bring all namespace members into current scope */
//using namespace std;  // case 1, global scope 

/* case 2. using declaration:
 *   a. Bring one specific namespace member to current scope.
 *   b. Bring a member from base class to current class's scope. */
//using std::cout; // case 2.a, global scope

class B {
public:
    void f(int a) { std::cout << "Print class B's f(): " << a << std::endl; }; //!!!!!!! need {} ow error Lnk 2019
};

class D : public B { // B's public fn become D's private fn.
public:
    void g() {
        using namespace std;  // case 1, local scope
        cout << "From D: Local scope of using directive. \n";
    }
    void h() {
        using std::cout;     // case 2.a, local scope
        cout << "From D: Local scope by using declaration. \n";
    }
    // f here is D's private fn; AND only use in class scope here but not in local or global scope!!!
    // using std::cout; // ILLEGAL: should not use the namespace member in the class scope; should be local scope 
    // using namespace std; // ILLEGAL: should not use in class scope;
    using B::f;   // case 2.b,  class scope
    void f() { std::cout << "Print class D's f()." << std::endl; };
    
};

/*  Anonymous Namespace: doesnt have a name; everything inside namespace can be accessed within the same file.
 *
 */
// defined a global static fn of h2 is similar to 
static void h2() { std::cout << "h2()\n"; }

void g2() { std::cout << "global g2()\n"; }
namespace {
    void g2() { std::cout << "g2()\n"; }        // if have same fn g2() inside namespace and globally, using below line to call inside namespace
    void h2() { std::cout << "h2()\n"; g2(); }  // g2() inside namespace called not the global one; also cannot call this h2() from other file
}

int main() {

    /* without using B::f:
        1. will not compile since f is private fn in D now
        2. put void f() in class D without it will lead class B void f(int a) will be shadowed by class D
    */
    D obj;
    obj.f(5);
    obj.g();
    obj.h();
   

    // using B::f; ILLEGAL: should not use it in global scope; should be class scope 
}


//namespace bw {
//
//	const std::string prefix = "{bw::string} ";
//
//	class string {
//		//private members
//		std::string _s = ""; 
//		string();
//	public:
//		string(const std::string& s) : _s(prefix + s) {}
//		const char* c_str() const { return _s.c_str(); }
//		operator std::string& () { return _s; }
//		operator const char* () const { return _s.c_str(); }
//
//	};
//};
//
//int main() {
//	const std::string s1("This is a string");
//	std::puts(s1.c_str());
//	int a = sizeof(s1.c_str());
//	printf("%d", a);
//
//	const bw::string s2(s1);
//	std::puts(s2);
//	int b = sizeof(s2);
//	printf("%d", b);
//
//	return 0;
//}