#include<mutex>			// mutex
#include<thread>		// thread
#include<fstream>		// ofstream
#include<iostream>		// cout
using namespace std;

/* Deadlock: system hanging somewhere and waiting
*	- t1 wait main thread release mu2 and main thread wait t1 release mu;
*	How to Avoid it?
*		1. Prefer locking single mutex.
*		2. Avoid locking a mutex and then calling a user provided function.
*		3. Use std::lock() to lock more than one mutex.
*		4. Lock the mutex in same order.
*	Locking Granularity ¼ä¸ô³ß´ç:
*		- Fine-grained lock:  protects small amount of data
*		- Coarse-grained lock: protects big amount of data
*/

/* System Hanging and waiting eg
class LogFile {
	std::mutex _mu;
	std::mutex _mu_2;
	ofstream f;
public:
	LogFile() {
		f.open("log.txt");
	}
	void shared_print(string id, int value) {
		std::lock_guard<mutex> locker(_mu);
		std::lock_guard<mutex> locker1(_mu_2);
		cout << "From " << id << ": " << value << endl;
	}
	void shared_print_2(string id, int value) {
		std::lock_guard<mutex> locker1(_mu_2);
		std::lock_guard<mutex> locker(_mu);
		cout << "From " << id << ": " << value << endl;
	}
};
*/

// Solution: lock the mutexes in a fixed order
/* C++ 11 std::lock */
class LogFile {
	std::mutex m_mutex;
	std::mutex m_mutex_2;
	ofstream f;
public:
	LogFile() {
		f.open("log.txt");
	}
	void shared_print(string id, int value) {
		std::lock(m_mutex, m_mutex_2);
		std::lock_guard<mutex> locker(m_mutex, std::adopt_lock);
		std::lock_guard<mutex> locker1(m_mutex_2, std::adopt_lock);
		cout << "From " << id << ": " << value << endl;
	}
	void shared_print_2(string id, int value) {
		std::lock(m_mutex, m_mutex_2);
		std::lock_guard<mutex> locker1(m_mutex_2, std::adopt_lock);
		std::lock_guard<mutex> locker(m_mutex, std::adopt_lock);
		cout << "From " << id << ": " << value << endl;
	}
};

void function_1(LogFile& log) {
	for (int i = 0; i < 10;++i) {
		log.shared_print(string("from t1: "), i);
	}
}
int main() {
	LogFile log;
	thread t1(function_1, ref(log));
	for (int i = 0; i < 10;++i) {
		log.shared_print_2(string("from main: "), i);
	}
	t1.join();
	return 0;
}