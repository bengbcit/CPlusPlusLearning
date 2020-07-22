#include <iostream>
using namespace std;

void printNumber (int x){
  cout<< "I'm print an interger "<< x << endl;
}
// overfloat the above funtion, run this fn now above one
void printNumber (float x){
  cout<< "now I'm print an float "<< x << endl;
}

int main(){
  int a = 54;
  float b = 3.1233;

  printNumber(a);
  printNumber(b);
  return 0;
}
