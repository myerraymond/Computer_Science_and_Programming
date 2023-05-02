#include <iostream>
using namespace std;

int value;
int i;
int main () {
  i = 12;

  value = 0xab; //this means load with hexadecimal value 41
  cout << "Value is " << (int)value << endl;
}
