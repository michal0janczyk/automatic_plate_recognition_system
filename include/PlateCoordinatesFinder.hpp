#ifndef PLATECOORDINATESFINDER_HPP
#define PLATECOORDINATESFINDER_HPP

#include "PossiblePlate.hpp"
#include "PlateCutter.hpp"
#include "CharComparision.hpp"

class PlateCoordinatesFinder
{
public:
    PlateCoordinatesFinder();
    ~PlateCoordinatesFinder();

    void findingPlateCoordinates(cv::Mat &inputImage, PossiblePlate &possiblePlate1, PossiblePlate &possiblePlate2, cv::Point2i(&p2fRectPointsAverage)[4]);

private:
    cv::Point2f p2fRectPoints1[4];
    cv::Point2f p2fRectPoints2[4];
    cv::Mat inputImage;
};

#endif // PLATECOORDINATESFINDER_HPP
