#include<iostream>		// std::cout
using namespace std;
#include<vector>
#include<set>
#include<algorithm>     // for sort, for_each
#include<functional>    // for bind
#include<deque>

/*  Function Objects (functors)
 *  Benefits:   1. Smart function: capabilities beyond operator() It can remember state.
                2. It can have its own type.
 *  Lists: less, greater, greater_equal,logical_and... muitiplies,modulus,negate
 */
class X {
public:
    // functor
    void operator()(string str) {cout << "Calling functor X with parameter " << str << endl;}

    // type conversion function
    operator string() const { return "x"; }
};

// parameterized function
class Y {
public:
    Y(int i) {}
    // functor
    void operator()(string str) { cout << "Calling functor X with parameter " << str <<endl; }
 
};

/*      Why functor not just pass multiple variables    */
// way 1: nasty way
int val = 2;    // define a global var 
void add2(int i) {
    cout << i + val << endl;
}
// way 2: use template
template<int val>    // have to be compile time constant, so addVal<x> wont compile
void addVal(int i) {
    cout << val + i << endl;
}
// way 3:use a functor, most flexible solution
class AddValue {// a functor
    int val;
public:
    AddValue(int j) : val(j) { } 
    void operator()(int i) {
        cout << i + val << endl;
    }
};
// way 4:use bind fn
void addVal_2(int i, int val) {
    cout << i + val << endl;
}

/*      Parameter Binding       */
void para_bingding(){
    // Build-in Functors egs
    int x = multiplies<int>()(3, 4);  //  x = 3 * 4 
    if (not_equal_to<int>()(x, 10))   // if (x != 10)
        cout << x << endl;

    set<int> myset = { 2, 3, 4, 5 };
    vector<int> vec;

    // transform takes only 1 parameter but multiply take 2!!!
    // solution: use bind, Multiply myset's elements by 10 and save in vec:
    transform(myset.begin(), myset.end(),   // source
        back_inserter(vec),                 // destination
        bind(multiplies<int>(), placeholders::_1, 10));  // combine 2 parameter into 1 para
// First parameter of multiplies<int>() is substituted with myset's element
// vec: {20, 30, 40, 50}
}

/*      Convert a regular function to a functor       */
double Pow(double x, double y) {
    return pow(x, y);
}
void reg_to_func() {
    set<int> myset = { 3, 1, 25, 7, 12 };
    deque<int> d;
    auto f = function<double(double, double)>(Pow);   //C++ 11
    transform(myset.begin(), myset.end(),       // source
        back_inserter(d),                       // destination
        bind(f, placeholders::_1, 2));          // functor
    //  d: {1, 9, 49, 144, 625}
}

int main()
{
    X foo;
    foo("Hi");    // Calling functor X with parameter Hi

    Y(8) ("Hi") ; // parameterised with 8 and invoked with a regular para of "hi"

    vector<int> vec = { 2, 3, 4, 5 };
    // way 1
    for_each(vec.begin(), vec.end(), add2); // {4, 5, 6, 7}
    // way 2
    for_each(vec.begin(), vec.end(), addVal<2>); // {4, 5, 6, 7}
    // way 3
    int x = 2;
    for_each(vec.begin(), vec.end(), AddValue(x)); // {4, 5, 6, 7}
    // way 4
    for_each(vec.begin(), vec.end(), bind(addVal_2, placeholders::_1, 2));

    para_bingding();
    reg_to_func();
}


