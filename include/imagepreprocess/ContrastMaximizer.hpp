#ifndef CONTRASTMAXIMIZER_HPP
#define CONTRASTMAXIMIZER_HPP

#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

class ContrastMaximizer
{
public:
    ContrastMaximizer();
    ~ContrastMaximizer();

    cv::Mat contrastIncreasing(cv::Mat &inputImage);

private:
    const cv::Size SIZE = cv::Size(5,5);
    cv::Mat structuringElement;
    cv::Mat imgTopHat;
    cv::Mat imgBlackHat;
    cv::Mat imgGrayscalePlusTopHat;
    cv::Mat outputImage;
};

#endif // CONTRASTMAXIMIZER_HPP
