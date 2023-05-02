#include <iostream>
using namespace std;

unsigned char value;
char value1;

int main() {
  value = 0xFF;
  value1 = 0xFA;
  cout << "Value is " << (int)value << endl;
  cout << "Value1 is " << (int)value1 << endl;
}
