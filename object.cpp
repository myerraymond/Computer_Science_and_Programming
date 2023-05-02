#include <iostream>
using namespace std;

class date_class {
public:
  int day, month, year;
};

date_class a;

int main(){
  a.day = 23;
  a.month = 11;
  a.year = 2019;
  cout << a.day << "/" << a.month;
  cout << "/" << a.year << endl;

}
