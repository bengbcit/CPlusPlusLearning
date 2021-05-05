/* Attribute Parser 
*	Reference from Isaac Asante
*   https://gist.github.com/IsaacAsante/82259bb87d10204f6a0e4e4b3cf4ba6e
*/
//#include <iostream>
//#include <map>
//#include <sstream>
//#include <string>
//using namespace std;

//int main() {
//    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
//    int n, q;
//    string curr, attr_name = "";    // new way declare string
//    map<string, string> m;          // pair of key(string), value(string)
//    cin >> n >> q;
//    cin.ignore();                   // igonre '\n'
//
//    for (int i = 0; i < n;++i) {
//        string line, tag, word;
//        cin >> line;
//        stringstream ss(line);
//       
//        while(ss >> word)  {        // extract each part by a delim ' '; 
//            switch (word[i]) {
//            case '<':
//                cout << word << endl;
//                break;
//            case '=':
//                cout << word << endl;
//                break;
//            case '"':
//                cout << word << endl;
//                break;
//            default: // for tag name
//                cout << word << endl;
//            }
//            
//        }
//
//    }
//    
//
//
//    return 0;
//}

//cin.ignore()的用法

//int main()
//{
//	char str[30];
//	cout << "请输入一个字符串：";
//	cin >> str;
//	cout << str << endl;
//
//
//	cin.ignore(100, '\n');
//	cout << "请输入任意字符结束程序！\n";
//	cin.get();
//
//	return 0;
//}

//
//int main() {
//    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
//    int n, q;
//    string curr = "", attr_name;
//    map<string, string> m;
//    cin >> n >> q;
//    cin.ignore();
//
//     For every word in the HRML Line (space delimiter), check:
//    for (int i = 0; i < n; i++) {
//        string line, tag, extract;
//        getline(cin, line);
//        stringstream ss(line);
//
//         Process the HRML lines
//        while (ss>>extract) {
//             If it's a tag
//            switch (extract[0]){
//                case'<':
//                     If it's an opening tag
//                    if (extract[1] != '/') {
//                         Remove the opening bracket
//                        tag = extract.substr(1);
//                         For tags without attributes
//                        if (tag[tag.length() - 1] == '>') {
//                             Remove the closing bracket
//                            tag.pop_back();
//                        }
//                         Check if any nesting is needed
//                        if (curr.size() > 0) {
//                             Nest this tag : previous + current tag
//                            curr += "." + tag;
//                        }
//                        else {
//                            curr = tag;
//                        }
//                       
//                    }
//                     If it's a closing tag
//                    else {
//                        tag = extract.substr(2, (extract.find('>') - 2));
//                         Check if a nested tag has to be closed
//                        size_t pos = curr.find("." + tag);
//                        if (pos != string::npos /*Maximum value for size_t*/) { 
//                             Remove the nested tag
//                            curr = curr.substr(0, pos);
//                        }
//                        else {
//                             All tags are closed
//                            curr = "";
//                        }
//                    }
//                    break;
//
//                 If's an attribute's value
//                case'"':
//                     Capture the full value
//                    size_t pos = extract.find_last_of('"');
//                    string attr_value = extract.substr(1, pos - 1);
//                     Add to the map
//                    m[attr_name] = attr_value;
//                    
//                    break;         
//            }
//            if (extract != "=") {
//                 It's definitely an attribute name
//                attr_name = curr + "~" + extract;
//               
//            }
//        }
//    }
//
//     Get the values with the queries
//    string query;
//    for (int i = 0; i < q; i++) {
//        getline(cin, query);
//
//         Search in the map
//        map<string, string>::iterator itr = m.find(query);
//        if (itr != m.end()) {// itrerator search before end, find it
//            cout << itr->second << endl;
//        }
//        else {
//            cout << "Not Found!" << endl;
//        }
//    }
//
//    return 0;
//}
//

// Question Deque-STL
//#include <iostream>
//#include <vector>
//#include <deque> 
//using namespace std;
//
//void printKMax(vector <int> arr, int n, int k) {
//    deque<pair<int, int>> dq;
//    for (int a = 0; a < n; a++) {
//        while (!dq.empty() && a - dq.front().second >= k) {// do when less than contiguous array size k
//            dq.pop_front();
//        }
//        while (!dq.empty() && dq.back().first <= arr[a]) {// if current dq.back.fisrt < next arr[a], pop current
//            dq.pop_back();
//        }
//        dq.push_back({ arr[a], a });
//        if (a >= k - 1) {   // start to print at a=k-1; eg k=4, so printing 4 sections (also the size range is 4)  
//                            // are: (arr[0]~arry[3]),(arr[1]~arry[4]),..(arr[3]~arry[6])
//            cout << dq.front().first << " ";
//        }
//    }
//    cout << "\n";
//}
//
//int main() {
//
//    int t;
//    cin >> t;
//    while (t > 0) {
//        int n, k;
//        cin >> n >> k;
//        vector<int> vec(n);
//       
//        for (int i = 0;i < n;i++)
//            cin >> vec[i];
//        printKMax(vec, n, k);
//        t--;
//        //delete [] arr[n];
//    }
//    return 0;
//}

/* Questions Accessing inherited functions*/
#include<iostream>

using namespace std;

class A
{
public:
    A() {
        callA = 0;
    }
private:
    int callA;
    void inc() {
        callA++;
    }

protected:
    void func(int& a)
    {
        a = a * 2;
        inc();
    }
public:
    int getA() {
        return callA;
    }
};

class B
{
public:
    B() {
        callB = 0;
    }
private:
    int callB;
    void inc() {
        callB++;
    }
protected:
    void func(int& a)
    {
        a = a * 3;
        inc();
    }
public:
    int getB() {
        return callB;
    }
};

class C
{
public:
    C() {
        callC = 0;
    }
private:
    int callC;
    void inc() {
        callC++;
    }
protected:
    void func(int& a)
    {
        a = a * 5;
        inc();
    }
public:
    int getC() {
        return callC;
    }
};

class D : public A, public B, public C
{
    int val;
public:
    D() { val = 1; }  //Initially val is 1
    void update_val(int new_val) {
        /*way 1*/
        /*while (val < new_val) {
            if (new_val % (val * 2) == 0) A::func(val);
            else if (new_val % (val * 3) == 0) B::func(val);
            else if (new_val % (val * 5) == 0) C::func(val);
        }*/
        /*way 2*/
        int a = new_val;
        while (a % 2 == 0)
        {
            a = a / 2;
            A::func(val);
        }
        while (a % 3 == 0)
        {
            a = a / 3;
            B::func(val);
        }
        while (a % 5 == 0)
        {
            a = a / 5;
            C::func(val);
        }
    }
    //For Checking Purpose
    void check(int); //Do not delete this line.
};



void D::check(int new_val)
{
    update_val(new_val);
    cout << "Value = " << val << endl << "A's func called " << getA() << " times " << endl << "B's func called " << getB() << " times" << endl << "C's func called " << getC() << " times" << endl;
}


int main()
{
    D d;
    int new_val;
    cin >> new_val;
    d.check(new_val);

}