#include <iostream>
using namespace std;

int linearsearch(int first, int last, int search);
int loadrandomdata();

int id[500];
int total;      //number of ID numbers in the array
int search;     //the ID number that we are looking for
int indx;      // inder of the ID number we are looking for

int main() {
  total = loadrandomdata();
  cout << "Enter an id to search for ";
  cin >> search;
  indx = linearsearch(0, total -1, search);
  if(indx == -1) {
    cout << "The id " << search << " is not in the array.\n";
  } else {
    cout << "The id " << search << " is at index " << indx << endl;
  }
}

int linesearch(int first, int last, int search) {
  //first = first index, last = last index
  int i;
  indx = -1;
  for (i = first; i <=last; i++){
    if (search == id[i]) {
      indx = i;
    }
  }
  return indx;
}

int loadrandomdata() {
  int num;
  // load the data randomly - feel free to use more numbers
  num = 6;
  id[0] = 846;
  id[1] = 109;
  id[2] = 528;
  id[3] = 761;
  id[4] = 391;
  id[5] = 220;
  return num;
}
