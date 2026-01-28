#include <iostream>
#include <opencv2/opencv.hpp>

#include "Image.hpp"



int main( void ) {
    std::cout << "entering main" << std::endl;

    try {
        Image im = Image( "/Users/kcourter/dev/upskill/data/test_images/standard/baboon.jpg" );
        std::cout << "Image is: " << im << std::endl;
    }
    catch (...) {
        std::cerr << "Error: Could not load image" << std::endl;
    }

 

    return 0;
}