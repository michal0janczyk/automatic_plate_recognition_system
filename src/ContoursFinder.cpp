#include "../include/ContoursFinder.hpp"

ContoursFinder::ContoursFinder()
{

}

ContoursFinder::~ContoursFinder()
{

}

std::vector<std::vector<cv::Point>> ContoursFinder::findAllContoursInScene(cv::Mat &inputImage)
{
    cv::findContours(inputImage,
                     vectorOfContoursPoint,
                     cv::RETR_LIST,
                     cv::CHAIN_APPROX_SIMPLE);

    return vectorOfContoursPoint;
}

std::vector<cv::Mat> ContoursFinder::cutChar (cv::Mat &inputImage)
{
    const static int PLATE_HEIGHT_FACTOR = inputImage.size().height;

    for(unsigned int i = 0; i < vectorOfContoursPoint.size(); i++ )
    {
        cv::Rect boundingRect = cv::boundingRect(vectorOfContoursPoint[i]);

        if (boundingRect.size().height > PLATE_HEIGHT_FACTOR * MIN_HEIGHT && boundingRect.size().height < PLATE_HEIGHT_FACTOR * MAX_HEIGHT)
        {
            vectorOfSigns.push_back(inputImage(boundingRect));
        }
    }

    return vectorOfSigns;
}

void ContoursFinder::sortContours(cv::Mat &inputImage)
{
    const static int PLATE_WIDTH_FACTOR = inputImage.size().width;

    struct contourSorter
    {
        bool operator ()(const std::vector<cv::Point> &a, const std::vector<cv::Point> &b)
        {
            cv::Rect ra(boundingRect(a));
            cv::Rect rb(boundingRect(b));
            return ((PLATE_WIDTH_FACTOR * ra.x + ra.y) < (PLATE_WIDTH_FACTOR * rb.x + rb.y));
        }
    };

    std::sort(vectorOfContoursPoint.begin(), vectorOfContoursPoint.end(), contourSorter());
}
