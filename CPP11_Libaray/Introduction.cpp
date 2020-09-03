#include<iostream>
#include<thread>
using namespace std;
/***************************** Concurrent C++ **********************************/
/** Multiprocessing: 
*	process 1(single thread) <--interprocess communication--> process 2(single thread)
*		- interprocess communication: files, pipes, message queue	
*	
*	Advantage:
*		- easy distributed to multiple computer
*	Disadvantage: 
*		- slow to start 
*		- more overhead ( a process has lots protection so it not accidently step on other process)
*/

/** Multithread: 
*	process 1 (thread 1 <--shared memory--> thread 2)
*
*	Advantage: 
*		- fast to start
*		- lower overhead
*		- communicate memory a lot faster than communicate channels
*	Disadvantage:
*		- difficult to implement
*		- cant't run on distributed system
*/

// First example:
void thread1() {
	cout << "Helldo, Worlds" << endl;
}

class Functor_ {//pass by ref
public:
	void operator ()( string& msg) {
		/*for (int i = 0; i < 10;++i) {
			cout << "from t1: " << i << endl;
		}*/
		cout << "t2 says: " << msg << endl;
		msg = "show this msg!";
	}
};

class Functor_PassbyValue {	// not sure why && works 
public:
	void operator ()(string&& msg) {
		
		cout << "t2 says: " << msg << endl;
		msg = "show this msg!";
	}
};

int main() {
	// EG1: thread with function 
	thread t1(thread1);	// t1 starts runnign

	// t1 will be join with or without exception
	try {
		for (int i = 0; i < 10;++i) {
			cout << "from main: " << i << endl;
		}
	}catch (...) {	// catch any exception
		t1.join();
		throw;		// rethrow it 
	}
	t1.join();			// main thread waits for t1 to finish
	cout << "FINISH example 1: thread with function. \n\n";
	//t1.detach();		// main thread let t1 to run on its own -- daemon process.
						// C++ runtime library is responsible returning t1's resources
						// and main thread(run fast) may finish before t2 prints "Hello"
	/**************************Note 1 ********************************************
	* 1. If neither detach nor join is called, terminate() will be called for the t1.
	* 2. A thread can only be joined once or detached once. After it is joined on detached, 
	*	 it becomes unjoinable ( t.joinable() returns false )
	****************************************************************************/
	
	// EG2: thread with functor
	string s = "A string!";
	// thread fct;				save a declaration functor step 
	thread t2((Functor_()),ref(s));	// CARE! need extra (Functor_()) bcuz tells compiler it's functor, not function with no passing variables
									// thread is pass by value, without using ref(s), the changing msg wont show

	//try {
	//	/*for (int i = 0; i < 10;++i) {
	//		cout << "from main: " << i << endl;
	//	}*/
	//	cout << "from main: " << s << endl;

	//}
	//catch (...) {	// catch any exception
	//	t2.join();
	//	throw;		// rethrow it 
	//}

	t2.join();			// main thread waits for t1 to finish
	cout << "from main: " << s << endl;
	cout << "FINISH example 2: thread with function. \n\n";

	// EG3: thread with functor and move
	s = "A string 3";
	cout << this_thread::get_id() << endl;	// parents thread id

	thread t3((Functor_PassbyValue()),move(s));
	cout << t3.get_id() << endl;			// child thread id
	// thread t4 = t3;						// wrong here! c++ fns, some can only be moved but not copied 
	thread t4 = move(t3);

	return 0;
}

