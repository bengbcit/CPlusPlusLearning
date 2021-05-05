#include <iostream>
/* Better Coding: List the FNs you wanna use from std library than simply add using namespace std*/
using std::cout;
using std::endl;
using std::string;

//using namespace std;	not recommendded 

namespace namespace1 {
	int age = 33;
	string name = "Daniel";
}

namespace namespace2 {
	int age = 10;
	string name = "Jack";
}

int main() {
	cout << namespace1::age << endl;
	cout << namespace2::name << endl;

	return 0;
}
