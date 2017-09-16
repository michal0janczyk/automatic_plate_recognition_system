#ifndef PLATEFINDER_HPP
#define PLATEFINDER_HPP

#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

#include "../include/imagepreprocess/ImageResizer.hpp"
#include "../include/imagepreprocess/Preprocess.hpp"
#include "ContoursFinder.hpp"
#include "PossibleCharInSceneFinder.hpp"
#include "ImpossibleCharsRemover.hpp"
#include "VectorOfMatchingCharsBuilder.hpp"
#include "PlateCutter.hpp"
#include "PossiblePlate.hpp"
#include "PlateCoordinatesFinder.hpp"

class PlateFinder
{
public:
    PlateFinder();
    ~PlateFinder();
    std::vector<PossiblePlate> findPlate(cv::Mat inputImage, int flag);

private:
    std::vector<cv::Mat> vectorOfBinaryImage;
    std::vector<std::vector<cv::Point>> vectorOfContoursPointInScen1;
    std::vector<std::vector<cv::Point>> vectorOfContoursPointInScen2;
    std::vector<PossibleChar> vectorOfPossibleCharInScene1;
    std::vector<PossibleChar> vectorOfPossibleCharInScene2;
    std::vector<PossibleChar> cleanedVectorOfPossibleCharInScene1;
    std::vector<PossibleChar> cleanedVectorOfPossibleCharInScene2;
    std::vector<std::vector<PossibleChar>> vectorOfVectorsOfMatchingCharsInScene1;
    std::vector<std::vector<PossibleChar>> vectorOfVectorsOfMatchingCharsInScene2;
    std::vector<PossiblePlate> vectorOfPossiblePlates1;
    std::vector<PossiblePlate> vectorOfPossiblePlates2;
    std::vector<PossiblePlate> vectorOfPossiblePlates;
    int IMAGE_RESIZE_WIDTH = 1920;
    int IMAGE_RESIZE_HEIGHT = 1080;
};

#endif // PLATEFINDER_HPP
