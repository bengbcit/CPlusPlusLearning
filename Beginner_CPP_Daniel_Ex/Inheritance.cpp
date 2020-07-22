#include <iostream>
using namespace std;
// when inheriance, you can public and protected but not private
class Chef{
  public:
    void makeChicken(){
      cout<< "Make Chicken \n";
    }
    void makeSalad(){
      cout<< "Make Salad \n";
    }
    void makeSpecialDish(){
      cout<< "Make Special BBQ Ribs \n";
    }
};

//using inheritance present an italian chef
class ItalianChef: public Chef{
  public: // without public it wont work
    // get extend on it
    void makePasta(){
      cout<< "Make Pasta \n";
    }
    void makeSpecialDish(){
      cout<< "Make Special Pizza \n";
    }
};

int main(){
  Chef chef;
  chef.makeChicken();
  chef.makeSpecialDish();
  cout<<endl;
  ItalianChef italianChef;
  italianChef.makeChicken();
  italianChef.makePasta();
  italianChef.makeSpecialDish();
  return 0;
}
