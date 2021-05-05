#include <iostream>
#include<array>
using namespace std;
// Pointer: poiner is refer to a variable's mem addr, so it cant be assign without mem addr.
// eg: int* ptr; *ptr =7; this is wrong, you need to 
//		int v; int* ptr = &v; *ptr =7; this is right way 

// Introduction Pointer
/*

void pointer_math(){
  int bucky[5];
  int *bp0 = &bucky[0];
  int *bp1 = &bucky[1];
  int *bp2 = &bucky[2];

  cout<< "bp0 is at " << bp0 << endl;
  cout<< "bp1 is at " << bp1 << endl;
  cout<< "bp2 is at " << bp2 << endl;
  // +2 depends on variable type, int (size 4) or double (8) or char (1)
  cout<< "bp0 now is at " << bp0+2 << endl;

}
int main(){
  int age = 19;
  double gpa = 3.1415;
  string name = "Daniel";

  // print out memery address,(ie:pointer in C++) stored (hex number)
  cout<<"Age: "<< &age << endl;
  cout<<"gpa: "<< &gpa << endl;
  cout<<"Name: "<< &name << endl;

  // store mem addr to pointers
  int *pAge = &age;
  double *pGpa = &gpa;
  string *pName = &name;

  // in this case: pAge = *&gpa
  cout<<"Age address: "<< pAge <<". The stored variable is " << *pAge<< endl;
  cout<<"gpa address: "<< pGpa <<". The stored variable is " << *pGpa<< endl;
  cout<<"Name address: "<< pName <<". The stored variable is " << *pName<< endl;

  pointer_math();
  return 0;
}

*/

// Pointer with Arrays
/*

int main() {

	int numArray[5] = { 5, 33,2, 3,1 };
	// INTERESTING Part : Same Result
	cout << numArray << endl;
	cout << &numArray[0] << endl;

	cout << *(numArray + 2) << endl;
	cout << numArray[2] << endl;
}

*/

// Using pointer to return multiple values
/* Below Fn only get minimum*/
int getMin(int nArrary[], int size) {
	int min = nArrary[0];
	for (int i = 0; i < size;i++ ) {
		if (nArrary[i] < min)
			min = nArrary[i];
	}
	return min;
}
// **** get min and Max 
void getMinandMax(int arry[],int size, int* min, int* max) {
	for (int i = 0; i < size;i++) {
		if (arry[i] < *min)
			*min = arry[i];
		if (arry[i] > *max)
			*max = arry[i];
	}
}
int main() {

	int numArray[5] = { 5, 33,-2, 3,1 };
	int arrySize = sizeof(numArray) / sizeof(numArray[0]);
	// only return 1 values
	cout << "Min is " << getMin(numArray, arrySize) << endl;
	// use pointers to return muti values
	int Min = numArray[0];
	int Max = numArray[0];
	getMinandMax(numArray, arrySize, &Min, &Max);
	cout <<"Minimum is "<< Min << " and Maximum is " << Max << endl;
}

