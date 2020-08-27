#include<iostream>		// std::cout
#include <vector>
#include<algorithm>	
using namespace std;

/*	Sorted Data Algorithms
 *   - Algorithms that require data being pre-sorted
 *   - Binary search, merge, set operations
 */

void print_Iterator(vector<int> vec) {
	for (vector<int>::const_iterator itr = vec.begin();itr != vec.end();++itr)
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
	vector<int> vec = { 8,9,9,10 };
	vector<int> vec2 = { 7,9,10 };
	vector<int> vec_out(5);
	sort(vec.begin(), vec.end());		// need to sort before use below alg. fns
	sort(vec2.begin(), vec2.end());

	// EG1: if X is in both vec and vec2, only one X is kept in vec_out
	set_union(vec.begin(), vec.end(),			// Input Range #1
			vec2.begin(), vec2.end(),			// input Range #2
			vec_out.begin());					// Output 
	print_Iterator(vec_out);					// vec_out: {7,8,9,9,10}

	// EG2: Only the items that are in both vec and vec2 are saved in vec_out
	vector<int> vec_out2(2);
	set_intersection(vec.begin(), vec.end(),    // Input Range #1
					vec2.begin(), vec2.end(),   // input Range #2
					vec_out2.begin());          // Output 
	print_Iterator(vec_out2);					// vec_out: {9,10,0,0,0}

	// EG3: Only the items that are in vec but not in vec2 are saved in vec_out
	// The objects in the ranges [first1,last1) and [first2,last2)are accessed.
	vector<int> vec_out3(7);
	vector<int>::iterator itr;
	itr = set_difference(vec.begin(), vec.end(),// Input Range #1
				vec2.begin(), vec2.end(),		// input Range #2
				vec_out3.begin());              // Output 
	vec_out3.resize(itr - vec_out3.begin()-1);	// ow give {8,9}
	print_Iterator(vec_out3);					// vec_out: {8}

	// EG4: vec_out has items from either vec or vec2, but not from both
	vector<int> vec_out4(5);
	vector<int>::iterator itr2;
	itr2= set_symmetric_difference(vec.begin(), vec.end(),// Input Range #1
		vec2.begin(), vec2.end(),						// input Range #2
		vec_out4.begin());								// Output 
	vec_out4.resize(itr2 - vec_out4.begin() - 1);		// vec_out: {7,8,0,0,0}
	print_Iterator(vec_out4);							// vec_out: {7,8}

}
int main() {
	Binary_Search();
	MergeEG();
	Set_Operation();
}