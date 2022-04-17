#include<iostream>
#include<image.h>
#include<io_tools.h>

using namespace std;
using namespace igg;
using namespace igg::io_tools;


const std::string& data_pgm_file = "/home/nk/2022/C++/Modern_cpp/igg_image/data/lena.ascii.pgm";

const std::string& pgm_file = "/home/nk/2022/C++/Modern_cpp/igg_image/data/img.pgm";


int main(){

    Image img1{};
    Image img2{10,10};

    cout << "image 1 : " << img1.rows() << " " << img1.cols() << endl;
        
    cout << "image 2 : " << img2.rows() << " " << img2.cols() << endl;

    cout << img2.at(5,5) << endl;

    img2.at(5,5) = 25;

    cout << img2.at(125,125) << endl;

    bool b = img1.FillFromPgm(data_pgm_file);

    if (b)
    {
        cout << img1.cols() << " " << img1.rows() << endl;

        cout << img1.at(0 , 0) << endl;
    }
    
    img1.WriteFromPgm(pgm_file);

    // ImageData img;

    // img = ReadFromPgm(data);

    // cout << img.cols << " " << img.rows << endl;

    // cout << img.data[512 * 512 -1] << endl;


    return 0;
}