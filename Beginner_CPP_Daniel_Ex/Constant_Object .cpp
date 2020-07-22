#include <iostream>
using namespace std;

/****************Declare constructor contains private members in diff. ways **********************/
//Way 1: with specical way to initialize it
class Sally{
public:
	Sally(int a, int b);
	void printMemberInitialst();
	/*	void printShz();
		void printShz2() const;*/
private:
	int regVar;
	const int constVar;
};
// define constructor outside with members in initializer list
Sally::Sally(int a, int b)
	:regVar(a), constVar(b){}

void Sally::printMemberInitialst() {
	cout << "Regular Var is " << regVar << " and Const Var is " << constVar << endl;
}
//void Sally::printShz() {
//	cout << "I am a regular fn" << endl;
//}
//
//void Sally::printShz2() const{
//	cout << "I am the const fn" << endl;
//}

// Way 2: pass private members in public fn
class Sally_2 {
public:
	Sally_2(){ regVar = 0; constVar = 0; }
	void getPrivate(int a, const int& b) {
		regVar = a;
		constVar = b;
	};
	void printMemberInitialst();
private:
	int regVar;
	int constVar;
};

void Sally_2::printMemberInitialst() {
	cout << "Regular Var is " << regVar << " and Const Var is " << constVar << endl;
}

int main() {
	Sally Sobj(1, 1);
	Sobj.printMemberInitialst();

	// cant use same name obj
	Sally_2 Sobj_;
	Sobj_.getPrivate(2, 2);
	Sobj_.printMemberInitialst();
	




		//Sally salObj;
		//salObj.printShz();

		//// variables can not be modified or changed
		//const Sally constObj;
		//constObj.printShz2();
};