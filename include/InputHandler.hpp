#ifndef INPUTHANDLER_HPP
#define INPUTHANDLER_HPP

#include <iostream>

#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

class InputHandler
{
public:
    InputHandler();
    virtual ~InputHandler();

    cv::Mat loadImage();
    cv::Mat loadImage(std::string inputPath);
    cv::Mat loadImage(unsigned char* inputArray);
    std::vector<cv::Mat> loadSeriesOfImage();

private:
    std::string fileName;
    std::vector<cv::Mat> seriesOfImage;
    const int IMAGE_HEIGHT = 1080;
    const int IMAGE_WIDTH = 1920;
};

#endif // INPUTHANDLER_HPP
