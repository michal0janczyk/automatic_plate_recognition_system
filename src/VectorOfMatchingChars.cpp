#include "VectorOfMatchingChars.hpp"

VectorOfMatchingChars::VectorOfMatchingChars()
{

}

VectorOfMatchingChars::~VectorOfMatchingChars()
{

}

std::vector<std::vector<PossibleChar>> VectorOfMatchingChars::findVectorOfVectorsOfMatchingChars(const std::vector<PossibleChar> &vectorOfPossibleChars)
{
    std::vector<std::vector<PossibleChar>> vectorOfVectorsOfMatchingChars;

    for (auto &possibleChar : vectorOfPossibleChars)
    {
        std::vector<PossibleChar> vectorOfMatchingChars = findVectorOfMatchingChars(possibleChar, vectorOfPossibleChars);

        vectorOfMatchingChars.push_back(possibleChar);

        if (vectorOfMatchingChars.size() < MIN_NUMBER_OF_MATCHING_CHARS)
        {
            continue;
        }

        vectorOfVectorsOfMatchingChars.push_back(vectorOfMatchingChars);

        std::vector<PossibleChar> vectorOfPossibleCharsWithCurrentMatchesRemoved;

        for (auto &possChar : vectorOfPossibleChars)
        {
            if (std::find(vectorOfMatchingChars.begin(), vectorOfMatchingChars.end(), possChar) == vectorOfMatchingChars.end())
            {
                vectorOfPossibleCharsWithCurrentMatchesRemoved.push_back(possChar);
            }
        }

        std::vector<std::vector<PossibleChar>> recursiveVectorOfVectorsOfMatchingChars;

        recursiveVectorOfVectorsOfMatchingChars = findVectorOfVectorsOfMatchingChars(vectorOfPossibleCharsWithCurrentMatchesRemoved);

        for (auto &recursiveVectorOfMatchingChars : recursiveVectorOfVectorsOfMatchingChars)
        {
            vectorOfVectorsOfMatchingChars.push_back(recursiveVectorOfMatchingChars);
        }
        break;
    }
    return(vectorOfVectorsOfMatchingChars);
}

std::vector<PossibleChar> VectorOfMatchingChars::findVectorOfMatchingChars(const PossibleChar &possibleChar, const std::vector<PossibleChar> &vectorOfChars)
{
    std::vector<PossibleChar> vectorOfMatchingChars;

    for (auto &possibleMatchingChar : vectorOfChars)
    {
        if (possibleMatchingChar == possibleChar)
        {
            continue;
        }

        PossibleChar possibleDistanceBeteenChar;
        dblDistanceBetweenChars = possibleDistanceBeteenChar.distanceBetweenChars(possibleChar, possibleMatchingChar);
        dblAngleBetweenChars = possibleDistanceBeteenChar.angleBetweenChars(possibleChar, possibleMatchingChar);
        dblChangeInArea = static_cast<double>(abs(possibleMatchingChar.boundingRect.area() - possibleChar.boundingRect.area())) / static_cast<double>(possibleChar.boundingRect.area());
        dblChangeInWidth = static_cast<double>(abs(possibleMatchingChar.boundingRect.width - possibleChar.boundingRect.width)) / static_cast<double>(possibleChar.boundingRect.width);
        dblChangeInHeight = static_cast<double>(abs(possibleMatchingChar.boundingRect.height - possibleChar.boundingRect.height)) / static_cast<double>(possibleChar.boundingRect.height);

        if (dblDistanceBetweenChars < (possibleChar.dblDiagonalSize * MAX_DIAG_SIZE_MULTIPLE_AWAY) &&
                dblAngleBetweenChars < MAX_ANGLE_BETWEEN_CHARS &&
                dblChangeInArea < MAX_CHANGE_IN_AREA &&
                dblChangeInWidth < MAX_CHANGE_IN_WIDTH &&
                dblChangeInHeight < MAX_CHANGE_IN_HEIGHT)
        {
            vectorOfMatchingChars.push_back(possibleMatchingChar);
        }
    }
    return(vectorOfMatchingChars);
}
