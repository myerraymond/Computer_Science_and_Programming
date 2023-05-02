#include <iostream>
using namespace std;

void loadalldata();
bool findpath(int here, int last);

class cave_class {
private:
  int numdoors;     // number of doors out of the cave
  int door[25];     // hold index number of cave behind the door
public:
  void loaddata(int n, int a, int b, int c, int d, int e);
  int getnumdoors() { return numdoors; }
  int getdoor(int i) { return door[i]; }
};

int cave_total;     //total number of caves
cave_class cave[500];   // assume a max of 500 cave_class

int main() {
  int first, last;
  bool pathexists;
  loadalldata();
  cout << "Enter the number of the first cave: ";
  cin >> first;
  cout << "Enter the number of the last cave: ";
  cin >> last;
  cout << endl;
  pathexists = findpath(first, last);
  cout << last << endl; //DEBUG cout
  if(pathexists == true) {
    cout << "A path was found from " << first;
    cout << " to " << last << endl << endl;
  } else {
    cout << "There is no path from " << first;
    cout << " to " << last << endl << endl;
  }
}


bool findpath(int here, int last) {
  int cavenum, num, i;
  bool success;
  if(here == last) {
    return true;      // the base case
  }
  num = cave[here].getnumdoors();
  cout << here << " -> ";   //debug cout
  for (i = 0; i < num; i++) {
    cavenum = cave[here].getdoor(i);
    success = findpath(cavenum, last);
    if (success == true) {
      return true;
    }
  }
  return false;
}

void loadalldata() {
  // load the data for all caves - change as needed
  // this data is for the example in the notes
  // -1 us used to indicate no door
  cave[0].loaddata(3, 4, 3, 2, -1, -1);
  cave[1].loaddata(0, -1, -1, -1, -1, -1);
  cave[2].loaddata(1, 1, -1, -1, -1, -1);
  cave[3].loaddata(2, 0, 2, -1, -1, -1);
  cave[4].loaddata(1, 3, -1, -1, -1, -1);
  cave_total = 5;
}

//----------methods for the cave_class-----------
void cave_class::loaddata(int n, int a, int b, int c, int d, int e){
  numdoors=n;
  door[0] = a;
  door[1] = b;
  door[2] = c;
  door[3] = d;
  door[4] = e;
}
