// FCI – Programming 1 – 2022 - Assignment 3
// Program Name: Gray-Scale-Image-Processor.cpp
// Last Modification Date: 7/4/2022
// Author1 and ID and Group: Ahmed Ashraf ... ID: 20210535
// Author2 and ID and Group: Abdelrhman Hamdy ... ID: 20210202
// Author3 and ID and Group: Mostafa Mahmoud ... ID: 20210398
// Teaching Assistant: Dr/ Mohamed EL-Ramly
// Purpose: Photoshop Program

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.h"
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];

int loadImage ();
void saveImage ();
void R_90_degree();
void R_180_degree ();
void R_270_degree();
void R_360_degree ();
void invert_Image ();
void  black_and_white();
void  Flip_Image();
void Darken_Lighten_image();
void Merge_Filter();
void Enlarge_Image();
void Shuffle_Image();
void blur();
void shrink();
void MirrorImage();
void DetectImageEdges();
int main()
{
  string start="1";
  int failed;
  int strt = 1;

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
    cout <<"choose Filter from 1 to 12:"<< endl;
    cout <<"Filter 1: Black and White Image."<< endl;
    cout << "Filter 2: Invert Image."<< endl;
    cout << "Filter 3: Merge Image."<< endl;
    cout << "Filter 4: Flip Image."<< endl;
    cout << "Filter 5: Rotate Image."<< endl;
    cout << "Filter 6: Darken and Lighten Image."<< endl;
    cout << "Filter 7: Detect Image Edges." << endl;
    cout << "Filter 8: Enlarge Image." << endl;
    cout << "Filter 9: Shrink Image." << endl;
    cout << "Filter 10: Mirror Image." << endl;
    cout << "Filter 11: Shuffle Image." << endl;
    cout << "Filter 12: Blur Image." << endl;
    cin>>way;
    if (way == 1){
        black_and_white();
    }
    if (way == 2){
        invert_Image();
    }
    if (way == 3){
        Merge_Filter();
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
        if (way == 6){
            Darken_Lighten_image();
        }
        if (way == 7){
            DetectImageEdges();
        }
        if (way == 8){
            Enlarge_Image();
        }
        if (way == 9){
            shrink();
        }
        if (way == 10){
            MirrorImage();
        }
        if (way == 11){
            Shuffle_Image();
        }
        if (way == 12){
            blur();
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
    failed = readGSBMP(imageFileName, image2);
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
      writeGSBMP(imageFileName, image2);
<<<<<<< HEAD

=======
>>>>>>> 4fada2d0b2a35a51f52d32b8c6213b21a709f322
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
void Darken_Lighten_image(){

    int choice;
    cout<<"Press 0 for lighten, 1 for darken..."<<endl;
    cin>>choice;
    if (choice ==1){

        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j< SIZE; j++) {
                if (image[i][j]>50)
                    image[i][j]-=50;

            }
        }

    }

    else{
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j< SIZE; j++) {
                if (image[i][j]<205)
                    image[i][j]+=50;

            }
        }
    }

}
//_________________________________________
void Merge_Filter() {
    char imageFileName2[100];
    cout << "Enter the source image2 file name: ";
    cin >> imageFileName2;
    strcat(imageFileName2, ".bmp");
    readGSBMP(imageFileName2, image2);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image[i][j] = (image[i][j] + image2[i][j]) / 2;

        }
    }
}
//_________________________________________
void Enlarge_Image(){
  int quart;

  cout<<"Which quarter to enlarge 1, 2, 3 or 4? : ";
  cin>>quart;

  if (quart == 1){
    for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j< SIZE; j++) {

        image[i][j] = image2[i/2][j/2];
      }
    }
  }

  if (quart == 2){
    for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j< SIZE; j++) {

        image[i][j] = image2[i/2][j/2+SIZE/2];
      }
    }
  }

  if (quart == 3){
    for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j< SIZE; j++) {

        image[i][j] = image2[i/2+SIZE/2][j/2];
      }
    }
  }

  if (quart == 4){
    for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j< SIZE; j++) {

        image[i][j] = image2[i/2+SIZE/2][j/2+SIZE/2];
      }
    }
  }


}
//_________________________________________
void Shuffle_Image() {
	int x, y, z, a;
	unsigned char image2[256][256];
	cout << "New order of quarters : ";
	cin >> x;
	if (x == 1) {
		int m =0, n=0;
		for (int i = 0; i < 128; i++) {
			n = 0;
			for (int j = 0; j < 128; j++) {
				image2[m][n] = image[i][j];
				n++;
			}
			m++;
		}
	}
	if (x == 2) {
		int c = 0, g = 0;
		for (int i = 0; i < 128; i++) {
			g = 0;
			for (int j = 128; j < 256; j++) {
				image2[c][g] = image[i][j];
				g++;
			}
			c++;
		}
	}
	if (x == 3) {
		int c = 0, g = 0;
		for (int i = 128; i < 256; i++) {
			g = 0;
			for (int j = 0; j < 128; j++) {
				image2[c][g] = image[i][j];
				g++;
			}
			c++;
		}
	}
	if (x == 4) {
		int c = 0, g = 0;
		for (int i = 128; i < 256; i++) {
			g = 0;
			for (int j = 128; j < 256; j++) {
				image2[c][g] = image[i][j];
				g++;
			}
			c++;
		}
	}
	cin >> y;
	if (y == 1) {
		int c = 0, g = 128;
		for (int i = 0; i < 128; i++) {
			g = 128;
			for (int j = 0; j < 128; j++) {
				image2[c][g] = image[i][j];
				g++;
			}
			c++;
		}
	}
	if (y == 2) {
		int c = 0, g = 128;
		for (int i = 0; i < 128; i++) {
			g = 128;
			for (int j = 128; j < 256; j++) {
				image2[c][g] = image[i][j];
				g++;
			}
			c++;
		}
	}
	if (y == 3) {
		int c = 0, g = 128;
		for (int i = 128; i < 256; i++) {
			g = 128;
			for (int j = 0; j < 128; j++) {
				image2[c][g] = image[i][j];
				g++;
			}
			c++;
		}
	}
	if (y == 4) {
		int c = 0, g = 128;
		for (int i = 128; i < 256; i++) {
			g = 128;
			for (int j = 128; j < 256; j++) {
				image2[c][g] = image[i][j];
				g++;
			}
			c++;
		}
	}
	cin >> z;
	if (z == 1) {
		int c = 128, g = 0;
		for (int i = 0; i < 128; i++) {
			g = 0;
			for (int j = 0; j < 128; j++) {
				image2[c][g] = image[i][j];
				g++;
			}
			c++;
		}
	}
	if (z == 2) {
		int c = 128, g = 0;
		for (int i = 0; i < 128; i++) {
			g = 0;
			for (int j = 128; j < 256; j++) {
				image2[c][g] = image[i][j];
				g++;
			}
			c++;
		}
	}
	if (z == 3) {
		int c = 128, g = 0;
		for (int i =128; i < 256; i++) {
			g = 0;
			for (int j = 0; j < 128; j++) {
				image2[c][g] = image[i][j];
				g++;
			}
			c++;
		}
	}
	if (z == 4) {
		int c = 128, g = 0;
		for (int i = 128; i < 256; i++) {
			g = 0;
			for (int j = 128; j < 256; j++) {
				image2[c][g] = image[i][j];
				g++;
			}
			c++;
		}
	}
	cin >> a;
	if (a == 1) {
		int c = 128, g = 128;
		for (int i = 0; i < 128; i++) {
			g = 128;
			for (int j = 0; j < 128; j++) {
				image2[c][g] = image[i][j];
				g++;
			}
			c++;
		}
	}
	if (a == 2) {
		int c = 128, g = 128;
		for (int i = 0; i < 128; i++) {
			g = 128;
			for (int j = 128; j < 256; j++) {
				image2[c][g] = image[i][j];
				g++;
			}
			c++;
		}
	}
	if (a == 3) {
		int c = 128, g = 128;
		for (int i = 128; i < 256; i++) {
			g = 128;
			for (int j = 0; j < 128; j++) {
				image2[c][g] = image[i][j];
				g++;
			}
			c++;
		}
	}
	if (a == 4) {
		int c = 128, g = 128;
		for (int i = 128; i < 256; i++) {
			g = 128;
			for (int j = 128; j < 256; j++) {
				image2[c][g] = image[i][j];
				g++;
			}
			c++;
		}
	}
	for (int i = 0; i < 256; i++) {
		for (int j = 0; j < 256; j++) {
			image[i][j] = image2[i][j];
		}
	}
}
//_________________________________________
void blur(){

    double average;

    for (int i = 0; i <SIZE; i++) {
        for (int j = 0; j<SIZE; j++) {
            int sum = 0;
            sum = image[i ][j ] + image[i ][j+1] + image[i][j + 2] + image[i+1][j] + image[i+1][j+1] +image[i+1][j +2] + image[i +2][j ] + image[i + 2][j+1] + image[i + 2][j + 2];
            average = (sum / 9);
            image[i][j] = average;
        }
    }
}
//_________________________________________

