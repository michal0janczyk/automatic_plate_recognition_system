#include "UnitTest++.h"
#include "CompareImage.h"
#include <string>
#include <fstream>
#include <iostream>

#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

namespace
{
    std::string expectedChar, result;
    std::ifstream bFile ("testsimage/singleChar.txt");
    std::vector<bool> tmpVec;
    std::vector<std::vector<bool> > binSigns;
    bool tmp;

TEST(CorrectCharTest)
{
    for(int i = 0; i < 625; i++)
    {
        bFile >> tmp;
        tmpVec.push_back(tmp);
    }
    binSigns.push_back(tmpVec);

    expectedChar = "B";
    CompareImage compareImage(binSigns);
    result = compareImage.getResult();

    CHECK_EQUAL(expectedChar, result);
}

}
