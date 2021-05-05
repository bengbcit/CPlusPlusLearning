#include<iostream>
#include<stack> // stack from standard template library(STL)
using namespace std;

/*introduction of stack*/
int main() {
	// empty, size, push , pop, top
	stack<int> numberStack;
	//numberStack.push(9);
	//numberStack.push(19);
	//numberStack.push(29);
	//numberStack.pop();

	if (numberStack.empty())
		cout << "Stack is empty" << endl;
	else
		cout << "Stack is not empty" << endl;
	cout << "Stack size is " << numberStack.size() << endl;

	while (!numberStack.empty()) {
		cout << "Top of stack is " << numberStack.top() << endl;
		numberStack.pop();
	}
	
	return 0;
}

/*string reversal using stack*/
// array in c/c++ always pass by reference, so char c[] is same as char *c
// void Reverse(char c[], int sizeStr) { 
//void Reverse(char* c, int sizeStr) {
//	stack<char> S;
//	for (int i = 0; i < sizeStr;i++) {S.push(c[i]);}	// push stack
//	for (int i = 0; i < sizeStr;i++) {	// pop stack
//		c[i] = S.top();					// overwrite the top of stack
//		S.pop();
//	}		
//}
//int main() {
//	// initial a char string with a fixed size
//	char c[50];
//	cout << "Please enter a string: ";
//	cin >> c;
//	Reverse(c, strlen(c));
//	cout << c;
//}

/*
  Evaluation Of postfix Expression in C++
  Input Postfix expression must be in a desired format.
  Operands must be integers and there should be space in between two operands.
  Only '+'  ,  '-'  , '*' and '/'  operators are expected.
*/
//#include<string>
//
//// Function to evaluate Postfix expression and return output
//int EvaluatePostfix(string expression);
//
//// Function to perform an operation and return output. 
//int PerformOperation(char operation, int operand1, int operand2);
//
//// Function to verify whether a character is operator symbol or not. 
//bool IsOperator(char C);
//
//// Function to verify whether a character is numeric digit. 
//bool IsNumericDigit(char C);
//
//int main()
//{
//	string expression;
//	cout << "Enter Postfix Expression \n";
//	getline(cin, expression);
//	int result = EvaluatePostfix(expression);
//	cout << "Output = " << result << "\n";
//}
//
//// Function to evaluate Postfix expression and return output
//int EvaluatePostfix(string expression)
//{
//	// Declaring a Stack from Standard template library in C++. 
//	stack<int> S;
//
//	for (int i = 0;i < expression.length();i++) {
//
//		// Scanning each character from left. 
//		// If character is a delimitter, move on. 
//		if (expression[i] == ' ' || expression[i] == ',') continue;
//
//		// If character is operator, pop two elements from stack, perform operation and push the result back. 
//		else if (IsOperator(expression[i])) {
//			// Pop two operands. 
//			int operand2 = S.top(); S.pop();
//			int operand1 = S.top(); S.pop();
//			// Perform operation
//			int result = PerformOperation(expression[i], operand1, operand2);
//			//Push back result of operation on stack. 
//			S.push(result);
//		}
//		else if (IsNumericDigit(expression[i])) {
//			// Extract the numeric operand from the string
//			// Keep incrementing i as long as you are getting a numeric digit. 
//			int operand = 0;
//			while (i < expression.length() && IsNumericDigit(expression[i])) {
//				// For a number with more than one digits, as we are scanning from left to right. 
//				// Everytime , we get a digit towards right, we can multiply current total in operand by 10 
//				// and add the new digit. 
//				operand = (operand * 10) + (expression[i] - '0');
//				i++;
//			}
//			// Finally, you will come out of while loop with i set to a non-numeric character or end of string
//			// decrement i because it will be incremented in increment section of loop once again. 
//			// We do not want to skip the non-numeric character by incrementing i twice. 
//			i--;
//
//			// Push operand on stack. 
//			S.push(operand);
//		}
//	}
//	// If expression is in correct format, Stack will finally have one element. This will be the output. 
//	return S.top();
//}
//
//// Function to verify whether a character is numeric digit. 
//bool IsNumericDigit(char C)
//{
//	if (C >= '0' && C <= '9') return true;
//	return false;
//}
//
//// Function to verify whether a character is operator symbol or not. 
//bool IsOperator(char C)
//{
//	if (C == '+' || C == '-' || C == '*' || C == '/')
//		return true;
//
//	return false;
//}
//
//// Function to perform an operation and return output. 
//int PerformOperation(char operation, int operand1, int operand2)
//{
//	if (operation == '+') return operand1 + operand2;
//	else if (operation == '-') return operand1 - operand2;
//	else if (operation == '*') return operand1 * operand2;
//	else if (operation == '/') return operand1 / operand2;
//
//	else cout << "Unexpected Error \n";
//	return -1;
//}