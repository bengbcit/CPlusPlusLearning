#include <iostream>
using namespace std;

void printBookOP();
void printTediousBook_1();

//Data Container: Small passvie objects that carry public data and have no or few basic member fns
struct Person_struct {
    // public members
    string name; 
    unsigned age;
};

//Complex Data Structure: Bigger active objects that carry private data, interfaced through public member fns
class Person {
    // private members
    string name_;
    unsigned age_;  // Encapsulation for OOP; that's why we put age_ in private not public
public:
    // Implementation: private or public variables
    // Interfaces: fn in real world
    unsigned age() const { return age_; };  // getter / accessor ---only fetch data (usually const fn)
    void set_age(unsigned a) { age_ = a; }  // setter / mutator  ---can change data (avoid using too many setter/getter)
};

int main() {

    Person_struct PT;
    PT.age = 10;
    cout << PT.age<<endl;

    Person P;
    cout << P.age()<< endl;

    // Good thing for Set fn: ez to do rule check eg if(...)
    P.set_age(33);
    cout << P.age()<< endl;

    // Create Book constructor egs
    printBookOP();
    printTediousBook_1();
    return 0;
}

class Book {
public:
    string title;
    string author;
    int pages;

    Book(string aTitle, string aAuthor, int aPages) {
        title = aTitle;
        author = aAuthor;
        pages = aPages;
    }

    // multiple constructors
    Book() {
        title = "no title";
        author = "no author";
        pages = 0;
    };
};
// Constructor eg
void printBookOP() {
    Book book1("Harry Potter", "JK Rowling", 500);
    // what if we want to update?
    // Book.title = "WHatever.."
    cout << "The book title is " << book1.title << " and author is " << book1.author
        << ". The book has " << book1.pages << " pages. \n";

    Book book2("Lord of the Rings", "Tolkein", 700);
    cout << "The book title is " << book2.title << " and author is " << book2.author
        << ". The book has " << book2.pages << " pages. \n";

    Book book3;
    cout << "The book title is " << book3.title << " and author is " << book3.author
        << ". The book has " << book3.pages << " pages. \n";
}

/*  tedious way to do */
class Book_1 {
  public:
    string title;
    string author;
    int pages;
    Book_1 (string name){cout << name <<endl;}
};

// tedious way to list all book attributes
void printTediousBook_1(){
  Book_1 book1("Harry Potter");
  book1.title = "Harry Potter";
  book1.author = "JK Rowling";
  book1.pages = 500;
  cout<<"The book title is "<<book1.title <<" and author is "<<book1.author
      <<". The book has "<<book1.pages<<" pages. \n";

  Book_1 book2("Lord of the Rings");
  book2.title = "Lord of the Rings";
  book2.author = "Tolkein";
  book2.pages = 700;
  cout<<"The book title is "<<book2.title <<" and author is "<<book2.author
      <<". The book has "<<book2.pages<<" pages. \n";
}