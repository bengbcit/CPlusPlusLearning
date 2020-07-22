#include <iostream>
using namespace std;

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

  // store a pointer var in *pAge
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
