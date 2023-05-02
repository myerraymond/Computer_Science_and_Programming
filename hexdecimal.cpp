#include <iostream>
using namespace std;

int value;
char chr;

int main() {
  cout << "Enter  a 2-digit hexadecimal number ";
  cin >> hex >> value;
  chr = value;
  cout << "Value is " << value << endl;
  cout << "Character is " << chr << endl;
  cout << "Hexadecimal value is ";
  cout << hex << uppercase << value << endl;
}
