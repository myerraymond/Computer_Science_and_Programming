#include <iostream>
using namespace std;

int decimal, rem, binary, p;
int main() {
  cin >> decimal;
  p = 1;
  while(decimal != 0){
    rem = decimal % 2;
    binary += (rem * p);
    decimal = (decimal / 2);
    p *= 10;
  }
cout << binary << endl;
return 0;
}
