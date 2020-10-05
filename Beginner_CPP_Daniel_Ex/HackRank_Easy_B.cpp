#include <bits/stdc++.h> 
using namespace std;

// *******Question_Class and Object *******

//class Student {
//public:
//    int scores[5], score_sum = 0;
//    int length = sizeof(scores) / sizeof(scores[0]);
//
//    void input() {
//
//        for (int i = 0; i < length;++i) { cin >> scores[i]; }
//    }
//
//    int calculateTotalScore() {
//        for (int i = 0; i < length;++i) { score_sum += scores[i]; }
//        return score_sum;
//    }
//};
//
//int main() {
//
//    int n; // number of students
//    cin >> n;
//    cin.ignore(numeric_limits<streamsize>::max(), '\n');
//
//    Student* s = new Student[n]; // an array of n students
//
//    for (int i = 0; i < n; i++) {
//        s[i].input();
//    }
//
//    // calculate kristen's score
//    int kristen_score = s[0].calculateTotalScore();
//
//    // determine how many students scored higher than kristen
//    int count = 0;
//    for (int i = 1; i < n; i++) {
//        int total = s[i].calculateTotalScore();
//        if (total > kristen_score) {
//            count++;
//        }
//    }
//
//    // print result
//    cout << count;
//
//    return 0;
//}
// *******Question_ Vector Erase *******

//int main() {
//   
//    int n,vi, q1_pos, q2_rangeA, q2_rangeB;
//    cin >> n;
//    vector<int> v;                       // number of int
//    for (int i = 0; i < n;++i) {         // make a vector contain n elements
//        cin >> vi;
//        v.push_back(vi);
//    }
//                           
//    cin >> q1_pos >> q2_rangeA >> q2_rangeB;  // q1: posiont; q2:range A to B
//    v.erase(v.begin() + q1_pos - 1);          // position v.begin start from 1
//    v.erase(v.begin() + q2_rangeA - 1, v.begin() + q2_rangeB);
//    cout << v.size() << endl;
//    for (auto i : v) { cout << i<<" "; }
//
//    return 0;
//}

// *******Question_ Lower Bound Stl *******
// not working correctly
//int main() {
//    int size, n, q, q_num;
//    vector<int> v;
//
//    cin >> size;
//    for (int i = 0;i < size;++i) {
//        cin >> n;
//        v.push_back(n);
//    }
//    sort(v.begin(), v.end());            // sort before getting query index
//    cin >> q;
//    bool flag;
//    for (int i = 0;i < q;++i) {
//        flag = false;
//        cin >> q_num;
//        for (int j = 0;j < size;++j){
//            while (!flag) {
//                if (q_num == v[j]) {
//                    cout << "Yes " << j + 1 << endl;   // vector position start from 0 so dont forget to inc 1;
//                    flag = true;
//                }
//                else
//                    if (v[j] > q_num) {
//                        cout << "No " << j + 1 << endl;    // after sorting, next index of q_num 
//                                                // will be the just greater than the present number 
//                        flag = true;
//                    }   
//            }
//        }
//
//    }
//
//
//    return 0;
//}


//int main() {
//   
//    int m, num;
//    cin >> m;
//    vector<int> v;
//    for (int i = 0; i < m; i++) {
//        cin >> num;
//        v.push_back(num);
//    }
//    int n, val;
//    cin >> n;
//    for (int i = 0; i < n; i++) {
//        cin >> val;
//        vector<int>::iterator low = lower_bound(v.begin(), v.end(), val);
//        if (v[low - v.begin()] == val)
//            cout << "Yes " << (low - v.begin() + 1) << endl;
//        else 
//            cout << "No " << (low - v.begin() + 1) << endl;
//    }
//    return 0;
//}


// *******Question_ Class Template *******
/*Why ios_base? 
- the fact that it speeds up the execution time is (or might be) just a side effect.     
- So if you untie cin from cout, you must make sure to flush cout manually every time you 
    want to display something before expecting input on cin.
*/
//#define cin ios_base::sync_with_stdio(false);cin.tie(NULL); cin
//
//template <class T>
//class AddElements {
//    T element;
//public:
//    AddElements(T arg) { element = arg; }
//    T add(T arg2) { return element + arg2; }
//
//};
//template<>
//class AddElements<string> {
//    string element;
//public:
//    AddElements(string arg) { element = arg; }
//    string concatenate(string arg3) { return element + arg3; }
//};
//
//int main() {
//    int n, i;
//    cin >> n;
//    for (i = 0;i < n;i++) {
//        string type;
//        cin >> type;
//        if (type == "float") {
//            double element1, element2;
//            cin >> element1 >> element2;
//            AddElements<double> myfloat(element1);
//            cout << myfloat.add(element2) << endl;
//        }
//        else if (type == "int") {
//            int element1, element2;
//            cin >> element1 >> element2;
//            AddElements<int> myint(element1);
//            cout << myint.add(element2) << endl;
//        }
//        else if (type == "string") {
//            string element1, element2;
//            cin >> element1 >> element2;
//            AddElements<string> mystring(element1);
//            cout << mystring.concatenate(element2) << endl;
//        }
//    }
//    return 0;
//}
//

