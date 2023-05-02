#include <iostream>
#include <stack>
using namespace std;

stack<int> digits;

int main() {
  int num;
  cout << "Enter a decimal number ";
  cin >> num;
  while(num >  0) {
    digits.push(num % 2);
    num = num/2;
  }
  cout << "The binary number is ";
  while(digits.empty() != true) {
    cout << digits.top();
    digits.pop();
  }
  cout << endl;
}
