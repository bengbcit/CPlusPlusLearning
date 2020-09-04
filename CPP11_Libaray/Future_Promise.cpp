#include<future>
#include<iostream>
#include<thread>

using namespace std;
/* Summary
 * 3 ways to get a future:
 * - promise::get_future()
 * - packaged_task::get_future()
 * - async() returns a future
 */

/*these two global var only for factorial-old case*/
mutex mu;					// protect x from thread factorial_old and main thread
condition_variable cond;	// need condition variable: wanna factorial_old thread set value first , then main thread get value
/*factorial_better_way-old case dont need global var*/

void factorial_old(int N,int& ref_x) {/*old*/
	int res = 1;
	for (int i = N; i > 1; i--)
		res *= i;

	cout << "Resut is: " << res << endl;
	ref_x = res;
}

int factorial_better_way(int N) {/* For threads to return values: future */
	int res = 1;
	for (int i = N; i > 1; i--)
		res *= i;

	return res;
}

int factorial_promise(future<int>& f) {/* Asynchronously provide data with promise */
	// do something else
	int N = f.get();     // If promise is distroyed, exception: future_errc::broken_promise
	cout << "Got from parent: " << N << endl;
	int res = 1;
	for (int i = N; i > 1; i--)
		res *= i;

	return res;
}

int factorial_Shared_future(shared_future<int> f) {/* shared_future */
	// do something else
	int N = f.get();     // If promise is distroyed, exception: std::future_errc::broken_promise
	f.get();
	cout << "Got from parent: " << N << endl;
	int res = 1;
	for (int i = N; i > 1; i--)
		res *= i;

	return res;
}

int main() {
	/*EG1: old*/
	int x;
	thread t1(factorial_old, 4, ref(x));
	t1.join();
	cout << "**********Example 1 finish here! **********" << endl << endl;

	/*EG2: For threads to return values: future */
	/*async: 
	*	- this fn return future will get result from child ie factorial_better_way
	* Syntax: 
	*	1. future<int> fu = async(factorial, 4) is exactly same as
	*	   future<int> fu = async(launch::deferred | launch::async, factorial, 4) default values;
	*	2. launch::deferred: async fn not creat a thread, defer the excution of the fn until later on fu.get()
	*	3. launch::async: async creat another thread
	*/
	future<int> fu = async(launch::deferred | launch::async, factorial_better_way, 4);
	cout << "Got from child thread #: " << fu.get()/*wait until child thread finish*/ << endl;
	// fu.get();  // will crash bcuz .get() should only call once
	cout << "**********Example 2 finish here! **********" << endl << endl;

	/*EG3: Asynchronously provide data with promise */
	// eg: i promise my child thread, I will send a value from main thread in the future
	promise<int> p;
	//promise<int> p2 = move(p);
	future<int> f = p.get_future();
	future<int> fu2 = std::async(std::launch::async, factorial_promise, std::ref(f)); // pass future to the thread factorial_promise
	p.set_value(5);   
	//p.set_value(28);  // It can only be set once
	//p.set_exception(std::make_exception_ptr(std::runtime_error("Sry but cant keep this promise")));  // set up exception if you know you will definitely break the promise
	cout << "Got from child thread #: " << fu2.get() << endl;
	cout << "**********Example 3 finish here! **********" << endl << endl;

	/*EG4:shared_future: avoiding making duplicate promise 1 - 10 */
	// Both promise and future cannot be copied, they can only be moved.
	promise<int> p2;
	future<int> f2 = p2.get_future();
	shared_future<int> sf = f2.share();

	future<int> fu_1 = std::async(std::launch::async, factorial_Shared_future, sf);
	future<int> fu_2 = std::async(std::launch::async, factorial_Shared_future, sf);
	// ....100 threads

	p2.set_value(5);

	cout << "Got from child thread #: " << fu_1.get() << endl;
	cout << "Got from child thread #: " << fu_2.get() << endl;
	cout << "**********Example 4 finish here! **********" << endl << endl;
	return 0;
}