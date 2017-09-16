#ifndef BLURREDIMAGE_HPP
#define BLURREDIMAGE_HPP

#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

class BlurredImage
{
public:
    BlurredImage();
    ~BlurredImage();

    cv::Mat imageBlurring(cv::Mat &InputImage);

private:
    cv::Mat outputImage;
    int BLURR_SIZE_WIDTH = 5;
    int BLURR_SIZE_HEIGHT = 5;
    int GAUSSIAN_BLURRED_KERNEL_STANDARD_DEVIATION = 0;
};

#endif // BLURREDIMAGE_HPP
