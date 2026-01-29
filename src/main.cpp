#include <iostream>



#include "Image.hpp"



int main( void ) {
    std::cout << "entering main" << std::endl;

    try {
        auto im = std::make_unique<Image>( "/Users/kcourter/dev/upskill/data/test_images/standard/baboon.jpg" );
        std::cout << "Image is: " << *im << std::endl;
        im->write( "/Users/kcourter/dev/upskill/data/results/bletch.png", Image::ImgType::PNG );
    }
    catch ( const std::runtime_error& err ) {
        std::cerr << err.what() << std::endl;
    }
    return 0;
}