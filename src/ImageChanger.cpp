#include "../include/ImageChanger.hpp"

ImageChanger::ImageChanger()
{

}

ImageChanger::~ImageChanger()
{

}

std::vector<std::vector<std::vector<bool>>> ImageChanger::changeImage(std::vector<std::vector<cv::Mat>> vectorOfSigns)
{
    for(int i = 0; i < vectorOfSigns.size(); i++)
    {
        std::vector<cv::Mat> tempVector = vectorOfSigns[i];
        swapImageToBinary(tempVector);
        vectorOfBinarySigns.push_back(binSigns);
    }
    return vectorOfBinarySigns;
}

void ImageChanger::swapImageToBinary(std::vector<cv::Mat> signs)
{
    binSigns.clear();
    for (std::size_t i = 0; i < signs.size(); i++)
    {
        tmpVec.clear();
        height = static_cast<float>(signs[i].size().height)/(LATTICESIZEHEIGHT+1);
        width = static_cast<float>(signs[i].size().width)/(LATTICESIZEWIDTH+1);

        for(int j = 0; j < LATTICESIZEHEIGHT; j++)
        {
            for(int k = 0; k < LATTICESIZEWIDTH; k++)
            {
                tmpVec.push_back((bool)(signs[i].at<unsigned int8_t>((j+1)* height,(k+1)*width)));
            }
        }
        binSigns.push_back(tmpVec);
    }
}


