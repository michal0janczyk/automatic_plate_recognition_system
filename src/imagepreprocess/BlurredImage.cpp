#include "../../include/imagepreprocess/BlurredImage.hpp"

BlurredImage::BlurredImage()
{

}

BlurredImage::~BlurredImage()
{

}

 cv::Mat BlurredImage::imageBlurring(cv::Mat &inputImage)
{
    cv::GaussianBlur(inputImage, outputImage, cv::Size(BLURR_SIZE_WIDTH, BLURR_SIZE_HEIGHT), GAUSSIAN_BLURRED_KERNEL_STANDARD_DEVIATION);

    return outputImage;
}

