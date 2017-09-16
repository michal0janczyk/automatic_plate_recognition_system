#ifndef PREPROCESS_HPP
#define PREPROCESS_HPP

#include "BlurredImage.hpp"
#include "ContrastMaximizer.hpp"
#include "GrayedImage.hpp"
#include "ImageBinarization.hpp"

class Preprocess
    : public BlurredImage,
      public ContrastMaximizer,
      public GrayedImage,
      public ImageBinarization
{
public:
    Preprocess();
    virtual ~Preprocess();

    std::vector<cv::Mat> imagePreprocess(cv::Mat &inputImage);
    std::vector<cv::Mat> platePreprocess(cv::Mat &inputPlate);

private:
    std::vector<cv::Mat> vectorOfBinaryImage;
    std::vector<cv::Mat> vectorOfBinaryPlate;
    cv::Mat thresholdImage;
    cv::Mat thresholdImageCopy;
    cv::Mat thresholdPlate;
    cv::Mat thresholdPlateCopy;
};

#endif // PREPROCESS_HPP
