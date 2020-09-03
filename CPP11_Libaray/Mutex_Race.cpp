#include<iostream>
#include<thread>
#include<string>
#include<mutex>

using namespace std;
mutex mu;

void shared_print(string msg, int id){
	lock_guard<mutex> guard(mutex);	// RAII, if flats exception, will be unlocked
	//mu.lock();					// without it will not print msg
	cout << msg << id << endl;		// synchorinized with mutex mu
									// AWARE: if cout here floats exception, mutex will continue being locked
									// AWARE: since cout is global var, other might still access cout which cuz race condition
	//mu.unlock();	

}
/** Race Condition:
*	- outcome of program depends on the relateive execution order 1 or more threads
*	- EG:
*		1 below both fn1 and main use cout, but race condition will print same time, so will mess up print out 
*		2 try to avoid it: eg using mutex to synchronize the access of common resource	
*/

void function_1() {
	for (int i = 0; i < 10;++i) {
		//cout << "from t1: " << i << endl;
		shared_print(string("from t1: "), i);
	}
}

int main() {

	std::thread t1(function_1);

	for (int i = 0; i < 10;++i) {
		//cout << "from main: " << i << endl;
		shared_print(string("from main: "), i);
	}

	t1.join();

	
	return 0;
}
