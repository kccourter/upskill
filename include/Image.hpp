#pragma once

#include <opencv2/opencv.hpp>
#include <string>


class Image {

public:
    Image( std::string_view img_path );
    virtual ~Image();

    friend std::ostream& operator<<(std::ostream& os, const Image& obj);

protected:
    std::string img_path;
    int32_t rows, cols, channels;
    cv::Mat img;

private:

};