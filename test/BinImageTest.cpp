#include "UnitTest++.h"
#include "BinImage.h"

#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

namespace
{
    float expectedRed, expectedGreen, expectedBlue;
    float red, green, blue;
    cv::Vec3b intensity;

    cv::Mat blurImage = cv::imread("testsimage/BlurredTestImage.png", CV_8UC1);
    BinImage binImage(blurImage);
    cv::Mat thresholdImage = binImage.getImage();

TEST(BlackPixelTest)
{
    expectedBlue = 255;
    expectedGreen = 255;
    expectedRed = 255;
    intensity = thresholdImage.at<cv::Vec3b>(0,0);
    blue = intensity.val[0];
    green = intensity.val[1];
    red = intensity.val[2];
    CHECK_EQUAL(expectedBlue, blue);
    CHECK_EQUAL(expectedGreen, green);
    CHECK_EQUAL(expectedRed, red);
}

}
