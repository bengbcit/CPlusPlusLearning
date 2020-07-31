#include<iostream>		// std::cout
using namespace std;
#include <vector>
#include<algorithm>	

/*	Algorithms
 *		- mostly loops
 *		- for more efficiency: remove for, while loops by replacing Algorithms
 */
void algorithms_ex() {
    vector<int> vec = { 4, 2, 5, 1, 3, 9 };
    vector<int>::iterator itr = min_element(vec.begin(), vec.end()); // search and find smallest in vec itr -> 1

    // Note 1: Algorithm always process ranges in a half-open way: [begin, end)
    sort(vec.begin(), itr);  // sort until position pt to itr->1(1 not include cuz[4 1) ), so vec: { 2, 4, 5, 1, 3, 9}

    reverse(itr, vec.end()); // sort until pt to itr->1(1 include bcz[1,9) ), vec: { 2, 4, 5, 9, 3, 1}   itr => 9
    

    // Note 2: two range
    vector<int> vec2(3);
    copy(itr, vec.end(),  // Source rang from vec begin to end
        vec2.begin());   // Destination only begin
        //vec2 needs to have at least have space same as first range which is 3 elements this case.



   // Note 3:
    vector<int> vec3;
    copy(itr, vec.end(), back_inserter(vec3));  // Inserting instead of overwriting 
                      // back_insert_iterator      safe but Not efficient

    vec3.insert(vec3.end(), itr, vec.end());  // Efficient and safe

    // Note 5: Algorithm with native C++ array: ptr treat as iterator
    int arr[4] = { 6,3,7,4 };
    sort(arr, arr + 4);
}

// Note 4: Algorithm with function
bool isOdd(int i) {
    return i % 2;
}

int main() {
    algorithms_ex();
    vector<int> vec = { 2, 4, 5, 9, 2 };
    vector<int>::iterator itr = find_if(vec.begin(), vec.end(), isOdd); // itr -> 5
}