#pragma once
#include <string>
#include "stb_image.h"
#include "stb_image_write.h"

typedef struct RGBPixel_t {
    uint8_t red = 0;
    uint8_t green = 0;
    uint8_t blue = 0;

} Pixel;


// Define a custom deleter for stbi_load data. Needed because
// stbi allocates memory using malloc, so calling delete would break things.
struct StbiDeleter {
    void operator()( unsigned char* data ) const {
        std::cout << "Custom delete - freeing stbi image" << std::endl;
        stbi_image_free(data);
    }
};

using UniqueStbiImage = std::unique_ptr< unsigned char, StbiDeleter>;


class Image {

public:
    enum class ImgType {
        PNG,
        JPG,
        BMP
    };

    Image( std::string img_path );
    virtual ~Image();

    friend std::ostream& operator<<(std::ostream& os, const Image& obj);

    void write( std::string img_path, ImgType type );

protected:
    std::string img_path;
    int32_t rows, cols, channels;

    UniqueStbiImage img;

private:

};