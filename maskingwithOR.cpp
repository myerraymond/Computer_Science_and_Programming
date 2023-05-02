#include <iostream>
using namespace std;

int x, mask, result;

int main() {
  x = 0x42;
  mask = 0x20;
  result = x | mask;
  cout << "x is " << (char)x;
  cout << " and result is " << (char)result << endl;
}
