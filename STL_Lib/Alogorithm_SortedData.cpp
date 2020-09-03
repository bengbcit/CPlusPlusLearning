#include<iostream>		// std::cout
#include <vector>
#include<algorithm>	
#include<map>
#include<set>
using namespace std;

/*	Sorted Data Algorithms
 *   - Algorithms that require data being pre-sorted
 *   - Binary search, merge, set operations
 */

void print_Iterator(vector<int> vec) {
	for (vector<int>::iterator itr = vec.begin();itr != vec.end();++itr)
		cout << *itr << ' ';
	cout << endl;
}

void Binary_Search() {
	vector<int> vec = { 8,9,9,9,45,87,90 };
	// Search Elements
	bool found = binary_search(vec.begin(), vec.end(), 9);  // check if 9 is in vec
	if (found)
		cout << "Yes" << endl;

	// Return true if all elements of s is included in vec
	// Both vec and s must be sorted!!! ow runtime error      
	vector<int> s = {  9,45 };
	bool found2 = includes(vec.begin(), vec.end(),     // Range #1
							s.begin(), s.end());        // Range #2
	
	if (found2)
		cout << "Yes, all of them inside \n";
	else
		cout << "Not all"<<endl;

	// Search Position
	vector<int>::iterator itr;
	itr = lower_bound(vec.begin(), vec.end(), 9);  // vec[1]  
	// Find the first position where 9 could be inserted and still keep the sorting.

	itr = upper_bound(vec.begin(), vec.end(), 9);  // vec[4] 
	// Find the last position where 9 could be inserted and still keep the sorting.

	pair<vector<int>::iterator, vector<int>::iterator> pair_of_itr;
	pair_of_itr = equal_range(vec.begin(), vec.end(), 9);
	// Returns both first and last position ie vec[1] and vec[4]  
}

void MergeEG() {
	vector<int> vec = { 8,9,9,10 };
	vector<int> vec2 = { 7,9,10 };
	vector<int> vec_out(7);		// runtime err if not specify this range 7
	// Both vec and vec2 should be sorted (same for the set operation)
	// Nothing is dropped, all duplicates are kept.
	merge(vec.begin(), vec.end(),		// Input Range #1
		vec2.begin(), vec2.end(),		// input Range #2
		vec_out.begin());               // Output 
	print_Iterator(vec_out);			// vec_out: {7,8,9,9,9,10,10}

	vec = { 1,2,3,4,1,2,3,4,5 };  // Both part of vec are already sorted 
	inplace_merge(vec.begin(), vec.begin() + 4, vec.end());
	print_Iterator(vec);	// vec: {1,1,2,2,3,3,4,4,5}  - One step of merge sort
}

void Set_Operation() {
	// Both vec and vec3 should be sorted 
	// The resulted data is also sorted
	vector<int> v1 = { 0,1,2,3,4,5 };
	vector<int> v2 = { 4,5,6,7,8,9 };
	vector<int> v3(12), v4(12), v5(12), v6(12);
	vector<int>::iterator itr1, itr2, itr3,itr4;

	sort(v1.begin(), v1.end());		// need to sort before use below alg. fns
	sort(v2.begin(), v2.end());

	// EG1: Union (v3) is X in both vec and vec2 
	itr1 = set_union(v1.begin(), v1.end(),				// Input Range #1
				v2.begin(), v2.end(),			// input Range #2
				v3.begin());					// Output 
	v3.resize(itr1 - v3.begin());				// ow v3: {0 1 2 3 4 5 6 7 8 9 0 0 }
	print_Iterator(v3);							// v3: {0 1 2 3 6 7 8 9}

	// EG2: Intersection (v4) are intersected numbers
	itr2 = set_intersection(v1.begin(), v1.end(),		// Input Range #1
					v2.begin(), v2.end(),		// input Range #2
					v4.begin());				// Output 
	v4.resize(itr2 - v4.begin());				// ow v3: {4 5 0 0 0 0 0 0 0 0 0 0 }
	print_Iterator(v4);							// vec_out: {4 5}

	// EG3: Only the items that are in v1 but not in vec2 
	itr3 = set_difference(v1.begin(), v1.end(),	// Input Range #1
					v2.begin(), v2.end(),		// input Range #2
					v5.begin());				// Output 
	v5.resize(itr3 - v5.begin());				// 
	print_Iterator(v5);							// vec_out: {0 1 2 3}

	// EG4: items from either vec or vec2
	itr4= set_symmetric_difference(v1.begin(), v1.end(),// Input Range #1
					v2.begin(), v2.end(),		// input Range #2
					v6.begin());				// Output 
	v6.resize(itr4 - v6.begin() );				
	print_Iterator(v6);							// vec_out: {0 1 2 3 6 7 8 9}

	/*	set purpose has almost exact same anwser
	*	Be aware: cant use back_inserter for set
	set<int> s1 = { 0, 1, 2,3,4,5 };
	...
	set_union ( s1.begin(),s1.end(),s2.begin(),s2.end(),inserter(s3,s3.end()) );
	set_intersection...
	set_difference
	set_symmetric_difference

	*/

	
	//map<int, int> m1 = { {1,1},{2,2}, {3,3} };
	//map<int, int> m2 = { {1,2},{2,4}, {3,3} };
	//map<int, int> m3 , m4, m5 , m6;
	//
	//map<int,int>::iterator itr_m1, itr_m2, itr_m3, itr_m4;
	//itr_m1 = set_union(m1.begin(), m1.end(), m2.begin(), m2.end(), inserter(m3, m3.end()));
	
	

}
int main() {
	Binary_Search();
	MergeEG();
	Set_Operation();
}