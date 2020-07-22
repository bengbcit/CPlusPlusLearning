#include <iostream>
using namespace std;

void passbyValue (int x);
void passbyReference (int *x);
int main(){
  int betty = 13;
  int sandy = 13;

  passbyValue(betty);
  passbyReference(&sandy); // this fn  only take memory addr, so dont forget &

  cout<< "betty is now " << betty << endl;
  cout<< "sandy is now " << sandy << endl; // result should change 13 to 66

}
// value wont change, you passing a copy
void passbyValue (int x){
  x = 99;
}
// fn recieve a memory, needs a point arg
// value will change, you passing a variable address
void passbyReference (int *x){
  *x = 66;
}
