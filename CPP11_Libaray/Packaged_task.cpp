#include<deque>
#include<mutex>
#include<future>
#include<iostream>
#include<thread>

using namespace std;
/*	packaged_task: tasks can be transported to diff places
*	Advantage: can link a callable obj to future whichs important for thread
*/

std::mutex mu;
std::deque<std::packaged_task<int()> > task_q;
std::condition_variable cond;

int factorial(int N) {
	int res = 1;
	for (int i = N; i > 1; i--)
		res *= i;

	return res;
}

void thread_1() {// thread 1
	for (int i = 0; i < 10000; i++) {
		std::packaged_task<int()> t;
		{	// lock mutex before access queue q 
			std::unique_lock<std::mutex> locker(mu);
			//if (task_q.empty())			   // make sure front fn call after pushback fn
			//	continue;
			/*Better way*/
			cond.wait(locker, []() {return !task_q.empty();});
			t = std::move(task_q.front()); // thread safe: front and pop front should in same locker
			task_q.pop_front();			   // pop off task after using
		}
		t();	// then call t() excution
	}
}

int main() { // main thread
	std::thread th(thread_1);

	std::packaged_task<int()> t(bind(factorial, 6)); // have to bind() factorial fn to create fn obj and then pass it
	//int x = t.get_future().get(); // return value from factorial fn
	std::future<int> ret = t.get_future();			 // use task t to create a future for return value from factorial

	{// lock mutex before access queue q 
		std::lock_guard<std::mutex> locker(mu);
		task_q.push_back(std::move(t));			// move t which it no longer be used in main thread, to task q
	}
	cond.notify_one();
	cout << "I see: " << ret.get() << endl;		// use .get() return value
	

	th.join();	// before exit
	return 0;
}
