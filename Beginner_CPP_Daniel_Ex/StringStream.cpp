#include <bits/stdc++.h> 
using namespace std;

/* counting words eg*/
int countWords(string s) {
	stringstream myStr(s);
	string words; 
	int count = 0;

	while (myStr >> words) {
		count++;
	}
	return count;
}

/* print frequencies of individual words in a string*/
void printFreq_str(string s) {
	map<string, int> map_Hash; // hash map for looking up freq.
	stringstream myStr(s);
	string words;

	while (myStr >> words) {	// find pairs of key and value
		map_Hash[words]++;
	}

	map<string, int>::iterator m; // use iterator to go thru
	for (m = map_Hash.begin(); m != map_Hash.end();m++) {
		cout << m->first << "->" << m->second<<endl;
	}

}
int main() {
	string s = "Hello String Stream String Stream";
	cout << "Numbers of words are:" << countWords(s)<< endl << endl;

	/* below is print frequency */
	printFreq_str(s);

	return 0;
}

