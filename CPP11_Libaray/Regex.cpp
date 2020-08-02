#include<iostream>
using namespace std;
#include <regex>

/*	Regular Expression:		a regular expression is a specific pattern that provides concise and flexible 
							means to "match" strings of text, such as particular characters, words, or 
							patterns of characters. - wikipedia
	Regular Expression Grammars:	ECMAScript	||	basic	|| extended
									awk			||	grep	|| egrep
*/
void regex_regular() {
	string str;
	int allowInputNum;
	cout << "Enter the number of trial in regular grammar: ";
	cin >> allowInputNum;

	// allow user to input only 
	while (allowInputNum) {
		
		cin >> str;
		//regex e("abc");								// match "abc" only case sensitive
		//regex e("abc.",regex_constants::icase);	// . Any character except newline; case not sensitive-->icase
		//regex e("abc?");               // ?       Zero or 1 preceding character
		//regex e("abc*");               // *       Zero or more preceding character
		//regex e("abc+");               // +       One of more preceding character
		//regex e("ab[cd]*");            // [...]   Any character inside the square brackets
		//regex e("ab[^cd]*");           // [...]   Any character not inside the square brackets
		//regex e("ab[cd]{3,5}");		 // 3 to 5 preceding char
		//regex e("abc|de[\]fg]");       // |       Or		[\] means match "[]"
		//regex  e("(abc)de+\\1");       // \1      match First group  () means group
		//regex  e("(ab)c(de+)\\2\\1");	 // grp ab, grp 2 de+; \\2 \\1 means grp 2 reappear first

		/*pre-difined classes go check table */
		//regex e("[[:w:]]+@[[:w:]]+\.com");	// [[:w:]] word character: digit, number, or underscore

		//regex e("^abc.");					// ^   search beginning of the string
		//regex e("abc.$");                 // $   search End of the string

		//bool match = regex_match(str, e);

		regex e("^abc.+", regex_constants::grep);		// + just a char, no other meaning
		bool match_partial = regex_search(str, e);	// instead match whole string, match substring

		//cout << (match ? "Matched" : "Not matched") << endl << endl;
		cout << (match_partial ? "Matched" : "Not matched") << endl << endl;

		allowInputNum--;	// only run 5 times
	}
}

/*
  std::match_results<>  Store the detailed matches
  smatch                Detailed match in string

  smatch m;
  m[0].str()   The entire match (same with m.str(), m.str(0))
  m[1].str()   The substring that matches the first group  (same with m.str(1))
  m[2].str()   The substring that matches the second group
  m.prefix()   Everything before the first matched character
  m.suffix()   Everything after the last matched character
*/
void regex_submatch() {
	string str;

	int allowInputNum;
	cout << "Enter the number of trial of submatch: ";
	cin >> allowInputNum;

	while (allowInputNum) {
		cin >> str;
		smatch m;	// smatch: temparary class match results of stream; typedef std::match_results<string>

		regex e("([[:w:]]+)@([[:w:]]+)\.com");		// use () to define two groups: user name and domain name

		bool found = regex_search(str, m, e);		// search e save to m

		cout << "m.size() " << m.size() << endl;
		for (int n = 0; n < m.size(); n++) {
			cout << "m[" << n << "]: str()=" << m[n].str() << endl;
			//cout << "m[" << n << "]: str()=" << m.str(n) << endl;
			//cout << "m[" << n << "]: str()=" << *(m.begin() + n) << endl;
		}
		cout << "m.prefix().str(): " << m.prefix().str() << endl;
		cout << "m.suffix().str(): " << m.suffix().str() << endl;
		allowInputNum--;
	}
}

int main() {

	regex_regular();
	regex_submatch();

}