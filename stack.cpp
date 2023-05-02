#include <iostream>
#include <stack>
using namespace std;

void displayandempty();

stack<char> mystack;

int main() {
  char ch;
  while (ch != '?') {
    cout << "Enter a character (? to stop) ";
    cin >> ch;
    if(ch != '?') {
      mystack.push(ch);
    }
  }
  displayandempty();
}

void displayandempty() {
  char k;
  cout << "The data in reverse order:\n";
  while (mystack.empty() != true) {
    k = mystack.top();
    cout << k << ", ";
    mystack.pop();
  }
  cout << endl;
  cout << "All items have now been removed from the stack\n";
}
