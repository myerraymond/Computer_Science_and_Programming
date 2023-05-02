#include <iostream>
using namespace std;
int k;
int *ptr;

int main() {
  k = 17;
  ptr = &k;
  cout << "The value in k is " << k << endl;
  cout << "The address of k is " << ptr << endl;
  cout << "The data at the address " << ptr << " is ";
  cout << *ptr << endl;
}
