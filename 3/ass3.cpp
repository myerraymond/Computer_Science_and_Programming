//Myer Raymond 18035406

/*NOTE FOR THE MARKER; ran out of time trying to figure out how to
identify between buttons? to allow for squares to be made individualy.
which means max and min values are for entire ppm file and not per button.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
using namespace std;


class pixel_class {
private:
  int red, green, blue;
  bool exclude;  // if true, do not check this pixel
public:
  void loaddata(int v1, int v2, int v3);
  void datatofile(fstream & ppmfile);
  int getR() { return red; }
  int getG() { return green; }
  int getB() { return blue; }
  void setexclude(bool ex) { exclude = ex; }
  bool getexclude() { return exclude; }
};

void loadButtons();

vector<int> yminvec, ymaxvec, xminvec, xmaxvec;

void identifybutton();
void findConnectedPixels(int x, int y);
void final();
int x, y, i;
int total, xmin, xmax, ymin, ymax;  // MUST be global if used SQUARES
int screenx, screeny, maxcolours;   // you must use these IDENTIFY Buttons
pixel_class picture[600][600];      // you must use this

int main() {
  // Step 1 : read in the image from Buttons.ppm
  loadButtons();
  // Step 2 : identify buttons and draw boxes
  xmax = 0;
  ymax = 0;
  xmin = screenx;
  ymin = screeny;
  identifybutton();
  for(x = xmin;x <= xmax; x++){
    picture[x][ymin].loaddata(0, 255, 0);
    picture[x][ymin].setexclude(true);
  }
  for(x = xmin;x <= xmax; x++){
    picture[x][ymax].loaddata(0, 255, 0);
    picture[x][ymax].setexclude(true);
  }

  for(y = ymin; y <= ymax; y++){
    picture[xmin][y].loaddata(0, 255, 0);
    picture[xmin][y].setexclude(true);
  }
  for(y = ymin; y <= ymax; y++){
    picture[xmax][y].loaddata(0, 255, 0);
    picture[xmax][y].setexclude(true);
  }


  findConnectedPixels(x, y);

  // Step 3 : output the final .ppm file
  final();
}

void loadButtons() {
  // load the picture from Buttons.ppm
  int x, y, R, G, B;
  fstream infile;
  string infilename, line;
  infilename = "Buttons.ppm";
  infile.open(infilename.c_str(), fstream::in);
  if (infile.is_open() == false) {
    cout << "ERROR: not able to open " << infilename << endl;
    exit(2);
  }
  getline(infile, line);  // this line is "P3"
  getline(infile, line);  // this line is "# filename"
  infile >> screenx >> screeny;  // this line is the size
  infile >> maxcolours;  // this line is 256
  for (y = 0; y < screeny; y++) {
    for (x = 0; x < screenx; x++) {
      infile >> R >> G >> B;
      picture[x][y].loaddata(R, G, B);
      picture[x][y].setexclude(true);
    }
  }
  infile.close();
}

void findConnectedPixels(int x, int y) {
  if(picture[x][y].getexclude() == true){ return; }
  if(picture[x][y].getR() <= 128) {
      picture[x][y].loaddata(0,255,0);
  } else {
    return;
  }

  if(ymax <= y){
    ymax = y;
    ymaxvec.push_back(y);
    picture[x][y].loaddata(0,255,0);
    picture[x][y].setexclude(true);
    //return;
  }
  if(xmax <= x){
    xmax = x;
    xmaxvec.push_back(x);
    picture[x][y].loaddata(255, 0,0);
    picture[x][y].setexclude(true);
    //return;
  }
  if(xmin >= x){
    xmin = x;
    xminvec.push_back(x);
    picture[x][y].loaddata(255,0,0);
    picture[x][y].setexclude(true);
    //return;
  }
  if(ymin >= y){
    ymin = y;
    yminvec.push_back(y);
    picture[x][y].loaddata(0,255,0);
    picture[x][y].setexclude(true);
    //return;
  }

  picture[x][y].setexclude(true);
  // buttonnum++;
  // return;
}




void identifybutton() {
  //identifying buttons
  int x, y, R, G, B;
  fstream infile;
  string infilename, line;
  infilename = "Buttons.ppm";
  infile.open(infilename.c_str(), fstream::in);
  if (infile.is_open() == false) {
    cout << "ERROR: not able to open " << infilename << endl;
    exit(2);
  }
  getline(infile, line); //this is line "P3"
  getline(infile, line); // this line is "# filename"
  infile >> screenx >> screeny; /// this is the size
  infile >> maxcolours; // this line is 256
  for(y = 0; y < screeny; y++) {
    for(x = 0; x < screenx; x++) {
      infile >> R >> G >> B;
      picture[x][y].loaddata(R,G,B);
      picture[x][y].setexclude(false);
     if(R >= 128){
        findConnectedPixels(x, y);
        findConnectedPixels(x-1, y);
        findConnectedPixels(x+1, y);
        findConnectedPixels(x, y-1);
        findConnectedPixels(x, y+1);
      }
  }
}

  infile.close();
}


void final() {
  int x, y;
  string filename;
  fstream myfile;
  filename = "Final.ppm";
  myfile.open(filename.c_str(), fstream::out);
  myfile << "P3\n";
  myfile << "# " << filename << endl;
  myfile << 600 << " " << 600 << endl;
  myfile << 256 << endl;
  for(y = 0; y < 600; y++) {
    for(x = 0; x < 600; x++) {
      picture[x][y].datatofile(myfile);
    }
    myfile << endl;
  }
  myfile.close();
}

//--------------- methods for the pixel_class ------------
void pixel_class::loaddata(int v1, int v2, int v3) {
  red = v1;
  green = v2;
  blue = v3;
}

void pixel_class::datatofile(fstream & ppmfile) {
  // write the data for one pixel to the ppm file
  ppmfile << red << " " << green;
  ppmfile << " " << blue << "  ";
}
