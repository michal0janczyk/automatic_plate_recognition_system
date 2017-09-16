#ifndef CONTOURSFINDER_HPP
#define CONTOURSFINDER_HPP

#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

class ContoursFinder
{
public:
    ContoursFinder();
    ~ContoursFinder();

    std::vector<std::vector<cv::Point>> findAllContoursInScene(cv::Mat &inputImage);
    std::vector<cv::Mat> cutChar(cv::Mat &inputImage);
    void sortContours(cv::Mat &inputImage);
    std::vector<cv::Mat> getVectorOfSigns(){return vectorOfSigns;}

private:
    std::vector<std::vector<cv::Point>> vectorOfContoursPoint;
    std::vector<cv::Mat> vectorOfSigns;

    const float MAX_HEIGHT = 0.8;
    const float MIN_HEIGHT = 0.5;
};

#endif // CONTOURSFINDER_HPP
