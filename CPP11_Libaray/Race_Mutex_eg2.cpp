#include<iostream>
#include<fstream>	// high lvl file stream input/output operation
#include<thread>
#include<string>
#include<mutex>

using namespace std;

class LogFile {
	mutex m_mutex;	// protected by mutex
	ofstream f;
public:
	LogFile() {
		f.open("log.txt");
	} // Need destructor to close file
	void shared_print(string id, int value) {
		lock_guard<mutex> locker(m_mutex);	// use lock guard to protect access of f not float exceptions
		cout << "From " << id <<			// order of lines may vary, but cout printouts are never mixed
			": " << value << endl;
	}
	/* Never leak f to outside world, like this:
	1. ofstream& getStream() { return f; }   ---> user can access it without going thru mutex
	2. void processf(void fun(ofstream&)) {  ---> user provide fn, which user has authority to change everything to resource eg, can close F, skip mutex...
		fun(f);
	}
	*/
};

void function_1(LogFile& log) {
	for (int i = 0; i < 10;++i) {
		log.shared_print(string("from t1: "), i);
	}
}
int main() {
	LogFile log;
	thread t1(function_1,ref(log));
	for (int i = 0; i < 10;++i) {
		log.shared_print(string("from main: "), i);
	}
	t1.join();
	return 0;
}
