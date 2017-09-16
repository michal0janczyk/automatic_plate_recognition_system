#ifndef IMAGERESIZER_HPP
#define IMAGERESIZER_HPP

#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

class ImageResizer
{
public:
    ImageResizer();
    ~ImageResizer();

    cv::Mat resizeImage(cv::Mat &inputImage, int &width, int &height);

private:
    cv::Mat outputImage;
};

#endif // IMAGERESIZER_HPP
