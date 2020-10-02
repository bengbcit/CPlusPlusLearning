#include<bits/stdc++.h> 
#include<iostream>
#include<vector>

using namespace std;

int main() {
    int n = 3;
    int m = 4;

    // Create a vector containing n vectors of size m.  
    vector<vector<int> > vec(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << vec[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}