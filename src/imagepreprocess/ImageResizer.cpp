#include "../../include/imagepreprocess/ImageResizer.hpp"

ImageResizer::ImageResizer()
{

}

ImageResizer::~ImageResizer()
{

}

cv::Mat ImageResizer::resizeImage(cv::Mat &inputImage, int &width, int &height)
{
    cv::Size sizeImg(width, height);
    cv::resize(inputImage, outputImage, sizeImg);

    return outputImage;
}
