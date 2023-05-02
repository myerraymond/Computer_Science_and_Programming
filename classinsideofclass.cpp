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

class birthday_class {
private:
  string name;
  date_class birthday;
public:
  void loaddata(string n, int d, int m, int y);
  void display();
  bool compare(birthday_class other);
};

birthday_class birthday1, birthday2;

int main() {
  birthday1.loaddata("Madonna", 16, 8, 1958);
  birthday1.display();
  birthday2.loaddata("John Tolkien", 3, 1, 1892);
  birthday2.display();
  if (birthday1.compare(birthday2) == true) {
    cout << "They have the same birthday\n";
  } else {
    cout << "They do not have the same birthday\n";
  }
}

//--------------- methods for the date_class ------------
void date_class::setdate(int d, int m, int y) {
  day = d;
  month = m;
  year = y;
}

void date_class::displaydate() {
  cout << day << "/" << month << "/" << year << endl;
}

//--------------- methods for the birthday_class ------------
void birthday_class::loaddata(string n, int d, int m, int y) {
  name = n;
  birthday.setdate(d, m, y);
}

void birthday_class::display() {
  cout << name << " birthday on ";
  birthday.displaydate();
}

bool birthday_class::compare(birthday_class other) {
  int day1, day2, month1, month2;
// people have the same birthday if day and month are the same
  day1 = birthday.getday();
  month1 = birthday.getmonth();
  day2 = other.birthday.getday();
  month2 = other.birthday.getmonth();
  if ((day1 == day2) && (month1 == month2)) {
    return true;
  }
  return false;
}
