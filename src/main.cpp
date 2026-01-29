#include <iostream>



#include "Image.hpp"



int main( void ) {
    std::cout << "entering main" << std::endl;

    Image *im = nullptr;
    try {
        im = new Image( "/Users/kcourter/dev/upskill/data/test_images/standard/baboon.jpg" );
        std::cout << "Image is: " << *im << std::endl;
    }
    catch ( const std::runtime_error& err ) {
        std::cerr << err.what() << std::endl;
    }

    im->write( "/Users/kcourter/dev/upskill/data/test_images/results/bletch.jpg", Image::ImgType::PNG );
 
    delete im;


    return 0;
}