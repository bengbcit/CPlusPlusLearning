#include <iostream>
using namespace std;

string getDayofWeek (int dayNum){
  string dayName;
  switch (dayNum) {
    case 0:
      dayName = "Sunday";
      break; // without break, it will continue checking below cases.
    case 1:
      dayName = "Monday";
      break;
    case 2:
      dayName = "Tuesday";
      break;
    case 3:
      dayName = "Wednesday";
      break;
    case 4:
      dayName = "Thursday";
      break;
    case 5:
      dayName = "Friday";
      break;
    case 6:
      dayName = "Saturday";
      break;
    default:
      dayName = "Invalid Day Number!";
  }

  return dayName;
}

int main() {
  int dayN;
  cout << "Enter a number between 0 to 6: ";
  cin >> dayN;
  // getline(cin,dayN) same thing 
  cout<<"Day of week is "<< getDayofWeek(dayN);
  return 0;
}
