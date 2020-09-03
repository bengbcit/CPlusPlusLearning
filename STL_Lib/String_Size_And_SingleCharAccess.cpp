#include <iostream>
#include<string>
using namespace std;

void String_Constructor(){
	string s1("hello");
	string s2("hello", 3/*size*/);				// s2: hel
	string s3(s1, 2/*starting position*/);		// s3: llo
	string s4(s1, 3/*pos.*/, 2/*size*/);		// s4: lo
	string s5(5, 'a');							// s5: aaaaa
	string s6({ 'a','b','c' });					// s6: abc
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	cout << s5 << endl;
	cout << s6 << endl<<endl;
}

void size_cons() {
	string s1 = "goodbye";
	cout<< s1.size()<<endl;			// 7
	cout << s1.length()<<endl;		// 7
	cout << s1.capacity()<<endl;	// 15, return num of characters a string can hold without reallocation
	// reserve doesnt change size or content of string, work for capacity
	s1.reserve(100);	// 100 chars
	s1.reserve(5);		// s1:goodbye  so s1.size() ==7 s1.capacity()>=7
	//s1.resize(9);		// s1:goodbye00
	cout << s1.capacity() << endl;	// gives 111 which greater than 100 reserve before
	//s1.resize(12, 'x');			// s1:goodbye00xxx
	s1.shrink_to_fit();				// 15, shrink the capacity to fit the holding content
	cout << s1.capacity() << endl;	
}

void single_element_access() {
	string s1 = "goodbye";
	//s1[2];
	s1[2] = 'x';
	s1.at(2) = 'y';
	// s1.at(20); out of range
	// s1[20] undefined behaviour
	
	s1.front();
	s1.back();
	s1.push_back('z');
	s1.pop_back();	// pop out last char in the string
	s1.begin();		// pop iterator begin of string
	s1.end();		// pop iterator end of string

	// constuct string with iterator
	string s3(s1.begin(), s1.begin() + 3);	// goo
}

void memberFN_Algorithm() {
	string s1 = "abcdefg";
	char buf[20];
	size_t len = s1.copy(buf, 3); // abc: copy 3 chars from s1 to buf
	len = s1.copy(buf, 4, 2);	// cdef: size of 4 , start pos@ 2

	s1 = "if a job is worth doing, it's worth doing well";
	size_t found = s1.find("doing");	// 17
	found = s1.find("doing",20);		// 35: find start pos@17 
	found = s1.find("doing well", 0);	// 35
	found = s1.find("doing well", 0, 5);// 17: bcuz looking at only first 5 char, "doing"

	found = s1.find_first_of("doing");  // 6:find first chars in s1 in this string "d o i n g", find first 'o' at pos@6
	found = s1.find_first_of("doing",10);	// 12: start pos@10
	found = s1.find_first_of("doing", 10,1);// 17: start pos@10 and only look at first char 'd'

	// similarly
	found = s1.find_last_of("doing");		// 39: find g from'doing'
	found = s1.find_first_not_of("doing");	// 0: first not doing so it's first word starting at 0
	found = s1.find_last_not_of("doing");	// 44: last not doing so it's last word starting at 44
	
	string s2 = "abccc";
	s1.compare(s2);	// ret positive if s1>s2; negative if s1>s2; 0 if s1=s2
	// better than if fn cuz you can compare portion of string
	s1.compare(3, 2, s2); // compare staring pos@3, size 2

	string ss = s1 + s2; // will casuing more mem if s1, s2 really big  
}

int main() {
	String_Constructor();
	size_cons();

	// convert a string to number, stol, stod,stof (long, double float)
	string s1 = "190";
	int i = atoi(s1.c_str());

	s1 = "190 mmm";
	size_t pos;
	int i2 = stoi(s1, &pos); // pos is index char where stopped passing number, ie 'space char' this case

	s1 = "a monkey";
	// int i = stoi(s1, &pos); not work cuz no number
	int i3 = stoi(s1, &pos,16); // 10, 16 stands hexnumber, so 'a' is hex of dec10
}