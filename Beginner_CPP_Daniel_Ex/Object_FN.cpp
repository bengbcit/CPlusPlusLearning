#include <iostream>
using namespace std;

class student {
  public:
    string name;
    string major;
    double gpa;
    // obj 1
    student(string aName, string aMajor, double aGpa){
      name = aName;
      major = aMajor;
      gpa = aGpa;
    }
    // obj 2: ez to modify if there's changes in the future.eg:honor when >= 2.0
    bool StudentHasHonors(){
      if (gpa>=3.5){
        return true;
      }
      return false;
    }
  };

  int main(){

    student student1("Jim", "Business", 2.4);
    student student2("Pam", "Art", 3.6);

    cout<<student1.StudentHasHonors()<<endl;
    cout<<student2.StudentHasHonors()<<'\n';
    return 0;
  }