void MirrorImage() {



    int choice ;
    cout << " 1- mirror left " << endl << "2- mirror right" << endl << "3- mirror up" << endl << "4- mirror down" << endl ;
    cin >> choice ;

    if (choice == 1){
            for (int row = 0; row < SIZE ; row++)
    {
        for (int col = 0; col < SIZE/2 ; col++)
        {
    image[row][col] = image[row][255-col] ;

        }
    }
}
else if (choice == 2){
        for (int row = 0; row < SIZE ; row++)
    {
        for (int col = 0; col < SIZE ; col++)
        {
            image[row][255-col] = image[row][col] ;
        }

        }
}
else if (choice == 3) {
        for (int row = 0; row < SIZE ; row++)
    {
        for (int col = 0; col < SIZE ; col++)
        {

                   image[255-col][row] = image [col][row] ;

        }
    }
}

else if (choice == 4 ){
        for (int row = 0; row < SIZE ; row++)
    {
        for (int col = 0; col < SIZE /2 ; col++)
        {
            image[col][row] = image [255-col][row] ;

        }
    }
}
}

//_________________________________________________________________

void DetectImageEdges() {
  for (int x = 0; x < SIZE; x++) {
    for (int y = 0; y< SIZE; y++) {

        if (image[x][y] > 127)
            image[x][y] = (255,255);
        else
            image[x][y] = 0;
    }
  }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (image[i][j] != image[i][j + 1] || image[i][j] != image[i][j - 1] || image[i][j] != image[i + 1][j]) {
                image2[i][j] = 0;
            } else {
                image2[i][j] = 255;
            }
        }
    }

}
//____________________________________________________________________________________________________
void shrink()
{
    for (int i =0 ; i <SIZE;i++) {
        for (int j = 0; j < SIZE; j++) {
                image[i / 4][j / 4]= image[i][j];
            }

        }

    for (int i =SIZE/4; i < SIZE; i++){
        for(int j =0 ; j<SIZE;j++)
        {
                image[i][j] = 255;

        }
    }
    for (int i =0; i < SIZE; i++){
        for(int j =SIZE/4; j<SIZE;j++)
        {
                image[i][j] = 255;

        }
    }

}
//____________________________________________________________________________________________________
