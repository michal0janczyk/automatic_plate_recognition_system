#ifndef ADDMARGINS_H
#define ADDMARGINS_H

#include "FindContours.h"

class AddMargins
{
public:
    AddMargins();
    AddMargins(std::vector<std::vector<cv::Mat>> signs);
    ~AddMargins();

    std::vector<std::vector<cv::Mat>> getVectorOfSignsWithMargins(){return vectorOfSignsWithMargins;};

private:
    std::vector<cv::Mat> signsWithMargins;
    std::vector<std::vector<cv::Mat>> vectorOfSignsWithMargins;

    static const int TOPMARGIN = 0;
    static const int BOTTOMMARGIN = 0;
    static const int MARGINPIXELVALUE = 0;
    static const int LARGESTLETTERWIDTH = 54;
    static const int LARGESTLETTERHEIGHT = 80;

    int signWidth;
    int signHeight;
    int signWithMarginsWidth;
    int marginWidth;
};

#endif // ADDMARGINS_H
