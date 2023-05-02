#include <iostream>
#include <iomanip>
using namespace std;

unsigned int GetUnit();
double GetUniform();

unsigned int mw, mz; // must be global

int main () {
  float f;
  int count;
  char choice;
  // load mw and mz -these two numbers make up the seed
  mw = 35;
  mz = 478;
  count = 0;

  while (count < 50){
    f = (float) GetUniform();
    f = f * 100;
    cout << setprecision(2) << fixed << f << ", ";
    count++;
  }
  cout << endl;

  cout << "\n Do you want a new seed? (Y/N): ";
  cin >> choice;
  if ((choice == 'Y') || (choice == 'y')) {
    mw = 9367;
    mz = 872;
  } else {
    mw = 35;
    mz = 478;
  }
  count = 0;
  while (count < 50) {
    f = (float) GetUniform();
    f = f * 100;
    cout << setprecision(2) << f << ", ";
    count++;
  }
  cout << endl << endl;
}

unsigned int GetUint() {
  mz = 36969 * (mz & 65535) + (mz >> 16);
  mw = (mz << 16) + mw;
}

double GetUniform() {
  // returns a double in the open interval (0,1)
  unsigned int u;
  u = GetUint();
  return(u+1.0) * 2.328306435454494e-10;
}
