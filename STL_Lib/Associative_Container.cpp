/*	Associative Container:|key|value| value associate with key
 *		Always sorted, default criteria is <
 *		No push_back(), push_front()
 *      set/multiset: value of the elements cannot be modified
 *      map/multimap: 
 *          keys cannot be modified
 *          type of *it:   pair<const char, int>
 */
#include <iostream>
using namespace std;
#include <set>
#include <map>


/*	set:	
	Properties of set:
 *		1. No duplicates
 *		2. O(log(n)) => O(1)
 *		3. pair<set<int>::iterator, bool> ret_VALUE
 */
void set_Container() {
    set<int> myset;
    myset.insert(3);                    // myset: {3}
    myset.insert(1);                    // myset: {1, 3}
    myset.insert(7);                    // myset: {1, 3, 7},  O(log(n))

    set<int>::iterator it;
    it = myset.find(7);                 // O(log(n)), it points to 7
                                        // Sequence containers don't even have find() member function
    pair<set<int>::iterator, bool> ret; // bool: check insertion successfull or not
    ret = myset.insert(3);              // insertion fn can be returned; but 3 is duplicate
    if (ret.second == false)
        it = ret.first;                 // "it" now points to element 3

    myset.insert(it, 9);                // "it" hint where 9 inserted; myset:  {1, 3, 7, 9}                       
    myset.erase(it);                    // "it" still points to 3 now; erase it will get myset:  {1, 7, 9}
    myset.erase(7);                     // myset:  {1, 9}
    cout << "The set elements are: ";
    for (it = myset.begin();it!=myset.end();++it)
        cout << "\t" << *it;
    // Note: none of the sequence containers provide this kind of erase.
}

/*	multiset:
    Properties of multiset:
 *		1. Allow duplicates
 *		2. Fast search: O(log(n))
 *		3. Traversing is slow (compared to vector & deque)
 *      4. No random access, no [] operator.
 */
void multiset_Container() {
    multiset<int, greater<int>> multiset_1;

    multiset_1.insert(50);
    multiset_1.insert(50);
    multiset_1.insert(60);
    multiset_1.insert(70);
    multiset_1.insert(80);

    multiset<int, greater<int>>::iterator iterator_1;
    cout << "\nThe multiset elements are: ";
    for (iterator_1 = multiset_1.begin(); iterator_1 != multiset_1.end(); ++iterator_1){
        cout << "\t" << *iterator_1;
    }
    // set/multiset: value of the elements cannot be modified
    //*it = 10;  // *it is read-only

}
/* greater: Binary function object class whose call returns whether the its first argument
            compares greater than the second (as returned by operator >).*/
#include <functional>   // std::greater
#include <algorithm>    // std::sort
void greater_class_temp() {
    int numbers[] = { 20,40,50,10,30 };
    sort(numbers, numbers + 5, std::greater<int>());
    for (int i = 0; i < 5; i++)
        std::cout << numbers[i] << ' ';
    std::cout << '\n';
}

/*	map:
    Properties of map:
 *		1. no duplicates keys
 */
void map_container() {
    map<char, int> mymap;
    mymap.insert(pair<char, int>('a', 100));            // need to create a pair(char to int) for map
    mymap.insert(make_pair('z', 200));                  // or use make_pair() fn

    map<char, int>::iterator it = mymap.begin();
    mymap.insert(it, pair<char, int>('b', 300));        // "it" is a hint

    it = mymap.find('z');                               // find based on key 'z'; O(log(n))

    // showing contents:
    for (it = mymap.begin(); it != mymap.end(); it++)
        cout << (*it).first << " => " << (*it).second << endl;
}
/*	multimap:
    Properties of multimap:
 *		1. Allow duplicates keys
 */
void multimap_container() {
    // (*it).first = 'd';  // Error -- keys cannot be modified
    // similar as map just allow duplicate keys
}

int main() {
    set_Container();
    multiset_Container();
    map_container();
    //multimap_container();

}