// *******Question_ print pretty *******
// without #include <iomanip> 
//int main() {
//    int A = 100;
//    int integer_A = (int(A) / 16) * 10 + (int(A) % 16);
//    stringstream ss;
//    string s;
//    ss << integer_A;
//    ss >> s;
//    s = "0x" + s;
//    cout << s<<endl;
//
//    double B = -206.5889;
//    B = (int)(B * 100 + .5);
//    B = (double)B / 100;
//    stringstream ss2;
//    string s2;
//    ss2 << B;
//    ss2 >> s2;
//    if (B > 0) 
//        s2 = "+" + s2;
//    else 
//        s2 = "-" + s2;
//    string pref_ ((15 - s2.size() - 1),'_');
//    s2 = pref_ + s2;
//    cout << s2<<endl;
//
//
//    return 0;
//}


//#include <iomanip> 
//
//int main() {
//    int T; cin >> T;
//    cout << setiosflags(ios::uppercase);
//    cout << setw(0xf) << internal;
//    while (T--) {
//        double A; cin >> A;
//        double B; cin >> B;
//        double C; cin >> C;
//        // Line 1:
//        cout << hex << left << showbase << nouppercase; // formatting
//        cout << (long long)A << endl; // actual printed part
//
//        // LINE 2
//        cout << dec << right << setw(15) << setfill('_')
//            << showpos << fixed << setprecision(2); // formatting
//        cout << B << endl; // actual printed part
//        // LINE 3
//        cout << scientific << uppercase << noshowpos << setprecision(9); // formatting
//        cout << C << endl; // actual printed part
//
//    }
//    return 0;
//
//}

// *******Question_ Box it *******
#include<bits/stdc++.h>

using namespace std;
//Implement the class Box  
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions : 

// Constructors: 
// Box();
// Box(int,int,int);
// Box(Box);
class Box {
	int l, b, h;
public:
	Box() :l(0), b(0), h(0) {}  // initialization for private member
	Box(int length, int breadth, int height) {
		l = length;
		b = breadth;
		h = height;
	}
	Box(const Box& B) {// create obj B to initial another obj
		l = B.l;
		b = B.b;
		h = B.h;
	}

	int getLength() { return l; }    // Return box's length
	int getBreadth() { return b; }  // Return box's breadth
	int getHeight() { return h; }   // Return box's height
	long long CalculateVolume() { return (long long)l * b * h; } // Return the volume of the box

	//Overload operator < as specified
	bool operator<(Box& B) {
		return (l < B.l) || ((b < B.b) && (l == B.l))
			|| ((h < B.h) && (b = B.b) && (l == B.l)) ? true : false;
	}

	//Overload operator << as specified
	friend ostream& operator<<(ostream& out, const Box& B) {
		out << B.l << ' ' << B.b << ' ' << B.h << endl;
		return out;
	}

};



void check2()
{
	int n;
	cin >> n;
	Box temp;
	for (int i = 0;i < n;i++)
	{
		int type;
		cin >> type;
		if (type == 1)
		{
			cout << temp << endl;
		}
		if (type == 2)
		{
			int l, b, h;
			cin >> l >> b >> h;
			Box NewBox(l, b, h);
			temp = NewBox;
			cout << temp << endl;
		}
		if (type == 3)
		{
			int l, b, h;
			cin >> l >> b >> h;
			Box NewBox(l, b, h);
			if (NewBox < temp)
			{
				cout << "Lesser\n";
			}
			else
			{
				cout << "Greater\n";
			}
		}
		if (type == 4)
		{
			cout << temp.CalculateVolume() << endl;
		}
		if (type == 5)
		{
			Box NewBox(temp);
			cout << NewBox << endl;
		}

	}
}

int main()
{
	check2();
}