#include "../../include/imagepreprocess/ImageBinarization.hpp"

ImageBinarization::ImageBinarization()
{

}

ImageBinarization::~ImageBinarization()
{

}

cv::Mat ImageBinarization::makeImageBinarization(cv::Mat &blurredImage, char binarizationType, char imageType)
{
    switch(binarizationType + imageType)
    {
        case ('G' + 'I'):
            binaryzationType = GAUSSIAN_BINARYZATION;
            blockSize = IMAGE_BLOCK_SIZE;
            constantSize = IMAGE_CONSTANT;
        break;

        case ('M' + 'I'):
            binaryzationType = MEAN_BINARYZATION;
            blockSize = IMAGE_BLOCK_SIZE;
            constantSize = IMAGE_CONSTANT;
        break;

        case ('G' + 'P'):
            binaryzationType = GAUSSIAN_BINARYZATION;
            blockSize = PLATE_BLOCK_SIZE;
            constantSize = PLATE_CONSTANT;
        break;

        case ('M' + 'P'):
            binaryzationType = MEAN_BINARYZATION;
            blockSize = PLATE_BLOCK_SIZE;
            constantSize = PLATE_CONSTANT;
        break;
    }

    int BinaryzationValues[3] = {binaryzationType, blockSize, constantSize};

    cv::adaptiveThreshold(blurredImage, binaryImage, MAX_THRESHOLD_VALUE,
                          BinaryzationValues[0], CV_THRESH_BINARY_INV,
                          BinaryzationValues[1], BinaryzationValues[2]);

    return binaryImage;
}
