#include <iostream>
using namespace std;

class StankFist {
	public:
		StankFist() {
			stinkyVar = 0;
		}
	private:
		int stinkyVar;
	//friend fn can use everything in this class
	friend void stinkysFriend(StankFist& sfo);
};

// & means reference to the type, this case is ref to class StankFist
void stinkysFriend(StankFist& sfo) {
	//bcuz friend fn, so that we can access variables inside that class
	sfo.stinkyVar = 99;
	cout << sfo.stinkyVar << endl;
}

int main() {
	StankFist Dan;
	stinkysFriend(Dan);
}
