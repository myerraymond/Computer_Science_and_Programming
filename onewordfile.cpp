#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
using namespace std;

fstream datafile;
string filename, word;
int memory[256];
int reg[16];
int pc, ir, i;
void masseymachine();
void readfile();


int main() {
  cout << "Enter the file name of the MASSEY machine code: ";
  cin >> filename;
  readfile();
  cout << endl << endl;
  masseymachine();
    //datafile.close();
}




void readfile() {
  datafile.open(filename.c_str(), fstream::in);
  if (datafile.is_open() == false) {
    cout << "ERROR: not able to open " << filename << endl;
  } else {
    cout << "Displaying all the code from " << filename << endl << endl;;
    pc = 0;
    i = 0;
    while (datafile >> word) {
      cout << "Memory[" << i << "] = ";
      pc++;
      cout << word << endl;
      cout << word.front() << endl;
      i++;
    }
    datafile.close();
}
}

void masseymachine() {
  datafile.open(filename.c_str(), fstream::in);
  pc = 0;
  if(datafile.is_open() == true){
    while(datafile >> word){
      cout << word;
      if(word[0] == '1'){
        cout << " = LOAD [1] WITH [23]";
        cout << endl;
      }
      if(word[0] == '2'){
        cout << " = LOAD [2] WITH [3]";
        cout << endl;
      }
      if(word[0] == '3'){
        cout << " = LOAD [1] WITH MEMORY [23]";
        cout << endl;
      }
      if(word[0] == '4'){
        cout << " = STORE [1] IN MEMORY [23]";
        cout << endl;
      }
      if(word[0] == '6'){
        cout << " = ADD [2+3] STORE IN [1]";
        cout << endl;
      }
      if(word[0] == '7'){
        cout << " = NEGATE [2] (10 x -1)";
        cout << endl;
      }
      if(word[0] == '8'){
        cout << " = SHIFT [1] RIGHT [3] TIMES";
        cout << endl;
      }
      if(word[0] == '9'){
        cout << " = SHIFT [1] LEFT [3] TIMES";
        cout << endl;
      }
      if(word[0] == 'A'){
        cout << " = AND [2+3] LOAD IN [1]";
        cout << endl;
      }
      if(word[0] == 'B'){
        cout << " = OR [2+3] LOAD IN [1]";
        cout << endl;
      }
      if(word[0] == 'C'){
        cout << " = XOR [2+3] LOAD IN [1]";
        cout << endl;
      }
      if(word[0] == 'D'){
        cout << " = JUMP TO [23] IF [1] = R0";
        cout << endl;
      }
      if(word[0] == 'E'){
        cout << " = HALT";
        cout << endl;
      }

    }
  }
}
