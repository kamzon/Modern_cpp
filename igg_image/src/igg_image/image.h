#pragma once

#include <vector>
#include <iostream>
#include <io_tools.h>

using namespace std;
using namespace igg::io_tools;

namespace igg {

class Image {
 public:
  ///////////////////// Create the public interface here ///////////////////////
  Image(){ data_ = {};cout << "Empty image " << endl; }
  Image(int rows, int cols):rows_{rows},cols_{cols}{
    for(int i=0; i<rows; i++){
      for(int j=0; j<cols; j++){
        data_.push_back(0);
      }
    }
    
  }

  int rows() const {return rows_;}
  int cols() const {return cols_;}

  int& at(int rows, int cols){
    int& pxl = data_[rows_ * rows + (rows+cols)];

    return pxl;
  }

  bool FillFromPgm(const std::string& file_name){
    ImageData img = ReadFromPgm(file_name);

    if( img.rows == 0 && img.cols == 0){
      cerr << "Error reading from pgm " << endl;
      return false;
    }
    rows_ = img.rows;
    cols_ = img.cols;
    max_val_ = img.max_val;
    data_ = img.data;

    return true;
  }

  void WriteFromPgm(const std::string& file_name){
    ImageData img;

    img.rows = rows_;
    img.cols = cols_;
    img.max_val = max_val_;
    img.data = data_;

    bool b = WriteToPgm(img, file_name);

    if (b){
      cout << "data written successfully " << endl;
    }else{
      cout << "error writing data " << endl;
    }

    return;
  }

 private:
  int rows_ = 0;
  int cols_ = 0;
  int max_val_ = 255;
  std::vector<int> data_;
};

}  // namespace igg
