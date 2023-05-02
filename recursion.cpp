#include <iostream>
using namespace std;

int factorial (int x) {
  int result;
  if(x==0) {
    return 1;
  }
  cout << x << ", ";
  result = x * factorial(x-1);
  return result;
}

int main() {
  factorial(3);
}
