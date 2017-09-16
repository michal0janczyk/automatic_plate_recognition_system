#ifndef DRAWREDRECTANGLE_H
#define DRAWREDRECTANGLE_H

#include "PossiblePlate.h"
#include "CutPlate.h"
#include "CompareImage.h"

class DrawRedRectangle
{
public:
    DrawRedRectangle();
    DrawRedRectangle(cv::Mat &originalImage, PossiblePlate &possPlate);
    ~DrawRedRectangle();

    void writeLicensePlateCharsOnImage(cv::Mat &originalImage,PossiblePlate &possPlate ,std::string res);

private:
    cv::Mat originalImage;
    std::string res;
};

#endif // DRAWREDRECTANGLE_H
