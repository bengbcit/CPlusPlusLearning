#include <iostream>
#include <vector>
using namespace std;

// const with functions
class Dog{
	int age;
	string name;
public:
	Dog() { age = 3;name = "Dummy"; }
	// const parameters
	void setAge(int& a) { age = a; a++; }		// overload the next line; you can modify 'a', it becomes inc by 1;
	void setAge(const int& a) { age = a; }		// you cant modify 'a' cuz const

	// const return value
	const string& getName() { return name; }	// returning by reference to improve the efficiency of program
	
	// const function: fn will not change any variables of the class
	/*invoke this function when Dog() is const*/
	void printDogName() const { cout << name <<" const" << endl; /*age++; wont work here cuz it changes variable*/ }
	
	//const can be overload with non-const function
	/*invoke this function when Dog() is NOT const*/
	void printDogName() { cout << getName() <<" non - const" << endl; }
};

/*Bitwise constness: doesnt change any member of class
  Logic   constness: it can be changed in the const fn */
class BigArray {
	vector<int> v;				// huge vector 
	mutable int accessCounter;  // Logic const
	int* v2;					// another int array

public:
	int getItem(int index) const {
		accessCounter++;
		//without mutable int, we can write: const_cast<BigArray*>(this)->accessCounter++;
		return v[index];
	}

	// if put const there, will be bitwise constness:doesnt change any member, so still works as const fn
	// if not put const, it will be non- const fn
	void setv2item(int index, int x)/*const */ {
		*(v2 + index) = x; // set v2 @ position index to be x
	}

	// quiz:
	//const int* const fun(const int* const& p)const;
};

int main() {
	Dog d;
	const Dog d2;

	int i = 9;
	d.setAge(i);
	cout << i << endl;

	const string& n = d.getName(); // call by ref;prevent caller modifying the code
	cout << n << endl;

	d.printDogName();
	d2.printDogName();

}

