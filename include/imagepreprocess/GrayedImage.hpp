#ifndef GRAYEDIMAGE_HPP
#define GRAYEDIMAGE_HPP

#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

class GrayedImage
{
public:
    GrayedImage();
    ~GrayedImage();

    cv::Mat grayScaleImage(cv::Mat &inputImage);

private:
    cv::Mat imgHSV;
    std::vector<cv::Mat> vectorOfHSVImages;
    cv::Mat outputImage;
};

#endif // GRAYEDIMAGE_HPP
