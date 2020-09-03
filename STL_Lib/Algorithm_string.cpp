#include <iostream>
#include <algorithm>	// count_if
#include <string>
using namespace std;

void string_algorithm() {
	string s1 = "variety is the spice of life.";
	string s2 = "Pang pang pang pang.";
	int num = count(s1.begin(), s1.end(), 'e'); // 4 (total 4 'e')
	num = count_if(s1.begin(), s1.end(), [](char c)
		{ return (c <= 'e' && c >= 'a');});// lambda expression, result 6 (total contain a b c d e)

	s1 = "Goodness is a successful lady.";
	string::iterator itr = search_n(s1.begin(), s1.begin()+2,2,'s' ); // seaching syllable 'ss', itr -> first s

	s1.erase(itr, itr + 5);			// remove from itr at size 5 so "ss is" removed
	s1.insert(itr, 3, 'x');			// insert 3 x at itr
	//s1.replace(itr, itr + 1, 'y');	// replace substring ,3 char start from itr

	// algorithm 
	is_permutation(s1.begin(), s1.end(), s2.begin());
	replace(s1.begin(), s1.end(), 'e', ' '); // replace all char e to space
	transform(s1.begin(), s1.end(), s2.begin(), [](char c) {
		if (c < 'n')
			return 'a';
		else
			return 'z';
		}); // save result to s2
	s1 = "abcdefg";
	rotate(s1.begin(), s1.begin() + 3, s1.end()); // defgabc: rotate at pos@3
	
	u16string s3;	// string char16_t
	u32string s4;	// string char32_t
	wstring s5;		// string wchar_t, wide character

}
int main() {

}