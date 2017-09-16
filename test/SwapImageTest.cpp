#include "UnitTest++.h"
#include "SwapImage.h"

#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

namespace
{
    int expectedLatticeSize, latticeSize;
    bool result = true;
    int i;

    cv::Mat tempChar = cv::imread("testsimage/singleChar.png");
    std::vector<cv::Mat> signs;

TEST(LatticeSizeTest)
{
    signs.push_back(tempChar);
    SwapImage swapImage(signs);
    std::vector<std::vector<bool> > binSigns = swapImage.getBinSigns();

    expectedLatticeSize = 625;
    latticeSize = binSigns[0].size();
    CHECK_EQUAL(expectedLatticeSize, latticeSize);
}

TEST(isBooleanVectorTest)
{
    signs.push_back(tempChar);
    SwapImage swapImage(signs);
    std::vector<std::vector<bool> > binSigns = swapImage.getBinSigns();

    for(i = 0; i < 30; i++)
    {
        if(binSigns[0][i] != 0 && binSigns[0][i] != 1)
        {
            result = false;
        }
    }

    CHECK_EQUAL(true, result);
}

}
