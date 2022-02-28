#pragma once

#include <vector>
#include <iostream>

namespace igg {

class Image {
 public:
     Image() { std::cout << "empty image ....." << std::endl; }
     Image(int rows, int cols): rows_{rows}, cols_{cols} {}

     int rows() const { return rows_; }
     int cols() const { return cols_; }
  ///////////////////// Create the public interface here ///////////////////////
 private:
  int rows_ = 0;
  int cols_ = 0;
  int max_val_ = 255;
  std::vector<int> data_;
};

}  // namespace igg
