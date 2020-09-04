#include<mutex>			// mutex
#include<thread>		// thread
#include<fstream>		// ofstream
#include<iostream>		// cout
using namespace std;


/* unique_lock: 
*	- more flexible way to implement a finer-grained lock
	- wrapper class of mutex(lock guard, unique lock etc) cant copy
*	Advantage
*		1. construct the locker without locking the mutex
*		2. unique lock can be moved
*	Disadv
*		1. heavy weighted than lock guard
*/

/* Deferred Lock */
class LogFile_0 {
	std::mutex m_mutex;
	ofstream f;
public:
	LogFile_0() {
		f.open("log.txt");
	}
	void shared_print(string id, int value) {
		//std::lock_guard<mutex> locker(m_mutex, std::adopt_lock);
		unique_lock<mutex> locker(m_mutex, defer_lock); // with unique lock, only below print synchornized with mutex
		// do something here before lock
		locker.lock();  // Now the mutex is locked
		f << "From " << id << ": " << value << endl; 											 
		locker.unlock();
		// do something angain, and then lock( you can lock mutiple times)
		locker.lock();

		unique_lock<mutex> locker_2 = move(locker);
	}
};

/* Lazy Initialization */
class LogFile_Lazy_Initialization {
	mutex mu_mutex;	// mutex for print
	mutex mu_open;	// mutex for open file once
	once_flag mu_flag;
	ofstream f;
public:
	void shared_print(string id, int value) {
		/******now thread safe, but it repeats using mutex****************/
		/*
		{	
			unique_lock<mutex> locker(mu_open);			// put here better, it can protect both operation with same mutex 
			if (!f.is_open()) {							// file only open once, lazy initialization
				// unique_lock<mutex> locker(mu_open);	// before thread can open lock file, it has to lock mutex
				f.open("log.txt");						// This must be synchronized
			}
		}
		*/
		/****A Better Way to do: file opened only once by the thread******/
		call_once(mu_flag, [&/*lambda funtion*/]() {f.open("log.txt");});
		unique_lock<mutex> locker(mu_mutex, defer_lock);
		f << "From " << id << ": " << value << endl;  // I don't care this is not synchronized
	}
};

/* unique_lock for transferring mutex ownership */
class LogFile {
	std::mutex m_mutex;
	ofstream f;
public:
	LogFile() {
		f.open("log.txt");
	}
	unique_lock<mutex> giveMeLock() {
		return unique_lock<mutex>(m_mutex);  // Moved
	}
	void shared_print(string id, int value) {
		std::unique_lock<mutex> locker(m_mutex);
		f << "From " << id << ": " << value << endl;
	}
};

int main() {
	LogFile log;
	unique_lock<mutex> locker = log.giveMeLock();
	// I don't want to shared_print anything, but I don't want anybody else to do that either untill I am done.

	// I can also release the lock before locker is destroyed
	locker.unlock();  // lock_guard can't unlock

	//...
	// allow other thread to use log

	locker.lock();  // lock again. -- finer grained lock alows more resource sharing 

	return 0;
}
