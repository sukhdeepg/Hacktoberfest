// A number guessing game
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
  srand(time(0));
  
  int num =  rand() % 100 + 1;
  int tries = 0, guess;

  do{
    cout << "Guess a Number: ";
    cin >> guess;
    tries++;
    
    if (guess > num)
      cout << "Too High!";
    if (guess < num)
      cout << "Too low!";
    
  }while(guess != num)

    cout << "You win! It took " << tries << "tries!" << endl;
  return 0;
}
