#include <iostream>
using namespace std;

int x, mask, result;

int main() {
  x = 12;
  mask = 4;
  result = x & mask;
  if (result != 0){
    cout << "The 3rd bit is set to one\n";
  }
}
