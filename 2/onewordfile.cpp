#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int wordcount;
fstream datafile;          // define a file object
string filename, word;

int main() {
  // 1. The user will enter the full name of the file
  cout << "Enter the FULL name of the file: ";
  cin >> filename;

  // 2. Open the file for reading (input)
  datafile.open(filename.c_str(), fstream::in);

  // only continue if the file has opened successfully
  if (datafile.is_open() == false) {
    cout << "ERROR: not able to open " << filename << endl;
  } else {

    // 3. Access the file - read one word at a time from the file
    cout << "Displaying all the code from " << filename << endl;
    wordcount = 0;
    while (datafile >> word) {
      wordcount++;
      cout << word << endl;
    }
    cout << "There are " << wordcount << " lines of code in the file.\n";

    // 4. Close the file
    datafile.close();
  }
}
