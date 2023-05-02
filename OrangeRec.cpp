#include <iostream>
#include <fstream>
using namespace std;

class pixel_class {
private:
  int red, green, blue;
public:
  void loaddata(int v1, int v2, int v3);
  void datatofile(fstream & ppmfile);
  int getR() { return red; }
  int getG() { return green; }
  int getB() { return blue; }
};

void createpicture();

string filename;
pixel_class picture[250][100];

int main() {
  int x, y;
  fstream myfile;
  createpicture();
  filename = "myImage.ppm";
  myfile.open(filename.c_str(), fstream::out);
  myfile << "P3\n";
  myfile << "# " << filename << endl;
  myfile << 250 << " " << 100 << endl;
  myfile << 256 << endl;
  for(y = 0; y < 100; y++) {
    for(x = 0; x < 250; x++) {
      picture[x][y].datatofile(myfile);
    }
    myfile << endl;
  }
  myfile.close();
}

void createpciture() {
  int x, y;
  for (y = 0; y < 100; y++) {
    for (x = 0; x < 250; x++) {
      picture[x][y].loaddata(255, 153, 0);
    }
  }
}

//-------------methods for the pixel_class------------------
void pixel_class::loaddata(int v1, int v2, int v3) {
  red = v1;
  green = v2;
  blue = v3;
}

void pixel_class::datatofile(fstream & ppmfile) {
  //write the data for one pixel to the ppm file
  ppmfile << red << " " << green;
  ppmfile << " " << blue << " ";
}
