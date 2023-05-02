#include <iostream>
using namespace std;


int main() {
  int i, n ,f;
  cout << "Enter a positive integer value: ";
  cin >> n;
  f = 1;
  for (i = 0; n > 0; i--){
    f = f * n;
    n--;
  }
  cout << f << " is " << i << endl;
}
