#include<iostream>		// std::cout
#include<vector>
#include<algorithm>
using namespace std;

/*	Sorting Algorithms
 *		- requires random access iterators
 *		- vector, deque,container array, native array
 */

// lsb_less() : last digit of two integers
bool lsb_less(int x, int y) { return (x % 10) < (y % 10);}
// lessthan10 fn
bool lessThan10(int i) { return i < 10; }

void print_sort(vector<int> vec) {
	for (vector<int>::const_iterator itr = vec.begin();itr != vec.end();++itr)
		cout << *itr << ' ';
	cout << endl;
}
int main() {
	/********** sorting examples *********/
	vector<int> vec = { 9,1,10,2,45,3,90,4,9,5,8 };

	// sort with operator <
	sort(vec.begin(), vec.end()); 
	print_sort(vec);	// vec:  1 2 3 4 5 8 9 9 10 45 90

	// sort with lsb_less()
	sort(vec.begin(), vec.end(), lsb_less); 
	print_sort(vec);	// vec: 10 90 1 2 3 4 45 5 8 9 9

	/********** partial sorting examples *********/
	vector<int> vec2 = { 9,60,70,8,45,87,90,69,69,55,7 };

	// sort 5 numbers with functor greater<int>()
	partial_sort(vec2.begin(), vec2.begin() + 5, vec2.end(), greater<int>()); 
	print_sort(vec2);	// vec: 90 87 70 69 69 8 9 45 60 55 7

	// sort bottom 5 number with overloaded and no functor
	partial_sort(vec2.begin(), vec2.begin() + 5, vec2.end()); 
	print_sort(vec2);	// vec: 7 8 9 45 55 90 87 70 69 69 60


	vector<int> vec3 = { 9,60,70,8,45,87,90,69,69,55,7 };	// change back original order
	// find top 5 numbers without sorted : get 90 87 70 69 69 60 55 45 9 8 7 ??
	nth_element(vec3.begin(), vec3.begin()+7, vec3.end(),greater<int>());
	print_sort(vec3);	// vec: 69 87 70 90 69 60 55 45 9 8 7

	vec2 = { 9,60,70,8,45,87,90,69,69,55,7 };
	// move numbers less than 10 to the front, randomly??
	partition(vec2.begin(), vec2.end(), lessThan10);
	print_sort(vec2);	// vec: 9 7 8 70 45 87 90 69 69 55 60
	
	vec2 = { 9,60,70,8,45,87,90,69,69,55,7 };
	// to get the original order within each partition eg: 9..8......7
	stable_partition(vec2.begin(), vec2.end(), lessThan10);
	print_sort(vec2);	// vec: 9 8 7 60 70 45 87 90 69 69 55

}
