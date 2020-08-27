#include<iostream>		// std::cout
#include<vector>
#include<algorithm>
using namespace std;

/*	Heap Algorithms (implement priority queue)
 *		- First element is always the largest
 *		- Add/remove takes O(log(n)) time
 */
// print vector of heap fn
void print_heap(vector<int> vec) {
	for (vector<int>::const_iterator itr = vec.begin();itr != vec.end();++itr)
		cout << *itr << ',';
	cout << endl;
}

int main() {
	/********** Heap examples *********/
	vector<int> vec = { 9,1,10,2,45,3,90,4,9,5,8 };
	// create new heap on target container, so it converts vector to a heap
	make_heap(vec.begin(), vec.end());
	// first element is largest regard rest of order
	print_heap(vec);	// vec: 90 45 10 9 8 3 9 4 2 5 1

	// Remove the largest element:
	pop_heap(vec.begin(), vec.end());  // 1. Swap vec[0] with last item vec[size-1]
									   // 2. Heapify [vec.begin(), vec.end()-1)
	print_heap(vec);	// vec: 45,9,10,4,8,3,9,1,2,5,90,

	// remove the last item( the largest one from above this case)
	vec.pop_back();  
	print_heap(vec);	// vec:  45 9 10 4 8 3 9 1 2 5

	// add new element 
	vec.push_back(100);
	push_heap(vec.begin(), vec.end()); // Heapify the last item in vec
	print_heap(vec);	// vec:  100,45,10,4,9,3,9,1,2,5,8,

	// Heap Sorting:  sort_heap can only work on a heap. make sure conv vec to heap first
	sort_heap(vec.begin(), vec.end());
	print_heap(vec);	// vec: 1 2 3 4 5 8 9 9 10 45 100
	


}