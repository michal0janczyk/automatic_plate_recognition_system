#include "FindContours.h"
#include <iostream>

FindContours::FindContours()
{
}

FindContours::FindContours(cv::Mat &binImage)
{
    cv::findContours(binImage,
                     ptContours,
                     cv::RETR_LIST,
                     cv::CHAIN_APPROX_SIMPLE);
}

void FindContours::sortContours(cv::Mat &binImage)
{
    const static int scaleFactor = binImage.size().width;

    struct contourSorter
    {
        bool operator ()(const std::vector<cv::Point> &a, const std::vector<cv::Point> &b)
        {
            cv::Rect ra(boundingRect(a));
            cv::Rect rb(boundingRect(b));
            return ((scaleFactor*ra.x + ra.y) < (scaleFactor*rb.x + rb.y));
        }
    };
    std::sort(ptContours.begin(), ptContours.end(), contourSorter());
}

void FindContours::cutChar (cv::Mat &binImage)
{
    const static int plateHeight = binImage.size().height;
    for(unsigned int i = 0; i < ptContours.size(); i++ )
    {
        cv::Rect boundingRect = cv::boundingRect(ptContours[i]);

        if (boundingRect.size().height > plateHeight * MINHEIGHT && boundingRect.size().height < plateHeight * MAXHEIGHT)
        {
            signs.push_back(binImage(boundingRect));
        }
    }
}

FindContours::~FindContours()
{
}

