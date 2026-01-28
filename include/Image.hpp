#pragma once
#include <string>
#include "stb_image.h"
#include "stb_image_write.h"


class Image {

public:
    Image( std::string_view img_path );
    virtual ~Image();

    friend std::ostream& operator<<(std::ostream& os, const Image& obj);

protected:
    std::string img_path;
    int32_t rows, cols, channels;

private:

};