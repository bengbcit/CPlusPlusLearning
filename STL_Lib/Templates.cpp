/*	Introduction to Template: may cuz code bloat if template fn on a lot of diff data types
*	USE WHEN:
*		1. avoid duplicate situation eg, create int , float , long similar fns
*		2. 
*		3.
*/
#include <iostream>
using namespace std;

// fn template
template <typename T>
T square(T x) { 
	return x * x;
}

// class template
template<typename T>
class BoVector {
	T arr[1000];
	int size;
public:
	BoVector():size(0) {}						// default ctor initialize private member size to 0
	void push(T x) { arr[size] = x; size++; }
	T get(int i) const { return arr[i]; }
	int getSize() const { return size; }		// retrun current size
	//void print() const {for(int i=0; i<size; i++) {cout << arr[i] << endl;}}
	void print() const {
		const int* p = arr;
		for (int i = 0; i < size; i++) { cout << *(p++) << endl; }
	}
};

// vector template: define operator multiply
template<typename T>
BoVector<T> operator*(const BoVector<T>& rhs1, BoVector<T>& rhs2) {
	BoVector<T> ret;							// declare a new vector for multiple result
	for (int i = 0; i < rhs1.getSize(); i++) {
		ret.push(rhs1.get(i) * rhs2.get(i));	// make a new (ie mutiple) vector  
	}
	return ret;
}

int main(){
	//cout << square<int>(5) << endl;
	//
	//cout << square<double>(5.5) << endl;	// template dont have to specifically the data type
	//cout << square(5.5) << endl;			// same result as above eg

	BoVector<int> bv;
	bv.push(2);
	bv.push(5);
	bv.push(8);
	bv.push(9);
	//bv.print();
	
	cout << "Print squared bv: " << endl;
	bv = square(bv);						// pass template obj. to template fn 
	bv.print();
}
