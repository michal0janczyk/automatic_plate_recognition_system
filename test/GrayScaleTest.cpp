//#include "UnitTest++.h"
//#include "GrayScale.h"
//
//#include<opencv2/core/core.hpp>
//#include<opencv2/highgui/highgui.hpp>
//#include<opencv2/imgproc/imgproc.hpp>
//
//
//namespace
//{
//    float expectedRed, expectedGreen, expectedBlue;
//    float red, green, blue;
//    cv::Vec3b intensity;
//
//    cv::Mat originalImage = cv::imread("testsimage/TestImage.png");
//    GrayScale grayScale(originalImage);
//    cv::Mat grayImage = grayScale.getImage();
//
//
//TEST(PureRedTest)
//{
//    expectedBlue = 0;
//    expectedGreen = 0;
//    expectedRed = 0;
//    intensity = grayImage.at<cv::Vec3b>(8, 8);
//    blue = intensity.val[0];
//    green = intensity.val[1];
//    red = intensity.val[2];
//    CHECK_EQUAL(expectedBlue, blue);
//    CHECK_EQUAL(expectedGreen, green);
//    CHECK_EQUAL(expectedRed, red);
//}
//
//TEST(PureBlueTest)
//{
//
//    expectedBlue = 150;
//    expectedGreen = 150;
//    expectedRed = 52;
//    intensity = grayImage.at<cv::Vec3b>(8, 0);
//    blue = intensity.val[0];
//    green = intensity.val[1];
//    red = intensity.val[2];
//    CHECK_EQUAL(expectedBlue, blue);
//    CHECK_EQUAL(expectedGreen, green);
//    CHECK_EQUAL(expectedRed, red);
//}
//
//TEST(PureGreenTest)
//{
//    expectedBlue = 84;
//    expectedGreen = 84;
//    expectedRed = 110;
//    intensity = grayImage.at<cv::Vec3b>(0, 8);
//    blue = intensity.val[0];
//    green = intensity.val[1];
//    red = intensity.val[2];
//    CHECK_EQUAL(expectedBlue, blue);
//    CHECK_EQUAL(expectedGreen, green);
//    CHECK_EQUAL(expectedRed, red);
//}
//
//TEST(PureBlackTest)
//{
//    expectedBlue = 0;
//    expectedGreen = 0;
//    expectedRed = 255;
//    intensity = grayImage.at<cv::Vec3b>(0, 0);
//    blue = intensity.val[0];
//    green = intensity.val[1];
//    red = intensity.val[2];
//    CHECK_EQUAL(expectedBlue, blue);
//    CHECK_EQUAL(expectedGreen, green);
//    CHECK_EQUAL(expectedRed, red);
//}
//
//TEST(PureWhiteTest)
//{
//    expectedBlue = 218;
//    expectedGreen = 218;
//    expectedRed = 29;
//    intensity = grayImage.at<cv::Vec3b>(0, 2);
//    blue = intensity.val[0];
//    green = intensity.val[1];
//    red = intensity.val[2];
//    CHECK_EQUAL(expectedBlue, blue);
//    CHECK_EQUAL(expectedGreen, green);
//    CHECK_EQUAL(expectedRed, red);
//}
//}
