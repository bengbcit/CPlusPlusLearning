#include <iostream>
using namespace std;

int main(){
  char c;
  int i;
  double d, bucky[10];
  float f;
  //sizeof(bucky): ret numbers of bytes the array occupied
  //sizeof(bucky[0]): ret numbers of bytes 1 elelment occupied
  double div = sizeof(bucky)/ sizeof(bucky[0]);

  cout<<"The size of char is " << sizeof(c) << endl;
  cout<<"The size of int is " << sizeof(i) << endl;
  cout<<"The size of double is " << sizeof(d) << endl;
  cout<<"The size of double bucky[10] is " << sizeof(bucky) << endl;
  cout<<"To get size of double array: bucky[10] / bucky[0] = "<< div <<endl;
  cout<<"The size of float is " << sizeof(f) << endl;

  return 0;
}
