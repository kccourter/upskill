#include <iostream>

#include "Image.hpp"


Image::Image( std::string img_path ) {
    this->img_path = img_path;

    rows = cols = channels = 0;

    unsigned char* data = stbi_load( img_path.c_str(), &cols, &rows, &channels, 0 );

    if ( data == nullptr ) {
        std::string errorMsg = "Could not open image file: "; 
        errorMsg += img_path;

        // std::cerr << "Could not open image file" << std::endl;
        throw std::runtime_error( errorMsg );;
    }
    img = UniqueStbiImage(data);
    
}

Image::~Image() {

}

void Image::write( std::string file_path, Image::ImgType type ) {
    if ( img == nullptr ) {
        std::string errorMsg = "No image allocated, cannot write"; 
        throw std::runtime_error( errorMsg );
    }
    int retVal;
    switch( type ) {
        case ImgType::PNG:
            std::cout << "Writing to " << file_path << std::endl;
            retVal = stbi_write_png( file_path.c_str(), cols, rows, channels, img.get(), cols * channels );
            std::cout << "stbi_write_png result = " << retVal << std::endl;
            if (retVal == 0) {
                std::cout << "Good luck figuring out what's wrong" << std::endl;
            }
            break;
        case ImgType::JPG:
            break;
        case ImgType::BMP:
            break;
    }
}

std::ostream& operator<<(std::ostream& os, const Image& obj) {
    os << "rows: " << obj.rows << std::endl;
    os << "cols: " << obj.cols << std::endl;
    os << "channels: " << obj.channels << std::endl;
    os << "img_path: " << obj.img_path << std::endl;
    return os;
}