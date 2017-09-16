#include "../include/CharComparision.hpp"

CharComparision::CharComparision()
{

}

CharComparision::~CharComparision()
{

}

std::string CharComparision::compareChar(std::vector<std::vector<std::vector<bool>>> binarySigns)
{
    charsSize = binarySigns[0].size();
    for(int i = 0; i < charsSize; i++)
    {
        vectorOfBinaryChar.clear();
        for(std::size_t j = 0; j < binarySigns.size(); j++)
        {
            vectorOfBinaryChar.push_back(binarySigns[j][i]);
        }

        for(std::size_t k = 0; k < vectorOfBinaryChar.size(); k++)
        {
            std::ifstream baseFile("BASE.txt");
            compatibilityMax = 0;

            for(int l = 0; l < BASESIZE; l++)
            {
                baseFile >> tempFit;
                compatibility = 0;

                for(std::size_t m = 0; m < vectorOfBinaryChar[k].size(); m++)
                {
                    baseFile >> logic;
                    if(vectorOfBinaryChar[k][m] == logic)
                    {
                        compatibility++;
                    }
                }

                if(compatibilityMax < compatibility)
                {
                    compatibilityMax = compatibility;
                    bestFit = tempFit;
                }
            }
            baseFile.close();

            vectorOfChars.push_back(bestFit);
            vectorOfCompability.push_back(compatibilityMax);
        }
    }

    int tempValue = 0;
    int tempVar = 0;

    for(int j=0; j < charsSize; j++)
    {
        char tempChar = vectorOfChars[tempVar];
        tempValue = vectorOfCompability[tempVar];
        for(std::size_t k=1; k < binarySigns.size(); k++)
        {
            tempVar++;
            if(vectorOfCompability[tempVar] > tempValue)
            {
                tempChar = vectorOfChars[tempVar];
            }
        }
        if(isFirstIteration > 0)
        {
            result += tempChar;
            tempVar++;
        }

        if(isFirstIteration == 0)
        {
            if(tempChar == '0')
            {
                result = result + "O";
                tempVar++;
                isFirstIteration++;
            }
            else if(tempChar == '8')
            {
                result = result + "B";
                tempVar++;
                isFirstIteration++;
            }
            else if(tempChar == 'X')
            {
                result = result + "K";
                tempVar++;
                isFirstIteration++;
            }
            else if(tempChar == '5')
            {
                result = result + "S";
                tempVar++;
                isFirstIteration++;
            }
            else if (std::find(possibleChars.begin(), possibleChars.end(), tempChar) != possibleChars.end())
            {
                result += tempChar;
                isFirstIteration++;
                tempVar++;
            }
            else
            {
                isFirstIteration++;
                tempVar++;
            }
        }
    }
    return result;
}
