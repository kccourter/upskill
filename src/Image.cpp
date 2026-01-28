#include <iostream>

#include "Image.hpp"

Image::Image( std::string_view img_path ) {
    this->img_path = img_path;
    img = cv::imread( this->img_path, cv::IMREAD_COLOR_RGB );
    if (img.empty()) {
        std::cout << "Error: Could not read the image file, check the path." << std::endl;
        throw;
    }
    cols = img.cols;
    rows = img.rows;
    channels = img.channels();
}

Image::~Image() {

}

std::ostream& operator<<(std::ostream& os, const Image& obj) {
    os << "rows: " << obj.rows << std::endl;
    os << "cols: " << obj.cols << std::endl;
    os << "channels: " << obj.channels << std::endl;
    os << "img_path: " << obj.img_path << std::endl;
    return os;
}