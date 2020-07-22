#include <iostream>
#include <vector>

using namespace std;

// vector void fn
void vector_simple(vector<int> numbers) {
	for (int i = 1; i <= 10; i++) {
		numbers.push_back(i);
		cout << numbers[i - 1] << endl;
	}
}

// vector void fn: pass by reference
void vector_simple_byRef(vector<int>& numbers_ref) {
	for (int i = 1; i <= 10; i++) {
		numbers_ref.push_back(i);
		cout << numbers_ref[i - 1] << endl;
	}
}

// print simple vectors
void print_someVector() {
	cout << "*******Print Vector************" << endl;
	// Initializing size of vector
	vector<double> v(4);
	v[0] = 1.14;
	v[1] = 2.1415;
	v[2] = 3.141592;
	v.push_back(4.14159265);

	// Initializing vector with values 
	vector<int> v2{ 1, 2, 3, 4 };
	
	cout << "from v1: " << v.front() <<"; from v2: "<< v2.front() << endl;
	cout << "from v1: " << v.back() << "; from v2: " << v2.back() << endl;
	cout << "from v1: " << v.at(2) << "; from v2: " << v2.at(2) << endl<<endl;

	// vector<int> v(size, value);
	vector<int> v3(3, 7);
	for (int i = 0; i < v3.size(); i++) {
		cout << v3[i] << endl;
	}
}

int main() {
	// initialization
	vector<int> vector_s;

	// EG1: without pass by reference, by end of return 0, 'vector_s' is still empty vector.
	vector_simple(vector_s);
	cout  << "vector size is " << vector_s.size() << endl<<endl ;

	// EG2: pass by ref, 'vector_s' will be 1 to 10
	vector_simple_byRef(vector_s);
	cout  << "vector size is " << vector_s.size() << endl << endl;

	// EG3: print some vectors
	print_someVector();
	cout << "*******Print Vector************" << endl<<endl;

	// EG4: Define vector of vectors: similar 2d array
	vector< vector<int> >v;
	//	fill the inner vector, then insert it into the outer vector
	for (int i = 0; i < 5; i++) { // row
		vector<int>temp;
		for (int j = 0; j <9; j++) {// column
			temp.push_back(i);
		}
		v.push_back(temp);
	}

	//	display all element to the user
	for (int i = 0; i < v.size();i++) {
		cout << "|";
		for (int j = 0; j < v[i].size();j++) {
			cout << v[i][j] << "|";
		}
		cout << endl;
	}

	return 0;
}
