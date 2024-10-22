#include <iostream>
using namespace std;

class OpenFile_disallow {
	/*for c++3, under fns will be disallow in private */
	OpenFile_disallow(OpenFile_disallow& rhs);						// disallow copy constructor
	//OpenFile_disallow(OpenFile_disallow& rhs) = delete;			// c++11: disallow copy constructor 
	OpenFile_disallow& operator= (const OpenFile_disallow& rhs);	// disallow copy assignment operator
	void writeLine(string str);										// disallow writeLine fn
	/*	~OpenFile_disallow() destructor in private not always a good idea to put here 
		that no destructor will be called might casues leaking resources*/
public:
	OpenFile_disallow(string filename) { cout << "Open a file: " << filename << endl; }
	string g(OpenFile_disallow& f) { OpenFile_disallow f2(f); }	// these way can access copy constructor f2
};

// Widely Use: reference counting shared pointers- counts # pointers that points to itself;stop until count to 0
class OpenFile {// cannot destroyed by others except itself and its relate FNs.
public:
	OpenFile( string filename) { cout << "Open a file: " << filename << endl; }
	void destroyMe(){delete this;}   // create a public interface to allow user to destroy this object
	
private:
	/*	Good thing to create private destructor��
		1. Let your object on memory forever, dont allow other users delete it
		2. Not allow create object on stack, cuz destructor out of scope as long as you create obj.
		3. Must create object on heap at main fn ie: OpenFile* f = new OpenFile(); 
	*/
	~OpenFile() { cout << "OpenFile object Destructed" << endl; }
};

int main() {
	OpenFile_disallow f1(string("The Files"));
	/*If make a copy constructor will be messy for running time; so, disallow copy constructor.*/
	//OpenFile f2(f);

	//	destructor will fail if OpenFile f is private; but if you create on heap you can use destructor in private
	//	create obj on heap with NEW:dynamic memory(need a pointer) 
	OpenFile* f2 = new OpenFile(string("The Files"));    
	f2->destroyMe();
}
/*	Summary of Disallowing FN:
		1. c++ 11: f()= delete;
		2. C++ 3��Declare the fn to be private, and not define it.
		3. Private destrcutor: stay out of stack
*/