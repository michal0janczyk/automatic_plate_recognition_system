#ifndef POSSIBLECHARINSCENEFINDER_HPP
#define POSSIBLECHARINSCENEFINDER_HPP

#include "PossibleChar.hpp"
#include "ContoursFinder.hpp"

class PossibleCharInSceneFinder
{
public:
    PossibleCharInSceneFinder();
    ~PossibleCharInSceneFinder();

    std::vector<PossibleChar> findAllPossibleCharsInScene(std::vector<std::vector<cv::Point>> &contours);
    bool checkIfPossibleChar(PossibleChar &possibleChar);

private:
    int intCountOfPossibleChars;
    std::vector<PossibleChar> vectorOfPossibleChars;
    const int MIN_PIXEL_AREA = 18;
    const int MIN_PIXEL_HEIGHT = 9;
    const int MIN_PIXEL_WIDTH = 2;
    const double MIN_ASPECT_RATIO = 0.18;
    const double MAX_ASPECT_RATIO = 0.9;
};

#endif // POSSIBLECHARINSCENEFINDER_HPP
