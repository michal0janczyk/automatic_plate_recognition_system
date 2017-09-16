#ifndef SWAPIMAGE_H
#define SWAPIMAGE_H

#include "FindContours.h"

class SwapImage
{
public:
    SwapImage();
    ~SwapImage();

    void swapImageFunction(std::vector<std::vector<cv::Mat>> vecOfSigns);
    void swapImageFunc(std::vector<cv::Mat> signs);

    std::vector<std::vector<std::vector<bool>>> getVectorOfBinarySigns(){ return vectorOfBinarySigns;};


private:
    std::vector<std::vector<std::vector<bool>>> vectorOfBinarySigns;
    std::vector<std::vector<bool>> binSigns;
    std::vector<bool> tmpVec;
    std::vector<cv::Mat> tempVector;
    float height;
    float width;
    static const int LATTICESIZEWIDTH = 27;
    static const int LATTICESIZEHEIGHT = 40;
};

#endif // SWAPIMAGE_H
