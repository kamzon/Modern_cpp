// Copyright Igor Bogoslavskyi, year 2018.
// In case of any problems with the code please contact me.
// Email: igor.bogoslavskyi@uni-bonn.de.
//
// Do not create a cpp file for this file. It is needed to use the library
// lib/libio_tools.so distributed with this repository.

#pragma once

#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

namespace igg {
namespace io_tools {

/// Dummy structure to store relevant image data.
struct ImageData {
  int rows;
  int cols;
  int max_val;
  std::vector<int> data;
};

/// Reads from a pgm image from ascii file. Returns empty ImageData if the path
/// is not found or any errors have occured while reading.
ImageData ReadFromPgm(const std::string& file_name){
    ImageData image;
    
    ifstream infile(file_name, ios::binary);
    stringstream ss;    
    string inputLine = "";

    getline(infile,inputLine);      // read the first line : P2
    if(inputLine.compare("P2") != 0) {
      cerr << "Version error" << endl;
      return {};
    }
    cout << "Version : " << inputLine << endl;

    // getline(infile,inputLine);  // read the second line : comment
    // cout << "Comment : " << inputLine << endl;

    ss << infile.rdbuf();   //read the third line : width and height
    ss >> image.cols >> image.rows >> image.max_val;
    cout << image.cols << " columns and " << image.rows << " rows " ;

   
    cout<<image.max_val <<endl;;

    int pixel;

    for (int row = 0; row < image.rows; row++){    //record the pixel values
        for (int col = 0; col < image.cols; col++){
             ss >> pixel;
             image.data.push_back(pixel);
             pixel = 0;
        }
        
    }
    
    infile.close();  



    return image;
}

/// Write image data into an ascii pgm file. Return true if successful.
bool WriteToPgm(const ImageData& image_data, const std::string& file_name){

  std::ofstream fileOut(file_name.c_str(),std::ios_base::out
                          |std::ios_base::binary
                          |std::ios_base::trunc
               );

  fileOut << "P2" <<endl;
  fileOut << image_data.rows << " " << image_data.cols << endl;
  fileOut << image_data.max_val << endl;
  cout << image_data.data.capacity() << endl;
  for (long unsigned i = 0;i<image_data.data.capacity();i++){
    
    fileOut << image_data.data[i] << " " ;
  }

  fileOut <<endl;

  fileOut.close();
  

  return true;

}

}  // namespace io_tools
}  // namespace igg
