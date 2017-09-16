#include "../include/PlateCoordinatesFinder.hpp"

PlateCoordinatesFinder::PlateCoordinatesFinder()
{

}

PlateCoordinatesFinder::~PlateCoordinatesFinder()
{

}

void PlateCoordinatesFinder::findingPlateCoordinates(cv::Mat &inputImage, PossiblePlate &possiblePlate1, PossiblePlate &possiblePlate2,  cv::Point2i(&plateCoordinates)[4])
{
    possiblePlate1.rrLocationOfPlateInScene.points(p2fRectPoints1);
    possiblePlate2.rrLocationOfPlateInScene.points(p2fRectPoints2);

    for (int i = 0; i < 4; i++)
    {
        plateCoordinates[i] = cv::Point2i(((p2fRectPoints1[i] + p2fRectPoints2[i])/2.0));
    }
}
