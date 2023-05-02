#include <iostream>
#include <cstdlib>
using namespace std;

int RandomInt (int first, int last);

int main () {
  int chance, count, i;

  srand(100);

  cout << "This event has a 56% chance of occuring. \n\n";
  count = 0;
  for(i = 0; i < 100; i++) {
    chance = RandomInt(1,100);
    if(chance <= 56) {
      count++;
    }
  }
  cout << "The event occurred " << count << " times. \n";
}

int RandomInt(int first, int last) {
  int diff;
  diff = (last - first) + 1;
  return rand() % diff + first;
}
