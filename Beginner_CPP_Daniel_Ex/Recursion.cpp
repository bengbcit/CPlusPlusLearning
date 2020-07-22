#include <iostream>
using namespace std;

//recursion: fn call itself;
int factorialFinder(int x){
  // eg of recursion basecase
  if(x==1)
    return 1; 
  else
    return x*factorialFinder(x-1);
}
// sometimes cuz computer crash, so need a basecase
// void bucky(){
//   cout<<"whatever";
//   bucky();
// }

int main(){

  cout<< factorialFinder(5)<< endl;
}
