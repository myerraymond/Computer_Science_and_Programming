#include <iostream>
using namespace std;

class date_class {
public:
  int day, month, year;
  void setdate(int d, int m, int y);
  void displaydate();
};

date_class today;

int main() {
  int m;
  today.setdate(23, 11, 2019);
  today.displaydate();
  m = today.month;
  cout << "The month in this date is " << m << endl;
}

void date_class::setdate(int d, int m, int y) {
  day = d;
  month = m;
  year = y;
}

void date_class::displaydate() {
  cout << day << "/" << month << "/" << year << endl;
}
