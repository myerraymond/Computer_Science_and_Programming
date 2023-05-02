//18035406 MYER RAYMOND
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

fstream datafile;
string filename, word;
int memory[256];
int reg[16];
int pc, ir, i, temp, temp2, temp3, num, num2, f;
string a, b, c, temp1;
void masseymachine();
void readfile();
void hexdec();


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
      i++;
    }
    datafile.close();
}
}


void masseymachine() {
  datafile.open(filename.c_str(), fstream::in);
  pc = 0;
  i = 0;
  if(datafile.is_open() == true){
    while(datafile >> word){
      cout << word << "   ";
      pc++;
      temp = 0;
      num = 0;
      num2 = 0;

      if(word[0] == '1'){
        //cout << " = LOAD [1] WITH [23]";
        cout << "   R" << word[1] << " = " <<  word[2] << word[3];
        cout << "   PC = " << pc;
        cout << endl;
        a = word[1];
        b = word[2];
        c = word[3];
        num = stoi(a);
        num2 = stoi(b);
        temp = stoi(c);
        if(num2 == 0){
          num2 = 0;
        }
        temp2 = num2 + temp;
        reg[num] = temp2;

      }
      if(word[0] == '2'){
        //cout << " = LOAD [2] WITH [3]";
        cout << "   R" << word[2] << " = " << word[3];
        cout << "   PC = " << pc;
        cout << endl;
        a = word[2];
        b = word[3];
        num = stoi(a);
        num2 = stoi(b);
        reg[num] = num2;
      }
      if(word[0] == '3'){
        //cout << " = LOAD [1] WITH MEMORY [23]";
        cout << "   R" << word[1] << " stored into memory location = " << word[2] << word[3];
        cout << "   PC = " << pc;
        cout << endl;
        a = word[1];
        b = word[2];
        c = word[3];
        temp1 = b + c;
        num = stoi(a);
        num2 = stoi(temp1);
        reg[num] = memory[num2];
      }
      if(word[0] == '4'){
        //cout << " = STORE [1] IN MEMORY [23]";
        cout << "   Memory[" << word[2] << word[3] << "] =  R" << word[1];
        cout << "   PC = " << pc;
        cout << endl;
        a = word[1];
        b = word[2];
        c = word[3];
        temp1 = b + c;
        num = stoi(a);
        num2 = stoi(a+b);
        memory[num2] = reg[num];
      }
      if(word[0] == '6'){
        //cout << " = ADD [2+3] STORE IN [1]";
        cout << "   R" << word[1] << " = " << "R" << word[2] << " +  R" << word[3];
        cout << "   PC = " << pc;
        cout << endl;
        a = word[1];
        b = word[2];
        c = word[3];
        temp3 = stoi(a);
        temp = stoi(b);
        temp2 = stoi(c);
        num = temp + temp2;
        reg[temp3] = num;
      }
      if(word[0] == '7'){
        //cout << " = NEGATE [2] (10 x -1)";
        cout << "   R" << word[2] << " = *-1";
        cout << "   PC = " << pc;
        cout << endl;
        a = word[2];
        temp = stoi(a);
        temp2 = temp * -1;
        reg[temp] = temp2;

      }
      if(word[0] == '8'){
        //cout << " = SHIFT [1] RIGHT [3] TIMES";
        cout << "   R" << word[1] << " = shift right";
        cout << "   PC = " << pc;
        cout << endl;
        a = word[1];
        b = word[3];
        temp = stoi(a);
        temp2 = stoi(b);
        reg[temp] = temp>>temp2;
      }
      if(word[0] == '9'){
        //cout << " = SHIFT [1] LEFT [3] TIMES";
        cout << "   R" << word[1] << " = shift left";
        cout << "   PC = " << pc;
        cout << endl;
        a = word[1];
        b = word[3];
        temp = stoi(a);
        temp2 = stoi(b);
        reg[temp] = temp>>temp2;
      }
      if(word[0] == 'A'){
        //cout << " = AND [2+3] LOAD IN [1]";
        cout << "   R" << word[1] << " = 2 AND 3";
        cout << "   PC = " << pc;
        cout << endl;
        a = word[1];
        b = word[2];
        c = word[3];
        temp = stoi(a);
        temp2 = stoi(b);
        temp3 = stoi(c);
        num = temp2&temp3;
        reg[temp] = num;
      }
      if(word[0] == 'B'){
        //cout << " = OR [2+3] LOAD IN [1]";
        cout << "   R" << word[1] << " = 2 OR 3";
        cout << "   PC = " << pc;
        cout << endl;
        a = word[1];
        b = word[2];
        c = word[3];
        temp = stoi(a);
        temp2 = stoi(b);
        temp3 = stoi(c);
        num = temp2|temp3;
        reg[temp] = num;
      }
      if(word[0] == 'C'){
        //cout << " = XOR [2+3] LOAD IN [1]";
        cout << "   R" << word[1] << " = 2 XOR 3";
        cout << "   PC = " << pc;
        cout << endl;
        a = word[1];
        b = word[2];
        c = word[3];
        temp = stoi(a);
        temp2 = stoi(b);
        temp3 = stoi(c);
        num = temp2^temp3;
        reg[temp] = num;
      }
      if(word[0] == 'D'){
        //cout << " = JUMP TO [23] IF [1] = R0";
        cout << "   R" << word[1] << " = R0, jump to " << pc;
        cout << "   PC = " << pc;
        cout << endl;
        a = word[1];
        b = word[2];
        c = word[3];
        temp = stoi(a);
        temp2 = stoi(b);
        temp3 = stoi(c);
        if(reg[0] == temp){
          temp1 = b + c;
        }
      }
      if(word[0] == 'E'){
        //cout << " = HALT";
        cout << endl;
      }
      if(word[0] == '0'){
        //cout << " = MEMORY ADDRESS";
        cout << endl;
        a = word[1];
        b = word[2];
        c = word[3];
        //temp = stoi(a);
        //temp2 = stoi(b);
        //temp3 = stoi(c);
        num = reg[pc];
        memory[num] = temp2+temp3;
      }

    }
  }
  //memory and reg
}


void hexdec(){
  int j, temp;
  temp = stoi(word);
  while(temp != 0){
    j = temp % 16;
    if (j < 10){
      cout << word;
    } else {
      j = j/16;
      cout << j;
    }
  }
}
