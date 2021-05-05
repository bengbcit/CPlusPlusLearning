#include<iostream>
#include<string>
using namespace std;

/*Encapsulation*/
//class Employee {	// user define
//private:
//	string Name;
//	string Company;
//	int Age;
//public:
//	// boolean check name alpha
//	bool IsNameAlpha(string name) {
//		for (int i = 0; i < name.size();i++) {
//			if (!isalpha(name[i]))
//				return false;
//		}
//		return true;
//	}
//	void setName(string name) { 
//		if (IsNameAlpha(name))
//			Name = name;
//	}
//	string getName() { return Name; }
//
//	// boolean check Company alphanumeric
//	bool IsCompanyAlphaNum(string company) {
//		for (int i = 0; i < company.size();i++) {
//			if (!(isalnum(company[i])))
//				return false;
//		}
//		return true;
//	}
//	void setCompanye(string company) { 
//		if (IsCompanyAlphaNum(company))
//			Company = company; 
//	}
//	string getCompany() { return Company; }
//
//	void setAge(int age) { 
//		if (age >=18)	// create a  validation rules for setter
//			Age = age; 
//	}
//	int getAge() { return Age; }
//
//	void introduce() { // constuctor does not has any return value, so no need void, int or string Employee()
//		cout << "Name - " << Name << endl;
//		cout << "Company - " << Company << endl;
//		cout << "Age - " << Age << endl;
//	}
//	Employee(string name, string company, int age) {
//		Name = name;
//		Company = company;
//		Age = age;
//	}
//};
//int main(){
//	// Employee employee1;								 //	not working, lost default constructor
//	Employee employee1 = Employee("Daniel", "Yaka", 33); // invoking your own constructor to make it work
//	employee1.introduce();
//
//	Employee employee2 = Employee("Pang", "Yaka", 33);
//	employee2.introduce();
//
//	employee1.setAge(15);
//	employee1.setName("Woha45"); // try woha
//	employee1.setCompanye("Boom2020");// try boom 20*
//	cout << employee1.getName() << " from "<<employee1.getCompany()<<" is " << employee1.getAge() << " years old" << endl;
//
//}


// Abstraction
//class AbstractEmployee {
//	virtual void askForPromotion()=0;  
//};
//class Employee:AbstractEmployee {	// user define
//private:
//	string Name;
//	string Company;
//	int Age;
//public:
//	// boolean check name alpha
//	bool IsNameAlpha(string name) {
//		for (int i = 0; i < name.size();i++) {
//			if (!isalpha(name[i]))
//				return false;
//		}
//		return true;
//	}
//	void setName(string name) {
//		if (IsNameAlpha(name))
//			Name = name;
//	}
//	string getName() { return Name; }
//
//	// boolean check Company alphanumeric
//	bool IsCompanyAlphaNum(string company) {
//		for (int i = 0; i < company.size();i++) {
//			if (!(isalnum(company[i])))
//				return false;
//		}
//		return true;
//	}
//	void setCompanye(string company) {
//		if (IsCompanyAlphaNum(company))
//			Company = company;
//	}
//	string getCompany() { return Company; }
//
//	void setAge(int age) {
//		if (age >= 18)	// create a  validation rules for setter
//			Age = age;
//	}
//	int getAge() { return Age; }
//
//	void introduce() { // constuctor does not has any return value, so no need void, int or string Employee()
//		cout << "Name - " << Name << endl;
//		cout << "Company - " << Company << endl;
//		cout << "Age - " << Age << endl;
//	}
//	Employee(string name, string company, int age) {
//		Name = name;
//		Company = company;
//		Age = age;
//	}
//	void askForPromotion() {
//		if (Age > 30)
//			cout << Name << " got promoted!" << endl;
//		else
//			cout << Name << ", sorry not this time!" << endl;
//	}
//};
//int main() {
//
//	Employee employee1 = Employee("Daniel", "Yaka", 33);
//
//	Employee employee2 = Employee("Pang", "Yaka", 15);
//
//
//	employee1.askForPromotion();
//	employee2.askForPromotion();
//}



 //Inheritance
