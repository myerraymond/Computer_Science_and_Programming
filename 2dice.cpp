#include <iostream>
#include <cstdlib>

using namespace std;

int RandomInt(int first, int last);
int i, x, a, b, c, d, e, f, g, h, m, j, k, l, result;

int main () {

  for(i = 0; i < 6000; i++){
    x = RandomInt(1, 6) + RandomInt(1, 6);
    if(x == 2){
      a = a + 1;
    }
    else if(x == 3){
      b = b + 1;
    }
    else if(x == 4){
      c = c + 1;
    }
    else if(x == 5){
      d = d + 1;
    }
    else if(x == 6){
      e = e + 1;
    }
    else if(x == 7){
      f = f + 1;
    }
    else if(x == 8){
      g = g + 1;
    }
    else if(x == 9){
      h = h + 1;
    }
    else if(x == 10){
      m = m + 1;
    }
    else if(x == 11){
      j = j + 1;
    }
    else if(x == 12){
      k = k + 1;
  }
}
  cout << "2 occured = " << a << endl;
  cout << "3 occured = " << b << endl;
  cout << "4 occured = " << c << endl;
  cout << "5 occured = " << d << endl;
  cout << "6 occured = " << e << endl;
  cout << "7 occured = " << f << endl;
  cout << "8 occured = " << g << endl;
  cout << "9 occured = " << h << endl;
  cout << "10 occured = " << m << endl;
  cout << "11 occured = " << j << endl;
  cout << "12 occured = " << k << endl;

  result = a + b + c + d + e + f + g + h + m + j + k;
  cout << result << endl;
}

int RandomInt(int first, int last) {
// returns a random number in the range [first, last]
int diff;
diff = (last - first) + 1;
return rand() % diff + first;
}
