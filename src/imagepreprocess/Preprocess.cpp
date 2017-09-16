#include "../../include/imagepreprocess/Preprocess.hpp"

Preprocess::Preprocess()
{

}

Preprocess::~Preprocess()
{

}

std::vector<cv::Mat> Preprocess::imagePreprocess(cv::Mat &inputImage)
{
    cv::Mat grayedSaclaedImage = GrayedImage::grayScaleImage(inputImage);

    cv::Mat maxContrastImage = ContrastMaximizer::contrastIncreasing(grayedSaclaedImage);

    cv::Mat blurredImage = BlurredImage::imageBlurring(maxContrastImage);

    thresholdImage = ImageBinarization::makeImageBinarization(blurredImage, 'G', 'I');
    thresholdImageCopy = thresholdImage.clone();

    vectorOfBinaryImage.push_back(thresholdImageCopy);

    thresholdImage = ImageBinarization::makeImageBinarization(blurredImage, 'M', 'I');
    thresholdImageCopy = thresholdImage.clone();

    vectorOfBinaryImage.push_back(thresholdImageCopy);

    return (vectorOfBinaryImage);
}

std::vector<cv::Mat> Preprocess::platePreprocess(cv::Mat &inputPlate)
{
    cv::Mat grayedSaclaedPlate = GrayedImage::grayScaleImage(inputPlate);

    cv::Mat maxContrastPlate = ContrastMaximizer::contrastIncreasing(grayedSaclaedPlate);

    cv::Mat blurredPlate = BlurredImage::imageBlurring(maxContrastPlate);

    thresholdPlate = ImageBinarization::makeImageBinarization(blurredPlate, 'G', 'P');
    thresholdPlateCopy = thresholdPlate.clone();

    vectorOfBinaryPlate.push_back(thresholdPlateCopy);

    thresholdPlate = ImageBinarization::makeImageBinarization(blurredPlate, 'M', 'P');
    thresholdPlateCopy = thresholdPlate.clone();

    vectorOfBinaryPlate.push_back(thresholdPlateCopy);

    return (vectorOfBinaryPlate);
}