/* *****************
class AbstractEmployee {
	virtual void askForPromotion() = 0;
};
class Employee :AbstractEmployee {	// user define
private:
	string Company;
	int Age;
protected:
	string Name;
public:
	// boolean check name alpha
	bool IsNameAlpha(string name) {
		for (int i = 0; i < name.size();i++) {
			if (!isalpha(name[i]))
				return false;
		}
		return true;
	}
	void setName(string name) {
		if (IsNameAlpha(name))
			Name = name;
	}
	string getName() { return Name; }

	// boolean check Company alphanumeric
	bool IsCompanyAlphaNum(string company) {
		for (int i = 0; i < company.size();i++) {
			if (!(isalnum(company[i])))
				return false;
		}
		return true;
	}
	void setCompanye(string company) {
		if (IsCompanyAlphaNum(company))
			Company = company;
	}
	string getCompany() { return Company; }

	void setAge(int age) {
		if (age >= 18)	// create a  validation rules for setter
			Age = age;
	}
	int getAge() { return Age; }

	void introduce() { // constuctor does not has any return value, so no need void, int or string Employee()
		cout << "Name - " << Name << endl;
		cout << "Company - " << Company << endl;
		cout << "Age - " << Age << endl;
	}
	Employee(string name, string company, int age) {
		Name = name;
		Company = company;
		Age = age;
	}
	void askForPromotion() {
		if (Age > 30)
			cout << Name << " got promoted!" << endl;
		else
			cout << Name << ", sorry not this time!" << endl;
	}
};

class Developer:public Employee { 

public:
	string FavProgLan;
	Developer (string name, string company, int age, string favprolan)
		:Employee(name, company,age)
	{
		FavProgLan = favprolan;
	}
	void FixBug() {
		cout << Name << " fixed bug using " << FavProgLan << endl;
	} 

};

class Teacher : public Employee {
public:
	string Subject;
	void prepareLesson() { cout <<Name << " is preparing " << Subject << " lesson" << endl; }
	Teacher(string name, string company, int age, string subject)
		:Employee(name, company , age)
	{
		Subject = subject;
	}
};
int main() {
	Developer d = Developer("Daniel", "Yaka", 33, "C++");
	//d.FixBug();
	//d.askForPromotion();
	Teacher t = Teacher("jack", "cool school", 35, "History");
	t.prepareLesson();
	t.askForPromotion();
}
***************** */

//polymorphism

class AbstractEmployee {
	virtual void askForPromotion() = 0;
};
class Employee:AbstractEmployee {	// user define
private:
	string Company;
	int Age;
protected:
	string Name;
public:
	// boolean check name alpha
	bool IsNameAlpha(string name) {
		for (int i = 0; i < name.size();i++) {
			if (!isalpha(name[i]))
				return false;
		}
		return true;
	}
	void setName(string name) {
		if (IsNameAlpha(name))
			Name = name;
	}
	string getName() { return Name; }

	// boolean check Company alphanumeric
	bool IsCompanyAlphaNum(string company) {
		for (int i = 0; i < company.size();i++) {
			if (!(isalnum(company[i])))
				return false;
		}
		return true;
	}
	void setCompanye(string company) {
		if (IsCompanyAlphaNum(company))
			Company = company;
	}
	string getCompany() { return Company; }

	void setAge(int age) {
		if (age >= 18)	// create a  validation rules for setter
			Age = age;
	}
	int getAge() { return Age; }

	void introduce() { // constuctor does not has any return value, so no need void, int or string Employee()
		cout << "Name - " << Name << endl;
		cout << "Company - " << Company << endl;
		cout << "Age - " << Age << endl;
	}
	Employee(string name, string company, int age) {
		Name = name;
		Company = company;
		Age = age;
	}
	void askForPromotion() {
		if (Age > 30)
			cout << Name << " got promoted!" << endl;
		else
			cout << Name << ", sorry not this time!" << endl;
	}
	virtual void work() {// allow overrides methods in subclass
		cout << Name << " is checking email, task backlog, performing task..." << endl;
	}
};

class Developer :public Employee {

public:
	string FavProgLan;
	Developer(string name, string company, int age, string favprolan)
		:Employee(name, company, age)
	{
		FavProgLan = favprolan;
	}
	void FixBug() {
		cout << Name << " fixed bug using " << FavProgLan << endl;
	}
	void work() {
		cout << Name << " is writing "<< FavProgLan << " code"<<endl;
	}
};

class Teacher : public Employee {
public:
	string Subject;
	void prepareLesson() { cout << Name << " is preparing " << Subject << " lesson" << endl; }
	Teacher(string name, string company, int age, string subject)
		:Employee(name, company, age)
	{
		Subject = subject;
	}
	void work() {
		cout << Name << " is teaching "<<Subject << endl;
	}
};
int main() { // The most common use of polymorphism is when a parent class reference is used to a child class object
	Developer d = Developer("Daniel", "Yaka", 33, "C++");
	Teacher t = Teacher("Jack", "cool school", 35, "History");
	// create pointer type 
	Employee* e1 = &d; // pointer of base class can hold derived class's reference
	Employee* e2 = &t;

	e1->work(); // want to access member using pointer
	e2->work();
}

