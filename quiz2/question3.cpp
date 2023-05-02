#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

class student_class {
private:
  int id;
  string degree;  // BA, BCom, BSc
public:
  void loaddata();
  void display();
  bool is_BSc();
};

void enterdata();

vector<float> idnum;
vector<string> degreev;
student_class student[50];
int g, i, total;

int main() {
  enterdata();
     for (i = 0; i < 1; i++) {
        student[i].display();
      }
    for(i = 0; i < 1; i++) {
      student[i].is_BSc();
    }
}

void enterdata(){
  student_class  temp;
  while(g >= 0){
    temp.loaddata();
  }
}

//----methods

void student_class::loaddata() {
  cout << "Insert the student id (-1 to stop): ";
  cin >> id;
  cout << "Insert the students degree: ";
  cin >> degree;
  degreev.push_back(degree);
  idnum.push_back(id);
    while(id >= 0) {
      cout << "Insert the student id (-1 to stop): ";
      cin >> id;
      g = id;
        if(id >= 0){
          idnum.push_back(id);
          cout << "Insert the students degree: ";
          cin >> degree;
          degreev.push_back(degree);
      }
    }
  }

void student_class::display() {
  int total, i;
  total = idnum.size();
  for(i = 0; i < total;i++){
    cout << "\nStudent with the id: " << idnum[i] << endl;
    cout << "Is studying: " << degreev[i] << endl << endl;
  }
}

bool student_class::is_BSc() {
  int total, k;
  total = idnum.size();
  for(k = 0; k < total;k++){
    if(degreev[i] == "BSc"){
      cout << "Student with id: " << idnum[k];
      cout << " is studying a BSc!! (the best degree...no bias)" << endl << endl;
    }
  }
  return true;
}
