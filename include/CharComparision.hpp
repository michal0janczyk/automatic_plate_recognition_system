#ifndef CHARCOMPARISION_HPP
#define CHARCOMPARISION_HPP

#include "ImageChanger.hpp"
#include "PossiblePlate.hpp"
#include "PossibleChar.hpp"

#include <fstream>
#include <iostream>

class CharComparision
{
public:
    CharComparision();
    ~CharComparision();

    std::string compareChar(std::vector<std::vector<std::vector<bool>>> binarySigns);

private:
    std::string result;
    std::vector<char> possibleChars {'B', 'C', 'D', 'E', 'F', 'G', 'H','K', 'L', 'N', 'O', 'P', 'R', 'S', 'T', 'U', 'W', 'Z'};
    std::vector<char> vectorOfChars;
    std::vector<int> vectorOfCompability;
    std::vector<std::vector<bool>> tempSigns;
    std::vector<std::vector<bool>> vectorOfBinaryChar;
    int charsSize = 0;
    char bestFit;
    char tempFit;
    bool logic;
    bool isFirstIteration = false;
    double compatibility = 0;
    double compatibilityMax;
    const static int LATTICESIZEWIDTH = 27;
    const static int LATTICESIZEHEIGHT = 40;
    const static int BASESIZE = 35;
};

#endif // CHARCOMPARISION_HPP
