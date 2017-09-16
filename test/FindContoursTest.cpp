#include "UnitTest++.h"
#include "FindContours.h"

#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

namespace
{
    int expectedLeftTopX, expectedLeftTopY, expectedRightDownX, expectedRightDownY;
    int leftTopX, leftTopY, rightDownX, rightDownY;
    cv::Mat binImage = cv::imread("testsimage/contoursTestImage.png", CV_8UC1);
    FindContours findContours(binImage);
    std::vector<std::vector<cv::Point> > contours = findContours.getPtContours();

    int expectedNumberOfChars, numberOfChars;
    cv::Mat binImage2 = cv::imread("testsimage/cutTestImage.png", CV_8UC1);
    cv::Mat binImage2Copy = cv::imread("testsimage/cutTestImage.png", CV_8UC1);


TEST(ContoursPointsTest)
{
    expectedLeftTopX = 1;
    expectedLeftTopY = 1;
    expectedRightDownX = 798;
    expectedRightDownY =207;

    leftTopX = contours[0][0].x;
    leftTopY = contours[0][0].y;
    rightDownX = contours[0][2].x;
    rightDownY = contours[0][2].y;

    CHECK_EQUAL(expectedLeftTopX, leftTopX);
    CHECK_EQUAL(expectedLeftTopY, leftTopY);
    CHECK_EQUAL(expectedRightDownX, rightDownX);
    CHECK_EQUAL(expectedRightDownY, rightDownY);
}

TEST (CutCharTest)
{

    FindContours findContours2(binImage2);
    findContours2.cutChar(binImage2Copy);
    std::vector<cv::Mat> signs = findContours2.getSigns();

    expectedNumberOfChars = 3;
    numberOfChars = signs.size();

    CHECK_EQUAL(expectedNumberOfChars, numberOfChars);
}

}
