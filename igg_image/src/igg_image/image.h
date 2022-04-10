#pragma once

#include <vector>
#include <iostream>

using namespace std;

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


 private:
  int rows_ = 0;
  int cols_ = 0;
  int max_val_ = 255;
  std::vector<int> data_;
};

}  // namespace igg
