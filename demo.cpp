#include <iostream>
using namespace std;

class date_class {
private:
  int day, month, year;
public:
  void setdate(int d, int m, int y);
  int getday() { return day; }
  int getmonth() { return month; }
  int getyear() { return year; }
  void displaydate();
};

date_class newyear;
date_class *ptr;

int main() {
  ptr = &newyear;
  ptr->setdate(1, 1, 2018);
  newyear.displaydate();
}

//----------- methods for the date_class -------
void date_class::setdate(int d, int m, int y) {
  day = d;
  month = m;
  year = y;
}

void date_class::displaydate() {
  cout << day << "/" << month << "/" << year << endl;
}
