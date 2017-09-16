#ifndef VECTOROFMATCHINGCHARSBUILDER_HPP
#define VECTOROFMATCHINGCHARSBUILDER_HPP

#include "PossibleCharInSceneFinder.hpp"

class VectorOfMatchingCharsBuilder
{
public:
    VectorOfMatchingCharsBuilder();
    ~VectorOfMatchingCharsBuilder();

    std::vector<std::vector<PossibleChar>> findVectorOfVectorsOfMatchingChars(const std::vector<PossibleChar> &vectorOfPossibleCharsInScene);
    std::vector<PossibleChar> findVectorOfMatchingChars(const PossibleChar &possibleChar, const std::vector<PossibleChar> &vectorOfChars);

private:
    const unsigned int MIN_NUMBER_OF_MATCHING_CHARS = 6;
    const double MAX_CHANGE_IN_AREA = 0.7;
    const double MAX_CHANGE_IN_WIDTH = 0.7;
    const double MAX_CHANGE_IN_HEIGHT = 0.20;
    const double MAX_ANGLE_BETWEEN_CHARS = 10.0;
    const double MAX_DIAG_SIZE_MULTIPLE_AWAY = 5.3;

    double dblDistanceBetweenChars = 0;
    double dblAngleBetweenChars = 0;
    double dblChangeInArea = 0;
    double dblChangeInWidth = 0;
    double dblChangeInHeight = 0;
};

#endif // VECTOROFMATCHINGCHARSBUILDER_HPP
