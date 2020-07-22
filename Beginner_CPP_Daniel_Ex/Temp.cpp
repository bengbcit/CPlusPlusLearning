#include<iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
	string str;
	stringstream mystr;

	mystr << 'A'; mystr >> str;

	cout << "The string obtained by converting single character : " << str;

	return 0;
}