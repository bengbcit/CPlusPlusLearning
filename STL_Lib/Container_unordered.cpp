#include<iostream>		// std::cout
using namespace std;
#include <unordered_set>
#include <unordered_map>
/*	 Unordered Container (C++ 11) usually implement with hash table
 *   - Unordered set and multiset
 *   - Unordered map and multimap

 *  Order not defined, and may change overtime
 *
 *  Default hash function defined for fundamental types and string.
 *
 *  No subscript operator[] or at()
 *  No push_back(), push_front()
 */

 /*	*************************unordered Containers*************************:
     Properties of unordered Containers:
  *		1. Fastest search/insert at any place: O(1) ie constant time search
  *		2. Unorderd set/multiset: element value cannot be changed.
  *		3. Unorderd map/multimap: element key cannot be changed.
  * **********************************************************************/
void unordered_Set_Container() {
    unordered_set<string> myset = { "red","green","blue" };
    unordered_set<string>::const_iterator itr = myset.find("green"); // O(1)
    /*  Important check here:
            if find item:   iterator return points to the item
            if not find:    iterator return points to the end of container
    */  
    if (itr != myset.end())     // find "green", so points to  the place
        cout << *itr << endl;   // dereference

    myset.insert("yellow");     // O(1) : constant time search
    vector<string> vec = { "purple", "pink" };
    myset.insert(vec.begin(), vec.end());     // insert every item in the vector into set

    // Hash table specific APIs:
    cout << "load_factor = " << myset.load_factor() << endl;    // ratio: tot # elements/ tot # buckets
    string x = "red";
    cout << x << " is in bucket #" << myset.bucket(x) << endl;  // bucket: the element stored at
    cout << "Total bucket #" << myset.bucket_count() << endl;

}

/*	*********Associateive Array: implement with map and unordered map*************
    Properties of Associateive Array:
 *		1. Search time: unordered_map, O(1); map, O(log(n)) logarithmic time search;
 *		2. Unordered_map may degrade to O(n) linear time search;
 *		3. Can't use multimap and unordered_multimap, they don't have [] operator.
 *  *****************************************************************************/
void foo(const unordered_map<char, string>& m) {
    //m['S'] = "SUNDAY";            const m, so cant modify it
    //cout << m['S'] << endl;       const m, so cant modify it
    auto it = m.find('S');
    if (it != m.end()) { cout << (*it).first << " => " << (*it).second << endl; }
}

void Associateive_Array_unordered() {
    unordered_map<char, string> day = { {'S',"Sunday"}, {'M',"Monday"} };
    
    cout << day['S'] << endl;           // No range check
    cout << day.at('S') << endl;        // Has range check

    vector<int> vec = { 1, 2, 3 };
    // vec[5] = 5;                       // Compile Error

    day['W'] = "Wednesday";                 // way 1: Inserting {'W', "Wednesday}
    day.insert(make_pair('F', "Friday"));   // way 2: Inserting {'F', "Friday"}

    //day.insert(make_pair('M', "MONDAY")); // Fail to modify, it's an unordered_map
    day['M'] = "MONDAY";                    // Succeed to modify
    cout << day.at('M') << endl;

    foo(day);
}

/* Container Adaptor
 *  - Provide a restricted interface to meet special needs
 *  - Implemented with fundamental container classes
 *
 *      1. stack:  LIFO, push(), pop(), top()
 *      2. queue:  FIFO, push(), pop(), front(), back()
 *      3. priority queue(first item always has the greatest priority): push(), pop(), top()                
 */

 /* Another way of categorizing containers:
  *     1. Array based containers: vector, deque
               - invalidates pointers: Native pointers, iterators, references
  *     2. Node base containers: list +  associative containers + unordered containers
  */

int main() {
    unordered_Set_Container();
    Associateive_Array_unordered();
    
}

/* Another example of unorder map */
// C++ program to demonstrate functionality of unordered_map
//#include <iostream>
//#include <unordered_map>
//using namespace std;
//
//int main()
//{
//    // Declaring umap to be of <string, double> type
//    // key will be of string type and mapped value will
//    // be of double type
//    unordered_map<string, double> umap;
//
//    // inserting values by using [] operator
//    umap["PI"] = 3.14;
//    umap["root2"] = 1.414;
//    umap["root3"] = 1.732;
//    umap["log10"] = 2.302;
//    umap["loge"] = 1.0;
//
//    // inserting value by insert function
//    umap.insert(make_pair("e", 2.718));
//
//    string key = "PI";
//
//    // If key not found in map iterator to end is returned
//    if (umap.find(key) == umap.end())
//        cout << key << " not found\n\n";
//
//    // If key found then iterator to that key is returned
//    else
//        cout << "Found " << key << "\n\n";
//
//    key = "lambda";
//    if (umap.find(key) == umap.end())
//        cout << key << " not found\n";
//    else
//        cout << "Found " << key << endl;
//
//    //    iterating over all value of umap
//    unordered_map<string, double>::iterator itr;
//    cout << "\nAll Elements : \n";
//    for (itr = umap.begin(); itr != umap.end(); itr++)
//    {
//        // itr works as a pointer to pair<string, double>
//        // type itr->first stores the key part  and
//        // itr->second stroes the value part
//        cout << itr->first << "  " << itr->second << endl;
//    }
//}