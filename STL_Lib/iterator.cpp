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
using namespace std;

int main() {

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
}
