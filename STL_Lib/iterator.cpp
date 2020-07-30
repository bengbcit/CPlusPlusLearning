/*				Std Template Libarary - Data Structures and Algorithms
****NOTES:
	1. What is it?
		-	It's inside c++ std libaray and the oppsite way of object oriented programming, 
			seperate algorithms and the data structures for code reuse purpose
	2. Main Structure
		N Algorithms + M containers = N*M implementation
		container:	data structure;		
	**	iterators:	
			a.	iterate each item inside a container; algorithms only needs to know the iterators 
				instead of writing N*M implementation
			b.	easily extendable  
					eg: define a new algorithm on iterator which all containers can use it
					eg: define a new container provide appropriate iterator interface, all algorithms can use it
	3. Not so ez to use
		-	continue later ...
*/
#include<iostream>		// std::cout
#include<algorithm>		// std::sort
#include<vector>		// std::vector
#include <list>			// std::list
#include<forward_list>	// std::forward_list
#include<set>
using namespace std;

// #############Iterator##################
 /* Iterator Adaptor (Predefined Iterator)
  *  - A special, more powerful iterator
  * 1. Insert iterator
  * 2. Stream iterator
  * 3. Reverse iterator
  * 4. Move iterator (C++ 11)
  */

/*
void Notes_For_Not_Run(vector<int> vec) {
	vector<int>::iterator itr;
	vector<int>::iterator itr1 = vec.begin();
	vector<int>::iterator itr2 = vec.end();

	// 1. Random Access Iterator:  vector, deque, array
	itr = itr + 5;  // advance itr by 5
	itr = itr- 4;
	if (itr2 > itr1)	
	++itr;			// faster than itr++
	--itr;

	// 2. Bidirectional Iterator: list, set/multiset, map/multimap
	// cant compare itr eg if(itr2>itr1)
	list<int> itr;
	++itr;
	--itr;

	// 3. Forward Iterator: forward_list -> only increment cannot decrement
	forward_list<int> itr;
	++itr;

	// 4. Input Iterator: read and process values while iterating forward. ->cant write to it
	int x = *itr;

	// 5. Output Iterator: output values while iterating forward. ->cant read to it
	*itr = 100;
}
*/

// iterator and const_iterator
void const_it() {
	// Every container has a iterator and a const_iterator
	set<int>::iterator itr;
	set<int>::const_iterator citr;  // Read_only access to container elements

	set<int> myset = { 2,4,5,1,9 };
	for (citr = myset.begin(); citr != myset.end(); ++citr) {
		cout << *citr << endl;
		//*citr = 3;				// cant modified 
	}
	//for_each(myset.cbegin(), myset.cend(), MyFunction);  // read only in C++ 11 asscess const iterator

	// Iterator Functions:
	advance(itr, 5);       // Move itr forward 5 spots.   itr += 5;
	//distance(itr1, itr2);  // Measure the distance between itr1 and itr2
}

// insert Iterator
void insert_it() {
	vector<int> vec1 = { 4,5 };
	vector<int> vec2 = { 12, 14, 16, 18 };
	vector<int>::iterator it = find(vec2.begin(), vec2.end(), 16);
	insert_iterator< vector<int> > i_itr(vec2, it);
	copy(vec1.begin(), vec1.end(),  // source
		i_itr);                   // destination
		//vec2: {12, 14, 4, 5, 16, 18}
   // Other insert iterators: back_insert_iterator, front_insert_iterator
}

// stream iterator: iterate data to or from a stream
void stream_it() {
	vector<string> vec4;
	//copy(istream_iterator<string>(cin), istream_iterator<string>(),
	//	back_inserter(vec4));

	//copy(vec4.begin(), vec4.end(), ostream_iterator<string>(cout, " "));

	// combine above two copy into 1 statement:
	copy(istream_iterator<string>(cin), istream_iterator<string>(),
		ostream_iterator<string>(cout, " "));

}

// reverse iterator
void rev_it() {
	vector<int> vec = { 4,5,6,7 };
	reverse_iterator<vector<int>::iterator> ritr;
	for (ritr = vec.rbegin(); ritr != vec.rend(); ritr++)
		cout << *ritr << endl;   // prints: 7 6 5 4
}

// iterator sort example
void it_sort() {
	vector<int> vec;		// container
	vec.push_back(4);
	vec.push_back(1);
	vec.push_back(8);

	// iterators below
	vector<int>::iterator itr1 = vec.begin();	// half-open:  [begin, end); so dont use like *vec.end() <--invalid
	vector<int>::iterator itr2 = vec.end();		// |vec.begin()|~|~|~|~|~|~|vec.end  <---.end() is outside of vector

	for (vector<int>::iterator itr = itr1; itr != itr2; ++itr)
		cout << *itr << " ";

	sort(itr1, itr2);		// algorithm
	
	for (int i = 0; i < vec.size();++i)			// now vector is {1 4 8}
		cout << vec[i] << " ";
}

int main() {
	it_sort();
	stream_it();
	
}
