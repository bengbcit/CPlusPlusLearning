/**********************************Containers***************************************/
/*	sequence containers (array and linked list)
*		-vector, deque, list, forward list, array
*/

/*	Associative containers (binary tree)
*		-set, multiset, map, multimap 
*/

/*	Unordered containers (hash table)
*		-unordered set, unordered multiset, unordered map, unordered multimap
*/

#include <iostream>
using namespace std;

/*		STL Headers		*/
#include <vector>
#include <deque>
#include <list>
#include <set>				// set and multiset
#include <map>				// map and multimap
#include <unordered_set>	// unordered set/multiset
#include <unordered_map>	// unordered map/multimap
#include <iterator>
#include <algorithm>
#include <numeric>			// some numeric algorithm
#include <functional>

/*
 * Vector
 */
void container_vector() {

	vector<int> vec;   // thru default constructor vec; vec.size() == 0
	vec.push_back(4);
	vec.push_back(1);
	vec.push_back(8);  // vec: {4, 1, 8};    vec.size() == 3

	// Vector specific operations:
	cout << vec[2]<<endl;     // o/p: 8  (no range check)
	cout << vec.at(2) << endl;  // o/p: 8  (throw range_error exception of out of range)

	// use vector like an array
	for (int i = 0; i < vec.size(); i++) 
		cout << vec[i] << " ";

	// recommend use iterator (universal way) to traverse a container
	for (vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr)
		cout << *itr << " ";

	// for (it : vec) /* C++ 11 */ { cout << it << " "; } not works

	// Vector is a dynamically allocated contiguous array in memory
	int* p = &vec[0];   p[2] = 6;
	cout << p;
}

int main() {
	container_vector();
}
