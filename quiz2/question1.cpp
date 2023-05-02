#include <iostream>
using namespace std;

void adding(int v1, int v2);
int r, s;
int v1, v2;
int main() {
  cout << "Enter the first value ";
  cin >> r;
  cout << "Enter the second value ";
  cin >> s;
  adding(r, s);
  cout << "The results are " << r;
  cout << " and " << s << endl;
}

void adding(int v1, int v2) {
  r = r + 2;
  s = s + 3;
}
