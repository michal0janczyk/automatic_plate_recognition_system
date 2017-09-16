#ifndef IMAGEBINARIZATION_HPP
#define IMAGEBINARIZATION_HPP

#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

class ImageBinarization
{
public:
    ImageBinarization();
    ~ImageBinarization();

    cv::Mat makeImageBinarization(cv::Mat &blurredImage, char binarizationType, char imageType);

private:
    cv::Mat binaryImage;

    int binaryzationType;
    int blockSize;
    int constantSize;

    static const int MAX_THRESHOLD_VALUE = 255;
    static const int MEAN_BINARYZATION = 0;
    static const int GAUSSIAN_BINARYZATION = 1;
    static const int IMAGE_BLOCK_SIZE = 19;
    static const int IMAGE_CONSTANT = 9;
    static const int PLATE_BLOCK_SIZE = 41;
    static const int PLATE_CONSTANT = 3;
};

#endif // IMAGEBINARIZATION_HPP
