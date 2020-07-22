#include <iostream>
using namespace std;

template<typename Number>
auto sum2(const Number& number) {
	return number;
}
template<typename Number,typename ...Others>
auto sum2(const Number& number, Others ... rest) {
	return number + sum2(rest...);

}
/***************************/
template <typename Output>
void Outputter(const Output& out) {
	cout << out << endl;
}
template <typename Output,typename...Others>
void Outputter(const Output& out, Others...rest) {
	cout << out << endl; // here have to call current one which is same as top
	Outputter(rest...);  // then make a function call here
}
int main() {
	cout << sum2(1, 2, 3, 4, 5) << endl;
	cout << sum2(1.2, 2.2, 3.2, 4.2, 5.2) << endl;
	Outputter(1, 3, 5, 7, 9);
	Outputter("John","Daniel","Aoi");
}