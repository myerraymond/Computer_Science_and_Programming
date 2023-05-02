#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

int RandomInt(int first, int last);
int x, y, z, i, null;

int main() {
  y = 4544;
    for(i=0; i < 10000; i++){
      cout << i << " - ";
      if(i == y){
        cout << " = THIS IS THE PIN!" << endl;
        break;
                }
            }
}


int RandomInt(int first, int last) {
// returns a random number in the range [first, last]
int diff;
diff = (last - first) + 1;
return rand() % diff + first;
}
