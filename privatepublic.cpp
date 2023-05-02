#include <iostream>
using namespace std;

class date_class {
private:
  int day, month, year;
public:
  void setdate(int d, int m, int y);
  int getday();
  int getmonth();
  int getyear();
  void displaydate();
};

date_class today;

int main() {
  int m;
  today.setdate(23, 11, 2019);
  today.displaydate();
  m = today.getmonth();
  cout << "The month in this date is " << m << endl;
}

void date_class::setdate(int d, int m, int y) {
  day = d;
  month = m;
  year = y;
}
int date_class::getday(){
  return day;
}
int date_class::getmonth(){
  return month;
}
int date_class::getyear(){
  return year;
}

void date_class::displaydate() {
  cout << day << "/" << month << "/" << year << endl;
}
