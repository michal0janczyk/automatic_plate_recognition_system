#include "../include/ImpossibleCharsRemover.hpp"

ImpossibleCharsRemover::ImpossibleCharsRemover()
{

}

ImpossibleCharsRemover::~ImpossibleCharsRemover()
{

}

std::vector<PossibleChar> ImpossibleCharsRemover::removeImpossibleChars(std::vector<PossibleChar> &vectorOfPossibleCharInScene)
{
    std::vector<PossibleChar> vectorOfMatchingCharsWithInnerCharRemoved(vectorOfPossibleCharInScene);

    for (auto &currentChar : vectorOfPossibleCharInScene)
    {
        for (auto &otherChar : vectorOfPossibleCharInScene)
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
