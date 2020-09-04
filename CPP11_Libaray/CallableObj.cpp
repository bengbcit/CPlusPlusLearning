#include<future>
#include<iostream>
#include<thread>
using namespace std;
/* async() are used in the same ways as thread(), bind() */
class A {
public:
	string note;
	void f(int x, char c) { }
	long g(double x) { note = "changed"; return 0; }
	int operator()(int N) { return 0; }
};

void foo(int x){}	// for t5

int main() {
	A a;
	// two way use child thread
	thread t1(a, 6);			// copy_of_a() functor in a different thread
	thread t2(ref(a), 6);		// use same a, create a diff thread
	thread t2(move(a), 6);		// move current thread to child thread

	thread t3(A(), 6);			// temp A moved into a thread obj;
	thread t4([](int x) {return x * x;}, 6); // takes lambda fn move into thread
	thread t5(foo, 6);						 // fn into thread
	thread t6(&A::f, a, 56, 'z');			 // member fn into thread; copy_of_a.f(56,'z')
	thread t7(&A::f, &a, 56, 'z');			 // a.f(56, 'z')										 

	return 0;
}
/*	similarly 

	std::thread t1(a, 6);   
	std::async(a, 6);   
    std::bind(a, 6);
    std::call_once(once_flag, a, 6);
	
	a.note = "Original";
	std::future<int> fu3 = std::async(A(), 4);    // A tmpA;  tmpA is moved to async(); create a task/thread with tmpA(4);
	std::future<int> fu4 = std::async(a, 7);
	std::future<int> fu4 = std::async(std::ref(a), 7); // a(7);  Must use reference wrapper
	std::future<int> fu5 = std::async(&a, 7); // Won't compile

	std::future<void> fu1 = std::async(&A::f, a, 56, 'z'); // A copy of a invokes f(56, 'z')
	std::future<long> fu2 = std::async(&A::g, &a, 5.6);    // a.g(5.6);  a is passed by reference
		// note: the parameter of the invocable are always passed by value, but the invokeable itself can be passed by ref.
	cout << a.note << endl;
*/