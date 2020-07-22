#include <iostream>
using namespace std;

int main() {
  int secretNum = 7;
  int guess;
  int guessCount = 0;
  int guessLimite = 3;
  bool outofGuesses = false;
  while ((secretNum != guess) && (!outofGuesses)){
    if (guessCount<guessLimite){
      cout<<"Enter a guess number(0 to 10): ";
      cin>> guess;
      guessCount++;
    } else{
      outofGuesses = true;
    }
  }
  if (outofGuesses)
    cout << "You Lose!" << '\n';
  else
    cout << "You win! \n";

 // simple do while loop
 // do {
 //   cout<<"Enter a guess number(0 to 10): ";
 //   cin>> guess;
 // } while(secretNum != guess);
 //  cout<< "You win!";

  return 0;
}
