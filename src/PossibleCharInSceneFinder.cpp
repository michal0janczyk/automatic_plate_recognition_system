#include "../include/PossibleCharInSceneFinder.hpp"

PossibleCharInSceneFinder::PossibleCharInSceneFinder()
{

}

PossibleCharInSceneFinder::~PossibleCharInSceneFinder()
{

}

std::vector<PossibleChar> PossibleCharInSceneFinder::findAllPossibleCharsInScene(std::vector<std::vector<cv::Point>> &contours)
{
    for(std::size_t i = 0; i < contours.size(); i++)
    {
        PossibleChar possibleChar(contours[i]);

        if (checkIfPossibleChar(possibleChar))
        {
            intCountOfPossibleChars++;
            vectorOfPossibleChars.push_back(possibleChar);
        }
    }
    return vectorOfPossibleChars;
}

bool PossibleCharInSceneFinder::checkIfPossibleChar(PossibleChar &possibleChar)
{
    if (possibleChar.boundingRect.area() > MIN_PIXEL_AREA &&
            possibleChar.boundingRect.width > MIN_PIXEL_WIDTH &&
            possibleChar.boundingRect.height > MIN_PIXEL_HEIGHT &&
            MIN_ASPECT_RATIO < possibleChar.dblAspectRatio &&
            possibleChar.dblAspectRatio < MAX_ASPECT_RATIO)
    {
        return(true);
    }
    else
    {
        return(false);
    }
}

