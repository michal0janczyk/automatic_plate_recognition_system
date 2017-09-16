#include "SwapImage.h"

SwapImage::SwapImage()
{
}

void SwapImage::swapImageFunction(std::vector<std::vector<cv::Mat>> vecOfSigns)
{
    for(int i = 0; i < vecOfSigns.size(); i++)
    {
        std::vector<cv::Mat> tempVector = vecOfSigns[i];
        swapImageFunc(tempVector);
        vectorOfBinarySigns.push_back(binSigns);
    }
}

void SwapImage::swapImageFunc(std::vector<cv::Mat> signs)
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
                tmpVec.push_back((bool)(signs[i].at<unsigned int8_t>((j+1)*height,(k+1)*width)));
            }
        }
        binSigns.push_back(tmpVec);
    }
}

SwapImage::~SwapImage()
{

}
