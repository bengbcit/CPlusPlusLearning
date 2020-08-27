#include <iostream>
#include <string>
using namespace std;

class Birthday
{
public:
	Birthday(int m, int d, int y);
	void printDate();
private:
	int month, day, year;
};
// way 1 constructor in public call private member variables
Birthday::Birthday(int m, int d, int y)
{
	month = m;
	day = d;
	year = y;
}

void Birthday::printDate() {
	cout << month << "/" << day << "/" << year << endl;
}

class People
{
public:
	People(string x, Birthday BO);
	void printInfo();
private:
	string name;
	Birthday dateOfBirth;
};
// way 2 constructor in public call private member variables
People::People(string x, Birthday BO)
	:name(x), dateOfBirth(BO)
{
}

void People::printInfo() {
	cout << name << " was born on ";
	dateOfBirth.printDate();
}

// composition class: using other class/object in current class
int main() {
	Birthday birthObj(9, 10, 1987);

	People buckyRoberts("Dan Practising", birthObj);
	buckyRoberts.printInfo();
}
