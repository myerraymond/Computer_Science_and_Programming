#include <iostream>
#include <cstdlib>   //for system
#include <cstdio>   // for getchar
using namespace std;

int main () {
  cout << "Thi is page one of the display...\n\n";
  cout << "Some stuff on page one...\n\n\n\n\n";
  cout << "Press Enter to display page two";
  getchar();
  system("cls");
  cout << "This is page two of the display...\n\n";
  cout << "some stuff on page two...\n\n\n\n";
}
