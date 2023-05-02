#include <iostream>
#include <cstdlib>

using namespace std;

int RandomInt(int first, int last);
int i, x, a, b, c, d, e, f, result;

int main () {

  for(i = 0; i < 6000; i++){
    x = RandomInt(1, 6);
    if(x == 1){
      a = a + 1;
    }
    else if(x == 2){
      b = b + 1;
    }
    else if(x == 3){
      c = c + 1;
    }
    else if(x == 4){
      d = d + 1;
    }
    else if(x == 5){
      e = e + 1;
    }
    else if(x == 6){
      f = f + 1;
    }
  }
  cout << a << endl<< b << endl << c << endl << d << endl << e << endl << f << endl;
  result = a + b + c + d + e + f;
  cout << result << endl;

}
int RandomInt(int first, int last) {
// returns a random number in the range [first, last]
int diff;
diff = (last - first) + 1;
return rand() % diff + first;
}
