#include "RemoveInnerOverlappingChars.hpp"

RemoveInnerOverlappingChars::RemoveInnerOverlappingChars()
{

}


RemoveInnerOverlappingChars::~RemoveInnerOverlappingChars()
{

}

std::vector<PossibleChar> RemoveInnerOverlappingChars::removeInnerOverlappingChars(std::vector<PossibleChar> &vectorOfMatchingChars)
{
    std::vector<PossibleChar> vectorOfMatchingCharsWithInnerCharRemoved(vectorOfMatchingChars);

    for (auto &currentChar : vectorOfMatchingChars)
    {
        for (auto &otherChar : vectorOfMatchingChars)
        {
            if (currentChar != otherChar)
            {
                PossibleChar findIn;

                if (findIn.distanceBetweenChars(currentChar, otherChar) < (currentChar.dblDiagonalSize * MIN_DIAG_SIZE_MULTIPLE_AWAY))
                {
                    if (currentChar.boundingRect.area() < otherChar.boundingRect.area())
                    {
                        std::vector<PossibleChar>::iterator currentCharIterator = std::find(vectorOfMatchingCharsWithInnerCharRemoved.begin(), vectorOfMatchingCharsWithInnerCharRemoved.end(), currentChar);
                        if (currentCharIterator != vectorOfMatchingCharsWithInnerCharRemoved.end())
                        {
                            vectorOfMatchingCharsWithInnerCharRemoved.erase(currentCharIterator);
                        }
                    }
                    else
                    {
                        std::vector<PossibleChar>::iterator otherCharIterator = std::find(vectorOfMatchingCharsWithInnerCharRemoved.begin(), vectorOfMatchingCharsWithInnerCharRemoved.end(), otherChar);
                        if (otherCharIterator != vectorOfMatchingCharsWithInnerCharRemoved.end())
                        {
                            vectorOfMatchingCharsWithInnerCharRemoved.erase(otherCharIterator);
                        }
                    }
                }
            }
        }
    }

    return(vectorOfMatchingCharsWithInnerCharRemoved);
}
