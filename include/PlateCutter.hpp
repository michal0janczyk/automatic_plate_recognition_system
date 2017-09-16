#ifndef PLATECUTTER_HPP
#define PLATECUTTER_HPP

#include "VectorOfMatchingCharsBuilder.hpp"
#include "PossiblePlate.hpp"
#include "PossibleChar.hpp"

class PlateCutter
{
public:
    PlateCutter();
    ~PlateCutter();

    std::vector<PossiblePlate> cutPlateFromScene(cv::Mat &inputImage, std::vector<std::vector<PossibleChar>> &vectorOfVectorsOfMatchingChars);
    PossiblePlate extractPlate(cv::Mat &inputImage, std::vector<PossibleChar> &vectorOfMatchingChars);

private:
    std::vector<PossiblePlate> vectorOfPossiblePlates;
    cv::Mat rotationMatrix;
    cv::Mat imgRotated;
    cv::Mat imgCropped;

    int intPlateWidth = 0;
    int intPlateHeight = 0;

    const double PLATE_WIDTH_PADDING_FACTOR = 1.04;
    const double PLATE_HEIGHT_PADDING_FACTOR = 1.5;
    double intTotalOfCharHeights = 0;
    double dblAverageCharHeight = 0;
    double dblPlateCenterX = 0;
    double dblPlateCenterY = 0;
    double dblOpposite = 0;
    double dblHypotenuse = 0;
    double dblCorrectionAngleInRad = 0;
    double dblCorrectionAngleInDeg = 0;
};

#endif // PLATECUTTER_HPP
