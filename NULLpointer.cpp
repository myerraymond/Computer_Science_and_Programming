#include <iostream>
using namespace std;

int *ptr;

int main () {
  ptr = NULL;
  cout << "The value of the pointer is " << ptr << endl;
  cout << "The data at the address " << ptr << " is ";
  cout << *ptr << endl;
}
