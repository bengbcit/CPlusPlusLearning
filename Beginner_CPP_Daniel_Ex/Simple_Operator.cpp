#include <iostream>
using namespace std;
int main() {
  int num1, num2, result = 0;
  char op;

  cout<< "Hello Kaito!"<<endl;
  cout << "Please enter first number: ";
  cin >> num1;
  cout << "and enter an operator(+, - , * ,/): ";
  cin >> op;
  cout << "Enter a second number: ";
  cin >> num2;

  if (op=='+'){
    result = num1 + num2;
  } else if (op=='-') {
    result = num1 - num2;
  } else if (op=='*') {
    result = num1 * num2;
  } else if (op=='/') {
    result = num1 / num2;
  } else{
    cout << "Invalid operator \n";
  }
  cout <<"Your result is "<< result <<"!" <<'\n';
  return 0;
}
