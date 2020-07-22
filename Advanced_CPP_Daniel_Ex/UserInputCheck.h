#include <string>
#include <iostream>
using namespace std;

#ifndef USERINPUTCHECK
#define USERINPUTCHECK
int case_num;
int Options_Num;

// make a user input option (1-9) check
int isdigit_fn(string str) {
	cout << endl;
	int flag = 0;
	for (int i = 0;i < str.size();i++) {
		if (!isdigit(str[i])) {
			cout << "Please enter digit only!\n";
			return flag;
		}
		else {
			if (str.size() != 1) {
				cout << "Please enter one digit (1 to "<< Options_Num <<") only!\n";
				return flag;
			}
			else {
				/*	stoi(str[i]) ---------- not work;
					stoi(str)-------------- work;
					atoi(str.c_str())------ work;
					int(str[i]) ----------- hacky way: return integer of ASC II CODES eg: '3' = 51
				*/
				if (stoi(str) < 1 || atoi(str.c_str()) > Options_Num) {
					cout << "Please enter digit (1 to " << Options_Num << ") only!\n";
					return flag;
				}
				case_num = stoi(str);
				return ~flag;
			}
		}
	}

}

string User_input(string str) {
	cout << "Please enter case number (1-"<<Options_Num<<"): ";
	cin >> str;
	return str;
}
#endif
