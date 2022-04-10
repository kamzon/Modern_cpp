#include<iostream>
#include<image.h>
#include<io_tools.h>

using namespace std;
using namespace igg;

int main(){

    Image img1{};
    Image img2{10,10};

    cout << "image 1 : " << img1.rows() << " " << img1.cols() << endl;
        
    cout << "image 2 : " << img2.rows() << " " << img2.cols() << endl;

    cout << img2.at(5,5) << endl;

    img2.at(5,5) = 25;

    cout << img2.at(5,5) << endl;


    return 0;
}