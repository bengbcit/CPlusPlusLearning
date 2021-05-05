#include<iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;

/* Question 1*/
// Ex1: way 1 use protected variables
class shape {
protected:
	int width;
	int height;
public:
	shape(int w, int h)
		:width(w), height(h) {}

	virtual int area() {
		return width * height;
	}
class triangle :public shape {
public:
	triangle(int width, int height) :shape(width, height) {};
	int area() {
		return width * height / 2;
	}
};

class rectangle :public shape {
public:
	rectangle(int width, int height) :shape(width, height) {};
	int area() {
		return width * height;
	}
};
};
 Ex1: way 2 use friend class
class shape {
private:
	int width;
	int height;
	friend class triangle;
	friend class rectangle;
public:
	shape(int w, int h) {
		width = w;
		height = h;
	}
};
class triangle{
public:
	int area(shape s) {
		return s.width * s.height/2;
	}	
};
class rectangle{
public:
	int area(shape s) {
		return s.width * s.height;
	}
};

int main() {
	// for way 1
	/*triangle t = triangle(15, 20);
	rectangle r = rectangle(10, 10);
	cout << t.area() << endl;
	cout << r.area() << endl;*/

	// for way 2
	shape s1 = shape(15,10);  
	shape s2 = shape(10, 10);
	triangle t;
	rectangle r;
	cout<<"Triangle Area: "<<t.area(s1)<<endl;
	cout<< "Rectangle Area: " << r.area(s2) << endl;
	return 0;
}

/* Question 2*/
//class mother {
//public:
//	 void display() {
//		cout << "Message print from mother class." << endl;
//	}
//};
//
//class daughter: public mother{
//public:
//	string message;
//	void display() {
//		cout << "Message print from daughter class." << endl;
//	}
//};
//int main() {
//
//	/*cout << "Enter message for daughter class." << endl;
//	string stringD;
//	cin >> stringD;*/
//
//	daughter d;
//	d.display();
//
//	mother m;
//	m.display();
//}

/* Question 3*/
class Animal {
protected:
	string Name;
	int Age;
public:
	Animal(string name, int age){
		Name = name;
		Age = age;
	}
	virtual void set_value() { // virtual can deep search inside subclass to find most derived fn (if with same name) 
		cout << "Name is " << Name << " and age is " << Age<<endl;
	}
};

class Zebra : public Animal {
public:
	string Origin;
	// create constructor in order to using base class variables or fns
	Zebra(string name, int age, string origin)
		:Animal(name,age)
	{
		Origin = origin;
	}
	void set_value() {
		cout << "Name is " << Name << " and age is " << Age<<endl;
		cout << "It's from " << Origin << endl;
	}
};

class Dolphin : public Animal {
public:
	string Date;
	// create constructor in order to using base class variables or fns
	Dolphin(string name, int age, string date)
		:Animal(name, age)
	{
		Date = date;
	}
	void set_value() {
		cout << "Name is " << Name << " and age is " << Age << endl;
		cout << "Get it by " << Date << endl;
	}
};

int main() {
	
	Animal a = Animal("Dog",4);
	Zebra z = Zebra("Zebra", 3, "Sourth Africa");
	Dolphin d = Dolphin("Dolphin", 5, "Apr 20");

	a.set_value();
	// this will not get the correct result
	// way 1
	/*z.set_value();
	d.set_value();*/
	// way2 :  pointer of base class can hold derived class reference
	Animal* a1 = &z;
	Animal* a2 = &d;
	a1->set_value();
	a2->set_value();
	return 0;
}

/* Practise Questions: https://www.cs.purdue.edu/homes/bxd/CandC++/      *****/
/* Module 1  C++ class exercises. Partial codes */
//// #1
//class ZooAnimal
//{
//private:
//    char* name;
//    int cageNumber;
//    int weightDate;
//    int weight;
//public:
//    void Destroy(); // destroy function
//    char* reptName();
//    int daysSinceLastWeighed(int today);
//    void Create(char* , int , int , int ) {}
//};
//
//// #2 
//void ZooAnimal::Destroy()
//{
//    delete[] name;
//}
//
//// -------- member function to return the animal's name
//char* ZooAnimal::reptName()
//{
//    return name;
//}
//
//// -------- member function to return the number of days
//// -------- since the animal was last weighed
//int ZooAnimal::daysSinceLastWeighed(int today)
//{
//    int startday, thisday;
//    thisday = today / 100 * 30 + today - today / 100 * 100;
//    startday = weightDate / 100 * 30 + weightDate - weightDate / 100 * 100;
//    if (thisday < startday)
//        thisday += 360;
//    return (thisday - startday);
//}

/* Module 3 */
//#1
//class ZooAnimal
//{
//private:
//    char* name;
//    int cageNumber;
//    int weightDate;
//    int weight;
//public:
//    ZooAnimal(char* n, int c, int d, int w) // constructor function
//    {
//        // Remember this 2 lines!!!
//        char *name = new char[20];
//        strcpy(name, n);
//
//        cageNumber = c;
//        weightDate = d;
//        weight = w;
//    }
//    ~ZooAnimal(); // destructor function
//    void changeWeight(int pounds);
//    char* reptName();
//    int reptWeight();
//    int daysSinceLastWeighed(int today);
//};
//#3
//class ZooAnimal
//{
//private:
//    char* name;
//    int cageNumber;
//    int weightDate;
//    int weight;
//public:
//    ZooAnimal(char*, int, int, int); // constructor function
//    operator int(); // member conversion function
//    inline ~ZooAnimal() {}; // destructor function
//    void changeWeight(int pounds);
//    char* reptName();
//    int reptWeight();
//    int daysSinceLastWeighed(int today);
//};
//ZooAnimal::operator int() { return cageNumber; }

/* Module 4 */
//#1
//class ZooAnimal
//{
//private:
//    char* name;
//    int cageNumber;
//    static int oldestWeightDate;
//    int weightDate;
//    int weight;
//public:
//    ZooAnimal(char*, int, int, int); // constructor function
//    void changeWeight(int pounds);
//    static void changeOldestWeightDate(int date);
//    char* reptName();
//    int reptWeight();
//    int daysSinceLastWeighed(int today);
//};
//int ZooAnimal::oldestWeightDate; //setter of a var , outside class
//
//void ZooAnimal::changeOldestWeightDate(int date) {
//    oldestWeightDate = date;
//}

class A {
public:
	static int x;
	// way 1
	/*A() { x++; }
	~A() { x--; } */

	//way 2:  overload new operator to reduces stack using, more dynamic use
	A() { }
	~A() { }

	void* operator new(size_t sz) { // new has been redefinated
		 x++;
	}
	/*void operator delete(void* sz) {
		x--;
	}*/
};
int A::x = 0;

int main() {
	A a, b;			// local - > stack 
	A c, d, e;

	// dynamic in c style allocate mem, doesn't call constructor , ie ctor,thus the cout will be 5
	//A* ptr = (A*)malloc(sizeof(A));

	// way 1:
	//A* ptr = new A; // will call c tor, so cout will be 6
	// delete ptr;	// call the destructor , so cout will be 6-1 = 5 now

	//way 2:
	A* ptr = new A;
	A* ptr2 = new A;
	/*delete ptr;
	delete ptr2;*/
	cout << A::x << endl;
}
