//#18035406  Myer Raymond
#include <iostream>
#include <string> //stoi() function.
#include <stdlib.h> //exit(0) function.

using namespace std;

int binary(int);
int decimal(int);
int total, num, i;
string x;

int main () {
  cout << "Enter a number: ";
    cin >> x;
  /*total = total length(characters/numbers/decimals) of the input to determine
  if the input is too large and to cipher through in the for loop */
  total = x.length();
  /*stoi() is used for the conversion from string to int,
  num is the global variable used.*/
  num = stoi(x);

  if(x[i] == '0'){
    if(total <= 9){
      for(i = 0; i <= total -1;i++ ){

        if((x[i] != '0') && (x[i] != '1')){
          cout << "Invalid Binary Number. \n";
          exit(0);
        }
      }
      binary(num);
    }
    else {
      cout << "This binary number has more than 9 binary digits.\n";
  }
  }
    else if (x[i] != '0'){
        if (total >= 4){
          cout << "Number is larger than 4 decimals. \n";
        } else if ((num <= 255) && (num >= 0)){
          decimal(num);
        } else {
          cout << "This decimal number is outside the range 0 to 255. \n";
        }
    }
}

// the conversion from binary to decimal shown below:
// note: the bitwise operations being used.
int binary(int num){
  cout << "Converting Binary to Decimal:   \n";
  int dec, i, rem, temp;
    dec = 0;
    i = 0;
    temp = num;

      while (num!=0) {
        rem = num % 10;
        num /= 10;
        dec += (rem << i);
        i++;
      }

      cout << temp << " in binary = " << dec << " in decimal.\n";
    return 0;
}

// the conversion from decimal to binary shown below:
int decimal(int num){
  cout << "Converting Decimal to Binary:  \n";
  int rem, binary, p, temp;
    p = 1;
    temp = num;
    binary = 0;

      while(num != 0){
        rem = num % 2;
        binary += (rem * p);
        num = (num / 2);
        p *= 10;
      }

      cout << temp << " in decimal = " << binary << " in binary.\n";
    return 0;
}
