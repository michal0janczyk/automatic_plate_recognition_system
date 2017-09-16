#include "CompareImage.h"

CompareImage::CompareImage()
{
}

CompareImage::CompareImage(std::vector<std::vector<std::vector<bool>>> binSigns)
{
    charsSize = binSigns[0].size();
    for(int i = 0; i < charsSize; i++)
    {
        vecOfChar.clear();
        for(std::size_t j = 0; j < binSigns.size(); j++)
        {
            vecOfChar.push_back(binSigns[j][i]);
        }

        for(std::size_t k = 0; k < vecOfChar.size(); k++)
        {
            std::ifstream baseFile("BASE.txt");
            compatibilityMax = 0;

            for(int l = 0; l < BASESIZE; l++)
            {
                baseFile >> tempFit;
                compatibility = 0;

                for(int m = 0; m < vecOfChar[k].size(); m++)
                {
                    baseFile >> logic;
                    if(vecOfChar[k][m] == logic)
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

    for(int n = 0; n < vectorOfChars.size(); n++)
    {
        std::cout << vectorOfChars[n] << " ";
    }
    std::cout <<"\n";
    for(int n = 0; n < vectorOfCompability.size(); n++)
    {
        std::cout << vectorOfCompability[n] << " ";
    }

    int tempValue = 0;
    int tempVar = 0;

    for(int j=0; j < charsSize; j++)
    {
        char tempChar = vectorOfChars[tempVar];
        tempValue = vectorOfCompability[tempVar];
        for(int k=1; k < binSigns.size(); k++)
        {
            tempVar++;
            if(vectorOfCompability[tempVar] > tempValue)
            {
                tempChar = vectorOfChars[tempVar];
            }
        }
        if(flag > 0)
        {
            result += tempChar;
            tempVar++;
        }

        if(flag == 0)
        {
            if(tempChar == '0')
            {
                result = result + "O";
                tempVar++;
                flag++;
            }
            else if (std::find(possibleChars.begin(), possibleChars.end(), tempChar) != possibleChars.end())
            {
                result += tempChar;
                flag++;
                tempVar++;
            }
            else
            {
                flag++;
                tempVar++;
            }
        }
    }

    std::cout << "Result: " << result;

}

CompareImage::~CompareImage()
{
}
