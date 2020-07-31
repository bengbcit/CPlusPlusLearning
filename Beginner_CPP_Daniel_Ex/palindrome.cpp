#include <iostream>
using namespace std;
#include<vector>
#include<algorithm>
//#include<sstream>
#include<string>

void way1() {
    int ori, remainder, ReV = 0, tempSave;
    cout << "Please enter the numbers only: ";
    cin >> ori;
    tempSave = ori;
    while (ori != 0) {
        remainder = ori % 10;
        ReV = ReV * 10 + remainder;
        ori = ori / 10;
    };

    if (ReV == tempSave)
        cout << "It's palindrome" << endl;
    else
        cout << "It's not palindrome"<<endl;
}

void way2() {

    vector<int> vec;
    string ori, tempSave, Rev;

    cout << "Please enter the input : ";
    cin >> ori;
    tempSave = ori;

    for (char& c : ori){vec.push_back(c);}       
    // for_each(ori.begin(), ori.end(), [](char c) {cout<< c;}); 
    for (vector<int>::reverse_iterator itr = vec.rbegin(); itr != vec.rend();++itr) {
        //Rev.assign(1,*itr); // replace the current string content with n copies of char
        Rev += *itr;
    }
    if (Rev == tempSave)
        cout << "It's palindrome" << endl;
    else
        cout << "It's not palindrome" << endl;
}
int main() {
    //way1();
    way2();

    return 0;
}