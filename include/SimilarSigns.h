#ifndef SIMILARSIGNS_H
#define SIMILARSIGNS_H

#include "CompareImage.h"
#include "SwapImage.h"

class SimilarSigns
{
public:
    SimilarSigns();
    SimilarSigns(std::vector<std::vector<bool>> binSigns);
    ~SimilarSigns();

private:
    std::vector<char> similarChars;
    std::vector<float> percent;
    char bestFit;
    char tempFit;
    bool logic;
    int LATTICESIZEWIDTH = 27;
    int LATTICESIZEHEIGHT = 40;
    const static int BASESIZE = 60;
    int compatibility = 0;
    float compatibilityMax;

};

#endif // SIMILARSIGNS_H
