// const - A compile time constraint that an obj can not be modified
/*
	Why const?
	- Guard against inadvertent write to the variable: stop at compile time rather than waiting a long time
	- self documenting
	- Enable compiler to do more optimiztion, making code tighter
	- const means the variable can be put in ROM: useful in embedded program
	EZ to remember rule: 
	- const at the right side of * means pt is const eg: int* const p3 = &j;
	- const at the left side of * means data is const eg : const int* p1 = &i;
*/
#include <iostream>
#include <string>
#include "UserInputCheck.h"
using namespace std;


int main() {

/*Instruction Code*/
	cout << "***************Const Instructions***************" << endl;
	cout << "*	Case 1: Use const away to avoid error.		*" << endl;
	cout << "*	Case 2: Data is const but pointer is not.	*" << endl;
	cout << "*	Case 3: Pointer is const but data is not.	*" << endl;
	cout << "*	Case 4: Both data and pointer are const.	*" << endl;
	cout << "***************Const Instructions***************" << endl<<endl;

	// initialization
	Options_Num = 4;
	string s = "0";

	// keep doing until return a number string (1 to 4)
	while (~isdigit_fn(User_input(s)));

	/* case 1 : cant resign i to an value cuz it's const, i = 6; gives error.
				we can use const_cast<> which is a hacky way but works */
	const int i = 9;
	//static_cast<const int&> (j)= 22; const err bczu cant modify j with static 
	const_cast<int&> (i) = 22;
	
	/* case 2 :data is const, pt is not; it's same if write in this way: int const * p1 = &i;*/
	const int* p1 = &i;
	int const* p2 = &i;

	/*case 3 :pt is const, data is not */
	int j = 10;
	int* const p3 = &j;
	*p3 = 7;

	/*case 4: data and pointer are both const*/
	const int k = 11;
	const int* const p4 = &k;

	switch (case_num) {
		
		case 1:
			cout << i << endl;
			break;
		case 2:
			cout << "pointer is " << *p1 << " and data is " << i << endl;
			cout << "pointer is " << *p2 << " and data is " << i << endl;
			p1++;
			cout << "Increasing pointer by one " << p1 << " and data is " << &i << endl;
			break;
		case 3:
			cout << "pointer value is " << *p3 << " and data is " << j << endl;
			cout << "pointer addr is " << p3 << " and data addr is " << &j << endl;
			j++;
			cout << "Increasing data by 1, the pointer addr is " << p3 << " and data addr " << &j 
				 << " corresponding to data  "<<j << endl;
			break;
		case 4:
			cout << "pointer is " << *p4 << " and data is " << k << endl;
			// cannot k++ or p4++ bcuz both pt and data is const
			break;
		default:
			cout << "Other Conditions!" << endl;
	}
	return 0;
}