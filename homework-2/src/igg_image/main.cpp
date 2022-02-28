#include "./image.h"
#include <iostream>

int main(){

    igg::Image img0;

    igg::Image img1(500, 500);

    std::cout << "image 0 size :" << img0.rows() << " , " << img0.cols() << std::endl;
    
    std::cout << "image 1 size :" << img1.rows() << " , " << img1.cols() << std::endl;


    return 0;
}
