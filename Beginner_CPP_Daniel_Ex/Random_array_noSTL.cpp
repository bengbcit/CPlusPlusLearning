#include <iostream>
#include<string>
#include<ctime>		// time
#include<cstdlib>


using namespace std;

int main() {
	const int arry_size = 5;
	srand(time(NULL));	// initial time seed,use null or 0

	string NameGen[arry_size] = { "Daniel","Aoi","Kaito","Ai-chan","Yaka" };

	for (int i = 0; i < arry_size;i++) {
		int iname = rand() % arry_size;
		
		// swap value in our original array
		string temp = NameGen[i];
		NameGen[i] = NameGen[iname];
		NameGen[iname] = temp;
		
	}
	for (int i = 0; i < arry_size;i++) {
		cout << NameGen[i] << endl;
	}
	return 0;

}