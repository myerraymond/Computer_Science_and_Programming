//#18035406  Myer Raymond
#include <iostream>
using namespace std;

void binary();
void decimal();
string x;

int main () {
  cout << "Enter a number: ";
  cin >> x;
binary();
decimal();
return 0;

}


void binary(){
  cout << "Binary to Decimal\n";
}

void decimal(){
  cout << "Decimal to Binary\n";
}
