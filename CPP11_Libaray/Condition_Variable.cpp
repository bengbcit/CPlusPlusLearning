#include <deque>
#include <functional>
#include <iostream>
#include <fstream>
#include <thread>
#include <string>
#include <mutex>
using namespace std;
/* condition variable 
*		- is to synchronize the excution order of flags
*/
/*Synchornize Issue: using mutex alone cant solve it*/
deque<int> q;	// global var: deque of integer
mutex mu;
condition_variable cond;

void function_1() {
	int count = 10;
	while (count > 0) {
		unique_lock<mutex> locker(mu);	// good to lock mutex bcuz queue q is shared memory with thread 1 and 2		
										// choose unique lock bcuz we use it many times( ie wake up and sleep)
		q.push_front(count);			// insert new element at beginning
		locker.unlock();
		cond.notify_one();				// Wake up one thread, if any that is waiting 
		//cond.notify_all()				// wake up for all threads
		this_thread::sleep_for(chrono::seconds(1));
		count--;
	}
}

void function_2() {
	int data = 0;
	while (data != 1) {
		unique_lock<mutex> locker(mu);
		if (!q.empty()) {		// pops a data if not empty
			data = q.back();	// return direct reference to the last element in the container.
			q.pop_back();		// remove last element
			locker.unlock();
			cout << "t2 got a value from t1: " << data << endl;
		}
		/******Bad Design for check next loop***************/
		/*
		else {					
			locker.unlock();	// go to next loop
		}
		this_thread::sleep_for(chrono::milliseconds(10));	// to avoid busy waiting (no efficient)
		*/

		/******Good Design for check next loop***************/
		//cond.wait(locker);	// put thread 2 to sleep until notified by thread 1
		cond.wait(locker, []() { return !q.empty();});	 // spurious wake ( ie wake up by thread2 itself)
														 // if empty, go back sleep; if not empty, codes continue runs ,eg pop back the data
	}
}
// It is hard to set the sleep time.
int main() {
	thread t1(function_1);
	thread t2(function_2);
	t1.join();
	t2.join();
	return 0;
}