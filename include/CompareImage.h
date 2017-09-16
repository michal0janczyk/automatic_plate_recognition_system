#ifndef COMPAREIMAGE_H
#define COMPAREIMAGE_H

#include "SwapImage.h"
#include <fstream>

class CompareImage
{
public:
    CompareImage();
    CompareImage(std::vector<std::vector<std::vector<bool>>> binSigns);
    ~CompareImage();

    std::string getResult(){return result;};

private:
    int h = 0;
    int charsSize = 0;
    std::string result;
    char bestFit;
    char tempFit;
    bool logic;
    bool flag = false;
    bool flag2 = false;
    std::vector<char> impossibleChars {'B', 'C', 'D', 'E', 'F', 'G', 'H',
                'K', 'L', 'N', 'O', 'P', 'R', 'S', 'T', 'U', 'W', 'Z'};
    std::vector<char> vectorOfChars;
    std::vector<int> vectorOfCompability;
    std::vector<std::vector<bool>> tempSigns;
    std::vector<std::vector<bool>> vecOfChar;

    double compatibility = 0;
    double compatibilityMax;
    double scale;
    double scaleMax;

    const static int LATTICESIZEWIDTH = 27;
    const static int LATTICESIZEHEIGHT = 40;
    const static int BASESIZE = 35;
};

#endif // COMPAREIMAGE_H
