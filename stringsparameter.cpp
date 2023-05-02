#include <iostream>
using namespace std;

int counting(char *ptr);

string str;         // this is a c++ string

int main() {
  int total;
  char *strptr;
  str = "Goodbye";
  strptr = (char*) str.c_str();
  total = counting(strptr);
  cout << "The string has " << total << " characters.\n";
}

int counting(char *ptr) {
  int i;
  i = 0;
  while (ptr[i] != '\0') {
    i++;
  }
  return i;
}
