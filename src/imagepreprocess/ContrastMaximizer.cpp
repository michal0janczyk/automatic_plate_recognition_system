#include "../../include/imagepreprocess/ContrastMaximizer.hpp"

ContrastMaximizer::ContrastMaximizer()
{

}

ContrastMaximizer::~ContrastMaximizer()
{

}

cv::Mat ContrastMaximizer::contrastIncreasing(cv::Mat &inputImage)
{
    structuringElement = cv::getStructuringElement(CV_SHAPE_RECT, SIZE);

    cv::morphologyEx(inputImage, imgTopHat, CV_MOP_TOPHAT, structuringElement);
    cv::morphologyEx(inputImage, imgBlackHat, CV_MOP_BLACKHAT, structuringElement);

    imgGrayscalePlusTopHat = inputImage + imgTopHat;
    outputImage = imgGrayscalePlusTopHat - imgBlackHat;

    return outputImage;
}
