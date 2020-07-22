#include <iostream>
using namespace std;

class Movie {
  // private: code(rating) works INSIDE "Movie" class, main fn not work
  private:
    string rating;
  public:
    string title;
    string director;

    Movie(string aTitle, string aDirector, string aRating){
      title = aTitle;
      director = aDirector;
      setRating(aRating);
    }
    // use for set up some rules, dont wanna user break
    void setRating (string aRating){
      if(aRating == "G" ||aRating == "PG" || aRating == "PG-13" || aRating == "R" || aRating == "NR" )
        rating = aRating;
      else
        rating = "NR";
    }

    string getRating(){
      return rating;
    }
};

int main() {
  Movie avengers ( "The Avengers", "Joss Whedon","PG-13");

  cout<<"The movie rating is "<<avengers.getRating()<<". \n";

  // avengers.rating not work anymore bcz private: no one can access directly,
  // if it changes like below, has to use fn call that class
  avengers.setRating("whatever");
  cout<<"The movie rating is "<<avengers.getRating()<<". \n";

  return 0;
}
