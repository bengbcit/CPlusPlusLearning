#include <bits/stdc++.h> 
using namespace std;

// *******Question_ 1*******
// more accurate way
//int main() {
//
//    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
//    const int max_input = 3;
//    int inputs[max_input], sum = 0;
//    int inputs_len = sizeof(inputs) / sizeof(inputs[max_input]);
//    //for -each loops do not provide a direct way to get array index
//    //for (auto i : inputs)
//
//    for (int i = 0;i < inputs_len;++i) {
//        do {
//            cout << "Enter the value (1 to 1000):";
//            cin >> inputs[i];
//        } while (inputs[i] < 1 || inputs[i]>1000);
//        sum += inputs[i];
//    }
//    cout << sum;
//
//    return 0;
//}

/*
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << a + b + c;
    return 0;
}
*/

// *******Question_ 2*******
/*
int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string num_str[10] = { "Greater than 9","one","two","three","four",
                        "five","six","seven","eight","nine" };
    if (n > 9) cout << num_str[0];
    else cout << num_str[n];

}
*/

// *******Question_ 3*******
/*
int main() {
    int a, b;
    cin >> a >> b;
    string num_str[11] = { "even","one","two","three","four",
                        "five","six","seven","eight","nine","odd" };

    for (int i = a; a <= b; ++a) {
        if (a > 9 && a % 2 == 0)  cout << "even" << endl;
        else if (a > 9 && a % 2 == 1)  cout << "odd" << endl;
        else cout << num_str[a] << endl;
    }
    return 0;
}
*/

// *******Question_4 *******
/*
int max_of_four(int a, int b, int c, int d) {
    int max = a;  // assume a is max to start with
    int nums[3] = { b,c,d };
    for (int i : nums) {
        if (max < i) max = i;
    }
    return max;
}

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);

    return 0;
}
*/

// *******Question_ 5*******
/*
#include <stdio.h>
#include <cstdlib>
void update(int *a,int *b) {
    int *temp = new int;     // declare new pointer
    *temp = *a;
    *a += *b;
    *b = abs(*temp - *b);
    // *b = *temp - *b > 0? *temp - *b : *b - *temp;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;

    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}

*/

// *******Question_6 *******
/*
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N;
    cin >> N;
    // stack-base mem must be know at compile time, create max fix size
    int num_ary[1000];

    for (int i = 0;i < N;++i) {
        cin >> num_ary[i];
    }
    for (int i = N-1;i >= 0;i--) {
        cout << num_ary[i]<<endl;
    }
    return 0;
}
*/

// *******Question_9 *******
/*
    int main() {
 
        int n, q, k, index_i, index_j;
        cin >> n >> q;
        vector< vector<int> >arr(n); // Create a vector containing n vectors. 
        for (int i = 0; i < n; ++i) {
            cin >> k;
            arr[i].resize(k);        // vector is resized 
            for (int j = 0; j < k; ++j) {
                cin >> arr[i][j];
            }
        }

        for (int i = 0; i < q; ++i) {
            cin >> index_i >> index_j;
            cout << arr[index_i][index_j] << endl;
        }

        return 0;
    }

*/

// *******Question_10 *******
/*
    interesting way: read comma',' change line, otherwise keep integer
    for (char c; std::cin >> c;) std::cout << (c != ','? c : '\n');

*/


vector<int> parseInts(string str) {
    vector<int> vec;            // Declares a vector to store the ints
    stringstream myStr(str);    // Declares a stringstream object to deal with the modification of the string
    char ch;
    int temp;

    while (myStr) {           // While the stringstream object does not hit a null byte
        myStr >> temp >> ch;    // Extract the comma seperated ints with the extraction >> operator
        vec.push_back(temp);// Push the int onto the vector
    }
    return vec; // Return the vector of ints
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for (int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }

    return 0;
}

