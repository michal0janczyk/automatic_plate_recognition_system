#include "../include/PlateCutter.hpp"

PlateCutter::PlateCutter()
{

}

PlateCutter::~PlateCutter()
{

}

std::vector<PossiblePlate> PlateCutter::cutPlateFromScene(cv::Mat &inputImage, std::vector<std::vector<PossibleChar>> &vectorOfVectorsOfMatchingChars)
{
    for(auto &vectorOfMatchingChars : vectorOfVectorsOfMatchingChars)
    {
        PossiblePlate possiblePlate = extractPlate(inputImage, vectorOfMatchingChars);

        if (possiblePlate.plateImage.empty() == false)
        {
            vectorOfPossiblePlates.push_back(possiblePlate);
        }
    }
    return vectorOfPossiblePlates;
}

PossiblePlate PlateCutter::extractPlate(cv::Mat &inputImage, std::vector<PossibleChar> &vectorOfMatchingChars)
{
    PossiblePlate possiblePlate;

    std::sort(vectorOfMatchingChars.begin(), vectorOfMatchingChars.end(), PossibleChar::sortCharsLeftToRight);

    dblPlateCenterX = static_cast<double>((vectorOfMatchingChars[0].intCenterX + vectorOfMatchingChars[vectorOfMatchingChars.size() - 1].intCenterX) / 2.0);
    dblPlateCenterY = static_cast<double>((vectorOfMatchingChars[0].intCenterY + vectorOfMatchingChars[vectorOfMatchingChars.size() - 1].intCenterY) / 2.0);
    cv::Point2d p2dPlateCenter(dblPlateCenterX, dblPlateCenterY);

    intPlateWidth = static_cast<int>(((vectorOfMatchingChars[vectorOfMatchingChars.size() - 1].boundingRect.x +
                                       vectorOfMatchingChars[vectorOfMatchingChars.size() - 1].boundingRect.width -
                                       vectorOfMatchingChars[0].boundingRect.x) * PLATE_WIDTH_PADDING_FACTOR));

    for (auto &matchingChar : vectorOfMatchingChars)
    {
        intTotalOfCharHeights = intTotalOfCharHeights + matchingChar.boundingRect.height;
    }

    dblAverageCharHeight = static_cast<double>(intTotalOfCharHeights / vectorOfMatchingChars.size());

    intPlateHeight = static_cast<int>(dblAverageCharHeight * PLATE_HEIGHT_PADDING_FACTOR);

    PossibleChar possibledblHypotenuse;
    dblOpposite = vectorOfMatchingChars[vectorOfMatchingChars.size() - 1].intCenterY - vectorOfMatchingChars[0].intCenterY;
    dblHypotenuse = possibledblHypotenuse.distanceBetweenChars(vectorOfMatchingChars[0], vectorOfMatchingChars[vectorOfMatchingChars.size() - 1]);
    dblCorrectionAngleInRad = asin(dblOpposite / dblHypotenuse);
    dblCorrectionAngleInDeg = dblCorrectionAngleInRad * (180.0 / CV_PI);

    possiblePlate.rrLocationOfPlateInScene = cv::RotatedRect(p2dPlateCenter, cv::Size2f(static_cast<float>(intPlateWidth), static_cast<float>(intPlateHeight)),
            static_cast<float>(dblCorrectionAngleInDeg));

    rotationMatrix = cv::getRotationMatrix2D(p2dPlateCenter, dblCorrectionAngleInDeg, 1.0);

    cv::warpAffine(inputImage, imgRotated, rotationMatrix, inputImage.size());

    cv::getRectSubPix(imgRotated, possiblePlate.rrLocationOfPlateInScene.size, possiblePlate.rrLocationOfPlateInScene.center, imgCropped);

    possiblePlate.plateImage = imgCropped;

    return(possiblePlate);
}
