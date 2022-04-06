#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.h"
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE];

int loadImage ();
void saveImage ();
void R_90_degree();
void R_180_degree ();
void R_270_degree();
void R_360_degree ();
void invert_Image ();
void  black_and_white();
void  Flip_Image();
int main()
{
  string start="1";
  int failed;

    while (start != "0"){
    cout<<"Press 0 to exit, any key to continue ..."<< endl;
    cin>>start;
    cout<<endl;
    if (start=="0"){
        start=false;
        break;
    }
    else{
        failed = loadImage();

while (failed){
    failed = loadImage();
   }
        cout << endl;
  int way;
  cout << endl;
    cout <<"choose Filter from 1 to c:"<< endl;
    cout <<"Filter 1: Black and White Image."<< endl;
    cout << "Filter 2: Invert Image."<< endl;
    cout << "Filter 3: Merge Image."<< endl;
    cout <<"Filter 4: Flip Image."<< endl;
    cout << "Filter 5: Rotate Image."<< endl;
    cout << "Filter 6: Darken and Lighten Image."<< endl;
    cout << "Filter 7: Detect Image Edges."<< endl;
    cout << "Filter 8: Enlarge Image."<< endl;
    cout << "Filter 9: Shrink Image."<< endl;
    cout << "Filter a: Mirror Image."<< endl;
    cout << "Filter b: Shuffle Image."<< endl;
    cout << "Filter c: Blur Image."<< endl;
    cin>>way;
    if (way == 1){
        black_and_white();
    }
    if (way == 2){
        invert_Image();
    }
    if (way == 4){
        Flip_Image();
    }
    if (way == 5){
        cout << "Rotate (90), (180) , (270) or (360) degrees?" << endl;
        cin >> way;
        if (way == 90){
            R_90_degree();
        }else if (way == 180){
            R_180_degree ();
        }else if (way == 270){
            R_270_degree();
        }else if (way == 360){
            R_360_degree ();
        }

        }
  saveImage();
    }
}
return 0;
}
//_________________________________________
int loadImage () {
   char imageFileName[100];

   // Get gray scale image file name_
   cout << "Enter the source image file name: ";
   cin >> imageFileName;
    int failed;
   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   failed = readGSBMP(imageFileName, image);
    return failed;
}

//_________________________________________
void saveImage () {
   char imageFileName[100];

   // Get gray scale image target file name
   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeGSBMP(imageFileName, image);
}

//_________________________________________
void R_270_degree() {

for (int i = 0; i < SIZE; i++){
        for (int j = 0, k = SIZE - 1; j < k; j++, k--){
            swap(image[i][j], image[i][k]);

        }
  }
  for (int i = 0; i < SIZE; i++){
        for (int j = i; j < SIZE; j++){
            swap(image[j][i], image[i][j]);
        }
  }
}
//_________________________________________
void R_90_degree(){
  for (int i = 0; i < SIZE; i++){
        for (int j = 0, k = SIZE - 1; j < k; j++, k--){
            swap(image[j][i], image[k][i]);

        }
  }
  for (int i = 0; i < SIZE; i++){
        for (int j = i; j < SIZE; j++){
            swap(image[i][j], image[j][i]);
        }
  }
}

//_________________________________________
void R_180_degree (){
    for (int x = 0; x < 2; x++){
        for (int i = 0; i < SIZE; i++){
            for (int j = 0, k = SIZE - 1; j < k; j++, k--){
                swap(image[j][i], image[k][i]);

        }
  }
  for (int i = 0; i < SIZE; i++){
        for (int j = i; j < SIZE; j++){
            swap(image[i][j], image[j][i]);
        }
  }
    }

    }
//_________________________________________
  void invert_Image (){
for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
        image[i][j] = 255-image[i][j];
    }
}
  }
//_________________________________________
void R_360_degree (){
    /*
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            image[i][j] = image[i][j];
        }
    }
*/
}
//_________________________________________
void  black_and_white() {
  for (int x = 0; x < SIZE; x++) {
    for (int y = 0; y< SIZE; y++) {

        if (image[x][y] > 127)
            image[x][y] = 255;
        else
            image[x][y] = 0;
    }
  }
}
//_________________________________________
void  Flip_Image() {

  for (int x = 0 ; x <= SIZE /2 ; x++) {

    for (int y = 0; y != SIZE ; ++y ) {
 std::swap(image[x][y], image[SIZE - 1 - x][y]) ;
    }
    }

}
//_________________________________________
