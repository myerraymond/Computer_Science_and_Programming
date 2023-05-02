#include <iostream>
using namespace std;

int x;
int *ptr;

int main() {
  ptr = &x;
  *ptr = 12;
  cout << "The value is " << x << endl;
}
