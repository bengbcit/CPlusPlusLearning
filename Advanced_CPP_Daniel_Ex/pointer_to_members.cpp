/*  C++ pointer to members: allow you to refer to nonstatic member of class objects
*   Since static member's address is not associated with any particular object, you can't use a pt to static member.
*   To point to a static class member, have to use normal pt
*/
#include <iostream>
#include <string>
using namespace std;

class X {
public:
    int a;
    void f(int b) {
        cout << "The value of b is " << b << endl;
    }
};

// way 1: same as pointer to fn; compare pt to member fn, assign value to them then use them to call member fn.
void pt_to_mem_fn() {
    cout << "*********Way 1*********\n";
    int X::* ptiptr = &X::a;            // declare pointer to data member
    void (X:: * ptfptr) (int) = &X::f;  // declare a pointer to member function
    X xobject;                          // create an object of class type X
    xobject.*ptiptr = 10;               // initialize data member
    cout << "The value of a is " << xobject.*ptiptr << endl;
    (xobject.*ptfptr) (20);             // call member function
}

// way 2: reduce complex syntax, declare a typedef to be a pt to a member; ez way
typedef int X::* my_pt_to_member;
typedef void (X::* my_pt_to_fn) (int);

int main() {
    // way 1: pointer to members declaration 
    pt_to_mem_fn();

    // way 2: typedef 
    cout << "*********Way 2*********\n";
    my_pt_to_member ptiptr = &X::a;
    my_pt_to_fn ptfptr = &X::f;
    X xobject;
    xobject.*ptiptr = 10;
    cout << "The value of a is " << xobject.*ptiptr << endl;
    (xobject.*ptfptr) (20);

    return 0;
}