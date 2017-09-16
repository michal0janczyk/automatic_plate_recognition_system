#ifndef CHARRECOGNIZER_HPP
#define CHARRECOGNIZER_HPP

#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

#include "PossiblePlate.hpp"
#include "PossibleChar.hpp"
#include "../include/imagepreprocess/Preprocess.hpp"
#include "../include/imagepreprocess/ImageResizer.hpp"
#include "ContoursFinder.hpp"
#include "ImpossiblePlateEliminator.hpp"
#include "ImageChanger.hpp"
#include "CharComparision.hpp"

class CharRecognizer
{
public:
    CharRecognizer();
    ~CharRecognizer();
    std::string recognizeChar(std::vector<PossiblePlate> vectorOfPossiblePlates);

private:
    std::vector<cv::Mat> vectorOfBinaryPlate1;
    std::vector<cv::Mat> vectorOfBinaryPlate2;
    std::vector<cv::Mat> signsMean1, signsMean2, signsGaus1, signsGaus2;
    std::vector<std::vector<cv::Mat>> tempVectorOfSigns;
    std::vector<std::vector<cv::Mat>> vectorOfSigns;
    std::vector<std::vector<std::vector<bool>>> vectorOfBinarySigns;
    std::string result;

    int PLATE_RESIZE_WIDTH = 560;
    int PLATE_RESIZE_HEIGHT = 122;
};

#endif // CHARRECOGNIZER_HPP
