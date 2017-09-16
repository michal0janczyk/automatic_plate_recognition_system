//#include "UnitTest++.h"
//#include "BlurImage.h"
//
//#include<opencv2/core/core.hpp>
//#include<opencv2/highgui/highgui.hpp>
//#include<opencv2/imgproc/imgproc.hpp>
//
//namespace
//{
//    float expectedRed, expectedGreen, expectedBlue;
//    float red, green, blue;
//    cv::Vec3b intensity;
//
//    cv::Mat originalImage = cv::imread("testsimage/TestImage.png");
//    BlurImage blurImage(originalImage);
//    cv::Mat blurImg = blurImage.getImage();
//
//
//TEST(BlurBlackTest)
//{
//    expectedBlue = 54;
//    expectedGreen = 46;
//    expectedRed = 32;
//    intensity = blurImg.at<cv::Vec3b>(0, 0);
//    blue = intensity.val[0];
//    green = intensity.val[1];
//    red = intensity.val[2];
//    CHECK_EQUAL(expectedBlue, blue);
//    CHECK_EQUAL(expectedGreen, green);
//    CHECK_EQUAL(expectedRed, red);
//}
//
//TEST(BlurBlueTest)
//{
//    expectedBlue = 42;
//    expectedGreen = 228;
//    expectedRed = 19;
//    intensity = blurImg.at<cv::Vec3b>(9, 0);
//    blue = intensity.val[0];
//    green = intensity.val[1];
//    red = intensity.val[2];
//    CHECK_EQUAL(expectedBlue, blue);
//    CHECK_EQUAL(expectedGreen, green);
//    CHECK_EQUAL(expectedRed, red);
//}
//
//TEST(BlurGreenTest)
//{
//    expectedBlue = 219;
//    expectedGreen = 49;
//    expectedRed = 52;
//    intensity = blurImg.at<cv::Vec3b>(0, 9);
//    blue = intensity.val[0];
//    green = intensity.val[1];
//    red = intensity.val[2];
//    CHECK_EQUAL(expectedBlue, blue);
//    CHECK_EQUAL(expectedGreen, green);
//    CHECK_EQUAL(expectedRed, red);
//}
//
//TEST(BlurRedTest)
//{
//    expectedBlue = 1;
//    expectedGreen = 28;
//    expectedRed = 218;
//    intensity = blurImg.at<cv::Vec3b>(9, 9);
//    blue = intensity.val[0];
//    green = intensity.val[1];
//    red = intensity.val[2];
//    CHECK_EQUAL(expectedBlue, blue);
//    CHECK_EQUAL(expectedGreen, green);
//    CHECK_EQUAL(expectedRed, red);
//}
//
//}
