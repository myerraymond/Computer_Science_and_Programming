#include <iostream>
using namespace std;

void swop(int *ptr1, int *ptr2);

int main () {
  int a, b;
  a = 3;
  b = 5;
  cout << "a is " << a << " and b is " << b << endl;
  swop(&a, &b);
  cout << "a is " << a << " and b is " << b << endl;
}

void swop(int *ptr1, int *ptr2) {
// swop the contents of ptr1 and ptr2
  int temp;
  temp = *ptr1;
  *ptr1 = *ptr2;
  *ptr2 = temp;
}
