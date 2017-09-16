#include "../../include/imagepreprocess/GrayedImage.hpp"

GrayedImage::GrayedImage()
{

}

GrayedImage::~GrayedImage()
{

}

cv::Mat GrayedImage::grayScaleImage(cv::Mat &inputImage)
{
    cvtColor(inputImage, imgHSV, CV_BGR2HSV);
    cv::split(imgHSV, vectorOfHSVImages);
    outputImage = vectorOfHSVImages[2];

    return outputImage;
}
